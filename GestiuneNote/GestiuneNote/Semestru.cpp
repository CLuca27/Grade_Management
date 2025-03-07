//Pentru clasele componente, am utilizat relatia de tip has-a ("aggregation") 
//Pentru a simplifica gestiunea metodelor, am preferat utilizarea unei interfete, intrucat functiile se repeta
#include "Semestru.h"
Semestru::Semestru()
{
    listaMateriiSemestru = nullptr;
    numarMateriiSemestru = 0;
    numarSemestru = 1; 
    anAsociat = 1; 
    initializat = 0; //vectorul Semestru[] va folosi constructorul default; 
}
                           
Semestru::Semestru(int numarMateriiSemestru, int numarSemestru, int anAsociat, Materie* listaMateriiSemestru)
{
    this->setNumarSemestru(numarSemestru); 
    this->setAnAsociat(anAsociat);
    this->numarMateriiSemestru = numarMateriiSemestru;
    this->initializat = 0;
    if (numarMateriiSemestru == 0)
        this->listaMateriiSemestru = nullptr; 
    else
    {
        this->listaMateriiSemestru = new Materie[numarMateriiSemestru];
        for (int i = 0; i < numarMateriiSemestru; i++)
            this->listaMateriiSemestru[i] = listaMateriiSemestru[i];
    }
    
   
}
Semestru::Semestru(Semestru& s)
{
    this->setNumarSemestru(s.numarSemestru);
    this->setAnAsociat(s.anAsociat);
    this->numarMateriiSemestru = s.numarMateriiSemestru;
    this->initializat = 0;
    if (numarMateriiSemestru == 0)
        this->listaMateriiSemestru = nullptr;
    else
    {
        this->listaMateriiSemestru = new Materie[numarMateriiSemestru];
        for (int i = 0; i < numarMateriiSemestru; i++)
            this->listaMateriiSemestru[i] = s.listaMateriiSemestru[i];
    }

}
Semestru::~Semestru()
{
    delete[] listaMateriiSemestru;
}

void Semestru::AdaugareMaterieSemestru(Materie& m)
{
    if (numarMateriiSemestru == 0)
    {
        listaMateriiSemestru = new Materie[++numarMateriiSemestru];
        listaMateriiSemestru[0] = m;
    }
    else
    {
        Materie* aux;
        aux = new Materie[++numarMateriiSemestru];
        for (int i = 0; i < numarMateriiSemestru - 1; i++)
        {
            aux[i] = listaMateriiSemestru[i];
        }
        aux[numarMateriiSemestru - 1] = m;
        delete[] listaMateriiSemestru;
        listaMateriiSemestru = aux;
    } 
    cout << "Materia " << m.getDenumireMaterie() << " a fost adaugata cu nota finala: "<< m.getNotaFinalaMaterie() << endl;
}

void Semestru::StergeMaterieSemestru(string denumireMaterie)
{   
    int numarMateriiRamase = 0; 
    for (int i = 0; i < numarMateriiSemestru; i++)
    {
        if (listaMateriiSemestru[i].getDenumireMaterie() != denumireMaterie)
        {
            listaMateriiSemestru[numarMateriiRamase++] = listaMateriiSemestru[i];
        } 
        else
        {
            cout << "Materia: " << listaMateriiSemestru[i].getDenumireMaterie() << " a fost stearsa !" << endl;
        }
    }
     
    /*pentru ca pot ramane spatii de memorie neocupate, copiem ce a ramas intr - un alt vector, dezalocam memoria catre care pointeaza
    listaMateriiSemestru si actualizam pointer-ul*/

    if (numarMateriiRamase == 0)
    {
        delete[] listaMateriiSemestru; 
        listaMateriiSemestru = nullptr;
        numarMateriiSemestru = 0;
    } 
    else
    {   
        numarMateriiSemestru = numarMateriiRamase;
        Materie* aux = new Materie[numarMateriiSemestru];
        for (int i = 0; i < numarMateriiSemestru; i++)
        {
            aux[i] = listaMateriiSemestru[i];
        }
        delete[] listaMateriiSemestru;
        listaMateriiSemestru = aux;
    }
}

void Semestru::StergereMemorie()
{   
    char raspuns;
    cout << "Atentie! Aceasta operatie va sterge toate materiile din semestrul " << to_string(this->numarSemestru) << " al anului " << to_string(this->anAsociat); 
    cout << " Continuati ? (D / N)" << endl;
    cin >> raspuns; 
    if (raspuns == 'D')
    {
        delete[] listaMateriiSemestru;
        numarMateriiSemestru = 0;
        listaMateriiSemestru = nullptr;
        cout << "Toate materiile au fost sterse !" << endl;
    }
    else
    {
        return;
    }
}

