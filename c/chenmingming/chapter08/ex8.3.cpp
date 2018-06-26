#include<iostream>
#include <stdexcept>
using namespace std;
istream& getword(istream& i)
{
        int ival;
        while(i >> ival, !i.eof())
        {
                if(i.bad())
                        throw runtime_error("IO stream wrong!");
                if(i.fail())
                {
                        cerr << "bad data , try again !";
                        i.clear();
                        i.ignore(200,' ');
                        continue;
                }
        cout << ival << " ";
        }
        i.clear();
        return i;
}
