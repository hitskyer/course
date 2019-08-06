/**
 * @description: 位图
 * @author: michael ming
 * @date: 2019/8/6 23:26
 * @modified by: 
 */
#include <iostream>
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
};
int main()
{
    BitMap bm(8);
    bm.set(8);
    cout << bm.get(8);
    return 0;
}