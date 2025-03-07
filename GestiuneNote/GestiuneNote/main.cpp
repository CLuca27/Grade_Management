#include "GestiuneNote.h" 
using namespace std; 

int main()
{  

	try {  
		
		Semestru s1[2], s2[2], s3[2]; 
		
		Semestru s;
		Materie m1("Matematica", 10); 
		Materie m2("TIC", 2);
		Materie m3("BPC", 4);
		s.AdaugareMaterieSemestru(m1); 
		s.AdaugareMaterieSemestru(m2); 
		s.AdaugareMaterieSemestru(m3); 
		//semestrele pot fi cititite: cin >> s1[1], cin >> s2[0]...
		cout << s; 
		s.StergeMaterieSemestru("Matematica");
		s1[0] = s; 
		//cin >> s1[1];
		An a1(1, s1);
	    An a2(2, s2);
		An a3(3, s3); 
		An a[] = { a1, a2, a3 };
		GestiuneNote g1(a); 
		An a4; 
		a1.StergereSemestru(1); 
		a1.AdaugareSemestru(s1[0], 1);
		g1.StergereAn(3); 
		g1.AdaugareAn(a4, 3); 
		//g1.AdaugareAn(a4, 3); <- o sa se afiseze ca nu poate fi introdus anul 3 pentru ca exista deja
		cout << g1.maxim(2, 1) << endl; 
		cout << g1.maxim(1) << endl; 
		cout << g1.maxim() << endl;
		cout << g1.medie(1, 2) << endl;
		cout << g1.medie(2) << endl;
		cout << g1.medie() << endl;
		cout << g1.minim(1, 1) << endl;
		cout << g1.minim(1) << endl;
		cout << g1.minim() << endl;

		cout << "PE ANI \n";
		g1.restante();

		cout << "PE AN \n";
		g1.restante(1);

		cout << "Pe semestru \n";
		g1.restante(2, 2); 

		g1.StergereMemorie(); 

		g1.AdaugareAn(a4, 3);
		
		
    }
	catch (const char* e)
	{
		cout << e;
	} 
	catch (string s)
	{
		cout << s;
	} 
	catch (...)
	{
		cout << "EROARE!";
	}
	return 0;
}