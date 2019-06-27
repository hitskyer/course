/**
 * @description: AC自动机
 * @author: michael ming
 * @date: 2019/6/27 2:03
 * @modified by: 
 */
#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#define charNum 26
using namespace std;
class ACNode    //AC自动机的Trie树节点类,假设只有26个字母的数据集
{
public:
    char data;
    ACNode *children[charNum];
    size_t count;   //记录这个节点被多少个单词占用
    bool isEndOfWord;//是否是一个单词的结束字符
    size_t freq;    //单词插入的频次
    int length;     //当isEndOFWord为True时，记录模式串长度
    ACNode *fail; //失败指针
    ACNode(char ch = '/'):data(ch), isEndOfWord(false),
                            count(0), freq(0),length(-1),fail(NULL)
    {
        memset(children,0,sizeof(ACNode*) * charNum);
    }
    ~ACNode(){}
};
class Trie
{
public:
    ACNode* root;
    Trie()
    {
        root = new ACNode;
    }
    ~Trie()
    {
        destory(root);
    }
    void buildFailPointer()
    {
        queue<ACNode*> ACNode_queue;
        ACNode_queue.push(root);
        ACNode *p, *pchild, *q, *qchild;
        int i;
        while(!ACNode_queue.empty())//用队列按层遍历
        {
            p = ACNode_queue.front();//队首的节点p
            ACNode_queue.pop();
            for(i = 0; i < charNum; ++i)
            {
                pchild = p->children[i];//找到p的非空子节点pc
                if(pchild == NULL)
                    continue;
                if(p == root)
                    pchild->fail = root;
                else
                {
                    q = p->fail;    //q为p的失效指针
                    while(q != NULL)    //q不为空
                    {
                        qchild = q->children[pchild->data-'a'];//字符等于pc的qc
                        if(qchild != NULL)//qc存在
                        {
                            pchild->fail = qchild;//链接pc失败指针到qc
                            break;//找到了就跳出循环
                        }
                        q = q->fail;//qc不存在，就再去上一个失效点找
                    }
                    if(q == NULL)//最后找到root处还没找到
                        pchild->fail = root;//pc的失效指针指向root
                }
                ACNode_queue.push(pchild);//把p的非空子节点pc入队
            }
        }
    }
    void match(const string &maintext)  //maintext是主串
    {
        int n = maintext.size();
        ACNode *p = root, *temp;//模式串从root开始
        int index, pos;
        for(int i = 0; i < n; ++i)//主串从i=0开始
        {
            index = maintext[i]-'a';//子节点下标
            while(p->children[index] == NULL && p != root)
            {//p不为root，且 子节点为空（找不到那个i对应的字符）
                p = p->fail;    //失败指针发挥作用的地方
            }
            p = p->children[index];
            if(p == NULL)
                p = root;   //如果没有匹配的，从root开始重新匹配
            temp = p;
            while(temp != root)//打印出可以匹配的模式串
            {
                if(temp->isEndOfWord == true)
                {
                    pos = i-temp->length+1;
                    cout << "Found " << maintext.substr(pos,temp->length) << " at "
                         "position(start from 0) "<< pos << " at " << maintext << endl;
                }
                temp = temp->fail;
            }
        }
    }
    void insert(const string &text)//插入一个字符串
    {
        ACNode *p = find_private(text);
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
                ACNode *newNode = new ACNode(text[i]);
                p->children[index] = newNode;
            }
            p->count++;
            p = p->children[index];
        }
        p->count++;
        p->freq++;
        p->isEndOfWord = true;
        p->length = text.size();
    }
    void find(const string &text) const//查找某个字符串
    {
        ACNode *p = root;
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
    ACNode* find_private(const string &text) const//查找某个字符串,返回最后一个字符节点的指针
    {
        ACNode *p = root;
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
    void destory(ACNode* proot)//树不再使用，结束前，释放资源
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
        ACNode *p = root;
        stack<ACNode*> nodeStack;
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
    size_t itemCount() const//字典中单词种数
    {
        return root->count;
    }
    void printStrWithPre(const string prefix) const//打印有指定前缀的单词
    {
        if(prefix.size() == 0)
            return;
        ACNode *p = root;
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
    void printDict() const//字典序输出全部单词
    {
        string word("");
        int printID = 0;
        cout << "-------------------------" << endl;
        cout << "all " << itemCount() << " words as following:" << endl;
        printWordsOfNode(root,word,printID);
        cout << "-----------end-----------" << endl;
    }
private:
    void printWordsOfNode(ACNode* p, string prefix, int &order) const
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
    string a("abcd"), b("bcd"), c("c");
    textlib.insert(a);
    textlib.insert(a);
    textlib.insert(b);
    textlib.insert(c);
    textlib.buildFailPointer();
    textlib.match("abcdc");
    textlib.find(a);
    textlib.find(b);
    textlib.printStrWithPre("a");
    textlib.printDict();
    textlib.delString("c");
    textlib.find(a);
    textlib.printStrWithPre("c");
    textlib.printDict();
    cout << "total kind(s) of word: " << textlib.itemCount() << endl;
    return 0;
}