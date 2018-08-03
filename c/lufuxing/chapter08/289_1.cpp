#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
 
struct PersonInfo{
   string name;
   vector<string> phones;
   };

int main()
{
  string line,word;
  vector<PersonInfo>people;
  istringstream record;

  while (getline(cin,line)){
     PersonInfo info;
     record.clear();
     record.str(line);
     record>>info.name;
     while(record>>word)
        info.phones.push_back(word);
     
     people.push_back(info);
  }

 return 0;
}
