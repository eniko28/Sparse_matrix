#include<iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

void ship(ritka* matrix, ritka* dim)
{
    ritka* a = matrix;
    int x, y, szomszed = 0, ert, sind, oind;
    ritka* ertekk = new ritka;
    while (a != NULL)
    {
        szomszed = 0;
        x = a->sor; // a jelenlegi elem sorszama, amelyiknek nezni fogjuk a szomszedjait
        y = a->oszlop; // a jelenlegi elem oszlopszama, amelyiknek nezni fogjuk a szomszedjait
        ritka* aux = a->kov; // a jelenlegi elemet koveto elem
        while (aux != NULL && szomszed <= 3) // haromnal tobb tamado szomszedja nem lehet
        {
            if (x == aux->sor && y + 1 == aux->oszlop) // jobb oldali szomszed
            {
                szomszed++;
            }
            if (x + 1 == aux->sor && y == aux->oszlop) // alatta levo szomszed
            {
                szomszed++;
            }
            if (x + 1 == aux->sor && y + 1 == aux->oszlop) // tole jobbra, atlos szomszed 
            {
                szomszed++;
            }
            aux = aux->kov; //a jelenlegi elemtol kezdodoen vegig megy az osszes elemen
        }
        sind = a->sor;
        oind = a->oszlop + 1;
        ert = a->ertek;
        ertekk = a->kov;
        a = a->kov;  // ugrik a kovetkezo elemre
        if (szomszed >= 2)
        {
            matrix = del(matrix, ert); // ez a hajo elsullyedt, ki kell venni a listabol
        }
        if (szomszed == 0 && oind != dim->m)
        {
            matrix = put(matrix->kov, sind, oind);
        }
    }
}

int main()
{
    srand(time(NULL));

    ritka* matrix = NULL;

    int sind = 0, oind = 0;

    ritka* dim = new ritka;

    matrix = create("hajo1.in", matrix, dim);
 
    ship(matrix, dim);

    print(matrix);

    free_node(matrix);

    return 0;
}