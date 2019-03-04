#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
int main(int argc, char **argv)
{
    int ia[] = {1,2,3,4,99,5,99};
    list<int> ilist(ia,ia+7);
    vector<int> ivec;
    sort(ilist.begin(),ilist.end());
    unique_copy(ilist.begin(),ilist.end(),back_inserter(ivec));
    for(list<int>::iterator iter = ilist.begin();iter != ilist.end();++iter)
        cout << *iter << " ";
    cout << endl;
    for(vector<int>::iterator iter1 = ivec.begin();iter1 != ivec.end();++iter1)
        cout << *iter1 << " ";
    cout << endl;
    return 0;
}