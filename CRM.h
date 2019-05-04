#pragma once
#include<string>
#include<vector>
#include<typeinfo>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace std;
class FullName
{
private:
	string surname;
	string name;
	string midname;
public:
	FullName(string sn="", string n="", string mn="");
	FullName(const FullName& fn);
	string getSurname();
	string getName();
	string getMidname();
	string getAll(); 
	FullName& operator=(const FullName& right);//перегрузка оператора =
	friend ostream& operator<<(ostream& out, const FullName& fn);//перегрузка оператора <<
	friend istream& operator>>(istream& in, FullName& fn);//перегрузка оператора >>
	~FullName();
};
class Address
{
private:
	string country;
	string city;
	string street;
public:
	Address(string c = "", string ci = "", string st = "");
	Address(const Address& ad);
	string getCountry();
	string getCity();
	string getStreet();
	string getAll();
	Address& operator=(const Address& right);//перегрузка оператора =
	friend ostream& operator<<(ostream& out, const Address& ad);//перегрузка оператора <<
	friend istream& operator>>(istream& in, Address& ad);//перегрузка оператора >>
	~Address();
};
class Manager
{
private:
	string position;
	FullName fname;
public:
	Manager(string s="", string n="", string m="", string p="");
	Manager(const Manager &m);
	FullName getFullName();
	string getPosition();
	Manager& operator=(const Manager& right);//перегрузка оператора =
	friend ostream& operator<<(ostream& out, const Manager& m);//перегрузка оператора <<
	friend istream& operator>>(istream& in, Manager& m);//перегрузка оператора >>
	~Manager();
};


class Client
{
protected:
	int id;
	Manager mngr;
	Address address;
	string phone;
	string inn;
	string activity;
public:
	Client(Manager mn=Manager(),int i=0,string a1="", string a2 = "", string a3 = "", string p="", string in="", string act="");
	Client(Manager mn, int i, string p, string in, string act,Address a=Address());
	int getId();
	Manager getMngr();
	string getAddress();
	string getPhone();
	string getINN();
	string getActivity();
	virtual string getName() = 0;
	virtual string forSave() = 0;
	virtual ~Client();
};

class Individual : public Client
{
private:
	FullName fname;
public:
	Individual(Manager mn = Manager(), int i=0,  string s="", string n="", string m="", string a1="", string a2 = "", string a3 = "", string p="", string in="", string act="");
	Individual(Manager mn, int i, FullName fn, string p, string in, string act,Address a = Address());
	Individual(const Individual& i);
	string getName();
	string forSave();
	~Individual();
};
class Entity : public Client
{
private:
	string name;
public:
	Entity(Manager mn = Manager(),int i=0,string n="", string a1="", string a2 = "", string a3 = "", string p="", string in="", string act="");
	Entity(Manager mn, int i, string n, string p, string in, string act, Address a = Address());
	Entity(const Entity &e);
	string getName();
	string forSave();
	~Entity();
};
class Storage
{
private:
	vector<Client*> sc;
public:
	Storage();
	Storage(const Storage& s);
	void Add(Client* clnt);
	void Delete(int id);
	void Save(ofstream& f);
	void Load(ifstream& f);
	void Sort(string by);
	void Print();
	void Find(string f, string field);
	int Size();
	~Storage();
};
	bool compID(Client* a, Client* b);
	bool compName(Client* a, Client* b);
	bool compManager(Client* a, Client* b);
	bool compAddress(Client* a, Client* b);
	bool compPhone(Client* a, Client* b);
	bool compINN(Client* a, Client* b);
	bool compActivity(Client* a, Client* b);


