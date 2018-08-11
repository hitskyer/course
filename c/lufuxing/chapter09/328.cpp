#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{ 
  vector<string> vs={"!23","+456","-789"};
  int sum=0;

  for(auto iter=vs.begin();iter!=vs.end();iter++)
    sum+=stoi(*iter);

  cout<<"和："<<sum<<endl;
  return 0;
}
