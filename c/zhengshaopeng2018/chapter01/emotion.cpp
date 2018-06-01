#include<iostream>
#include<string>
using namespace std;
int main()
{
      string str="ab";
      while(true)
      {
        cout<<"你的心情因他会变的不同"<<endl;
        
        while(true)
        {
           cin>>str;
           if("发怒"==str)
           {
                cout<<"不轻易发怒的，胜过勇士。制服己心的，强如取城。  箴 16 ：32 "<<endl;
                break;
            }
                else if("伤心"==str)
                { 
                    cout<<"喜乐的心乃是良药，忧伤的灵使骨枯干。  箴 17 ：22"<<endl;
                    break;
                 }
                else if("消沉"==str)
                {
                    cout<<"你们要将一切的忧虑卸给神，因为他顾念你们。  彼得前书 5 ：7"<<endl;
                    break;
                }
                else if("害怕"==str)
                {

                    cout<<"他对我说；‘我的恩典够你用的，因为我的力量是在人的软弱上显得完全。’所以，我更喜欢夸自己的软弱，好叫基督的能力覆庇我。 哥林多后书 12：9 "<<endl;         
                    break; 
                }
               else 
               {
                 cout<<"上帝是你的依靠，他知道你内心的渴求，祷告吧，把你的需要告诉他，他必应允"<<endl;
                 return 0;
             }
         } 
      }
       return 0;
}


