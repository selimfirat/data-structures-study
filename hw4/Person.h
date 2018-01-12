#ifndef PERSON_H1
#define PERSON_H1

#include <string>
#include "PersonNode.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
class PersonNode;

class Person
{

public:
	Person(string name);
	~Person();
	PersonNode* addFriend(Person* person);
	void removeFriend(Person* person);
	void listFriends();
	string name;
	PersonNode* friendsHead;


private:


};
#endif