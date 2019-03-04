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
	set<string> readedBooks;
	string name;
	
	cout<<"enter names for books you would like to read.(ctrl+d to end):"<<endl;
	while(cin>>name)
	{
		books.push_back(name);
	}
	cin.clear();
	
	bool timeOver = false;
	string answer, bookName;
	srand((unsigned)time(NULL));
	
	while(!timeOver && !books.empty())
	{
		//时间未到6个月 且还没有读的书
		cout<<"would you like to read a book(yes/no)?"<<endl;
		cin>>answer;
		if(answer[0] == 'y' || answer[0] == 'Y')
		{
			int i = rand()%books.size();
			bookName = books[i];
			cout<<"you can read this book:"<<bookName<<endl;
			readedBooks.insert(bookName);
			books.erase(books.begin()+i);
			
			cout<<"did you read it?(yes/no)"<<endl;
			cin>>answer;
			if(answer[0] == 'n' || answer[0] == 'N')
			{
				readedBooks.erase(bookName);
				books.push_back(bookName);
			}
		}
		else
			cout<<"i do not want to read."<<endl;

		cout<<"Time over?(yes/no)"<<endl;
		cin>>answer;
		if(answer[0] == 'y' || answer[0] == 'Y')
		{
			timeOver = true;
		}
		
	}
	if(timeOver)
	{
		cout<<"books read:"<<endl;
		for(set<string>::iterator sit = readedBooks.begin(); sit!=readedBooks.end();++sit)
		{
			cout<<*sit<<endl;
		}
		cout<<"books not read:"<<endl;
		for(vector<string>::iterator it = books.begin(); it!=books.end(); ++ it)
		{
			cout<<*it<<endl;
		}
	}
	else
		cout<<"congratulations! you have read all these books."<<endl;
	return 0 ;
}
