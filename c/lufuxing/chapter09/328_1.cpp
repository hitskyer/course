#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
  vector<string> vs={"12.3","-4.56","+7.8e-2"};
  float sum=0;

  for(auto iter=vs.begin();iter !=vs.end();iter++)
    sum+=stof(*iter);

  cout<<"和："<<sum<<endl;
  return 0;
}
