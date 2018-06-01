#include <iostream>
using namespace std;
int main()
{
	cout<<"please input your current mood number"<<endl;
	cout<<"eg:1:喜乐、2:忧虑、3:委屈、4:生气、5:难过"<<endl;
        int i;
	cin >> i;
	switch(i)
	{
	case 1:
            { 
		cout << "我就走到　神的祭坛，到我最喜乐的　神那里。　神啊，我的　神，我要弹琴称赞你！(诗篇 43:4 和合本)" << endl;
		break;
 	    }
	case 2:
            {
		cout << "你们要将一切的忧虑卸给　神，因为他顾念你们。(彼得前书 5:7 和合本)" << endl; 
		break;
	    }	
	case 3:
	    {
		cout << "为义受逼迫的人有福了！因为天国是他们的。(马太福音 5:10 和合本)" << endl;
		break;
	    }	
	case 4:
	    {
		cout<< "当止住怒气，离弃忿怒；不要心怀不平，以致作恶。因为作恶的必被剪除；惟有等候耶和华的必承受地土。(诗篇 37:8-9 和合本)" << endl; 
	        break;
       	    }
	case 5:
	   {
		cout<<"神所要的祭就是忧伤的灵；　神啊，忧伤痛悔的心，你必不轻看。(诗篇 51:17 和合本)"<<endl;
		break;
	   }
        defaul:
                cout<<"未完待续..."<<endl; 
	}
	return 0;
}
