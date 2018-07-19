#include<iostream>
#include<vector>

using namespace std;
int main()
{
  vector<unsigned> vUS(11);
  auto it = vUS.begin();
  int iVal;
  cout<<"请输入已铸成（0-100）："<<endl;
  while(cin >> iVal)
     if(iVal < 101)
          ++*(it+iVal/10);

  cout <<"您总计输入了"<<vUS.size() <<"个成绩"<<endl;
  cout <<"各分数段的人数分布是（成绩由低到高）： "<<endl;
  for(it = vUS.begin();it != vUS.end() ;it++)
  {
    cout<<*it<<" ";
  }
  cout<<endl;
  return 0;
}
