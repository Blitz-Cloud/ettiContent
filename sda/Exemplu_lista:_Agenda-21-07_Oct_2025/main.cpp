#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Added for string operations like strcpy

typedef struct
{
    char Nume[20];
    char Tel[12];
    int Ord;
} Info;

struct Nod
{
    Info Date;
    struct Nod *Urm;
};

struct Lista
{
    int Lungime;
    struct Nod *Prim, *Curent, *Ultim;
};

// Function prototypes (corrected to match implementations or common C practices)
int Creare(struct Lista *ListaPtr);
int TestVida(struct Lista *ListaPtr);
int Primul(struct Lista *ListaPtr);
int Ultimul(struct Lista *ListaPtr);
int Lungime(struct Lista *ListaPtr);
int Inceput(struct Lista *ListaPtr);
// int Sfarsit (struct Lista *ListaPtr); // Sfarsit is implemented to set Curent to the node BEFORE Ultim
int Urmator(struct Lista *ListaPtr);
int Precedent(struct Lista *ListaPtr);
int Pozitionare(struct Lista *ListaPtr, int Pozitie);
void AdaugaSfarsit(struct Lista *ListaPtr, Info Nou);
void AdaugaDreapta(struct Lista *ListaPtr, Info Nou);
int Stergere(struct Lista *ListaPtr);
// int PermDreapta (struct Lista *ListaPtr); // This function name is misleading for a swap
void Ordonare(struct Lista *ListaPtr);
void Afisare(struct Lista *ListaPtr);
void AfisareMeniu();
void InDatePers(struct Lista *ListaPtr, Info InfoInreg);
int SwapWithNext(struct Lista *ListaPtr); // Renamed PermDreapta for clarity

int c;
struct Lista *ListaTel;
Info InfoPers;
int Poz;

int Creare(struct Lista *ListaPtr)
{
    ListaPtr->Prim = (struct Nod *)malloc(sizeof(struct Nod));
    if (!ListaPtr->Prim)
        return 0;
    ListaPtr->Ultim = (struct Nod *)malloc(sizeof(struct Nod));
    if (!ListaPtr->Ultim)
    {
        free(ListaPtr->Prim); // Free previously allocated memory
        return 0;
    }
    ListaPtr->Prim->Urm = ListaPtr->Ultim;
    ListaPtr->Ultim->Urm = NULL; // The sentinel 'Ultim' points to NULL
    ListaPtr->Lungime = 0;
    ListaPtr->Curent = ListaPtr->Prim;
    return 1;
}

int TestVida(struct Lista *ListaPtr) //este lista goala ?
{
    return ListaPtr->Lungime == 0;
}

int Primul(struct Lista *ListaPtr) //este nodul curent primul din lista ?
{
    return (ListaPtr->Prim->Urm == ListaPtr->Curent) && (!TestVida(ListaPtr));
}

int Ultimul(struct Lista *ListaPtr) //este nodul curent ultimul din lista ?
{
    // This function checks if the *data node* at Curent is the last one.
    // It's not about Curent being ListaPtr->Ultim sentinel itself.
    return (ListaPtr->Curent != ListaPtr->Prim && ListaPtr->Curent->Urm == ListaPtr->Ultim) && (!TestVida(ListaPtr));
}

int Lungime(struct Lista *ListaPtr)
{
    return ListaPtr->Lungime;
}

int Inceput(struct Lista *ListaPtr) //seteaza prompterul pe primul element din lista
{
    if (TestVida(ListaPtr))
        return 0;
    else
    {
        ListaPtr->Curent = ListaPtr->Prim->Urm;
        return 1;
    }
}

// Helper function to set Curent to the node before the sentinel Ultim
// This is useful for AdaugaSfarsit.
int GoToLastDataNode(struct Lista *ListaPtr)
{
    if (TestVida(ListaPtr))
        return 0;
    ListaPtr->Curent = ListaPtr->Prim;
    while (ListaPtr->Curent->Urm != ListaPtr->Ultim)
    {
        ListaPtr->Curent = ListaPtr->Curent->Urm;
    }
    return 1;
}

int Urmator(struct Lista *ListaPtr)
{
    if (TestVida(ListaPtr))
        return 0;
    else
    {
        if (ListaPtr->Curent->Urm != ListaPtr->Ultim)
        { // "de ce ?" -> Because Curent should not move past the last data node,
            // which is the node before the sentinel Ultim.
            ListaPtr->Curent = ListaPtr->Curent->Urm;
            return 1;
        }
        else
            return 0; // Curent is already the last data node or invalid position
    }
}

