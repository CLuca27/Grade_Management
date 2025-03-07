#pragma once 


class IOperatiiClase
{     
	/*Interfata este folosita de clasele Semestru si Materie
	  Initial am vrut sa fie folosita si de clasa GestiuneMaterie, 
	  dar parametrii default nu se mostenesc */
	
public:
	virtual int minim() = 0; 

    virtual int maxim() = 0; 

	virtual float medie() = 0; 

	virtual void restante() = 0;  

	virtual void StergereMemorie() = 0;

};

