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
	string sn, n, mn, adrs1, adrs2, adrs3, ph, in, act;
	Manager  mngr;
	ifstream fin("Storage.txt");
	string menu = "Available commands: add individ, add entity, save, sort, delete, print, find, exit";
	system("mode con cols=200 lines=50");
	s.Load(fin);
	fin.close();
	while (d!="exit")
	{
		cout << menu << endl;

		getline(cin,d);
		if (d=="add individ")
		{
			cout << "Input ID" <<endl;
			cin >> id;
			cout << "Input surname, name, midname" << endl;
			cin >> sn >> n >> mn;
			cin.ignore();
			cout << "Input country" << endl;
			getline(cin, adrs1);
			cout << "Input city" << endl;
			getline(cin, adrs2);
			cout << "Input street" << endl;
			getline(cin, adrs3);
			cout << "Input phone" << endl;
			cin >> ph;
			cout << "Input INN" << endl;
			cin >> in;
			cin.ignore();
			cout << "Input activity" << endl;
			getline(cin,act);
			cout << "Input manager(surname,name,midname,postion)" << endl;
			cin >> mngr;
			i = new Individual(mngr, id, sn, n, mn, adrs1, adrs2, adrs3, ph, in, act);
			s.Add(i);
			cout << "Individual was added";
		}
		else if (d == "add entity")
		{
			cout << "Input ID" << endl;
			cin >> id;
			cin.ignore();
			cout << "Input name" << endl;
			getline(cin,n);
			cout << "Input country" << endl;
			getline(cin, adrs1);
			cout << "Input city" << endl;
			getline(cin, adrs2);
			cout << "Input street" << endl;
			getline(cin, adrs3);
			cout << "Input phone" << endl;
			cin >> ph;
			cout << "Input INN" << endl;
			cin >> in;
			cin.ignore();
			cout << "Input activity" << endl;
			getline(cin, act);
			cout << "Input manager(surname,name,midname,postion)" << endl;
			cin >> mngr;
			e = new Entity(mngr, id, n, adrs1, adrs2, adrs3, ph, in, act);
			s.Add(e);
			cout << "Entity was added";
		}
		else if (d == "print")
		{
			s.Print();
		}
		else if (d == "sort")
		{
			cout << "Input field" << endl;
			cin >> n;
			s.Sort(n);
			cout << "Storage was sorted" << endl;;
		}
		else if (d == "save")
		{
			ofstream fout("Storage.txt");
			s.Save(fout);
			fout.close();
			cout << "Storage was saved" << endl;;
		}
		else if (d == "delete")
		{
			cout << "Input ID" << endl;
			cin >> id;
			s.Delete(id);
			cout << "Element was deleted" << endl;
		}
		else if (d == "find")
		{
			cout << "Input field" << endl;
			cin >> n;
			cout << "Input substring" << endl;
			cin >> sn;
			s.Find(sn,n);
			cin.ignore();
		}
		
	}
	system("pause");
    return 0;
}

