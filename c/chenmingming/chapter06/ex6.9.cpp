#include<iostream>
using namespace std;
int main()
{
	char ch;
	int ffc=0,flc=0,fic=0;
	while(cin.get(ch))
	{
		switch(ch)
		{
			case 'f':
				cin.get(ch);
				switch(ch)
				{
				case 'f':
					++ffc;break;
				case 'l':
					++flc;break;
				case 'i':
					++fic;break;
				default :break;
				}
			break;
			default :break;
		}
	}
	cout << "numbers of ff are " << ffc << endl;
	cout << "numbers of fl are " << flc << endl;
	cout << "numbers of fi are " << fic << endl;
	return 0;
}
