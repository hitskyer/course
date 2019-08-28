/**
 * @description: 位图
 * @author: michael ming
 * @date: 2019/8/6 23:26
 * @modified by: 
 */
#include <iostream>
#include <cstring>
using namespace std;
class BitMap
{
    char *bytes;    //char是1字节，8位
    int nbits;
public:
    BitMap(int n)
    {
        nbits = n;
        bytes = new char [nbits/8 + 1];
        memset(bytes, 0, (nbits/8+1)*sizeof(char));
    }
    ~BitMap()
    {
        delete [] bytes;
    }
    void set(int k)
    {
        if(k > nbits)
            return;
        int byteIndex = k/8;
        int bitIndex = k%8;
        bytes[byteIndex] |= (1<<bitIndex);
    }
    bool get(int k)
    {
        if(k > nbits)
            return false;
        int byteIndex = k/8;
        int bitIndex = k%8;
        return (bytes[byteIndex] & (1 << bitIndex)) != 0;
    }
    void print()
    {
    	for(int i = 15; i >= 0; --i)
    		cout << get(i) << " ";
    }
};
int main()
{
    BitMap bm(8);
    bm.set(8);
    cout << bm.get(8) << endl;
    bm.print();
    return 0;
}