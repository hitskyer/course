/**
 * @description: trie树，字典树
 * @author: michael ming
 * @date: 2019/6/24 19:00
 * @modified by: 
 */
#include <iostream>
#include <cstring>
#include <stack>

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
public:
    TrieNode* root;
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
        p->count++;
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
    bool delString_1(const string &text)
    {
        TrieNode *p = root;
        stack<TrieNode*> nodeStack;
        nodeStack.push(root);
        int index;
        for(int i = 0; i < text.size(); ++i)
        {
            index = text[i] - 'a';
            if(p->children[index] == NULL)
                return false;//还没匹配完
            p = p->children[index];
            nodeStack.push(p);
        }
        if(p->isEndOfWord == false)//匹配完，但是只是前缀
            return false;
        else
        {
            while(nodeStack.top()->count == 1)//删除单词只要自己包含的部分
            {
                index = nodeStack.top()->data - 'a';
                cout << "要删的是：" << nodeStack.top()->data << endl;
                delete nodeStack.top();
                nodeStack.pop();
            }
            nodeStack.top()->children[index] = NULL;//断开已删除的部分
            while(!nodeStack.empty())
            {
                nodeStack.top()->count--;//单词占用记录减1
                nodeStack.pop();
            }
            return true;
        }
    }
    size_t itemCount()
    {
        return root->count;
    }
    void print(TrieNode *proot)
    {
        if(proot == NULL)
            return;
        cout << proot->data << endl;
        for(int i = 0; i < charNum; ++i)
            print(proot->children[i]);
    }
};
int main()
{
    Trie textlib;
    textlib.insert("hello");
    textlib.insert("her");
    textlib.insert("world");
    textlib.print(textlib.root);
    cout << textlib.find("hello") << " " << textlib.find("her") << endl;
    cout << textlib.delString_1("hello") << endl;
    cout << textlib.find("her") << " " << endl;
    cout << "共有：" << textlib.itemCount() << "个单词。" << endl;
    return 0;
}