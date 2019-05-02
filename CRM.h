#pragma once
#include<string>
#include<vector>
#include <typeinfo>
#include<iostream>
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
	~Individual();

};
class Entity : public Client
{
private:
	string orgzn;
	string city;
public:
	Entity(Manager mn = Manager(),int i=0,string o="", string c="", string a="", string p="", string in="", string act="");
	Entity(const Entity &e);
	string getOrgzn();
	string getCity();
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

