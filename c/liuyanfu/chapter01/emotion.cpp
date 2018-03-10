#include <iostream>

using namespace std;

      	int main()
          {
            string s;
	    char flag='y';
            do
              {
	    	cout << "请输入你当下的心情：" <<endl;
		cin >> s;
		if (s == "喜乐")
	              {
		 	cout << "我就走到 神的祭坛，到我最喜乐的 神那里。" << endl;
			cout << "神啊，我的 神，我要弹琴称赞你！" << endl;
		      }
		else if (s == "生气")
			{
			    cout << "生气却不要犯罪；不可含怒到日落，" << endl;  
			    cout << "因为人的怒气不成就，神的义。" << endl;
			}
		     else if (s == "忧虑")
			    {	
				cout << "所以，不要为明天忧虑，因为明天自有明天的忧虑；" << endl;
			        cout << "一天的难处一天当就够了" << endl;
				cout << "你们要将一切的忧虑卸给  神，因为他顾念你们" << endl;
			    }
			   else if (s == "愤怒")
				     {	
					cout << "当止住怒气，离弃忿怒；" << endl;
					cout << "不要心怀不平，以致作恶；"<< endl;
					cout << "因为作恶的必被剪除；" << endl;
					cout << "惟有等候耶和华的必承受地土" <<endl;
				     }   
					else
					     {
						cout << "其他情绪请按照下面总纲自行体悟：" << endl;
						cout << "*******************************" << endl;
						cout << "虚心的人有福了！因为天国是他们的。" << endl;
						cout << "哀恸的人有福了！因为他们必得安慰。" << endl;
						cout << "温柔的人有福了！因为他们必承受地土。" << endl;
						cout << "饥渴慕义的人有福了!因为他们必得饱足。" << endl;
						cout << "怜恤人的人有福了！因为他们必蒙受怜恤。" << endl;
						cout << "清心的人有福了！因为他们必得见 神。" << endl;
						cout << "使人和睦的人有福了！因为他们必称为 神的儿子。" << endl;
						cout << "为义受逼迫的人有福了！因为天国是他们的。" << endl;
						cout << "人若因我辱骂你们，逼迫你们，捏造各种坏话毁谤你们，你们就有福了"<< endl;
					        cout << "凡不因我跌倒的就有福了！" << endl;
						}
                         cout << "请问是否继续输入，若继续请入请按【y/Y】!" << endl;
			 cin >> flag;
	      }while (flag == 'y'|| flag == 'Y');
	    
		
       	    return 0;
          }
