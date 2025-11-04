#include <stdio.h>
#include <stdlib.h>

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

int Creare(struct Lista *ListaPtr);
int TestVida(struct Lista *ListaPtr);
int Primul(struct Lista *ListaPtr);
int Ultimul(struct Lista *ListaPtr);
int Lungime(struct Lista *ListaPtr);
int Inceput(struct Lista *ListaPtr);
int Sfarsit(struct Lista *ListaPtr);
int Precedent(struct Lista *ListaPtr);
int Pozitionare(struct Lista *ListaPtr, int Pozitie);
void AdaugaSfarsit(struct Lista *ListaPtr, Info Nou);
void AdaugaDreapta(struct Lista *ListaPtr, Info Nou);
int Stergere(struct Lista *ListaPtr);
int PermDreapta(struct Lista *ListaPtr);
void Ordonare(struct Lista *ListaPtr);
void Afisare(struct Lista *ListaPtr);
void AfisareTel(struct Lista *ListaPtr, int ord);
void AfisareMeniu();
void InDatePers(struct Lista *ListaPtr, Info InfoInreg);
char getTel(struct Lista *ListaPtr);

void adaugaLaInceput(struct Lista *ListaPtr, Info InfoI)
{
    Inceput(ListaPtr);
    AdaugaDreapta(ListaPtr, InfoI);
    // PermDreapta(ListaPtr);
}

int c;
struct Lista *ListaTel;
Info InfoPers;
int Poz;

char* getTel(struct Lista *ListaPtr)
{
    char *out = ListaPtr->Curent->Date.Tel;
    return out;
}

void AfisareTel(struct Lista *ListaPtr, int ord)
{
}

int Creare(struct Lista *ListaPtr)
{
    ListaPtr->Prim = (struct Nod *)malloc(sizeof(struct Nod));
    if (!ListaPtr->Prim)
        return 0;
    ListaPtr->Ultim = (struct Nod *)malloc(sizeof(struct Nod));
    if (!ListaPtr->Ultim)
        return 0;
    ListaPtr->Prim->Urm = ListaPtr->Ultim;
    ListaPtr->Ultim->Urm = NULL;
    ListaPtr->Lungime = 0;
    ListaPtr->Curent = ListaPtr->Prim;
    return 1;
}

int TestVida(struct Lista *ListaPtr) // este lista goala ?
{
    return ListaPtr->Lungime == 0;
}

int Primul(struct Lista *ListaPtr) // este nodul curent primul din lista ?
{
    return (ListaPtr->Prim->Urm == ListaPtr->Curent) && (!TestVida(ListaPtr));
}

int Ultimul(struct Lista *ListaPtr) // este nodul curent ultimul din lista ?
{
    return (ListaPtr->Curent->Urm == ListaPtr->Ultim) && (!TestVida(ListaPtr));
}

int Lungime(struct Lista *ListaPtr)
{
    return ListaPtr->Lungime;
}

int Inceput(struct Lista *ListaPtr) // seteaza prompterul pe primul element din lista
{
    if (TestVida(ListaPtr))
        return 0;
    else
    {
        ListaPtr->Curent = ListaPtr->Prim->Urm;
        return 1;
    }
}

int Sfarsit(struct Lista *ListaPtr) // seteaza prompterul pe ultimul element din lista
{
    if (TestVida(ListaPtr))
        return 0;
    else
    {
        ListaPtr->Curent = ListaPtr->Ultim;
        if (Precedent(ListaPtr))
            return 1; // de ce ?
        else
            return 0;
    }
}

int Urmator(struct Lista *ListaPtr)
{
    if (TestVida(ListaPtr))
        return 0;
    else
    {
        if (ListaPtr->Curent->Urm != ListaPtr->Ultim) // de ce ?
        {
            ListaPtr->Curent = ListaPtr->Curent->Urm;
            return 1;
        }
        else
            return 0;
    }
}

int Precedent(struct Lista *ListaPtr) // de rescris
{
    struct Nod *Temp;

    if (ListaPtr->Lungime == 0)
        return 0;
    if (ListaPtr->Lungime == 1)
    {
        ListaPtr->Curent = ListaPtr->Prim->Urm;
        return 0;
    }
    Temp = ListaPtr->Curent;
    ListaPtr->Curent = ListaPtr->Prim;
    if (Temp == ListaPtr->Prim)
        return 0; // in ce situatie este true ?
    else
    {
        while (ListaPtr->Curent->Urm != Temp && Urmator(ListaPtr))
            ;
        return 1;
    }
}

int Pozitionare(struct Lista *ListaPtr, int Pozitie)
{
    int l;
    l = Lungime(ListaTel);

    if (Inceput(ListaPtr))
    {
        do
        {
            if (ListaPtr->Curent->Date.Ord == Pozitie)
                return (1);
            Urmator(ListaPtr);
            l--;
        } while (l > 0);
        return 0;
    }
    else
        return 0;
}

