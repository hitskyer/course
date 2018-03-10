#include <iostream>

using namespace std;


int main(){
	//情绪管理  如果输入 “开心 ” 返回  我很开心 
	//如果 输入不开心  返回    我不开心   
	//else  返回  else
	//
	
	string ishappy="y";
	
	cout <<"你好，请输入现在的心情？"<<endl;
	cin >>ishappy;  // 接受用户输入的值 
	if(ishappy=="开心"){
		cout<<"wo hen 开心 "<<endl;
	}else if(ishappy=="不开心"){
		cout<<"心情不开心 不ok   !!!"<<endl;
	}else{
		cout<<"else"<<endl;
	}
	
	cout<<"aaaa"<<endl;
	return 0;
}
