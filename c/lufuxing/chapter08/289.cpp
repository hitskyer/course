#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

int main()

{
  ifstream in("data");
  if(!in){
    cerr<<"无法打开输入文件"<<endl;
    return -1;
  }
  string line;
  vector<string> words;
  while (getline(in,line)) {
     words.push_back(line);
  }
  
  in.close();
  
  vector<string>::const_iterator it=words.begin();
  while (it!=words.end()) {
   istringstream line_str(*it);
   string word;
   while (line_str>>word)
    cout<<word<<" ";
   cout<<endl;
   ++it;
  }
  return 0;
}
