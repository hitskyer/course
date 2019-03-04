//
// Created by mingm on 2019/1/28.
//

#ifndef COMMODITY_COMMODITY_H
#define COMMODITY_COMMODITY_H
#include <cstring>
#include "stdafx.h"
class commodity
{
private:
    int ID;
    int stock;
    float buyValue;
    float sellValue;
    char name[30];
public:
    int static kinds;
    int getID();
    int getStock();
    float getBuyValue();
    float getSellValue();
    char* getName();
    void UpdateStock(int n);
    commodity(char name[], float buyValue, float sellValue)
    {
        kinds++;
        ID = kinds;
        this->stock = 0;
        this->buyValue = buyValue;
        this->sellValue = sellValue;
        strcpy(this->name, name);
    }
};


#endif //COMMODITY_COMMODITY_H
