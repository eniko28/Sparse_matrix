#include "matrix.h"
#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

ritka* create_node(ritka* matrix, int sori, int oszlopi, int x)
{
    ritka* a = matrix;           // fejjel ekvivalens  

    if (a == NULL) //vagyis meg ures a lista
    {
        //az elso lepes, amikor meg ures a lista
        ritka* uj_elem = new ritka;

        uj_elem->sor = sori;       // hozzaadja a sorindexet
        uj_elem->oszlop = oszlopi;    // hozzaadja az oszlopindexet
        uj_elem->ertek = x;         // hozzaadja az erteket 
        uj_elem->kov = NULL; 

        return uj_elem;
    }
    else
    { // itt a lista mar nem ures, csak hozza kell fuzni az uj_elem elemet a tobbihez
        while (a->kov != NULL)
        {
            a = a->kov; // ugrik a kovetkezo elemre a listaban
        }

        ritka* uj_elem = new ritka;

        uj_elem->sor = sori;    // hozzaadja a sorindexet
        uj_elem->oszlop = oszlopi;   // hozzaadja az oszlopindexet
        uj_elem->ertek = x;        //hozzaadja az erteket
        uj_elem->kov = NULL;
        a->kov = uj_elem;

        return matrix;           // nem valtozott a fej
    }
}

ritka* create(const char* fnev, ritka* matrix, ritka* dim)
{
    ifstream f(fnev);
    int x, i, j;
    matrix = NULL;
    dim = new ritka;
    f >> dim->n >> dim->m; // a ritka matrix szelessege es hosszusaga
    for (i = 0; i < dim->n; i++)
    {
        for (j = 0; j < dim->m; j++)
        {
            f >> x;
            if (x != 0) // ha ertekes az elem, akkor  be kell tenni a listaba
            {
                matrix = create_node(matrix, i, j, x); // hozzaadja a listahoz
            }
        }
    }
    return matrix;
}
  
void free_node(ritka* matrix)
{
    //rekurziv felszabaditas
    if(matrix->kov != NULL)
    {
        free_node(matrix->kov);  // vegigmegy az osszes elemen s visszafele felszabaditja oket
    }
    delete matrix;
}
 
ritka* del(ritka* matrix, int ertek)
{
    ritka* aux = matrix;
    ritka* seged = NULL;

    if (aux != NULL && aux->ertek == ertek)  // amikor pont az elso elemet kell torolni
    {
        matrix = aux->kov;   // kicsereljuk az elso elemet
         delete aux;
    }
    else
    {
        while (aux != NULL && aux->ertek != ertek)   // addig megy, amig megtalalja a torolni kivant elemet
        {
            seged = aux; 
            aux = aux->kov;
        }

        if (aux != NULL)
        {
            seged->kov = aux->kov;   // kivesszuk a lancolt listabol
             delete aux;
        }
    }
    return matrix;
}

ritka* put(ritka* matrix, int sind, int oind)
{
    ritka* uj_elem = new ritka;
    uj_elem->sor = sind;
    uj_elem->oszlop = oind;
    uj_elem->ertek = rand()%100;
    uj_elem->kov = matrix->kov;
    matrix->kov = uj_elem; 
    matrix = matrix->kov;   // atugorja az ujonnan betett erteket, mert azt mar nem szabad torolni

    return matrix;
}

void print(ritka* matrix)
{
    ofstream g("hajo1.out");
    ritka* ptr = matrix;
    ptr = matrix;
    while (ptr != NULL)
    {
        g << ptr->ertek << ' ';
        ptr = ptr->kov;
    }
}