#include"CRM.h"
////////////FullName///////////////////
FullName::FullName(string sn, string n, string mn) : surname(sn), name(n), midname(mn) {};
FullName::FullName(const FullName& fn)
{
	surname = fn.surname;
	name = fn.name;
	midname = fn.midname;
}
string FullName::getSurname()
{
	return surname;
}
string FullName::getName()
{
	return name;
}
string FullName::getMidname()
{
	return midname;
}
string FullName::getAll()
{
	string out;
	out = surname + " " + name + " " + midname;
	return out;
}
FullName& FullName::operator=(const FullName& right) {
	if (this == &right) {
		return *this;
	}
	surname = right.surname;
	name = right.name;
	midname = right.midname;
	return *this;
};
ostream& operator<<(ostream& out, const FullName& fn)
{
	out << setw(12) << fn.surname << " " << setw(12) << fn.name  << " " << setw(12) << fn.midname;
	return out;
};

istream& operator>>(istream& in, FullName& fn)
{
	in >> fn.surname >> fn.name >> fn.midname;
	return in;
};
FullName::~FullName()
{};
////////////FullName///////////////////

////////////Address///////////////////
Address::Address(string c, string ci, string st) : country(c), city(ci), street(st) {};
Address::Address(const Address& ad)
{
	country = ad.country;
	city = ad.city;
	street = ad.street;
}
string Address::getCountry()
{
	return country;
}
string Address::getCity()
{
	return city;
}
string Address::getStreet()
{
	return street;
}
string Address::getAll()
{
	string out;
	out = country + " " + city + " " + street;
	return out;
}
Address& Address::operator=(const Address& right)//перегрузка оператора =
{
	if (this == &right) {
		return *this;
	}
	country = right.country;
	city = right.city;
	street = right.street;
	return *this;
}
ostream& operator<<(ostream& out, const Address& ad)//перегрузка оператора <<
{
	out << ad.country << " " << ad.city << " " << ad.street;
	return out;
}
istream& operator>>(istream& in, Address& ad)//перегрузка оператора >>
{
	in >> ad.country >> ad.city >> ad.street;
	return in;
}
Address::~Address() {};
////////////Address///////////////////

////////////Manager///////////////////
Manager::Manager(string s, string n, string m, string p) : fname(s,n,m), position(p) {};
Manager::Manager(const Manager &m)
{
	fname = m.fname;
	position = m.position;
};
FullName Manager::getFullName()
{
	return fname;
};
string Manager::getPosition()
{
	return position;
};

Manager& Manager::operator=(const Manager& right) {
	if (this == &right) {
		return *this;
	}
	fname = right.fname;
	position = right.position;
	return *this;
};
ostream& operator<<(ostream& out, const Manager& m)
{
	out << m.fname << setw(10) << m.position;
	return out;
};

istream& operator>>(istream& in, Manager& m)
{
	in >>  m.fname >> m.position;
	return in;
};
Manager::~Manager() 
{};
////////////Manager///////////////////

////////////Client///////////////////
Client::Client(Manager mn, int i, string a1, string a2, string a3, string p, string in, string act) : id(i), mngr(mn), address(a1,a2,a3), phone(p), inn(in), activity(act) {};
Client::Client(Manager mn, int i, string p, string in, string act, Address a) :id(i), mngr(mn), address(a), phone(p), inn(in), activity(act) {};
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
	return address.getAll();
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
////////////Client///////////////////

