#include "Person.h"

Person::Person(string name)
{
	this->name = name;
	this->friendsHead = nullptr;
}

Person::~Person()
{
	PersonNode* cur = this->friendsHead;
	while (cur != nullptr)
	{
		PersonNode* next = cur->next;
		delete cur;
		cur = next;
	}

	this->friendsHead = nullptr;
}

PersonNode* Person::addFriend(Person* person) {

	PersonNode* pn = new PersonNode(person);

	PersonNode* tmp = this->friendsHead;
	this->friendsHead = pn;
	pn->next = tmp;

	return pn;
}

void Person::removeFriend(Person* person) {

	PersonNode* cur = this->friendsHead;

	PersonNode* prev = nullptr;

	while (cur != nullptr && cur->person->name != person->name) {
		prev = cur;
		cur = cur->next;
	}

	if (cur != nullptr && prev != nullptr)
	{
		prev->next = cur->next;
		delete cur;
	}

	else if (cur != nullptr && cur == this->friendsHead)
	{
		delete cur;
	}
	

}


void Person::listFriends() {
	PersonNode* cur = this->friendsHead;

	while (cur != nullptr)
	{
		cout << cur->person->name << " ";
		cur = cur->next;
	}
	cout << endl;
}