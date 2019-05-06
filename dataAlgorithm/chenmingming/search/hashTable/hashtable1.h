/**
 * @description: 哈希表，开放寻址--线性探测法
 * @author: michael ming
 * @date: 2019/5/6 10:26
 * @modified by: 
 */
#ifndef SEARCH_HASHTABLE1_H
#define SEARCH_HASHTABLE1_H
#include <iostream>
enum KindOfItem {Empty, Active, Deleted};
template <class DataType>
struct HashItem
{
    DataType data;
    KindOfItem info;
    HashItem<DataType>(KindOfItem i = Empty):info(i){}
    HashItem<DataType>(const DataType &d, KindOfItem i = Empty):data(d), info(i){}
    int operator== (HashItem<DataType> &a)
    {
        return data == a.data;
    }
    int operator!= (HashItem<DataType> &a)
    {
        return data != a.data;
    }
};
template <class DataType>
class hashtable1
{
private:
    HashItem<DataType> *ht; //散列表数组
    int TableSize;  //散列表长度
    int currentSize;    //当前表项个数
    int deletedSize;    //删除标记的元素个数
public:
    hashtable1<DataType>(int m)
    {
        TableSize = m;
        ht = new HashItem<DataType> [TableSize];
        currentSize = 0;
        deletedSize = 0;
    }
    ~hashtable1<DataType>()
    {
        delete [] ht;
    }
    int hash(const DataType &newData) const
    {
        return newData%TableSize;   //留余数法
    }
    int find(const DataType &x) const;
    int find_de(const DataType &x) const;   //当有deleted标记的元素时，插入函数调用此查找
    int insert(const DataType &x);
    int delete_elem(const DataType &x);
    void print() const
    {
        for(int i = 0; i < TableSize; ++i)
        {
            std::cout << ht[i].data << " " << ht[i].info << "->";
        }
        std::cout << std::endl;
    }
    int isInTable(const DataType &x)
    {
        int i = find(x);
        return i >= 0 ? i : -1;
    }
    DataType getValue(int i) const
    {
        return ht[i].data;
    }
};
#endif //SEARCH_HASHTABLE1_H