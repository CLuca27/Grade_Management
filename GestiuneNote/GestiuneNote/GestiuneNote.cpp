#include "GestiuneNote.h"
GestiuneNote::GestiuneNote() {}

GestiuneNote::GestiuneNote(An a[])  //Vectorul trebuie sa fie de trei elemente
{
	
	for (int i = 0; i < 3; i++)
	{
		this->a[i] = a[i]; 
		this->a[i].switchInitializat();
	}

} 

GestiuneNote::~GestiuneNote() {} 

void GestiuneNote::AdaugareAn(An a, int index)
{  
	string eroare; 

	if (index >= 1 && index <= 3)
	{
		if (this->a[index - 1].isInitializat())
		{
			eroare = "Anul " + to_string(index) + " a fost deja adaugat ! " + '\n' +
				"Stergeti anul " + to_string(index) + " pentru a adauga altul ! " + '\n'; 
			throw eroare;
		} 
		else
		{
			this->a[index - 1] = a; 
			this->a[index - 1].switchInitializat(); 

			cout << "Anul " << to_string(index) << " a fost adaugat !" << endl;
		}
	} 
	else
	{
		throw "Numarul introdus este invalid";
	}
} 
void GestiuneNote::StergereAn(int index)
{
	string eroare;

	if (index >= 1 && index <= 3)
	{
		if (this->a[index - 1].isInitializat())
		{
			this->a[index - 1].switchInitializat(); 
			
			cout << "Anul " << to_string(index) << " a fost sters !" << endl;
		}
		else
		{
			throw eroare = "Anul " + to_string(index) + " nu exista ! " + '\n';
		}
	} 
	else
	{
		throw "Numarul introdus este invalid";
	}
}
int GestiuneNote::minim(int an, int semestru)
{
	if (an == -1 && semestru == -1)
	{
		return min(min(a[0].minim(), a[1].minim()), a[2].minim());
	} 
	else if (semestru == -1)
	{
		if (an < 1 || an > 3)
		{
			throw "Anii sunt numerotati de la 1 la 3 !";
		} 
		else
		{
			return a[an - 1].minim();
		}
	} 
	else
	{
		if ((an < 1 || an > 3) || (semestru < 1 || semestru > 2))
		{
			throw "Anul sau semestrul introdus este incorect !";
		} 
		else
		{
			return a[an - 1][semestru].minim();
		}
	}

}
int GestiuneNote::maxim(int an, int semestru)
{
	if (an == -1 && semestru == -1)
	{
		return max(max(a[0].maxim(), a[1].maxim()) , a[2].maxim());
	}
	else if (semestru == -1)
	{
		if (an < 1 || an > 3)
		{
			throw "Anii sunt numerotati de la 1 la 3 !";
		}
		else
		{
			return a[an - 1].maxim();
		}
	}
	else
	{
		if ((an < 1 || an > 3) || (semestru < 1 || semestru > 2))
		{
			throw "Anul sau semestrul introdus este incorect !";
		}
		else
		{
			return a[an - 1][semestru].maxim();
		}
	}

}
float GestiuneNote::medie(int an, int semestru)
{
	if (an == -1 && semestru == -1)
	{
		return (a[0].medie() + a[1].medie() + a[2].medie()) / 3;
	}
	else if (semestru == -1)
	{
		if (an < 1 || an > 3)
		{
			throw "Anii sunt numerotati de la 1 la 3 !";
		}
		else
		{
			return a[an - 1].medie();
		}
	}
	else
	{
		if ((an < 1 || an > 3) || (semestru < 1 || semestru > 2))
		{
			throw "Anul sau semestrul introdus este incorect !";
		}
		else
		{
			return a[an - 1][semestru].medie();
		}
	}

}
void GestiuneNote::restante(int an, int semestru)
{
	if (an == -1 && semestru == -1)
	{
		a[0].restante(); 
		a[1].restante(); 
		a[2].restante();
	}
	else if (semestru == -1)
	{
		if (an < 1 || an > 3)
		{
			throw "Anii sunt numerotati de la 1 la 3 !";
		}
		else
		{
			a[an - 1].restante();
		}
	}
	else
	{
		if ((an < 1 || an > 3) || (semestru < 1 || semestru > 2))
		{
			throw "Anul sau semestrul introdus este incorect !";
		}
		else
		{
			a[an - 1][semestru].restante();
		}
	}

} 

void GestiuneNote::StergereMemorie(int an, int semestru)
{ 
	char raspuns;
	if (an == -1 && semestru == -1)
	{
		cout << "Atentie ! Toti anii vor fi stersi ! Continuati ? (D/N)" << endl; 
		cin >> raspuns; 
		if (raspuns == 'D')
		{
			if (a[0].isInitializat())
			{
				a[0].switchInitializat();
			}
			if (a[1].isInitializat())
			{
				a[1].switchInitializat();
			}
			if (a[2].isInitializat())
			{
				a[2].switchInitializat();
			} 

			cout << "Toti anii au fost stersi !" << endl;
		} 
		else
		{
			return;
		}
	}
	else if (semestru == -1)
	{
		if (an < 1 || an > 3)
		{
			throw "Anii sunt numerotati de la 1 la 3 !";
		}
		else
		{
			a[an - 1].StergereMemorie(); 


		}
	}
	else
	{
		if ((an < 1 || an > 3) || (semestru < 1 || semestru > 2))
		{
			throw "Anul sau semestrul introdus este incorect !";
		}
		else
		{
			a[an - 1][semestru].StergereMemorie();
		}
	}

}
