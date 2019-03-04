//
// Created by mingm on 2019/1/28.
//

#ifndef COMMODITY_TRADE_H
#define COMMODITY_TRADE_H
#include "stdafx.h"
#include <list>
#include "commodity.h"
using std::list;

class trade
{
private:
    list<commodity> datalist;
public:
    bool GetInformation(int index);
    void GetIndex();
    bool init();
    void save();
    bool Buy(int ID, int count);
    bool Sell(int n, int ID);
    void AddNew(char name[], float buyValue, float sellValue);
    struct record
    {
        char name[30];
        int count;
        char sTime[70];
        record(char* name, int count, char* time)
        {
            strcpy(this->name,name);
            this->count = count;
            strcpy(sTime,time);
        }
    };
    list<record> sellRecordList;
    list<record> buyRecordList;
    void getSellRecord();
    void getBuyRecord();
};


#endif //COMMODITY_TRADE_H
