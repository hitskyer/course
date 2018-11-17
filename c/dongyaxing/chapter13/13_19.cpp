#include<set>
#include<string>

class Folder;
class Message
{
public:
	//folders自动初始化空集
	Message(const std::string &str = ""):contents(str) { }    // 提供默认实参。可以作为默认构造函数
	
	//复制控制成员
	Message(const Message&);
	Message& operator = (const Message&);
	~Message();
	
	//在指定Folder的消息集中增加/删除该消息
	void save(Folder&);
	void remove(Folder&);

	//在包含该消息的目录中集中增加/删除指定Folder
	void addFldr(Folder*);
	void remFldr(Folder*);

private:
	std::string contents;  //存储实际消息
	//指向Message所在的Folder的指针
	std::set<Folder*> folders;   //包含该消息的目录
	
	//复制构造函数、赋值、析构函数所使用的实用函数
	//将消息加到形参所指的目录集中
	void put_Msg_in_Folders(const std::set<Folder*>&); //（隐式）将Folder的set初始化为空集
	void remove_Msg_form_Folders();   //用于赋值操作符和析构函数，从folder中删除指向这个message的指针
};

//复制构造函数将旧对象成员的副本初始化新对象的数据成员。
Message::Message(const Message &m):contents(m.contents), folders(m.folders)
{
	//将该消息加到指向m的每个目录中
	put_Msg_in_Floders(folders);
}

//将该消息加到rhs所指的目录及中
void Message::put_Msg_in_Folders(const set<Folder*> &ths)
{
	for(std::set<Folder*>::const_iterator beg = rhs.begin();
		beg!=rhs.end(); ++beg)
	{
		(*beg)->addMsg(this);    //*beg 指针的指针
	}
}

Message& Message::operator = (const Message &rhs)
{
	if(&rhs != this)
	{
		remove_Msg_from_Folders();	//更新现有目录
		contents = rhs.contents;	//从rhs复制消息内容
		folders rhs.folders;		//从ths复制目录指针集
		//将该消息加到中的每个目录中
		put_Msg_in_Folders(rhs.folders);
	}
	return *this;
}

//从对应目录中删除该消息
void Message::remove_Msg_from_Folders()
{
	for(std::set<Folders*>::const_iterator beg = folders.begin();
		beg!=folders.eng(); ++beg)
	{ (*beg)->remMsg(this); }	//*beg指向一个目录
}

//复制控制函数是析构函数
Message::~Message()
{
	remove_Msg_from_Floders();
}

void Message::save(Folder& fldr)
{
	remFldr(&fldr);
	fldr.addMsg(this);	//更新相应的目录
}

void Message::remove(Folder& rldr)
{
	remFldr(&fldr);
	fldr.remMsg(this);	//更新相应的目录
}

void Message::addFldr(Folder* fldr)
{
	folders.insert(fldr);
}

void Message::remFldr(Folder* fldr)
{
	folders.erase(fldr);
}

class Folder
{
public:
	Folder() {}
	//复制控制成员
	Folder(const Folder&);
	Folder& operator = (const Folder&);
	~Folder();

	//在指定Message的目录集中增加/删除该目录
	void save (Message&);
	void remove(Message&);

	//在该目录的消息集中增加/删除指定Message
	void addMsg(Message*);
	void remMsg(Message*);
private:
	std::set<Message*> messages;   //该目录中的消息集
	//复制控制成员所使用的实用函数：
	//将目录加到形参所指的消息集中
	void put_Fldr_in_Messages(const std::set<Message*>&);

	//从目录所指的所有消息中删除该目录
	void remove_Fldr_from_Messages();
};

Floder::Folder(const Folder &f);
messages(f.messages)
{
	//将目录加到f所指向的每个消息中
	put_Fldr_in_Messages(messages);
}

//将该目录加到rhs所指的消息集中
void  Folder::put_Fldr_in_Messages(const std::set<Message*> &rhs)
{
	for(std::set<Message*>::const_iterator beg = rhs.begin();beg!=rhs.end();++beg)
		(*beg)->addFldr(this);  //*beg指向一个消息
}

Folder& Folder::operator=(const Folder &rhs)
{
	if(&rhs != this)
	{
		remove_Fldr_from_Messages();	//更新现有消息
		messages = rhs.messages;	//从rhs复制消息指针集
		//将该目录加到rhs中的每个消息中
		put_Fldr_in_Messages(rhs.messages);
	}
	return *this;
}

//从对应消息中删除该目录
void Folder::remove_Fldr_from_Messages()
{
	//从对应消息中删除该目录
	for(std::set<Message*>::const_iterator beg = messages.begin();beg!=messages.end();++beg)
		(*beg)->remFldr(this);	//*beg指向一个消息
}

Folder::~Folder()
{
	remove_Fldr_from_Messages();
}

void Folder::save(Message& msg)
{
	addMsg(&msg);
	msg.addFldr(this);	//更新相应的消息
}

void Folder::remove(Message& msg)
{
	remMsg(&msg);
	msg.remFldr(this);	//更新相应的消息
}

void Folder::addMsg(Message* msg)
{
	messages.insert(msg);
}

void Folder::remMsg(Message* msg)
{
	messages.erase(msg);
}
