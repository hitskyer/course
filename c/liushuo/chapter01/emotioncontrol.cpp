#include<iostream>;

int main()
{
	string s;
	char a='y';
	while (a=='y'||a=='Y')
	{
	cout<<"Express your emotion now"<< endl;
	cin >> s;
	if (s == "happy")
		{
		cout<< "【来1:9】你喜爱公义,恨恶罪恶。所以神就是你的神,用喜乐油膏你,胜过膏你的同伴。"<< endl;
		}
	else if	(s == "sad")
		{
		cout<<"【太6:25】 所以我告诉你们,不要为生命忧虑吃什么,喝什么。为身体忧虑穿什么。生命不胜于饮食吗?身体不胜于衣裳吗?"<< endl;
	else {
		cout <<" No information"<<endl;
		}
	cout << "--------------退出----------------------"<<endl;
	cin>>a;
	cin.ignore(1000,'\n');
	}
	return 0;
