#include"CRM.h"
Client::Client(int i, Manager mn, string a, string p, string in, string act) :id(i), mngr(mn), address(a), phone(p), inn(in), activity(act) {};
Client::Client(const Client& c)
{
	id = c.id;
	mngr = c.mngr;
	address = c.address;
	phone = c.phone;
	inn = c.inn;
	activity = c.activity;
};