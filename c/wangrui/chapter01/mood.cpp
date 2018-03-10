#include <iostream>
using namespace std;
int main(){
        char flag='y';
        while('y'==flag){
	cout<<"请输入此刻你是啥心情？"<<endl;
	string mood="开心";
	cin>>mood;
	if (mood=="开心"){
		cout<<"喜乐的心乃是良药，忧伤的灵使骨枯干。愿常常保持喜乐的心！"<<endl;
	}else if(mood=="愤怒"){
		cout <<"生气却不可犯罪，不可含怒到日落。弗4:26"<<endl;
	}else if(mood=="嫉妒"){
		cout<<"不可贪恋人的房屋；也不可贪恋人的妻子、仆俾、牛驴，并他一切所有的。 出20:17"<<endl;
	}else if (mood=="抱怨"){
		cout<<"要常常喜乐、不住的祷告，凡事谢恩，因为这是神在基督耶稣里向你们所定的旨意。"<<endl;
	}else {
		cout<<"神爱世人，甚至将他的独生子赐给他们，叫一切信他的不至灭亡，反得永生。 约3:16"<<endl;
	}
        while(true){

            cout<<"输入“y/n”继续或终止程序："<<endl;
            cin>>flag;
            if('y'==flag){

                 break;
            }else if('n'==flag){
                return 0;
           }else{
                continue;
           }


       }
	
}
         return 0;
}
