/**
 * @description: poj 1581 judge winner 判断胜者是谁
 * @author: michael ming
 * @date: 2019/4/5 16:00
 * @modified by: 
 */
#include <string>
#include <iostream>
#include <queue>
using namespace std;
class Competitor
{
private:
    string name;
    int submitTime[4];
    int penaltyPoint[4];
    void numsOfSolved()
    {
        this->solved = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(penaltyPoint[i] != 0)
            {
                this->solved++;
                total_penalty += 20*(submitTime[i]-1) + penaltyPoint[i];
            }
        }
    }
public:
    int total_penalty;
    int solved;
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
        numsOfSolved();
    }
    string getName() const
    {
        return name;
    }
};
bool operator<(const Competitor &a, const Competitor &b)
{
    if(a.solved < b.solved)
        return true;
    else if(a.solved > b.solved)
        return false;
    else
    {
        if(a.total_penalty > b.total_penalty)
            return true;
        else
            return false;
    }
}
int main()
{
    int nums_of_player;
    cin >> nums_of_player;
    priority_queue<Competitor> playerQueue;
    int info[8];
    string name;
    for(int i = 0; i < nums_of_player; ++i)
    {
        cin >> name;
        for(int j = 0; j < 8; ++j)
            cin >> info[j];
        Competitor player(name,info);
        playerQueue.push(player);
    }
    cout << playerQueue.top().getName() << " " << playerQueue.top().solved << " "
            << playerQueue.top().total_penalty << endl;
    return 0;
}