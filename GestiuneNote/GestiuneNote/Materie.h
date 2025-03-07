#pragma once
#include <iostream> 
#include <string>
#include <algorithm> 

using namespace std;
class Materie
{  

    string denMaterie;
    int notaFinalaMaterie;
public:

    Materie(); 

    Materie(string denMaterie, int notaFinalaMaterie);

    ~Materie();

    string getDenumireMaterie(); 

    int getNotaFinalaMaterie(); 

    void setDenumireMaterie(string materie);

    void setNotaFinalaMaterie(int notaFinala);
};