void AdaugaSfarsit(struct Lista *ListaPtr, Info Nou)
{
    struct Nod *Elem;

    Sfarsit(ListaPtr);
    Elem = (struct Nod *)malloc(sizeof(struct Nod));
    Elem->Urm = ListaPtr->Ultim;
    Elem->Date = Nou;
    ListaPtr->Curent->Urm = Elem;
    ListaPtr->Curent = Elem;
    ListaPtr->Lungime++;
}

void AdaugaDreapta(struct Lista *ListaPtr, Info Nou)
{
    struct Nod *Elem;

    Elem = (struct Nod *)malloc(sizeof(struct Nod));
    Elem->Urm = ListaPtr->Curent->Urm;
    Elem->Date = Nou;
    ListaPtr->Curent->Urm = Elem;
    ListaPtr->Lungime++;
}

int Stergere(struct Lista *ListaPtr)
{
    struct Nod *Elem;

    if (Lungime(ListaPtr))
    {
        Precedent(ListaPtr);
        Elem = ListaPtr->Curent->Urm;
        ListaPtr->Curent->Urm = Elem->Urm;
        free(Elem);
        ListaPtr->Lungime--;
        return 1;
    }
    else
        return 0;
}

int PermDreapta(struct Lista *ListaPtr)
{
    if (ListaPtr->Lungime > 1)
    {
        struct Nod *Temp1 = ListaPtr->Curent, *Temp2 = ListaPtr->Curent->Urm;
        ListaPtr->Curent->Urm = ListaPtr->Curent->Urm->Urm;
        if (Precedent(ListaPtr))
        {
        }
        ListaPtr->Curent->Urm = Temp2;
        Temp2->Urm = Temp1;
        ListaPtr->Curent = Temp1;
        return 1;
    }
    else
        return 0;
}

void Ordonare(struct Lista *ListaPtr)
{
    int i, j;

    if (Inceput(ListaPtr))
        for (i = 1; i < Lungime(ListaPtr); i++)
        {
            if (Inceput(ListaPtr))
                for (j = i; j < Lungime(ListaPtr); j++)
                {
                    if (ListaPtr->Curent->Date.Ord > ListaPtr->Curent->Urm->Date.Ord)
                        PermDreapta(ListaPtr);
                    else
                        Urmator(ListaPtr);
                }
        }
}

void Afisare(struct Lista *ListaPtr)
{
    printf("Lista contine elementele:\n");
    if (Inceput(ListaPtr))
    {
        do
        {
            printf("%d  ", ListaPtr->Curent->Date.Ord);
            printf("Nume: %s, Telefon: %s\n", ListaPtr->Curent->Date.Nume,
                   ListaPtr->Curent->Date.Tel);
        } while (Urmator(ListaPtr));
        printf("Lista are %d abonati.\n", Lungime(ListaPtr));
    }
    else
        printf("Lista este vida\n");
}

void AfisareMeniu(void)
{
    printf("1.Creare lista \n");
    printf("2.Adaugare la lista \n");
    printf("3.Stergere din lista \n");
    printf("4.Ordonare lista \n");
    printf("5.Printare lista \n");
    printf("6.Final program \n");
    printf("7.Afisare numar de telefon in functie de numarul de ordine\n");
    printf("8.Adauga la inceput\n");
}

void InDatePers(struct Lista *ListaPtr, Info InfoInreg)
{
    printf("Introduceti numele persoanei\n");
    scanf("%s", InfoInreg.Nume);
    printf("Introduceti telefonul persoanei\n");
    scanf("%s", InfoInreg.Tel);
    printf("Introduceti numarul de ordine\n");
    scanf("%d", &InfoInreg.Ord);
    AdaugaSfarsit(ListaPtr, InfoInreg);
}

int main(void)
{
    ListaTel = (struct Lista *)malloc(sizeof(struct Lista));
    do
    {
        AfisareMeniu();
        scanf("%d", &c);
        if (c < 1 || c > 8)
        {
            printf("Introduceti un numar! \n");
            break;
        }
        switch (c)
        {
        case 1:
            Creare(ListaTel);
            printf("Lista a fost creata!\n\n");
            break;
        case 2:
            InDatePers(ListaTel, InfoPers);
            break;
        case 3:
            printf("Numarul de ordine : ");
            scanf("%d", &Poz);
            if (Pozitionare(ListaTel, Poz))
            {
                Stergere(ListaTel);
            }
            else
            {
                printf("Elementul nu exista!\n");
                break;
            }
            printf("Elementul a fost sters!\n");
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
            break;
        case 7:
            printf("Sa se introduca numarul de ordine:\n");
            int ord;
            scanf("%d", &ord);
            Pozitionare(ListaTel, ord);
            printf("Numarul de telefon de pe pozitia %d este %s\n", ord, getTel(ListaTel));
            break;
        case 8:
            printf("Adauga la inceput utilizator\n");
            Info InfoI;
            printf("Introduceti numele persoanei\n");
            scanf("%s", InfoI.Nume);
            printf("Introduceti telefonul persoanei\n");
            scanf("%s", InfoI.Tel);
            printf("Introduceti numarul de ordine\n");
            scanf("%d", &InfoI.Ord);
            adaugaLaInceput(ListaTel, InfoI);
            break;
        default:
            printf("Optiune gresita!\n");
            break;
        }
    } while ((c != 6));
}
