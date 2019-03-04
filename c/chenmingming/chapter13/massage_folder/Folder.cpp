#include"Folder.h"
#include"Message.h"

Folder::Folder(const Folder &f):messages(f.messages)
{
    put_fldr_in_messages(messages);
}

void Folder::put_fldr_in_messages(const std::set<Message*> &rhs)
{
    for(std::set<Message*>::const_iterator beg = rhs.begin();
        beg != rhs.end();++beg)
    {
        (*beg)->addfldr(this);
    }
}

Folder& Folder::operator=(const Folder &rhs)
{
    if(&rhs != this)
    {
        remove_fldr_from_messages();
        messages = rhs.messages;
        put_fldr_in_messages(rhs.messages);
    }
    return *this;
}

void Folder::remove_fldr_from_messages()
{
    for(std::set<Message*>::const_iterator beg = messages.begin();
        beg != messages.end();++beg)
    {
        (*beg)->remfldr(this);
    }
}
Folder::~Folder()
{
    remove_fldr_from_messages();
}
void Folder::save(Message& msg)
{
    addMsg(&msg);
    msg.addfldr(this);
}
void Folder::remove(Message& msg)
{
    remMsg(&msg);
    msg.remfldr(this);
}
void Folder::addMsg(Message* msg)
{
    messages.insert(msg);
}
void Folder::remMsg(Message* msg)
{
    messages.erase(msg);
}