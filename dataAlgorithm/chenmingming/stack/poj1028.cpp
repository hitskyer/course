#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    stack<string> webstackmain, webstacktemp;
    webstackmain.push("http://www.acm.org/");
    string function,web;
    while(cin >> function && function != "QUIT")
    {
        if(function == "VISIT")
        {
            cin >> web;
            webstackmain.push(web);
            for(int i = webstacktemp.size(); i != 0; i--)
            {
                webstacktemp.pop();
            }
            cout << webstackmain.top() << endl;
        }
        else if(function == "BACK")
        {
            if(webstackmain.size() == 1)
                cout << "Ignored" << endl;
            else
            {
                web = webstackmain.top();
                webstackmain.pop();
                webstacktemp.push(web);
                cout << webstackmain.top() << endl;
            }
        }
        else    //function == "FORWARD"
        {
            if(webstacktemp.empty())
                cout << "Ignored" << endl;
            else
            {
                web = webstacktemp.top();
                webstacktemp.pop();
                webstackmain.push(web);
                cout << webstackmain.top() << endl;
            }
        }
    }
    return 0;
}