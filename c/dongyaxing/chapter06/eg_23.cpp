#include <iostream>
#include<bitset>
#include<stdexcept>

using namespace std;

int main()
{
        bitset<200> bi;
	for(size_t i=0 ;i!=bi.size();++i)
	{
		bi[i]=1;
	}
        try{
		bi.to_ulong();
	}catch(runtime_error err){
		cout<<err.what()<<endl;	
	}
        return 0;
}
