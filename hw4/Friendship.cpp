#include "Friendship.h"



Friendship::Friendship(PersonNode* pn1, PersonNode* pn2)
{
	Person* p1 = pn1->person;
	Person* p2 = pn2->person;

	string name = p1->name > p2->name ? (p2->name + p1->name) : (p1->name + p2->name);

	this->pn1 = pn1;
	this->pn2 = pn2;
	this->name = name;
}


Friendship::~Friendship()
{
	this->pn1 = nullptr;
	this->pn2 = nullptr;
}