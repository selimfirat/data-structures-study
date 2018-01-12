#ifndef PERSONNODE_H1
#define PERSONNODE_H1
#include "PersonNode.h"
#include "Person.h"
#include <iostream>
using std::string;
using std::endl;

class Person;

class PersonNode
{

public:
	PersonNode(Person* person);
	~PersonNode();
	PersonNode* next;
	Person* person;

private:

};

#endif