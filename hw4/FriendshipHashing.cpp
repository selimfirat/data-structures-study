#include "FriendshipHashing.h"



FriendshipHashing::FriendshipHashing()
{
}


FriendshipHashing::~FriendshipHashing()
{
	for (int i = 0; i < 71; i++)
		delete friendships[i];

}

int FriendshipHashing::hashFunction(string name) {
	return accumulate(name.begin(), name.end(), 0) % 71;
}

// quadratic probing
int FriendshipHashing::probe(int hashedVal, int i) {
	return (hashedVal + i*i) % 71;
}

void FriendshipHashing::hash(Friendship* f) {

	int hashed = hashFunction(f->name);
	for (int i = 0; ; i++) // assumption is that hash table is never full
	{
		int probed = probe(hashed, i);

		if (this->friendships[probed] == nullptr)
		{
			this->friendships[probed] = f;
			this->isDeleted[probed] = false;
			return;
		}
	}

}

bool FriendshipHashing::friendsExist(string name1, string name2) {

	string name = name1 > name2 ? (name2 + name1) : (name1 + name2);

	int hashed = hashFunction(name);
	for (int i = 0; ; i++) // assumption is that hash table is never full
	{
		int probed = probe(hashed, i);

		if (isDeleted[probed])
			continue;

		if (this->friendships[probed] == nullptr)
			return false;

		if (this->friendships[probed]->name == name)
			return true;
	}

	return false; // never reaches here!
}

void FriendshipHashing::remove(string name1, string name2) {

	string name = name1 > name2 ? (name2 + name1) : (name1 + name2);

	int hashed = hashFunction(name);
	int probed;
	for (int i = 0; ; i++) // assumption is that hash table is never full
	{
		probed = probe(hashed, i);

		if (isDeleted[probed])
			continue;

		if (this->friendships[probed] == nullptr)
			return;

		if (this->friendships[probed]->name == name)
			break;
	}
	delete friendships[probed];
	friendships[probed] = nullptr;
	isDeleted[probed] = true;

}