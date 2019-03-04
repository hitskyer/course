#define Type int
#define HEART 3
#define DIAMOND 4
#define CLUB 5
#define SPADE 6
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
class Card
{
private:
    int value;
    Type type;
public:
    Card(int value, Type type)
    {
        this->value = value;
        this->type = type;
    }
    void GetInfo()
    {
        printf("%c%d ",type,value);
    }
};
void InitCardVector(vector<Card> &v)
{
    for(int i = 1; i < 14; ++i)
    {
        for(Type t = HEART; t<=SPADE;++t)
        {
            v.push_back(Card(i,t));
        }
    }
}
void ShowCard(vector<Card> &v)
{
    int k = 0;
    for(vector<Card>::iterator it = v.begin();it != v.end();++it)
    {
        it->GetInfo();
        k++;
        if(k%10==0){printf("\n");}
    }
    printf("\n");
}
int main()
{
    vector<Card> card_vector;
    printf("初始发牌：\n");
    InitCardVector(card_vector);
    ShowCard(card_vector);
    printf("1次洗牌：\n");
    random_shuffle(card_vector.begin(),card_vector.end());
    ShowCard(card_vector);
    printf("2次洗牌：\n");
    random_shuffle(card_vector.begin(),card_vector.end());
    ShowCard(card_vector);
    system("pause");
    return 0;
}