
Acest cod C implementează un sistem simplu de gestionare a informațiilor despre jucători (gamers).  Programul permite adăugarea, listarea, afișarea scorului, afișarea clasamentului, listarea jucătorilor după vârstă și ștergerea jucătorilor.

**Structura codului:**

1.  **Include-uri:**
    *   `#include <stdio.h>`: Include fișierul antet standard pentru intrare/ieșire (e.g., `printf`, `scanf`).
    *   `#include <stdbool.h>`: Include fișierul antet pentru tipul `bool` (true/false). Deși inclus, nu este folosit în cod.
    *   `#include <string.h>`: Include fișierul antet pentru funcții de manipulare a șirurilor (e.g., `strcpy`, `strcmp`).

2.  **Structura `gamer`:**
    *   `