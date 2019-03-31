//
// Created by mingm on 2019/3/31.
//
#ifndef STACK_BROWSER_H
#define STACK_BROWSER_H

#include "stack.cpp"
class Browser
{
private:
    Stack<const char*> forward_stack, back_stack;
    void displayCurWeb(const char *ch)
    {
        cout << "Current web is : " << ch << endl;
    }
public:
    Browser(){}
    ~Browser(){}
    void forward()
    {
        if(!back_stack.Empty())
        {
            forward_stack.Push(back_stack.GetTop()->data);
            back_stack.Pop();
            displayCurWeb(forward_stack.GetTop()->data);
        }
        else
        {
            cout << "can not forward, there is no more page!" << endl;
            displayCurWeb(forward_stack.GetTop()->data);
        }
    }
    void back()
    {
        if(forward_stack.GetLength()>1)
        {
            back_stack.Push(forward_stack.GetTop()->data);
            forward_stack.Pop();
            displayCurWeb(forward_stack.GetTop()->data);
        }
        else
        {
            cout << "can not back, there is no more page! " << endl;
            displayCurWeb(forward_stack.GetTop()->data);
        }
    }
    void browseWeb(const char* ch)
    {
        back_stack.Clear();
        forward_stack.Push(ch);
        displayCurWeb(forward_stack.GetTop()->data);
    }
};
#endif //STACK_BROWSER_H
