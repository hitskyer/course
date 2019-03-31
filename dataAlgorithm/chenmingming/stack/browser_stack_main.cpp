//浏览器前进后退功能，栈实现
// Created by mingm on 2019/3/31.
//
#include "browser.h"
#include <iostream>
using namespace std;

int main()
{
    Browser webBrowser;
    webBrowser.browseWeb("baidu.com");
    webBrowser.browseWeb("google.com");
    webBrowser.browseWeb("163.com");
    cout << "forward..." << endl;
    webBrowser.forward();
    cout << "back..." << endl;
    webBrowser.back();
    cout << "browse mi.com ..." << endl;
    webBrowser.browseWeb("mi.com");
    cout << "forward..." << endl;
    webBrowser.forward();
    cout << "back..." << endl;
    webBrowser.back();
    cout << "back..." << endl;
    webBrowser.back();
    cout << "back..." << endl;
    webBrowser.back();
    cout << "forward..." << endl;
    webBrowser.forward();
}

