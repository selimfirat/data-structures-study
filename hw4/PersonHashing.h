#ifndef PERSONHASHING_H
#define PERSONHASHING_H
#include "PersonNode.h"
#include <string>
#include <numeric>

using std::string;

class PersonHashing
{
public:
	PersonHashing();
	~PersonHashing();
	void hash(Person* p);
	Person* getPerson(string name);

private:
	PersonNode* persons[11] = { nullptr };
	int hashFunction(string name);

};
#endif