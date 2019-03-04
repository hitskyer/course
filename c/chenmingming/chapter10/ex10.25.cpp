#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	vector<string> books;
	set<string> readedbooks;
	string name;
	cout << "enter names for books you'd like to read £º"
		<< endl;
	while(cin >> name)
		books.push_back(name);
	cin.clear();
	bool timeover = false;
	string bookname,answer;
	srand((unsigned)time(NULL));
	while(!timeover && !books.empty())
	{
		cout << "would you like read a book? yes/no?" << endl;
		cin >> answer;
		if(answer[0] == 'y' || answer[0] == 'Y')
		{
			int i = rand()%books.size();
			bookname = books[i];
			cout << "you can read this book: " << bookname << endl;
			readedbooks.insert(bookname);
			books.erase(books.begin()+i);
			cout << "did you read it yes/no? " << endl;
			cin >> answer;
			if(answer[0] == 'n' || answer[0] == 'N')
			{
				readedbooks.erase(bookname);
				books.push_back(bookname);
			}
		}
		cout << "time is over? yes/no " << endl;
		cin >> answer;
		if(answer[0] == 'y' || answer[0] == 'Y')
		{
			timeover = true;
		}
		if(timeover && !books.empty())
		{
			cout << "books read: " << endl;
			for(set<string>::iterator sit = readedbooks.begin();
				sit != readedbooks.end();++sit)
			{
				cout << *sit << endl;
			}
		}
		else if(!timeover && !books.empty())
		{
			cout << "continue to read books!" << endl;
			continue;
		}
		else
		{
			cout << " congratulations! you have read all books!" << endl;
		}
	}
	return 0;
}