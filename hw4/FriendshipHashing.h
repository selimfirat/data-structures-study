#ifndef FRIENDSHIPHASHING_H
#define FRIENDSHIPHASHING_H
#include <string>
#include <numeric>
#include "Friendship.h"

class FriendshipHashing
{
public:
	FriendshipHashing();
	~FriendshipHashing();
	void hash(Friendship* f);
	bool friendsExist(string name1, string name2);
	void remove(string name1, string name2);

private:
	Friendship* friendships[71] = { nullptr };
	bool isDeleted[71] = { false }; // init with false values
	int probe(int hashedVal, int i);
	int hashFunction(string f);

};

#endif