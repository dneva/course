#pragma once
#include<string>
#include<vector>
#include<typeinfo>
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
class Manager
{
private:
	string surname;
	string name;
	string midname;
	string position;
public:
	Manager(string s="", string n="", string m="", string p="");
	Manager(const Manager &m);
	string getSurname();
	string getName();
	string getMidname();
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
	string address;
	string phone;
	string inn;
	string activity;
public:
	Client(Manager mn=Manager(),int i=0,string a="", string p="", string in="", string act="");
	int getId();
	Manager getMngr();
	string getAddress();
	string getPhone();
	string getINN();
	string getActivity();
	virtual string get() = 0;
	virtual ~Client();
};
class Individual : public Client
{
private:
	string surname;
	string name;
	string midname;
public:
	Individual(Manager mn = Manager(), int i=0,  string s="", string n="", string m="", string a="", string p="", string in="", string act="");
	Individual(const Individual& i);
	string getSurname();
	string getName();
	string getMidname();
	string get();
	~Individual();

};
class Entity : public Client
{
private:
	string orgzn;
public:
	Entity(Manager mn = Manager(),int i=0,string o="", string a="", string p="", string in="", string act="");
	Entity(const Entity &e);
	string getOrgzn();
	string get();
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
	void Sort(string by);
	void Print();
	Storage Find(string in, string f);
	~Storage();
};
bool compID(Client* a, Client* b);
bool compName(vector<Client*> a, vector<Client*> b);
bool compSurname(vector<Client*> a, vector<Client*> b);
bool compMidname(vector<Client*> a, vector<Client*> b);
bool compManager(vector<Client*> a, vector<Client*> b);
bool compAddress(vector<Client*> a, vector<Client*> b);
bool compPhone(vector<Client*> a, vector<Client*> b);
bool compINN(vector<Client*> a, vector<Client*> b);
bool compActivity(vector<Client*> a, vector<Client*> b);
bool compOrgzn(vector<Client*> a, vector<Client*> b);

