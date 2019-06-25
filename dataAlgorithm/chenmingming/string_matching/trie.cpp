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
//                cout << "del char: " << nodeStack.top()->data << endl;//(调试代码)
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
    void printStrWithPre(const string prefix)//打印有指定前缀的单词
    {
        if(prefix.size() == 0)
            return;
        TrieNode *p = root;
        int index,printID = 0;
        for(int i = 0; i < prefix.size(); ++i)
        {
            index = prefix[i] - 'a';
            if(p->children[index] == NULL)//前缀还没匹配成功
            {
                cout << "-------------------------" << endl;
                cout << "no string with prefix: " << prefix << " can be found!" << endl;
                return;
            }
            else
                p = p->children[index];
        }//匹配完了，p指向前缀最后一个字符节点
        cout << "-------------------------" << endl;
        cout << p->count << " string(s) with prefix: " << prefix << " , as following:" << endl;
        printWordsOfNode(p,prefix,printID);
        cout << "-----------end-----------" << endl;
    }
    void printDict()//字典序输出全部单词
    {
        string word("");
        int printID = 0;
        cout << "-------------------------" << endl;
        cout << "all " << itemCount() << " words as following:" << endl;
        printWordsOfNode(root,word,printID);
        cout << "-----------end-----------" << endl;
    }
private:
    void printWordsOfNode(TrieNode* p, string prefix, int &order)
    {//递归打印前缀最后一个字符对应节点下面所有的字符
        if(!p->isEndOfWord)
        {
            for(int i = 0; i < charNum; ++i)
            {
                if(p->children[i] != NULL)
                    printWordsOfNode(p->children[i],prefix+(p->children[i]->data),order);
            }
        }
        else    //是终止字符，prefix是不断+出来的，是整个字符串
            cout << ++order << " " << prefix << ", frequency: " << p->freq << endl;
    }
};
int main()
{
    Trie textlib;
    string a("hello"), b("her"), c("so"), d("hi"), e("how"), f("see");
    textlib.insert(a);
    textlib.insert(a);
    textlib.insert(b);
    textlib.insert(c);
    textlib.insert(d);
    textlib.insert(e);
    textlib.insert(f);
    textlib.find(a);
    textlib.find(b);
    textlib.find(d);
    textlib.printStrWithPre("h");
    textlib.printDict();
    textlib.delString("hello");
    textlib.find(a);
    textlib.printStrWithPre("h");
    textlib.printDict();
    cout << "total kind(s) of word: " << textlib.itemCount() << endl;
    return 0;
}