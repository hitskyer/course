#include<iostream>
#include<cstring>
using namespace std;

int main()
{
   char str1[]="Welcome to";
   char str2[]="C++ family!";
   char result[strlen(str1) + strlen(str2)-1];
   strcpy(result,str1);
   strcat(result,str2);
   cout<<"第一个字符串是："<<str1<<endl;
   cout<<"第二个字符串是："<<str2<<endl;
   cout<<"拼接后的字符串是："<< result<<endl;
   return 0;
}
