#include <iostream>

#include<cstring>

using namespace std;



int main()

{

	const char *pc1="My name is liwei";

	const char *pc2="I love reading";

	 char *newstr= new char[strlen(pc1)+strlen(pc2)+1];

	strcpy(newstr,pc1);

	strcat(newstr,pc2);

	char *pc=newstr;

	while(*pc)

	{

		cout << *pc;

		++pc;

	}

	delete [] newstr;

	return 0;

}
