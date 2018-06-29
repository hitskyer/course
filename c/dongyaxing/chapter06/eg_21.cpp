#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
        vector<string> svec;
        string str;
        while(cin>>str)
        {
                svec.push_back(str);
        }
        for(vector<string>::iterator iter=svec.begin();iter!=svec.end();++iter)
        {
                if(isupper((*iter)[0]))
                {
                        cout<<*iter<<"\t"<<endl;
						continue;
                }
        }
        return 0;
}
