#include "stack.cpp"
#include <string>
#include <iostream>

using namespace std;
int main()
{
    for(int i = 0; i < 10; ++i)
    {
        int nums = 0;
        Stack<int> intstack;
        if(intstack.Empty())
            cout << "intstack is empty!" << endl;
        cout << "after push nums: " << endl;
        while(nums < i)
        {
            intstack.Push(nums);
            nums++;
        }
        intstack.print();
        intstack.Pop();
        cout << "len of stack is " << intstack.GetLength() << endl;
        if(intstack.GetTop())
            cout << "top elem is " << intstack.GetTop()->data << endl;
        if(!intstack.Empty())
            cout << "intstack is not empty!" << endl;
        intstack.print();
        cout << "---------------------------------" << endl;
    }
    cout << "以下测试一个字符串是否有非法格式的括号" << endl;
    char conti = 'y', str;
    bool legal = true;
    while(conti == 'y'|| conti == 'Y')
    {
        Stack<char> charstack;
        cout << "please enter a string to check its brackets legal or not ！" << endl;
        while(cin.get(str) && str != '\n')
        {
            if(str == '{' || str == '[' || str == '(')
            {
                charstack.Push(str);
                continue;
            }
            switch(str)
            {
                case '}':
                    if(charstack.GetTop() && charstack.GetTop()->data == '{')
                        charstack.Pop();
                    else
                        legal = false;
                    break;
                case ']':
                    if(charstack.GetTop() && charstack.GetTop()->data == '[')
                        charstack.Pop();
                    else
                        legal = false;
                    break;
                case ')':
                    if(charstack.GetTop() && charstack.GetTop()->data == '(')
                        charstack.Pop();
                    else
                        legal = false;
                    break;
                default:
                    break;
            }
            if(!legal)
                break;
        }
        if(legal && charstack.Empty())
            cout << "legal string !" << endl;
        else
        {
            cout << "illegal string !" << endl;
            cin.ignore(10000,'\n');
        }
        cout << "continue? y/n: " ;
        cin >> conti;
        cin.get();
    }
    return 0;
}