///////////Individual////////////////
Individual::Individual(Manager mn, int i,  string s, string n, string m, string a1, string a2, string a3, string p, string in, string act) : Client(mn, i,  a1, a2, a3, p, in, act), fname(s,n,m) {};
Individual::Individual(Manager mn, int i, FullName fn, string p, string in, string act, Address a) : Client(mn, i, p, in, act, a), fname(fn) {};
Individual::Individual(const Individual& i)
{
	id = i.id;
	mngr = i.mngr;
	address = i.address;
	phone = i.phone;
	inn = i.inn;
	activity = i.activity;
	fname = i.fname;
};
string Individual::getName()
{
	return  fname.getAll();
};
string Individual::forSave()
{
	string out;
	out = "ID: " + to_string(id) + " Surname: " + fname.getSurname() + " Name: " + fname.getName()
		+ " Midname: " + fname.getMidname() + " Address: Country: " + address.getCountry() +
		+" City: " + address.getCity() + " Street: " + address.getStreet()
		+ " Phone: " + phone + " INN: " + inn + " Activity: " + activity
		+ " Manager: " + mngr.getFullName().getAll() +" "+ mngr.getPosition() + '\n';
	return out;
}
Individual::~Individual()
{};
///////////Individual////////////////

///////////Entity////////////////
Entity::Entity(Manager mn, int i, string n, string a1, string a2, string a3, string p, string in, string act) :Client(mn, i, a1,a2,a3, p, in, act), name(n) {};
Entity::Entity(Manager mn, int i, string n, string p, string in, string act, Address a) : Client(mn, i, p, in, act, a), name(n) {};
Entity::Entity(const Entity &e)
{
	id = e.id;
	mngr = e.mngr;
	address = e.address;
	phone = e.phone;
	inn = e.inn;
	activity = e.activity;
	name = e.name;
};
string Entity::getName()
{
	return name;
};
string Entity::forSave()
{
	string out;
	out = "ID: " + to_string(id) + " Name: " + name
		+ " Address: Country: " + address.getCountry() +
		+ " City: " + address.getCity() + " Street: " + address.getStreet()
		+ " Phone: " + phone + " INN: " + inn + " Activity: " + activity
		+ " Manager: " + mngr.getFullName().getAll() + " " + mngr.getPosition() + '\n';
	return out;
}
Entity::~Entity()
{};
///////////Entity////////////////

