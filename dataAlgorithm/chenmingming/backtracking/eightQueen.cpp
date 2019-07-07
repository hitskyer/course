/**
 * @description: 回溯算法--八皇后问题
 * @author: michael ming
 * @date: 2019/7/7 0:10
 * @modified by: 
 */
#include <iostream>
using namespace std;
class EightQueen
{
    int result[8];//下标表示行，值表示queen在哪一列
    void printQueens(int *result)
    {
        int i,r,c,flag = 1;
        cout << "  ";
        for(i = 0; i < 8; ++i)
            cout << "▁";
        cout << endl;
        for(r = 0; r < 8; ++r)
        {
            cout << "┃";
            for(c = 0; c < 8; ++c)
            {
                if(result[r] == c)
                    cout << "★";
                else
                {
                    if(flag < 0)
                        cout << "  ";
                    else
                        cout << "■";
                }
                flag = -1*flag;
            }
            cout << "▏" << endl;
            flag = -1*flag;
        }
        cout << "  ";
        for(i = 0; i < 8; ++i)
            cout << "▔";
        cout << endl;
    }
    bool isOk(int r, int c)//判断在r行c列放置是否可以满足要求
    {
        int leftup = c - 1, rightup = c + 1;
        for(int i = r - 1; i >= 0; --i)//逐行向上考察每一行
        {
            if(result[i] == c)//第i行的c列有棋子吗
                return false;
            if(leftup >= 0)//考察左上对角线
            {
                if(result[i] == leftup)//第i行leftup列有棋子吗
                    return false;
            }
            if(rightup < 8)//考察右上对角线
            {
                if(result[i] == rightup)//第i行rightup列有棋子吗
                    return false;
            }
            --leftup; ++rightup;
        }
        return true;
    }
public:
    int kinds;  //可行布局种类
    EightQueen():kinds(0){}
    void cal8queens(int row)    //调用方式cal8queens(0)
    {
        if(row == 8)    //8个棋子都放置好了，打印结果
        {
            kinds++;
            cout << "第" << kinds << "种放法：" << endl;
            printQueens(result);
            return;//都放置好了，没法再递归了
        }
        for(int column = 0; column < 8; ++column)//每行有8种放法
        {
            if(isOk(row,column))    //该放法满足要求
            {
                result[row] = column;//第row行的棋子放到了column列
                cal8queens(row+1);  //考察下一行
            }
        }
    }

};
int main()
{
    EightQueen eq;
    eq.cal8queens(0);
    cout << "共有" << eq.kinds << "种摆放方法。" << endl;
    return 0;
}