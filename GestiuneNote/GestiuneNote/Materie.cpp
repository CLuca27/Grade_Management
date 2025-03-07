#include "Materie.h"

using namespace std;

    Materie::Materie()
    {
        notaFinalaMaterie = 0;
    }
    Materie::Materie(string denMaterie, int notaFinalaMaterie)
    {
        this->denMaterie = denMaterie;
        this->notaFinalaMaterie = notaFinalaMaterie;

        //cout << "Materia " << denMaterie << " a fost adaugata";
    }
    Materie::~Materie()
    {
        //cout << "Materia " << denMaterie << " a fost stearsa";
    }
    string Materie::getDenumireMaterie()
    {
        return denMaterie;
    } 
    int Materie::getNotaFinalaMaterie()
    {
        return notaFinalaMaterie;
    } 

    void Materie::setDenumireMaterie(string materie)
    {
        this->denMaterie = materie; 
    } 

    void Materie::setNotaFinalaMaterie(int notaMaterie)
    {   
        if (notaMaterie >= 1 && notaMaterie <= 10)
            this->notaFinalaMaterie = notaMaterie;
        else
            throw "Nota introdusa este invalida !";

    }
