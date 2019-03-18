//用单链表实现LRU策略   2019.3.17
#include <iostream>
#include <string>
using namespace std;
struct weburl
{
	string website;
	weburl *next;
	
};
class webList
{
	weburl *p_head;
	size_t cacheSize;
public:
	webList():p_head(new weburl),cacheSize(0)
	{
	    p_head->next = NULL;    //犯错，开始没有写这句，导致后面有的地方非法访问
	}
	~webList()
	{
	    eraseAll();
	    delete p_head;
	}
	void eraseAll()
    {
	    weburl *tempNode = p_head->next, *del_Node = NULL;
        while(tempNode != NULL)
        {
            del_Node = tempNode;
            delete del_Node;
            cacheSize--;
            tempNode = tempNode->next;
        }
    }
    weburl* get_head()
    {
	    return p_head;
    }
    weburl* find(string &str)
    {
	    weburl *tempNode = p_head;
	    while(tempNode->next != NULL)
        {
	        if(tempNode->next->website == str)
	            return tempNode;    //返回的是找到的节点的上一个节点
	        else
                tempNode = tempNode->next;
        }
	    return NULL;
    }
    size_t getCacheSize()
    {
	    return cacheSize;
    }
    void incrCacheSize()
    {
	    cacheSize++;
    }
    void decrCacheSize()
    {
	    cacheSize--;
    }
    void push_front(weburl *p)
    {
        p->next = p_head->next;
        p_head->next = p;
        incrCacheSize();
    }
    void move_to_front(weburl *p)
    {
        p->next = p_head->next;
        p_head->next = p;
    }
    void pop_back()
    {
	    weburl *p = p_head, *prev = NULL;
	    while(p->next != NULL)
        {
	        prev = p;
	        p = p->next;
        }
	    prev->next = NULL;
	    delete p;
	    decrCacheSize();
    }
    void printCacheList()
    {
	    cout << "the recently visit website: " << endl;
	    weburl *tempNode = p_head;
	    size_t i = 0;
	    while(tempNode->next != NULL)
        {
	        tempNode = tempNode->next;
	        cout << ++i << " " << tempNode->website << endl;
        }
    }
};
int main()
{
	char conti = 'y';
	size_t maxCacheSize = 5;
    string web;
    webList cacheList;
    while(conti == 'y' || conti == 'Y')
    {
        
        cout << "-------------------------------------------" << endl;
        cout << "please enter the weburl you want to visit: " << endl;
        cin >> web;
        weburl *tempNode = cacheList.find(web);
        weburl *head = cacheList.get_head();
        if (tempNode == NULL)    //没有找到，是新的访问记录
        {
            weburl *newWeb = new weburl;
            newWeb->website = web;
            newWeb->next = NULL;
            if (cacheList.getCacheSize() < maxCacheSize) //存储没满，直接加到队首
            {
                cacheList.push_front(newWeb);
            } else    //存储满了，删除队尾，插入新的到队首
            {
                cacheList.pop_back();
                cacheList.push_front(newWeb);
            }
        } else    //从已有的数据中找到了记录
        {
            if (tempNode == head);   //记录在第一条，则无需操作
            else {
                weburl *mvRecord = tempNode->next;
                tempNode->next = mvRecord->next;
                cacheList.move_to_front(mvRecord);
            }

        }
        cacheList.printCacheList();
        cout << "continue? y/n" << endl;
        cin >> conti;
        cin.get();
    }
    return 0;
}