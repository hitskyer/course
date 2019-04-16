/**
 * @description: 查找ip地址归属，找到最后一个区间开始地址<=ip的
 * @author: michael ming
 * @date: 2019/4/16 23:38
 * @modified by: 
 */
#include <iostream>
#include "binarySearch_findLastLessNum.cpp"
int main()
{
    int start[5] = {101,201,301,401,501};   //假设为ip起始地址
    int end[5] =    {200,300,400,500,600};  //对应ip终止地址
    size_t ip;
    while(1)
    {
        std::cout << "请输入要查询的ip: ";
        std::cin >> ip;
        int index = binarySearch_simple(start,5,ip);    //在ip区间头里查找最后一个<=我的
        if(index != -1 && ip <= end[index])
            switch(index)
            {
                case 0:
                    std::cout << "ip in city A"<< std::endl;
                    break;
                case 1:
                    std::cout << "ip in city B"<< std::endl;
                    break;
                case 2:
                    std::cout << "ip in city C"<< std::endl;
                    break;
                case 3:
                    std::cout << "ip in city D"<< std::endl;
                    break;
                case 4:
                    std::cout << "ip in city E"<< std::endl;
                    break;
            }
        else
            std::cout << "ip not found!" << std::endl;
    }
}