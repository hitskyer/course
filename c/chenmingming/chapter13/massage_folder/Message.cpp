#include"Message.h"
#include"Folder.h"

Message::Message(const Message &m):contents(m.contents),folders(m.folders)
{
    put_Msg_in_folders(folders);
}

void Message::put_Msg_in_folders(const std::set<Folder*> &rhs)
{
    for(std::set<Folder*>::const_iterator beg = rhs.begin();
        beg != rhs.end();++beg)
    {
        (*beg)->addMsg(this);
    }
}

Message& Message::operator=(const Message &rhs)
{
    if(&rhs != this)
    {
        remove_Msg_from_folders();
        contents = rhs.contents;
        folders = rhs.folders;
        put_Msg_in_folders(rhs.folders);
    }
    return *this;
}

void Message::remove_Msg_from_folders()
{
    for(std::set<Folder*>::const_iterator beg = folders.begin();
        beg != folders.end();++beg)
    {
        (*beg)->remMsg(this);
    }
}

void Message::save(Folder& fldr)
{
    addfldr(&fldr);
    fldr.addMsg(this);
}
void Message::remove(Folder& fldr)
{
    remfldr(&fldr);
    fldr.remMsg(this);
}

void Message::addfldr(Folder* fldr)
{
    folders.insert(fldr);
}
void Message::remfldr(Folder* fldr)
{
    folders.erase(fldr);
}
Message::~Message()
{
    remove_Msg_from_folders();
}