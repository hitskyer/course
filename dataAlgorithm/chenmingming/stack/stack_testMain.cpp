#include <string>
#include <iostream>
#include "stack.cpp"
int main()
{
    int nums = 0;
    for(size_t i = 0; i < 10; ++i)
    {
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
    while(conti == 'y'|| conti == 'Y')
    {
        Stack<char> charstack;
        cout << "please enter a string to check its brackets legal or not ！" << endl;
        while(cin.get(str) && str != '\n')
        {
            if(str == '{' || str == '[' || str == '(')
                charstack.Push(str);
            switch(str)
            {
                case '}':
                    if(charstack.GetTop()->data == '{')
                        charstack.Pop();
                    else
                        cout << "illegal string !" << endl;
                    break;
                case ']':
                    if(charstack.GetTop()->data == '[')
                        charstack.Pop();
                    else
                        cout << "illegal string !" << endl;
                    break;
                case ')':
                    if(charstack.GetTop()->data == '(')
                        charstack.Pop();
                    else
                        cout << "illegal string !" << endl;
                    break;
//                case '】':
//                    if(charstack.GetTop()->data == '【')
//                        charstack.Pop();
//                    else
//                        cout << "illegal string !" << endl;
//                    break;
//                case '）':
//                    if(charstack.GetTop()->data == '（')
//                        charstack.Pop();
//                    else
//                        cout << "illegal string !" << endl;
//                    break;
                default:
                    break;
            }
        }
        cout << "continue? y/n" << endl;
        cin >> conti;
        cin.get();
    }
    return 0;
}