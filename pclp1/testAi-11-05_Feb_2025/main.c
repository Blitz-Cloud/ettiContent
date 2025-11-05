#include <stdio.h>
#include <stdlib.h>

void creareFisier(FILE *file, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&j, sizeof(int), 1, file);
        }
    }
}

void printFisier(FILE *file, int width, int height) {
    printf("Dimensiunile matricei sunt %d x %d\n", width, height);

    int *ptr = (int*)malloc(width * height * sizeof(int));
    if (!ptr) {
        fprintf(stderr, "Eroare la alocarea memoriei\n");
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(ptr + i * width + j, sizeof(int), 1, file);
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%03d ", ptr[i * width + j]);
        }
        printf("\n");
    }
    free(ptr);
}

int comparareSuperComplicat(int x, int y) {
    return x > y;
}

void dacaMaiIntelegiSiAstaEstiBun(int x, int y, int (*comparare)(int, int)) {
    printf("Cele 2 numere de comparat sunt %d %d\n", x, y);
    if (comparare(x, y)) {
        printf("Numarul mai mare este: %d\n", x);
    } else {
        printf("Numarul mai mare este: %d\n", y);
    }
}

int main() {
    FILE *file;
    int width = 10, height = 4;

    file = fopen("./out.txt", "w+b");
    if (!file) {
        fprintf(stderr, "Eroare la deschiderea fișierului\n");
        return 1;
    }

    creareFisier(file, width, height);
    rewind(file);

    printFisier(file, width, height);

    dacaMaiIntelegiSiAstaEstiBun(width, height, comparareSuperComplicat);

    fclose(file);
    return 0;
}