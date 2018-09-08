#include<string>
#include<iostream>
using namespace std;
int main()
{
    string str = "ab2c3d7R4E6";
    string num = "0123456789";
    string letters = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string::size_type position = 0;
    cout << string::npos << endl;
    cout << str.size() << endl;
    // cin >> letters;
    while((position = str.find_first_of(num,position)) != string::npos)
    {
        cout << str[position] << " ";
        ++position;
    }
    cout << endl;
    position = 0;
    while((position = str.find_first_of(letters,position)) != string::npos)
    {
        cout << str[position] << " ";
        ++position;
    }
    cout << endl;
    position = 0;
    while((position = str.find_first_not_of(letters,position)) != string::npos)
    {
        cout << str[position] << " ";
        ++position;
    }
    cout << endl;
    position = 0;
    while((position = str.find_first_not_of(num,position)) != string::npos)
    {
        cout << str[position] << " ";
        ++position;
    }
    cout << endl;
}