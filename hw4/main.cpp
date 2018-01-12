#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  
#include <numeric>
#include "Person.h"
#include "PersonNode.h"
#include "PersonHashing.h"
#include "Friendship.h"
#include "FriendshipHashing.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

int main()
{
	PersonHashing personHash;
	FriendshipHashing friendshipHash;

	ifstream input("input.txt");
	for (std::string line; getline(input, line); )
	{

		char command = line.at(0);
		string content = line.replace(0, 2, "");




		if (command == 'P')
		{
			Person* person = new Person(content);
			
			personHash.hash(person);
		}
		else if (command == 'F')
		{
			string pn1 = content.substr(0, content.find(" "));
			string pn2 = content.substr(content.find(" ")+1, content.length());

			for (string::iterator i = pn1.begin(); i != pn1.end(); i++)
			{
				if (!isalpha(pn1.at(i - pn1.begin()))){

					pn1.erase(i);
					i--;
				}
			}
			for (string::iterator i = pn2.begin(); i != pn2.end(); i++)
			{
				if (!isalpha(pn2.at(i - pn2.begin()))) {
					pn2.erase(i);
					i--;

				}
			}

			if (pn1 == pn2)
				continue;

			Person* p1 = personHash.getPerson(pn1);
			Person* p2 = personHash.getPerson(pn2);

			PersonNode* f1 = p1->addFriend(p2);
			PersonNode* f2 = p2->addFriend(p1);

			Friendship* f = new Friendship(f1, f2);
			friendshipHash.hash(f);
		}
		else if (command == 'U')
		{
			string pn1 = content.substr(0, content.find(" "));
			string pn2 = content.substr(content.find(" ") + 1, content.length());

			if (!friendshipHash.friendsExist(pn1, pn2))
				continue;

			Person* p1 = personHash.getPerson(pn1);
			Person* p2 = personHash.getPerson(pn2);


			p1->removeFriend(p2);
			p2->removeFriend(p1);

			friendshipHash.remove(pn1, pn2);
		}
		else if (command == 'L')
		{
			Person* p = personHash.getPerson(content);

			p->listFriends();
		}
		else if (command == 'Q')
		{
			string pn1 = content.substr(0, content.find(" "));
			string pn2 = content.substr(content.find(" ") + 1, content.length());

			Person* p1 = personHash.getPerson(pn1);
			Person* p2 = personHash.getPerson(pn2);

			bool exists = friendshipHash.friendsExist(p1->name, p2->name);
			
			cout << (exists ? "Yes" : "No") << endl;

		}


	}

	int x;
	cin >> x;

	return 0;
}