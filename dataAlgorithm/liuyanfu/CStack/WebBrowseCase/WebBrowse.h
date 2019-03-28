#ifndef _WEB_BROWSE_H
#define _WEB_BROWSE_H
#include "TmpStack.cpp"

class WebBrowse
{
public:
	WebBrowse(void);
	~WebBrowse(void);
	void forward();
	void back();
	void browseWeb(char *);
	void displayCurWeb(char *);
private:
	TmpStack<char *> fstk;
	TmpStack<char *> bstk;
};


#endif //_WEB_BROWSE_H