#include<set>
#include<string>
class Message;
#ifndef FOLDER_H
#define FOLDER_H
class Folder
{
public:
    Folder(){}
    //复制控制成员函数声明
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    //在所有folder里增加/删除message
    void save(Message&);
    void remove(Message&);
    //在folder里增加/删除某个message
    void addMsg(Message*);
    void remMsg(Message*);
private:
    std::set<Message*> messages;	//message里是所有消息的地址
    //把消息的地址添加到消息中
    void put_fldr_in_messages(const std::set<Message*>&);
    //从目录所指的所有消息中删除该目录
    void remove_fldr_from_messages();
};
#endif