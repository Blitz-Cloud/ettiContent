#include <stdio.h>
#include <stdlib.h>
//exemplu de exercitiu de citere a unor date dintr un fisier cu alocare dinamica
// plus scrierea unei chestii in alt fisier
// iar findca lucram in clion si executabilul se afla in cmake-build-debug acolo ne vom uita de de fisiere

// la aceasta problema prin fisierul in.txt vom primi datele
/*
* 55
* 1234
* 1234
* 1234
* 1234
* */
// pe prima linie se aflata dimensiunile adica width si height
// iar de pe a doua linie se afla matricea propriu zisa
// Pentru a imi simplifica viata nu am enter dupa dimensiuni
// acesta este un exmplu de simplu si nu foarte complex

void creareFisier(FILE *file,int width,int height){
   
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fwrite(&j, sizeof(int), 1, file);
        }
        // char end = '\n';
        // fwrite(&end, sizeof(char), 1, file);
    }
}

void printFisier(FILE *file){
    int *ptr;
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    printf("Matricea are dimensiunile %d %d\n", width, height);

    ptr = (int*)malloc(width * height * sizeof(int));
    char end;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fread(ptr+i*width+j, sizeof(int), 1, file);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%03d ", *(ptr + i * width + j));
        }
        printf("\n");
    }
    free(ptr);
}

int comparareSuperComplicat(int x,int y){
    // vom presupune prin absurd ca aici vom avea o comparare super avansata ale unur nr complexe
    if(x>y){
        return 1;
    }
    return 0;
}

// aceasta functie primeste ca argumente 2 pointeri catre 2 numere si o functie de comparare
void dacaMaiIntelegiSiAstaEstiBun(int x,int y, int (*comparare)(int, int)){
    printf("Cele 2 numere de comparat sunt %d %d\n",x,y);
    if(comparare(x, y)){
        printf("Numarul mai mare este: %d", x);
    }else{
        printf("Numarul mai mare este: %d", y);
    }
}



int main(){
    FILE *file;
    int width = 10, height = 4;
    file = fopen("./../out.txt", "w+b");
    creareFisier(file,width,height);
    rewind(file);
    printFisier(file);

    dacaMaiIntelegiSiAstaEstiBun(width, height, comparareSuperComplicat);
}