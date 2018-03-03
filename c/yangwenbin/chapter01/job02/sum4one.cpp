#include<iostream>
#include<string.h>
#include <cstdlib>
using namespace std;

//四则运算
template <class T> class ElementaryArithmetic{
private:
    int result;
    int operand1, operand2;
public:
    //四则运算
    void Calculate();
    //加法运算
    void add(int, int);
    //减法运算
    void subtraction(int, int);
    //乘法运算
    void multiplication(int, int);
    //除法运算
    void divide(int, int);
};

//四则运算
template <class T> void ElementaryArithmetic<T>::Calculate(){
    int type;
    loop1:
    cout << endl << "*******************" << endl;
    cout << "*   1.加法运算    *" << endl;
    cout << "*   2.减法运算    *" << endl;
    cout << "*   3.乘法运算    *" << endl;
    cout << "*   4.除法运算    *" << endl;
    cout << "*   5.结束程序    *" << endl;
    cout << "*******************" << endl;
    cout << "请输入菜单项(1-5)：";
    try{
        cin >> type;
        if (type != 1 && type != 2 && type != 3 && type != 4 && type != 5)
            throw 1;
    }
    catch (int e){
        cout << endl << "输入错误，请重新输入选项...";
        system("pause");
        goto loop1; //去loop1在循环
    }
    if (type == 5){
        exit(0);
    }
    cout << endl << "请输入两个数字：";
    cin >> operand1 >> operand2;
    if (type == 1){
        add(operand1, operand2);
    }
    else if (type == 2){
        subtraction(operand1, operand2);
    }
    else if (type == 3){
        multiplication(operand1, operand2);
    }
    else if (type == 4){
        divide(operand1, operand2);
    }
}

//加法运算
template <class T> void ElementaryArithmetic<T>::add(int operand1,int operand2){
    //校验是否是整数
    if(cin.fail() ==1){
        cout<<"错误的输入,请重新输入!!!"<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        ElementaryArithmetic<double> calc;
        calc.Calculate();
    }else{
        result = operand1 + operand2;
        cout << "第一个数是:" << operand1 << ",第二个数是:" << operand2 << ",相加的结果是:" << result << endl;
        ElementaryArithmetic<double> calc;
        calc.Calculate();
    }

}

//减法运算
template <class T> void ElementaryArithmetic<T>::subtraction(int operand1, int operand2){
    if(cin.fail() ==1){
        cout<<"错误的输入,请重新输入!!!"<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        ElementaryArithmetic<double> calc;
        calc.Calculate();
    }else {
        result = operand1 - operand2;
        cout << "第一个数是:" << operand1 << ",第二个数是:" << operand2 << ",相减的结果是:" << result << endl;
        ElementaryArithmetic<double> calc;
        calc.Calculate();
    }
}

//乘法运算
template <class T> void ElementaryArithmetic<T>::multiplication(int operand1, int operand2){
    if(cin.fail()==1){
        cout<<"错误的输入,请重新输入!!!"<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        ElementaryArithmetic<double> calc;
        calc.Calculate();
    }else {
        result = operand1 * operand2;
        cout << "第一个数是:" << operand1 << ",第二个数是:" << operand2 << ",相乘的结果是:" << result << endl;
        ElementaryArithmetic<double> calc;
        calc.Calculate();
    }
}

//除法运算
template <class T> void ElementaryArithmetic<T>::divide(int operand1, int operand2){
    try{
        //除数为0，出现异常
        if ((operand2 - 0) < 1e-8 && (operand2 - 0) > -1e-8)
            throw 0;
    }
    catch (int){
        throw ;
    }
    if(cin.fail() ==1){
        cout<<"错误的输入,请重新输入!!!"<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
        ElementaryArithmetic<double> calc;
        calc.Calculate();
    }else {
        result = operand1 / operand2;
        cout << "第一个数是:" << operand1 << ",第二个数是:" << operand2 << ",相除的结果是:" << result << endl;
        ElementaryArithmetic<double> calc;
        calc.Calculate();
    }
}

int main(){
    int type;

    loop:
    while (true){
        cout << "*******主菜单**********" << endl;
        cout << "*                     *" << endl;
        cout << "*   1. 四则运算       *" << endl;
        cout << "*   2. 退出程序       *" << endl;
        cout << "*                     *" << endl;
        cout << "***********************" << endl << endl;
        cout << "请输入菜单项(1-2)：";

        try{
            cin >> type;
            if (type != 1 && type != 2)
                throw - 1;
            if (type == 1){
                ElementaryArithmetic<double> calc;
                calc.Calculate();
            }
            else if (type == 2)
                cout << "您已经退出程序,谢谢！";
                break;
        }catch (int e){
            if (e == -1){
                cout << endl << "输入错误，请重新输入选项...";
                system("pause");
                goto loop;
            }
            else if (e == 0)
                cout << "除数不能为 0 " << endl;

        }
        cout << endl;
        system("pause");
    }
    return 0;
}
