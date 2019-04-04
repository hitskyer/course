/**
 * @description: 用队列打印杨辉三角
 * @author: michael ming
 * @date: 2019/4/4 20:30
 * @modified by: 
 */
#include <iostream>
#include <queue>
#include <iomanip>
using  namespace std;
void yanghuitriangle(size_t n)
{
    queue<int> line;
    line.push(1);    //第一行元素
    int temp, space = n;
    for(int i = 2; i <= n+1; ++i)   //打印第n行元素，产生第n+1行队列
    {
        line.push(1);        //第n+1行的第1个元素
        cout << setw(space--);  //设置开始打印前的空格个数
        for(int j = 1; j <= i - 2; ++j) //产生第n+1行的中间n-1个元素
        {
            temp = line.front();
            cout << temp << " ";    //打印第n行的n-1个元素，并出队
            line.pop();
            temp = temp + line.front(); //相邻两数相加，并入队（n+1行的）
            line.push(temp);
        }
        cout << line.front() << endl;   //打印第n行最后1个元素，并出队
        line.pop();
        line.push(1);    //n+1行最后1个元素
    }
}

int main()
{
    size_t N;
    cout << "请输入杨辉三角的行数：";
    cin >> N;
    yanghuitriangle(N);
    return 0;
}