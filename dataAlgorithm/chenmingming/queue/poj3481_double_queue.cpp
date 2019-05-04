#include<map>
#include<iostream>
using namespace std;
int main()
{
	map<int, int> doubleQueue;
	map<int, int>::iterator it;
	int function, key, value;
	while(scanf("%d",&function) && function)
	{
		if(function == 1)
		{
			scanf("%d%d",&value,&key);
			doubleQueue.insert(pair<int, int>(key, value));
		}
		else if(function == 2)
		{
			if(doubleQueue.size() == 0)
				printf("0\n");
			else
			{
				it = doubleQueue.end();
				printf("%d\n",(--it)->second);
				doubleQueue.erase(it);
			}
		}
		else if(function == 3)
		{
			if(doubleQueue.size() == 0)
				printf("0\n");
			else
			{
				it = doubleQueue.begin();
				printf("%d\n",it->second);
				doubleQueue.erase(it);
			}
		}
	}
	return 0;
}