int Precedent(struct Lista *ListaPtr) // de rescris
{
    struct Nod *Temp;

    if (TestVida(ListaPtr))
        return 0;
    if (ListaPtr->Curent == ListaPtr->Prim->Urm)
    { // Already at the first data node
        ListaPtr->Curent = ListaPtr->Prim; // Move Curent to the sentinel Prim
        return 0;                          // Indicate cannot go further back (no previous data node)
    }

    Temp = ListaPtr->Curent;
    ListaPtr->Curent = ListaPtr->Prim; // Start from the dummy head
    while (ListaPtr->Curent->Urm != Temp && ListaPtr->Curent->Urm != NULL)
    { // Iterate until the next node is Temp
        ListaPtr->Curent = ListaPtr->Curent->Urm;
    }
    // At this point, ListaPtr->Curent is the node immediately preceding Temp.
    // If we didn't find Temp, something is wrong, or Temp was the Prim sentinel.
    // The previous implementation had a logic error where Urmator was called in a while condition.
    return 1;
}

int Pozitionare(struct Lista *ListaPtr, int Pozitie)
{
    if (TestVida(ListaPtr))
        return 0;

    Inceput(ListaPtr); // Start from the beginning
    while (ListaPtr->Curent != ListaPtr->Ultim && ListaPtr->Curent->Date.Ord != Pozitie)
    {
        ListaPtr->Curent = ListaPtr->Curent->Urm;
    }

    if (ListaPtr->Curent != ListaPtr->Ultim)
    {
        return 1; // Found the element
    }
    else
    {
        // Not found, reset Curent to a safe position (e.g., Prim)
        ListaPtr->Curent = ListaPtr->Prim;
        return 0;
    }
}

void AdaugaSfarsit(struct Lista *ListaPtr, Info Nou)
{
    struct Nod *Elem;

    // We need to find the node *before* Ultim to insert
    GoToLastDataNode(ListaPtr);

    Elem = (struct Nod *)malloc(sizeof(struct Nod));
    if (!Elem)
    {
        printf("Memory allocation failed for new node!\n");
        return;
    }
    Elem->Urm = ListaPtr->Curent->Urm; // Elem's next is now Ultim
    Elem->Date = Nou;
    ListaPtr->Curent->Urm = Elem; // Curent's next is now Elem
    ListaPtr->Curent = Elem;      // Curent moves to the newly added element
    ListaPtr->Lungime++;
}

void AdaugaDreapta(struct Lista *ListaPtr, Info Nou)
{
    if (ListaPtr->Curent == ListaPtr->Ultim)
    { // Cannot add to the right of the Ultim sentinel
        printf("Cannot add right of the list end sentinel.\n");
        return;
    }

    struct Nod *Elem;
    Elem = (struct Nod *)malloc(sizeof(struct Nod));
    if (!Elem)
    {
        printf("Memory allocation failed for new node!\n");
        return;
    }
    Elem->Urm = ListaPtr->Curent->Urm; // New element points to what Curent was pointing to
    Elem->Date = Nou;
    ListaPtr->Curent->Urm = Elem; // Curent now points to the new element
    ListaPtr->Lungime++;
}

int Stergere(struct Lista *ListaPtr)
{
    if (TestVida(ListaPtr))
    {
        printf("List is empty, cannot delete.\n");
        return 0;
    }
    if (ListaPtr->Curent == ListaPtr->Prim || ListaPtr->Curent == ListaPtr->Ultim)
    {
        printf("Cannot delete sentinel nodes or Curent is not on a valid data node.\n");
        return 0;
    }

    // We need the node *before* Curent to correctly remove Curent.
    // So, we'll save Curent, move back, and then perform deletion.
    struct Nod *nodeToDelete = ListaPtr->Curent;
    if (!Precedent(ListaPtr))
    { // If Precedent returns 0, it means Curent was the first data node
        // In this case, ListaPtr->Curent is now ListaPtr->Prim
    }

    ListaPtr->Curent->Urm = nodeToDelete->Urm;
    free(nodeToDelete);
    ListaPtr->Lungime--;

    // After deletion, Curent points to the node *before* the deleted one.
    // To maintain a logical position, we might want to move Curent to the node
    // that now occupies the deleted node's original successor position,
    // or just leave it where it is (pointing to the predecessor).
    // For now, let's leave it pointing to the predecessor.
    return 1;
}

