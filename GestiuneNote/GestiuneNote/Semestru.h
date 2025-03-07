#pragma once
#include "IOperatiiClase.h" 
#include "Materie.h" 

class Semestru :
    public IOperatiiClase
{ 
     
        Materie* listaMateriiSemestru; //Mostenirea de tip has-a
        int numarMateriiSemestru;
        int numarSemestru; 
        int anAsociat; 
        bool initializat; /* flag care va fi folosit in vectorul Semestru s[]
                             pentru a verifica daca exista deja un obiect de tip semestru pe
                             o anumita pozitie. Acesta este modificat doar cand folosim vectorul Semestru[] */
public:
        Semestru();

        Semestru(int numarMateriiSemestru, int numarSemestru, int anAsociat, Materie* listaMateriiSemestru); 

        Semestru(Semestru& s);

        ~Semestru(); 
        
        void setAnAsociat(int anAsociat); 

        void setNumarSemestru(int numarSemestru);

        void AdaugareMaterieSemestru(Materie& m); 

        void StergeMaterieSemestru(string denumireMaterie);

        void StergereMemorie();

        int maxim();

        int minim();

        float medie();

        void restante();

        bool isInitializat(); 

        void switchInitializat(); 

        void operator=(const Semestru& s);

        //optionale
        friend ostream& operator<<(ostream& out, Semestru& s); 
        
        friend istream& operator>>(istream& in, Semestru& s);

};

