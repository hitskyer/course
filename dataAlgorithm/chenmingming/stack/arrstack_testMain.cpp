//
// Created by mingm on 2019/3/27.
//
#include "arrStack.cpp"
#include <string>
#include <iostream>
using namespace std;
int main()
{
    for(int i = 0; i < 20; ++i)
    {
        int k = 0;
        arrStack<int> int_arr_stack(8);
        int_arr_stack.print();
        cout << "the capacity of stack is " << int_arr_stack.GetLength() << endl;
        while(k < i)
        {
            int_arr_stack.Push(k);
            ++k;
        }
        try
        {
            cout << "top elem is " << int_arr_stack.GetTop() << endl;
        }
        catch(const char* str)
        {
            cout << str << endl;
        }
        cout << "the capacity of stack is " << int_arr_stack.GetLength() << endl;
        int_arr_stack.print();
        int_arr_stack.Clear();
        cout << "---------------------------------" << endl;
    }
    cout << "以下测试一个字符串是否有非法格式的括号" << endl;
    char conti = 'y', str;
    while(conti == 'y'|| conti == 'Y')
    {
        bool legal = true;
        arrStack<char> charstack(100);
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
                    try
                    {
                        if(charstack.GetTop()  && charstack.GetTop() == '{')   //栈不为空且栈顶与右括号匹配
                            charstack.Pop();    //删除左括号
                        else
                            legal = false;  //直接遇上右括号，非法；or 栈顶与当前右括号不匹配
                    }
                    catch(const char* str)  //若捕获try内的异常，没有元素在栈内，则遇到右括号，非法
                    {
                        legal = false;
                    }
                    break;
                case ']':
                    try
                    {
                        if(charstack.GetTop() && charstack.GetTop() == '[')
                            charstack.Pop();
                        else
                            legal = false;
                    }
                    catch(const char* str)
                    {
                        legal = false;
                    }
                    break;
                case ')':
                    try
                    {
                        if(charstack.GetTop() && charstack.GetTop() == '(')
                            charstack.Pop();
                        else
                            legal = false;
                    }
                    catch(const char* str)
                    {
                        legal = false;
                    }
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