#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *n;
    printf("Cate nume vrei sa introduci? ");
    scanf("%d", &n);

    // Alocăm memorie pentru n pointeri către șiruri de caractere
    char *nume = (char) malloc(n * sizeof(char));

    if (nume == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    // Citirea numelor de la utilizator
    for (int i = 0; i < n; i++) {
        char buffer[100]; // Citim inițial într-un buffer temporar

        printf("Introdu numele %d: ", i + 1);
        scanf("%s", buffer);

        // Alocăm exact câtă memorie este necesară pentru numele introdus
        nume[i] = (char*) malloc((strlen(buffer) + 1) * sizeof(char));

        if (nume[i] == NULL) {
            printf("Eroare la alocarea memoriei pentru numele %d!\n", i + 1);
            return 1;
        }

        // Copiem numele din buffer în memoria alocată
        strcpy(nume[i], buffer);
    }

    // Afișăm lista de nume
    printf("\nLista de nume introduse:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nume[i]);
    }

    // Eliberăm memoria alocată
    for (int i = 0; i < n; i++) {
        free(nume[i]);  // Eliberăm fiecare șir de caractere
    }
    free(nume);  // Eliberăm vectorul de pointeri

    return 0;
}