#include "PersonNode.h"



PersonNode::PersonNode(Person *person)
{
	this->person = person;
	this->next = nullptr;
}


PersonNode::~PersonNode()
{

}