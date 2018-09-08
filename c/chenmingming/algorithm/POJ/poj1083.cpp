#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int testtime, table, roomid1, roomid2;
	int corridor[200]={0}, corridor_id, maxtime;
	cin >> testtime;
	while(testtime--)
	{
		memset(corridor,0,sizeof(corridor)); 
		//清零初始化（不能写corridor[200]={0};只能定义的时候写一次），memset需要cstring头文件
		//经测试，单独写的corridor[200]={0};对数组没有任何操作，编译器可能不报错，需要避开这个坑！！！
		cin >> table;
		while(table--)
		{
			cin >> roomid1 >> roomid2;
			if(roomid1 > roomid2)
				swap(roomid1,roomid2);
			for(corridor_id = (roomid1-1)/2; corridor_id <= (roomid2-1)/2; ++corridor_id)
			{
				corridor[corridor_id] += 10;
			}
		}
		maxtime = 0;
		for(corridor_id = 0; corridor_id != 200; ++corridor_id)
		{
			if(maxtime < corridor[corridor_id])
				maxtime = corridor[corridor_id];
		}
		cout << maxtime << endl;
	}
}