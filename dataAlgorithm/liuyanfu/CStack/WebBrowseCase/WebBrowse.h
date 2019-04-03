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
	void browseWeb(const char *);
	void displayCurWeb(const char *);
private:
	TmpStack<const char *> fstk;
	TmpStack<const char *> bstk;
};


#endif //_WEB_BROWSE_H