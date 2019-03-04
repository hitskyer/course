//
// Created by mingm on 2019/1/26.
//

#include "Book.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
CBook::CBook(char *cName, char *cIsbn, char *cPrice, char *cAuthor)
{
    strncpy(m_cName, cName, NUM1);
    strncpy(m_cIsbn, cIsbn, NUM1);
    strncpy(m_cPrice, cPrice, NUM2);
    strncpy(m_cAuthor, cAuthor, NUM2);
}
char* CBook::GetName() { return m_cName; }
void CBook::SetName(char* cName) { strncpy(m_cName, cName, NUM1); }
char* CBook::GetIsbn() { return m_cIsbn; }
void CBook::SetIsbn(char *cIsbn) { strncpy(m_cIsbn, cIsbn, NUM1); }
char* CBook::GetPrice() { return m_cPrice; }
void CBook::SetPrice(char *cPrice) { strncpy(m_cPrice, cPrice, NUM2); }
char* CBook::GetAuthor() { return m_cAuthor; }
void CBook::SetAuthor(char *cAuthor) { strncpy(m_cAuthor, cAuthor, NUM2); }
void CBook::WriteData()
{
    ofstream ofile;
    ofile.open("book.txt", ios::binary|ios::app);
    try
    {
        ofile.write(m_cName, NUM1);
        ofile.write(m_cIsbn, NUM1);
        ofile.write(m_cPrice, NUM2);
        ofile.write(m_cAuthor, NUM2);
    }
    catch(...)
    {
        throw "file error occurred";
        ofile.close();
    }
    ofile.close();
}
void CBook::GetBookFromFile(int iCount)
{
    char cName[NUM1];
    char cIsbn[NUM1];
    char cPrice[NUM2];
    char cAuthor[NUM2];
    ifstream ifile;
    ifile.open("book.txt", ios::binary);
    try
    {
        ifile.seekg(iCount*(NUM1+NUM1+NUM2+NUM2),ios::beg);
        ifile.read(cName, NUM1);
        if(ifile.tellg()>0)
            strncpy(m_cName, cName, NUM1);
        ifile.read(cIsbn, NUM1);
        if(ifile.tellg()>0)
            strncpy(m_cIsbn, cIsbn, NUM1);
        ifile.read(cPrice, NUM2);
        if(ifile.tellg()>0)
            strncpy(m_cPrice, cPrice, NUM2);
        ifile.read(cAuthor, NUM2);
        if(ifile.tellg()>0)
            strncpy(m_cAuthor, cAuthor, NUM2);
    }
    catch(...)
    {
        throw "file error occurred";
        ifile.close();
    }
    ifile.close();
}
void CBook::DeleteData(int iCount)
{
    long respos;
    int iDataCount = 0;
    fstream file;
    fstream tmpfile;
    ofstream ofile;
    char cTempBuf[NUM1+NUM1+NUM2+NUM2];
    file.open("book.txt", ios::binary|ios::in|ios::out);
    tmpfile.open("temp.txt", ios::binary|ios::in|ios::out|ios::trunc);
    file.seekg(0, ios::end);
    respos = file.tellg();
    iDataCount = respos/(NUM1+NUM1+NUM2+NUM2);
    if(iCount < 0 && iCount > iDataCount)
    {
        throw "Input number error";
    }
    else
    {
        file.seekg((iCount)*(NUM1+NUM1+NUM2+NUM2), ios::beg);
        for(int j = 0; j < (iDataCount-iCount); ++j)
        {
            memset(cTempBuf,0,NUM1+NUM1+NUM2+NUM2);
            file.read(cTempBuf,NUM1+NUM1+NUM2+NUM2);
            tmpfile.write(cTempBuf,NUM1+NUM1+NUM2+NUM2);
        }
        file.close();
        tmpfile.seekg(0,ios::beg);
        ofile.open("book.txt");
        ofile.seekp((iCount-1)*(NUM1+NUM1+NUM2+NUM2), ios::beg);
        for(int i = 0; i < (iDataCount-iCount); ++i)
        {
            memset(cTempBuf,0,NUM1+NUM1+NUM2+NUM2);
            tmpfile.read(cTempBuf,NUM1+NUM1+NUM2+NUM2);
            ofile.write(cTempBuf,NUM1+NUM1+NUM2+NUM2);
        }
    }
    tmpfile.close();
    ofile.close();
    remove("temp.txt");
}