// Renamed for clarity: performs a swap of the node pointed by Curent with its immediate successor.
int SwapWithNext(struct Lista *ListaPtr)
{
    if (TestVida(ListaPtr) || ListaPtr->Lungime < 2)
    {
        return 0; // Need at least two data nodes to swap
    }
    if (ListaPtr->Curent == ListaPtr->Prim || ListaPtr->Curent->Urm == ListaPtr->Ultim)
    {
        // Curent is either the dummy head or the last data node, so no next to swap with
        return 0;
    }

    struct Nod *node1_prev; // The node before Curent
    struct Nod *node1 = ListaPtr->Curent;
    struct Nod *node2 = ListaPtr->Curent->Urm;
    struct Nod *node2_next = ListaPtr->Curent->Urm->Urm;

    // Find the node before node1 (Curent)
    node1_prev = ListaPtr->Prim;
    while (node1_prev->Urm != node1 && node1_prev->Urm != NULL)
    {
        node1_prev = node1_prev->Urm;
    }
    if (node1_prev->Urm != node1)
    {
        // This should ideally not happen if Curent is valid
        return 0;
    }

    // Perform the swap by relinking pointers
    node1_prev->Urm = node2;
    node2->Urm = node1;
    node1->Urm = node2_next;

    // Update Curent to point to the swapped node that is now at the original 'Curent' position
    ListaPtr->Curent = node2;

    return 1;
}

void Ordonare(struct Lista *ListaPtr)
{
    if (ListaPtr->Lungime < 2)
    {
        return; // No need to sort if 0 or 1 element
    }

    int i, j;
    struct Nod *tempCurent;

    // Simple bubble sort adapted for a singly linked list
    for (i = 0; i < ListaPtr->Lungime - 1; i++)
    {
        ListaPtr->Curent = ListaPtr->Prim->Urm; // Start from the first data node

        for (j = 0; j < ListaPtr->Lungime - 1 - i; j++)
        {
            if (ListaPtr->Curent->Date.Ord > ListaPtr->Curent->Urm->Date.Ord)
            {
                // We need to swap Curent and Curent->Urm.
                // The SwapWithNext function is designed for this, but it expects ListaPtr->Curent
                // to be the first node of the pair to be swapped.
                // We must reposition Curent to the node *before* the first node of the pair to swap.
                // This is a common complexity in linked list bubble sort.

                // To use SwapWithNext, we'd need to go back one step.
                // A simpler direct swap of *data* is usually preferred for bubble sort on linked lists
                // if `PermDreapta` meant swapping data, not nodes.
                // Assuming `PermDreapta` was intended to swap nodes (as its implementation implies),
                // we'll modify it slightly to use it effectively.
                // Let's re-implement the node swap logic directly here for clarity,
                // or ensure `SwapWithNext` correctly operates on `ListaPtr->Curent` and `ListaPtr->Curent->Urm`.

                // Let's assume the previous `PermDreapta` (now `SwapWithNext`) was meant to swap
                // the node *pointed to by Curent* with its *successor*.
                // For a bubble sort, we iterate, and if `Curent->Date.Ord > Curent->Urm->Date.Ord`,
                // we need to swap `Curent` and `Curent->Urm`.
                // The `SwapWithNext` function as defined (which updates `ListaPtr->Curent` to `node2`)
                // would be:

                struct Nod *prev_of_current = ListaPtr->Prim;
                while (prev_of_current->Urm != ListaPtr->Curent)
                {
                    prev_of_current = prev_of_current->Urm;
                }

                struct Nod *node1 = ListaPtr->Curent;
                struct Nod *node2 = ListaPtr->Curent->Urm;
                struct Nod *node2_next = ListaPtr->Curent->Urm->Urm;

                prev_of_current->Urm = node2;
                node2->Urm = node1;
                node1->Urm = node2_next;

                // After swap, `node2` is now at `node1`'s old position. `node1` is at `node2`'s old position.
                // We need to continue checking from the "new" node that moved forward.
                // So, `ListaPtr->Curent` should stay at `node2` (the element that just moved left).
                // The inner loop's `Urmator(ListaPtr)` will then move it to the *next* element.
                ListaPtr->Curent = node2; // Curent is now the node that moved left
            }
            else
            {
                Urmator(ListaPtr); // Move to the next element if no swap occurred
            }
        }
    }
}

