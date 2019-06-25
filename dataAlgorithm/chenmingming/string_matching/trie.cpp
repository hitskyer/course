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
    bool isEndOfWord;//是否是一个单词的结束字符
    size_t freq;    //单词插入的频次
    TrieNode(char ch = '/'):data(ch), isEndOfWord(false), count(0), freq(0)
    {
        memset(children,0,sizeof(TrieNode*) * charNum);
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
        TrieNode *p = find_private(text);
        if(p)//找到了字符串，不用插入，频次加1
        {
            p->freq++;
            return;
        }
        p = root;
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
        p->freq++;
        p->isEndOfWord = true;
    }
    void find(const string &text) const//查找某个字符串
    {
        TrieNode *p = root;
        int index;
        for(int i = 0; i < text.size(); ++i)
        {
            index = text[i] - 'a';
            if(p->children[index] == NULL)//还没匹配完
            {
                cout << "can not find string: " << text << endl;
                return;
            }
            p = p->children[index];
        }
        if(p->isEndOfWord == false)//匹配完，但是只是前缀
        {
            cout << "can not find string: " << text << endl;
            return;
        }
        else
        {
            cout << text << " occurs " << p->freq << " time(s)." << endl;
            return;
        }
    }

private:
    TrieNode* find_private(const string &text) const//查找某个字符串,返回最后一个字符节点的指针
    {
        TrieNode *p = root;
        int index;
        for(int i = 0; i < text.size(); ++i)
        {
            index = text[i] - 'a';
            if(p->children[index] == NULL)
                return NULL;//还没匹配完
            p = p->children[index];
        }
        if(p->isEndOfWord == false)//匹配完，但是只是前缀
            return NULL;
        else
        {
            return p;//私有find无输出信息
        }
    }

public:
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
                cout << "del char: " << nodeStack.top()->data << endl;
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
    size_t itemCount()//字典中单词种数
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
    string a("hello"), b("her"), c("world"), d("he");
    textlib.insert(a);
    textlib.insert(a);
    textlib.insert(b);
    textlib.insert(c);
//    textlib.print(textlib.root);
    textlib.find(a);
    textlib.find(b);
    textlib.find(d);
    textlib.delString("hello");
    textlib.find(a);
    textlib.find("her");
    cout << "total kind(s) of word: " << textlib.itemCount() << endl;
    return 0;
}