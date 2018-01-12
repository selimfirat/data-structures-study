#ifndef FRIENDSHIP_H
#define FRIENDSHIP_H
#include "PersonNode.h"
#include <string>
#include "Person.h"

class Friendship
{
public:
	Friendship(PersonNode* pn1, PersonNode* pn2);
	~Friendship();
	PersonNode* pn1;
	PersonNode* pn2;
	string name;
};
#endif