///////////Storage////////////////
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
	cout << left <<setw(13) << "Type:" << setw(4) << "ID:" << setw(30) << "Name:"
		<< setw(40) << "Address:" << setw(20) << "Phone:" << setw(15) << "INN:"
		<< setw(15) << "Activity:" << setw(30) << "Manager:"<<endl;
	for (Client* v : sc)
	{
		if (strcmp(typeid(*v).name(),"class Individual")==0) 
			cout << setw(13) << left<< "Individual: ";
		else cout<< setw(13) << left << "Entity: ";
		cout << setw(4) <<left << v->getId() << setw(30) << v->getName() << setw(40) 
			<< v->getAddress() << setw(20) << v->getPhone() << setw(15) <<
			v->getINN() << setw(15) << v->getActivity() <<v->getMngr()<< endl;
	}
}
void Storage::Sort(string by)
{
	if (by=="id")
	{
		sort(sc.begin(),sc.end(),compID);
	}
	else if(by=="name")
	{
		sort(sc.begin(), sc.end(), compName);
	}
	else if (by == "manager")
	{
		sort(sc.begin(), sc.end(), compManager);
	}
	else if (by == "address")
	{
		sort(sc.begin(), sc.end(), compAddress);
	}
	else if (by == "phone")
	{
		sort(sc.begin(), sc.end(), compPhone);
	}
	else if (by == "inn")
	{
		sort(sc.begin(), sc.end(), compINN);
	}
	else if (by == "activity")
	{
		sort(sc.begin(), sc.end(), compActivity);
	}
	else
	{
		cout << "Incorrect field" << endl;
	}
}
void Storage::Save(ofstream& f)
{
	for (Client*c : sc)
	{
		if (strcmp(typeid(*c).name(), "class Individual") == 0)
			f << "Individual: ";
		else 
			f << "Entity: ";
		f << c->forSave();
	}
}
void Storage::Delete(int id)
{
	int i=0;
	for (Client*c : sc)
	{
		if (c->getId() == id)
		{
			sc.erase(sc.begin()+i);
		}
		i++;
	}
}
void Storage::Find(string f, string field)
{
	Storage strg;
	string s;
	for (Client*c : sc)
	{
		if (field == "id") s = to_string(c->getId());
		else if (field == "name") s = c->getName();
		else if (field == "manager") s = c->getMngr().getFullName().getAll();
		else if (field == "address") s = c->getAddress();
		else if (field == "phone") s = c->getPhone();
		else if (field == "inn") s = c->getINN();
		else if (field == "activity") s = c->getActivity();

		if (s.find(f) != string::npos)
		{
			cout << s.find(f) << endl;
			strg.Add(c);
		}
	}
	if (strg.Size() > 0) strg.Print();
	else cout << "Not found"<<endl;
	
}
int Storage::Size()
{
	return sc.size();
}
void Storage::Load(ifstream& f)
{
	string buf;
	Individual* i;
	Entity* e;
	int id;
	string sn, n, mn, adrs1, adrs2, adrs3, ph, in, act;
	Manager  mngr;
	while (f >> buf)
	{
		if (buf == "Individual:")
		{
			f >> buf >> id >> buf >> sn >> buf >> n >> buf >> mn >> buf >> buf >> buf;
			while (buf != " City:")
			{
				adrs1 += buf;
				f >> buf;
				buf = " " + buf;
			}
			f >> buf;
			while (buf != " Street:")
			{
				adrs2 += buf;
				f >> buf;
				buf = " " + buf;
			}

			f >> buf;

			while (buf != " Phone:")
			{
				adrs3 += buf;
				f >> buf;
				buf = " " + buf;
			}
			f >> ph;
			f >> buf;
			f >> in;
			f >> buf >> buf;
			while (buf != " Manager:")
			{
				act += buf;
				f >> buf;
				buf = " " + buf;
			}
			f >> mngr;
			i = new Individual(mngr, id, sn, n, mn, adrs1, adrs2, adrs3, ph, in, act);
			Add(i);

		}
		else
		{
			f >> buf >> id >> buf >> buf;
			while (buf != " Address:")
			{
				n += buf;
				f >> buf;
				buf = " " + buf;
			}
			f >> buf >> buf;
			while (buf != " City:")
			{
				adrs1 += buf;
				f >> buf;
				buf = " " + buf;
			}
			f >> buf;
			while (buf != " Street:")
			{
				adrs2 += buf;
				f >> buf;
				buf = " " + buf;
			}
			f >> buf;
			while (buf != " Phone:")
			{
				adrs3 += buf;
				f >> buf;
				buf = " " + buf;
			}
			f >> ph;
			f >> buf;
			f >> in;
			f >> buf >> buf;
			while (buf != " Manager:")
			{
				act += buf;
				f >> buf;
				buf = " " + buf;
			}
			f >> mngr;
			e = new Entity(mngr, id, n, adrs1, adrs2, adrs3, ph, in, act);
			Add(e);

		}
		n = ""; adrs1 = ""; adrs2 = ""; adrs3 = ""; act = "";
	}
}
Storage::~Storage()
{}

///////////Storage////////////////
bool compID(Client* a, Client* b)
{
	return (a->getId()<b->getId());
}
bool compName(Client* a, Client* b)
{
	return (a->getName() < b->getName());
}
bool compManager(Client* a, Client* b)
{
	return (a->getMngr().getFullName().getAll() < b->getMngr().getFullName().getAll());
}
bool compAddress(Client* a, Client* b)
{
	return (a->getAddress()<b->getAddress());
}
bool compPhone(Client* a, Client* b)
{
	return (a->getPhone()<b->getPhone());
}
bool compINN(Client* a, Client* b)
{
	return (a->getINN()<b->getINN());
}
bool compActivity(Client* a, Client* b)
{
	return (a->getActivity()<b->getActivity());
}