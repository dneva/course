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
ostream& operator<<(ostream& out, const Manager& m)
{
	out << m.surname << " " << m.name << " "<< m.midname << " : " << m.position;
	return out;
};

istream& operator>>(istream& in, Manager& m)
{
	in >> m.surname >> m.name >> m.midname >> m.position;
	return in;
};
Manager::~Manager() 
{};
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
{};
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
string Individual::get()
{
	string out;
	out= to_string(id)+" " + surname + " " + name + " " + midname +
		" " + address + " " + phone + " " + inn + " "+ activity+"\nManager: " +
		mngr.getSurname() + " " + mngr.getName() + " " + mngr.getMidname() + " " + mngr.getPosition();
	return out;
}
Individual::~Individual()
{};
///////////////////
Entity::Entity(Manager mn, int i, string o, string a, string p, string in, string act) :Client(mn, i, a, p, in, act), orgzn(o) {};
Entity::Entity(const Entity &e)
{
	id = e.id;
	mngr = e.mngr;
	address = e.address;
	phone = e.phone;
	inn = e.inn;
	activity = e.activity;
	orgzn = e.orgzn;
};
string Entity::getOrgzn()
{
	return orgzn;
};
string Entity::get()
{
	string out;
	out= to_string(id)+" " + orgzn +" " + address + " " + phone + " " + inn + " "+activity+ "\nManager: " +
		mngr.getSurname() + " " + mngr.getName() + " " + mngr.getMidname() + " " + mngr.getPosition();
	return out;
};
Entity::~Entity()
{};
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
};
void Storage::Add(Client *clnt)
{
	sc.push_back(clnt);
}
void Storage::Print()
{
	for (Client* v : sc)
	{
		if (strcmp(typeid(*v).name(),"class Individual")==0) 
			cout << "Individual: ";
		else cout << "Entity: ";
		cout << v->get() << endl;
	}
}
void Storage::Sort(string by)
{
	if (by=="id")
	{
		sort(sc.begin(),sc.end(),compID);
	}
}
Storage::~Storage()
{
	for (Client*c : sc)
	{
		delete c;
	}
}
bool compID(Client* a, Client* b)
{
	return (a->getId()<b->getId());
}
bool compName(vector<Client*> a, vector<Client*> b);
bool compSurname(vector<Client*> a, vector<Client*> b);
bool compMidname(vector<Client*> a, vector<Client*> b);
bool compManager(vector<Client*> a, vector<Client*> b);
bool compAddress(vector<Client*> a, vector<Client*> b);
bool compPhone(vector<Client*> a, vector<Client*> b);
bool compINN(vector<Client*> a, vector<Client*> b);
bool compActivity(vector<Client*> a, vector<Client*> b);
bool compOrgzn(vector<Client*> a, vector<Client*> b);