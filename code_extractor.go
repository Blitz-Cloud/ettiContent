package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
	"strings"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Usage: go run code_extractor.go <directory>")
		os.Exit(1)
	}
	rootDir := os.Args[1]

	err := filepath.Walk(rootDir, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}
		if !info.IsDir() && (strings.HasSuffix(info.Name(), "main.c") || strings.HasSuffix(info.Name(), "main.cpp")) {
			content, err := ioutil.ReadFile(path)
			if err != nil {
				fmt.Printf("Error reading file %s: %v\n", path, err)
				return nil
			}

			strContent := string(content)
			codeBlockStart := strings.Index(strContent, "```c")
			if codeBlockStart == -1 {
				codeBlockStart = strings.Index(strContent, "```cpp")
			}

			if codeBlockStart != -1 {
				codeBlockEnd := strings.LastIndex(strContent, "```")
				if codeBlockEnd > codeBlockStart {
					code := strContent[codeBlockStart+4 : codeBlockEnd]
					code = strings.TrimSpace(code)
					err = ioutil.WriteFile(path, []byte(code), info.Mode())
					if err != nil {
						fmt.Printf("Error writing to file %s: %v\n", path, err)
					} else {
						fmt.Printf("Processed file: %s\n", path)
					}
				}
			}
		}
		return nil
	})

	if err != nil {
		fmt.Printf("Error walking the path %q: %v\n", rootDir, err)
	}
}
