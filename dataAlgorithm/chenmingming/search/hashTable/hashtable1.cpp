/**
 * @description: 哈希表，开放寻址--线性探测法
 * @author: michael ming
 * @date: 2019/5/6 10:26
 * @modified by: 
 */
#include "hashtable1.h"
template <class DataType>
int hashtable1<DataType>::find(const DataType &x) const
{
    int i = hash(x);
    int j = i;
    while(ht[j].info == Deleted || (ht[j].info == Active && ht[j].data != x))  //说明存在冲突
    {
        j = (j+1)%TableSize;    //用解决冲突的方法继续查找(开放定址法)
        if(j == i)
            return -TableSize;  //遍历整个散列表，未找到
    }
    if(ht[j].info == Active)
        return j;   //找到,返回正值
    else
        return -j;  //没找到，返回负值
}
template <class DataType>
int hashtable1<DataType>::find_de(const DataType &x) const   //当有deleted标记的元素时，插入函数调用此查找
{
    int i = hash(x);
    int j = i;
    while(ht[j].info == Active)  //说明存在冲突
    {
        j = (j+1)%TableSize;    //用解决冲突的方法继续查找(开放定址法)
        if(j == i)
            return -TableSize;  //遍历整个散列表，没有空位
    }
    return j;   //返回标记为Empty或者Deleted的位置
}
template <class DataType>
int hashtable1<DataType>::insert(const DataType &x)
{
    int i = find(x);
    if(i > 0)
        return 0;   //元素x已存在
    else if(i != -TableSize && !deletedSize)    //元素x不存在，且散列表未满(且没有deleted标记)
    {
        ht[-i].data = x;    //元素赋值
        ht[-i].info = Active;   //占用了，标记一下
        currentSize++;
        return 1;
    }
    else if(i != -TableSize && deletedSize)    //元素x不存在，且散列表未满(且有deleted标记)
    {
        int j = find_de(x);
        if(j >= 0)
        {
            if(ht[j].info == Deleted)
                deletedSize--;
            ht[j].data = x;    //元素赋值
            ht[j].info = Active;   //占用了，标记一下(删除标记改成占用标记 )
            currentSize++;
            return 1;
        }
        else
            return 0;
    }
    else return 0;
}
template <class DataType>
int hashtable1<DataType>::delete_elem(const DataType &x)
{
    int i = find(x);
    if(i >= 0)
    {
        ht[i].info = Deleted;   //找到了要删除的，标记删除
        currentSize--;
        deletedSize++;
        return 1;
    }
    else return 0;
}