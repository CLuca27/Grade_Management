#include "An.h"

An::An()
{
	numarAn = 1;
	initializat = 0;
} 
An::An(int numarAn, Semestru s[]) //Vectorul trebuie sa fie de doua elemente
{   
	this->numarAn = numarAn;
	initializat = 0;
	for (int i = 0; i < 2; i++)
	{
		this->s[i] = s[i]; 
		this->s[i].setAnAsociat(numarAn); 
		this->s[i].setNumarSemestru(i + 1);
		this->s[i].switchInitializat();
	}
} 
An::An(An& a)
{
	
	numarAn = a.numarAn;
	initializat = a.initializat;
	for (int i = 0; i < 2; i++) {
		s[i] = a.s[i];
	}
	
}
An::~An() {} 

void An::AdaugareSemestru(Semestru s, int index)
{  
	string eroare;
	if (index >= 1 && index <= 2)
	{
		if (this->s[index - 1].isInitializat())
		{
			eroare = "Semestrul " + to_string(index) + " a fost deja adaugat ! " + '\n' +
				"Stergeti semestrul " + to_string(index) + " pentru a adauga altul ! " + '\n';
			throw eroare;
		}
		else
		{   
			this->s[index - 1] = s;
			this->s[index - 1].setAnAsociat(numarAn);
			this->s[index - 1].setNumarSemestru(index);
			this->s[index - 1].switchInitializat(); 
			
			cout << "Semestrul " << to_string(index) << " a fost adaugat !" << endl;
		}
	} 
	else
	{
		throw "Numarul introdus este invalid !";
	}
} 
void An::StergereSemestru(int index)
{   
	string eroare;

	if (index >= 1 && index <= 2)
	{
		if (this->s[index - 1].isInitializat())
		{
			s[index - 1].switchInitializat(); 

			cout << "Semestrul " << to_string(index) << " al anului " << to_string(numarAn) << " a fost sters !" << endl;
		}
		else
		{
			throw eroare = "Semsestrul " + to_string(index) + " nu exista ! " + '\n';
		}
	} 
	else
	{
		throw "Numarul introdus este invalid !";
	}
}

int An::minim()
{
	return min(s[0].minim(), s[1].minim());
} 

int An::maxim()
{
	return max(s[0].maxim(), s[1].maxim());
} 
float An::medie()
{
	return (s[0].medie() + s[1].medie()) / 2;
} 

void An::restante()
{
	s[0].restante(); 
	s[1].restante();
} 

void An::StergereMemorie()
{   
	char raspuns;
	cout << "Anul " << to_string(this->numarAn) << endl;
	cout << "Atentie ! " << "Ambele semestre vor fi sterse inclusiv toate materiile si notele salvate !" << endl;
	cout << "Continuati ? (D/N)" << endl;

	cin >> raspuns; 

	if (raspuns == 'D')
	{
		if (s[0].isInitializat())
		{
			s[0].switchInitializat();
		}
		if (s[1].isInitializat())
		{
			s[1].switchInitializat();
		}
		cout << "Anul " << to_string(this->numarAn) << " a fost sters !";
	}
	else
	{
		return;
	}
} 

bool An::isInitializat()
{
	return initializat;
} 

void An::switchInitializat()
{   
	
    this->initializat = !(this->initializat);
}

void An::operator = (const An& a)
{
	numarAn = a.numarAn;
	initializat = a.initializat;
	for (int i = 0; i < 2; i++) {
		s[i] = a.s[i];
	}
}
Semestru& An::operator[](int index)
{
	if (index < 1 || index > 2)
	{
		throw "Semestrele sunt numerotate de la 1 la 2 pentru fiecare an ! Introduceti un numar din multimea {1, 2}.";
	} 
	else
	{
		return s[index - 1];
	}

}

