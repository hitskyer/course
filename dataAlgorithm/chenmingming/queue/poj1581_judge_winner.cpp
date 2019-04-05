/**
 * @description: poj 1581 judge winner 判断胜者是谁
 * @author: michael ming
 * @date: 2019/4/5 16:00
 * @modified by: 
 */
#include <string>
#include <iostream>
#include <priority_queue.h>
class Competitor
{
private:
    string name;
    int submitTime[4];
    int penaltyPoint[4];
    int total_penalty;
public:
    Competitor(string str, int* info):total_penalty(0)
    {
        name = str;
        for(int i = 0, j = 0; i < 4; ++i, ++j)
        {
            submitTime[i] = info[j++];
        }
        for(int i = 0, j = 1; i < 4; ++i, ++j)
        {
            penaltyPoint[i] = info[j++];
        }
    }
    string& getName() const
    {
        return name;
    }
    int numsOfSolved()
    {
        int solved = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(penaltyPoint[i] != 0 && submitTime != 1)
        }
    }
    int total_penalty()
    {

    }
};
