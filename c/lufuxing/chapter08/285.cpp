#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main()
{
  ifstream in("data");
  if (!in){
    cerr<<"无法打开输入文件"<<endl;
    return -1;
  }
  
  string line;
  vector<string>words;
  while(getline(in,line)){
   words.push_back(line);
  }
  
  in.close();

  vector<string>::const_iterator it=words.begin();
  while(it !=words.end()){
    cout<<*it<<endl;
    ++it;
  }

  return 0;
}
