#include "PersonHashing.h"



PersonHashing::PersonHashing()
{
}


PersonHashing::~PersonHashing()
{
	for (int i = 0; i < 11; i++)
	{
		PersonNode* cur = persons[i];
		while (cur != nullptr)
		{
			PersonNode* next = cur->next;
			delete cur;
			cur = next;
		}

		persons[i] = nullptr;
	}
}

int PersonHashing::hashFunction(string name) {
	int sum = 0;
	for (unsigned int i = 0; i < name.size(); i++) {
		sum += name[i];
	}

	return sum % 11;
}

void PersonHashing::hash(Person* p) {

	int s = this->hashFunction(p->name);

	PersonNode* pn = new PersonNode(p);

	PersonNode* cur = this->persons[s];

	this->persons[s] = pn;
	this->persons[s]->next = cur;

	pn = nullptr;
	cur = nullptr;
}

Person* PersonHashing::getPerson(string name) {
	PersonNode* cur = this->persons[hashFunction(name)];

	while (cur->person->name != name)
	{
		cur = cur->next;
	}

	return cur->person;
}