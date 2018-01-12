
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  

using namespace std;

int main()
{
	ifstream input("input.txt");
	for (std::string line; getline(input, line); )
	{
		if (line != "X") {
			cout << line << endl;

			char command = line.at(0);
			string content = line.replace(0, 2, "");

		}


	}

	int x;
	cin >> x;

	return 0;
}