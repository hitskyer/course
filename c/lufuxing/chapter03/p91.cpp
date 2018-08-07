#include<iostream>
#include<vector>
using namespace std;
int main()
{
 vector<int> vInt;
 int i;
 char cont ='y';
 while(cin>>i)
 {
 vInt.push_back(i);
 cout<<"您要继续吗（y or n）？"<<endl;
 if (cont !='y' && cont !='Y')
    break;
 }
 for(auto mem : vInt)
    cout << mem << " ";
 cout <<endl;
 return 0;
}
