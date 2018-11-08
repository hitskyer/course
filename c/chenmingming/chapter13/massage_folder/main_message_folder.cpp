#include"Message.h"
#include"Folder.h"

int main()
{
	Message msg1("msg1 "),msg2("msg2 "),msg3;
	msg3 = Message(msg2);
	Folder folder1,folder2;
	folder2 = Folder(folder1);
	msg1.save(folder1);
	msg2.save(folder1);
	msg2.remove(folder1);
	msg1.addfldr(&folder2);
	msg3.addfldr(&folder2);
	msg3.remfldr(&folder2);
	folder2.save(msg2);
	folder2.save(msg3);
	folder2.remove(msg3);
	folder2.addMsg(&msg3);
	folder2.remMsg(&msg3);
	return 0;
}