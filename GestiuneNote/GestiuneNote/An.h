#pragma once
#include "IOperatiiClase.h" 
#include "Semestru.h" 


class An :
    public IOperatiiClase
{ 
 
    Semestru s[2];
    int numarAn; 
    bool initializat; /* flag utilizat de vectorul An a[] pentru a verifica daca pe o anumita pozitie 
                         exista deja un an introdus */
public: 
     
    An();

    An(int numarAn, Semestru s[]); //Vectorul trebuie sa fie de doua elemente 

    An(An& a);

    ~An(); 

    void AdaugareSemestru(Semestru s, int index); 

    void StergereSemestru(int index); 

    int minim();

    int maxim();

    float medie();

    void restante();

    void StergereMemorie();

    bool isInitializat(); 

    void switchInitializat(); 

    void operator=(const An& a);

    Semestru& operator[](int index);
};

