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
    bool isEndOfWord;
    TrieNode(char ch = '/'):data(ch), isEndOfWord(false)
    {
        memset(children,NULL,sizeof(TrieNode*) * charNum);
    }
    ~TrieNode(){}
};
class Trie
{
public:
    TrieNode* root;
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
};
int main()
{
    Trie textlib;
    textlib.insert("hello");
    textlib.insert("world");
    cout << textlib.find("hello") << " " << textlib.find("he") << endl;
    return 0;
}