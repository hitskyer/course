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
        while(cin.get(str) && str != '\n')  //不断地获取输入的字符
        {
            if(str == '{' || str == '[' || str == '(')  //遇到左括号不断地压栈
            {
                charstack.Push(str);
                continue;
            }
            switch(str) //遇到非左括号
            {
                case '}':
                    if(charstack.GetTop() && charstack.GetTop()->data == '{')   //栈不为空且栈顶与右括号匹配
                        charstack.Pop();    //删除左括号
                    else
                        legal = false;  //直接遇上右括号，非法；or 栈顶与当前右括号不匹配
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
                break;  //如果非法，不必循环了，直接退出
        }
        if(legal && charstack.Empty())  //如果合法，且符号都匹配了（栈为空）
            cout << "legal string !" << endl;
        else
        {
            cout << "illegal string !" << endl;
            cin.ignore(10000,'\n'); //清除非法字符后面尚未get的字符
        }
        cout << "continue? y/n: " ;
        cin >> conti;
        cin.get();
    }
    return 0;
}