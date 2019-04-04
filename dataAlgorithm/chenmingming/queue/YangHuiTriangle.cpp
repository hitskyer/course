/**
 * @description: 用队列打印杨辉三角
 * @author: michael ming
 * @date: 2019/4/4 20:30
 * @modified by: 
 */
#include <iostream>
#include "listQueue.h"
void yanghuitriangle(size_t n)
{
    ListQueue<int> line;
    line.enqueue(1);    //第一行元素
    int temp;
    for(int i = 2; i <= n+1; ++i)   //打印第n行元素，产生第n+1行队列
    {
        line.enqueue(1);        //第n+1行的第一个元素
        for(int j = 1; j <= i - 2; ++j) //产生第n+1行的中间n-1个元素
        {
            temp = line.getHead()->data;
            cout << temp << " ";    //打印第n行的元素，并出队
            line.dequeue();
            temp = temp + line.getHead()->data; //相邻两数相加，并入队（n+1行的）
            line.enqueue(temp);
        }
        cout << line.getHead()->data << endl;   //打印第n行最后一个元素，并出队
        line.dequeue();
        line.enqueue(1);    //n+1行最后1个元素
    }
}

int main()
{
    size_t N;
    cin >> N;
    yanghuitriangle(N);
    return 0;
}