//
// Created by mingm on 2019/1/28.
//
#include "stdafx.h"
#include "commodity.h"
int commodity::kinds = 0;
void commodity::UpdateStock(int n) { stock += n; }
int commodity::getStock() { return stock; }
int commodity::getID() { return ID; }
float commodity::getBuyValue() { return buyValue; }
float commodity::getSellValue() { return sellValue; }
char* commodity::getName() { return name; }