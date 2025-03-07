#pragma once
#include "An.h"
class GestiuneNote
{
    An a[3];
public:

    GestiuneNote(); 

    GestiuneNote(An a[]); //Vectorul trebuie sa fie de trei elemente

    ~GestiuneNote(); 

    void AdaugareAn(An a, int index);

    void StergereAn(int index); 

    int maxim(int an = -1, int semestru = -1);

    int minim(int an = -1, int semestru = -1);

    float medie(int an = -1, int semestru = -1);

    void restante(int an = -1, int semestru = -1);

    void StergereMemorie(int an = -1, int semestru = -1);
};

