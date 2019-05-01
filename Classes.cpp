#include"CRM.h"
Manager::Manager(string s, string n, string m, string p) :surname(s), name(n), midname(m), position(p) {};
Manager::Manager(const Manager &m)
{
	surname = m.surname;
	name = m.name;
	midname = m.midname;
	position = m.position;
};
string Manager::getSurname()
{
	return surname;
};
string Manager::getName()
{
	return name;
};
string Manager::getMidname()
{
	return midname;
};
string Manager::getPosition()
{
	return position;
};
Manager& Manager::operator=(const Manager& right) {
	if (this == &right) {
		return *this;
	}
	surname = right.surname;
	name = right.name;
	midname = right.midname;
	position = right.position;
	return *this;
};
Manager::~Manager() 
{
	cout << "Manager: " << surname << "deleted" << endl;
};
////////////////
Client::Client(Manager mn, int i, string a, string p, string in, string act) : id(i), mngr(mn), address(a), phone(p), inn(in), activity(act) {};
int Client::getId()
{
	return id;
};
Manager Client::getMngr()
{
	return mngr;
};
string Client::getAddress()
{
	return address;
};
string Client::getPhone()
{
	return phone;
};
string Client::getINN()
{
	return inn;
};
string Client::getActivity()
{
	return activity;
};
Client::~Client()
{
	cout << "ID: "<< id << "deleted" << endl;
};
/////////////////
Individual::Individual(Manager mn, int i,  string s, string n, string m, string a, string p, string in, string act) : Client(mn, i,  a, p, in, act), surname(s), name(n), midname(m) {};
Individual::Individual(const Individual& i)
{
	id = i.id;
	mngr = i.mngr;
	address = i.address;
	phone = i.phone;
	inn = i.inn;
	activity = i.activity;
	surname = i.surname;
	name = i.name;
	midname = i.midname;
};
string Individual::getSurname()
{
	return surname;
};
string Individual::getName()
{
	return name;
};
string Individual::getMidname()
{
	return midname;
};
Individual::~Individual()
{
	cout << "Individual: " << surname << "deleted" << endl;
};
Entity::Entity(Manager mn, int i, string o, string c, string a, string p, string in, string act) :Client(mn, i, a, p, in, act), orgzn(o), city(c) {};
Entity::Entity(const Entity &e)
{
	id = e.id;
	mngr = e.mngr;
	address = e.address;
	phone = e.phone;
	inn = e.inn;
	activity = e.activity;
	orgzn = e.orgzn;
	city = e.city;
};
string Entity::getOrgzn()
{
	return orgzn;
};
string Entity::getCity()
{
	return city;
};
Entity::~Entity()
{
	cout << "Entity: " << orgzn << "deleted" << endl;
};
Storage::Storage() {};
Storage::Storage(const Storage& s)
{
	for (Client*c : sc)
	{
		for (Client*c1 : s.sc)
		{
			c = c1;
		}
	}
	for (string str : type)
	{
		for (string str1 : s.type)
		{
			str = str1;
		}
	}
};
string Storage::setType(Client *clnt)
{
	if (typeid(*clnt).name() == "Individual")
		return "Individual";
	else if (typeid(*clnt).name() == "Entity")
		return "Entity";
};
void Storage::Add(Client *clnt)
{
	sc.push_back(clnt);
	type.push_back(setType(clnt));
}
void Storage::Print()
{
	for (string str : type)
	{
		for (Client* v : sc)
		{
			cout << str << " ";
		}
	}
}
Storage::~Storage()
{
	for (Client*c : sc)
	{
		delete c;
	}
}