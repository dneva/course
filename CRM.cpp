// CRM.cpp: определяет точку входа для консольного приложения.
//
#include "CRM.h"
int main()
{
	Storage s;
	Individual* in=new Individual;
	Entity* e=new Entity;
	s.Add(in);
	s.Add(e);
	s.Print();
	cout << endl;
	system("pause");
    return 0;
}

