#include<string>
#include<set>
class Folder;
#ifndef MESSAGE_H
#define MESSAGE_H
class Message
{
public:
    // 构造函数
    Message(const std::string &str = ""):contents(str){ }
    //复制控制成员
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    //在指定Folder的消息集中增加/删除该消息
    void save(Folder&);
    void remove(Folder&);
    //在包含该消息的目录集中增加/删除指定Folder
    void addfldr(Folder*);
    void remfldr(Folder*);
private:
    std::string contents;	//数据成员，文件内容
    std::set<Folder*> folders;	//一个消息的目录集
    //将消息加到形参所指的目录集中
    void put_Msg_in_folders(const std::set<Folder*>&);
    //从消息所在的所有目录中删除该消息
    void remove_Msg_from_folders();
};
#endif