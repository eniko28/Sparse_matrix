#ifndef matrix_h
#define matrix_h

struct ritka
{
    int n, m;
    int sor;                 //ertekes elem sorindexe
    int oszlop;              //ertekes elem oszlopindexe
    int ertek;               //az ertekes elem
    ritka* kov;              //megmutatja azt a cimet, ahova kovetkezonek kell ugrani
};

 ritka* create(const char*, ritka*, ritka*);

 ritka* del(ritka* matrix, int ertek);

 ritka* put(ritka* matrix, int sind, int oind);

 void print(ritka*);

 void free_node(ritka*);

#endif