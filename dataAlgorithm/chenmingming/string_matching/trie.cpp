/**
 * @description: trie树，字典树
 * @author: michael ming
 * @date: 2019/6/24 19:00
 * @modified by: 
 */
#include <iostream>
#include <cstring>
#define charNum 26
using namespace std;
class TrieNode//Trie树节点类,假设只有26个字母的数据集
{
public:
    char data;
    TrieNode *children[charNum];
    size_t count;//记录这个节点被多少个单词占用
    bool isEndOfWord;
    TrieNode(char ch = '/'):data(ch), isEndOfWord(false), count(0)
    {
        memset(children,NULL,sizeof(TrieNode*) * charNum);
    }
    ~TrieNode(){}
};
class Trie
{
private:
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode;
    }
    ~Trie()
    {
        destory(root);
    }
    void insert(const string &text)//插入一个字符串
    {
        TrieNode *p = root;
        int index;
        for(int i = 0; i < text.size(); ++i)
        {
            index = text[i] - 'a';
            if(p->children[index] == NULL)
            {
                TrieNode *newNode = new TrieNode(text[i]);
                p->children[index] = newNode;
            }
            p->count++;
            p = p->children[index];
        }
        p->isEndOfWord = true;
    }
    bool find(const string &text)//查找某个字符串
    {
        TrieNode *p = root;
        int index;
        for(int i = 0; i < text.size(); ++i)
        {
            index = text[i] - 'a';
            if(p->children[index] == NULL)
                return false;//还没匹配完
            p = p->children[index];
        }
        if(p->isEndOfWord == false)//匹配完，但是只是前缀
            return false;
        else
            return true;
    }
    void destory(TrieNode* proot)//树不再使用，结束前，释放资源
    {
        if(proot == NULL)
        {
            return;
        }
        for(int i = 0; i < charNum; ++i)
        {
            destory(proot->children[i]);
        }
        delete proot;
        proot = NULL;
    }
    bool delString(const string &text)
    {
        if(!find(text))
            return false;
        TrieNode *p = root, *q = NULL;
        int i, index;
        bool flag = true;
        for(i = 0; i < text.size() && flag; ++i)
        {
            index = text[i] - 'a';
            if(p->children[index]->count == 1)
            {
                q = p;//记录下只有一个单词占用的节点(要删的起始节点)的父节点
                flag = false;//此处代码块只执行一次
            }
            p->count--;//单词占用记录减1
            p = p->children[index];
        }
        q->children[index] = NULL;//断开要删除的部分
       while(p != NULL)
       {
           index = text[i++] - 'a';
           q = p;
           p = p->children[index];
           cout << "要删的是：" << q->data << endl;
           delete q;//删除节点（conut为1的）
           q = NULL;
       }
        return true;
    }
    size_t itemCount()
    {
        return root->count;
    }
};
int main()
{
    Trie textlib;
    textlib.insert("hello");
    textlib.insert("her");
    textlib.insert("world");
    cout << textlib.find("hello") << " " << textlib.find("her") << endl;
    cout << textlib.delString("hello") << endl;
    cout << textlib.find("her") << " " << endl;
    cout << "共有：" << textlib.itemCount() << "个单词。" << endl;
    return 0;
}