void Afisare(struct Lista *ListaPtr)
{
    printf("Lista contine elementele:\n");
    if (TestVida(ListaPtr))
    {
        printf("Lista este vida\n");
    }
    else
    {
        Inceput(ListaPtr); // Set Curent to the first data node
        do
        {
            printf("%d  ", ListaPtr->Curent->Date.Ord);
            printf("Nume: %s, Telefon: %s\n", ListaPtr->Curent->Date.Nume,
                   ListaPtr->Curent->Date.Tel);
        } while (Urmator(ListaPtr)); // Urmator will return 0 when at the last element
        printf("Lista are %d abonati.\n", Lungime(ListaPtr));
    }
}

void AfisareMeniu(void)
{
    printf("\n--- Meniu Lista Telefonica ---\n");
    printf("1. Creare lista \n");
    printf("2. Adaugare la lista \n");
    printf("3. Stergere din lista \n");
    printf("4. Ordonare lista \n");
    printf("5. Printare lista \n");
    printf("6. Final program \n");
    printf("------------------------------\n");
    printf("Alegeti o optiune: ");
}

void InDatePers(struct Lista *ListaPtr, Info InfoInreg)
{
    printf("Introduceti numele persoanei: ");
    scanf("%19s", InfoInreg.Nume); // Use %19s to prevent buffer overflow for Nume[20]
    printf("Introduceti telefonul persoanei: ");
    scanf("%11s", InfoInreg.Tel); // Use %11s to prevent buffer overflow for Tel[12]
    printf("Introduceti numarul de ordine: ");
    scanf("%d", &InfoInreg.Ord);
    // After reading, pass the filled InfoInreg (by value) to AdaugaSfarsit
    AdaugaSfarsit(ListaPtr, InfoInreg);
}

int main(void) // Correct main function signature
{
    ListaTel = (struct Lista *)malloc(sizeof(struct Lista));
    if (!ListaTel)
    {
        printf("Memory allocation failed for ListaTel!\n");
        return 1; // Indicate error
    }

    // Initialize the list to a safe empty state before any operations
    ListaTel->Prim = NULL;
    ListaTel->Ultim = NULL;
    ListaTel->Curent = NULL;
    ListaTel->Lungime = 0;

    // Corrected the initial state for better handling
    if (!Creare(ListaTel))
    {
        printf("Failed to create list during initialization.\n");
        free(ListaTel);
        return 1;
    }

    do
    {
        AfisareMeniu();
        // Clear input buffer before reading new choice to avoid issues with previous newlines
        while (getchar() != '\n');
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            // Creare is already called at the start. Calling it again would re-initialize
            // and potentially lose existing data without freeing it first.
            // If the intention is to empty and re-create, add logic for that.
            printf("List has already been created at program start.\n\n");
            break;
        case 2:
            InDatePers(ListaTel, InfoPers); // Pass by value, as InDatePers fills it
            break;
        case 3:
            if (TestVida(ListaTel))
            {
                printf("Lista este vida, nu se poate sterge nimic.\n");
                break;
            }
            printf("Introduceti numarul de ordine al persoanei de sters: ");
            scanf("%d", &Poz);
            if (Pozitionare(ListaTel, Poz))
            { // Pozitionare sets Curent to the found node
                Stergere(ListaTel);
                printf("Elementul a fost sters!\n");
            }
            else
            {
                printf("Elementul cu numarul de ordine %d nu exista!\n", Poz);
            }
            break;
        case 4:
            Ordonare(ListaTel);
            printf("Lista a fost ordonata!\n");
            break;
        case 5:
            Afisare(ListaTel);
            break;
        case 6:
            printf("Program terminat!\n");
            // Add cleanup for the list (freeing all nodes)
            struct Nod *current = ListaTel->Prim->Urm;
            struct Nod *next;
            while (current != ListaTel->Ultim)
            {
                next = current->Urm;
                free(current);
                current = next;
            }
            free(ListaTel->Prim);
            free(ListaTel->Ultim);
            free(ListaTel); // Free the list structure itself
            break;
        default:
            printf("Optiune gresita! Va rugam introduceti un numar intre 1 si 6.\n");
            break;
        }
    } while ((c != 6));

    return 0; // Indicate successful execution
}