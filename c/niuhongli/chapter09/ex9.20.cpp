#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;

int main()
{
    list<int> ilist;
    //输入元素
    int ival;
    vector<int> ivec;
    cout << "Please enter integer to list:" << endl; // 输入list元素
    while(cin >> ival)
    {
        ilist.push_back(ival);
        if(cin.get()=='\n')
            break;
    }
    cout << "Please enter integer to vector" << endl; //输入vector元素
    while(cin >> ival)
    {
        ivec.push_back(ival);
        if(cin.get()=='\n')
            break;
    }

    //比较
    list<int>::iterator il=ilist.begin();
    vector<int>::iterator it=ivec.begin();
    while(il!=ilist.end()&&it!=ivec.end())
    {
    	if(*il==*it)
    	{
    		++il;
    		++it;
    	}
    	else
    		break;
    }	
    // 输出
    if(il==ilist.end()&&it==ivec.end())
    {
   	 cout << " The elements in vector and list are the same" << endl;
   	 return 0;
    }
    else
    {
    	cout << " The elements in vector  and list are not the same" << endl;
    	return -1;
    } 
}
    	
