#pragma once
#include<string>
#include<vector>
using namespace std;
class Client
{
private:
	int id;
	Manager mngr;
	string address;
	string phone;
	string inn;
	string activity;
public:
	Client(int i, Manager mn, string a, string p, string in, string act);
	Client(const Client& c);
	int getId();
	Manager getMngr();
	string getAddress();
	string getPhone();
	string getINN();
	string getActivity();
	virtual ~Client();
};
class Individual : public Client
{
private:
	string surname;
	string name;
	string midname;
public:
	Individual(int i, Manager mn, string s, string n, string m, string a, string p, string inn);
	Individual(const Individual& i);
	string getSurname();
	string getName();
	string getMidname();
	~Individual();
};
class Entity : public Client
{
private:
	string orgzn;
	string city;
public:
	Entity(int i, Manager mn, string o, string c, string a, string p, string inn);
	Entity(const Entity &e);
	string getOrgzn();
	string getCity();
	~Entity();
};
class Manager
{
private:
	string surname;
	string name;
	string midname;
	string position;
public:
	Manager(string s, string n, string m, string p);
	Manager(const Manager &m);
	string getSurname();
	string getName();
	string getMidname();
	string getPosition();
	Manager& operator=(const Manager& right);//перегрузка оператора =
	~Manager();
};
class Storage
{
private:
	vector<Client*> sс;
	vector<string> type;
public:
	Storage(const Storage& s);
	string setType(Client *clnt);
	void Add(Client* clnt);
	void Sort(string by);
	Storage Find(string in, string f);
	~Storage();
};