int Semestru::maxim()
{   
    int maxi = 0; 

    if (numarMateriiSemestru > 0)
    {
        int copie;

        for (int i = 0; i < numarMateriiSemestru; i++)
        {
            copie = listaMateriiSemestru[i].getNotaFinalaMaterie();
            if (copie > maxi)
                maxi = copie;
        }
    } 
    return maxi;

} 

int Semestru::minim()
{
    int mini = 0;

    if (numarMateriiSemestru > 0)
    {   
        mini = listaMateriiSemestru[0].getNotaFinalaMaterie();
        int copie;

        for (int i = 1; i < numarMateriiSemestru; i++)
        {
            copie = listaMateriiSemestru[i].getNotaFinalaMaterie();
            if (copie < mini)
                mini = copie;
        }
    }
    return mini;

}
float Semestru::medie()
{
    float m = 0;

    if (numarMateriiSemestru > 0)
    {
        for (int i = 0; i < numarMateriiSemestru; i++)
        {
            m += listaMateriiSemestru[i].getNotaFinalaMaterie();
        } 
        return m / numarMateriiSemestru;
    } 
    else
    {
        return m;
    }

} 

void Semestru::restante()
{   
    int contor = 0;

    for (int i = 0; i < numarMateriiSemestru; i++)
    {
        if (listaMateriiSemestru[i].getNotaFinalaMaterie() < 5)
        {
            cout << "Studentul are restanta la materia : " << listaMateriiSemestru[i].getDenumireMaterie();
            cout << " din semestrul " << numarSemestru << " al anului " << anAsociat;
            cout << " unde are nota: " << listaMateriiSemestru[i].getNotaFinalaMaterie();
            cout << endl;
            contor++;
        }
    } 
    if (contor == 0)
        cout << "Studentul nu are restante in semestrul " << numarSemestru << " al anului " << anAsociat << endl;


}

void Semestru::setAnAsociat(int anAsociat)
{
    if (1 <= anAsociat && anAsociat <= 3)
        this->anAsociat = anAsociat;
    else
        throw "Anul introdus trebuie sa fie intre 1 si 3";
} 

void Semestru::setNumarSemestru(int numarSemestru)
{
    if (1 <= numarSemestru && numarSemestru <= 2)
        this->numarSemestru = numarSemestru;
    else
        throw "Numarul semestrului trebuie sa fie intre 1 si 2";
} 

bool Semestru::isInitializat()
{
    return initializat;
}
void Semestru::switchInitializat()
{
    this->initializat = !(this->initializat);
} 
void Semestru::operator=(const Semestru& s)
{
    this->setNumarSemestru(s.numarSemestru);
    this->setAnAsociat(s.anAsociat);
    this->numarMateriiSemestru = s.numarMateriiSemestru;
    this->initializat = 0; 
    delete[] this->listaMateriiSemestru;
    if (numarMateriiSemestru == 0)
        this->listaMateriiSemestru = nullptr;
    else
    {
        this->listaMateriiSemestru = new Materie[numarMateriiSemestru];
        for (int i = 0; i < numarMateriiSemestru; i++)
            this->listaMateriiSemestru[i] = s.listaMateriiSemestru[i];
    }
}

ostream& operator<<(ostream& out, Semestru& s)
{
    cout << "Ati ales semestrul " << s.numarSemestru << " din anul " << s.anAsociat << endl; 
    cout << "Materiile acestui semestru si notele finale sunt: " << endl;
    for (int i = 0; i < s.numarMateriiSemestru; i++)
        cout << s.listaMateriiSemestru[i].getDenumireMaterie() << " " << s.listaMateriiSemestru[i].getNotaFinalaMaterie() << endl; 
    return out;
} 

istream& operator >>(istream& in, Semestru& s)
{    
    int nr; 
    string nume;
    int nota;
    cout << "Introduceti numarul semestrului: " << endl; 
    in >> nr; 
    s.setNumarSemestru(nr);
    cout << "Introduceti numarul de materii: " << endl; 
    in >> s.numarMateriiSemestru;
    delete[] s.listaMateriiSemestru; 
    s.listaMateriiSemestru = new Materie[s.numarMateriiSemestru]; 
    for (int i = 0; i < s.numarMateriiSemestru; i++)
    {   
        in.ignore(numeric_limits<streamsize>::max(), '\n'); //ignora bufferul. Astfel, pot citi denumiri cu spatii 
                                                            //numeric_limits<streamsize>::max() <- dimensiunea maxima a bufferului
        cout << "Introduceti numele materiei: " << endl; 
        getline(in, nume);
        s.listaMateriiSemestru[i].setDenumireMaterie(nume); 
        cout << "Introduceti nota finala obtinuta de student la aceasta materie: " << endl; 
        in >> nota; 
        s.listaMateriiSemestru[i].setNotaFinalaMaterie(nota);
         
    } 
    return in;
}





