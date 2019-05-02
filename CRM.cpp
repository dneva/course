// CRM.cpp: определяет точку входа для консольного приложения.
//
#include "CRM.h"

int main()
{
	Storage s;
	string buf,d;
	Individual* i;
	Entity* e;
	int id;
	string sn,n,mn,adrs,ph,in,act,mngr;	
	ifstream fin("Storage.txt");
	while (fin >> buf)
	{
		if (buf == "Individual:")
		{
			
			fin >> id >> sn >> n >> mn >> adrs >> ph >> in >> act;
			getline(fin, mngr);
			i=new Individual(mngr, id, sn, n, mn, adrs, ph, in, act);
			s.Add(i);
		}
		else
		{
			fin >> id >> n >> adrs >> ph >> in >> act;
			getline(fin, mngr);
			e = new Entity(mngr, id, n, adrs, ph, in, act);
			s.Add(e);
		}
		
	}
	fin.close();
	while (d!="exit")
	{
		getline(cin,d);
		if (d=="add individ")
		{
			cout << "Input id, surname, name, midname, address, phone, inn, activity, manager" << endl;
			cin >> id >> sn >> n >> mn >> adrs >> ph >> in >> act;
			getline(cin,mngr);
			i = new Individual(mngr,id,sn,n,mn,adrs,ph,in,act);
			s.Add(i);
		}
		if (d == "add entity")
		{
			cout << "Input id, organization, address, phone, inn, activity, manager" << endl;
			cin >> id >> n >> adrs >> ph >> in >> act >> mngr;
			getline(cin, mngr);
			e = new Entity(mngr, id, n, adrs, ph, in, act);
			s.Add(e);
		}
		if (d == "print")
		{
			s.Print();
		}
		if (d == "sort")
		{
			cout << "Input field" << endl;
			cin >> n;
			s.Sort(n);
		}

	}
	system("pause");
    return 0;
}

