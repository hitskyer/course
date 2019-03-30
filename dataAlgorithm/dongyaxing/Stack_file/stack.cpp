#include"stack.h"

Stack::Stack(void)
{
	m_pTop = nullptr;
	m_nStackLen = 0;
}

Stack::~Stack(void)
{
	Clear();
}

bool Stack::Empty() const
{
	return 0 == m_nStackLen;
}

void Stack::Clear()
{
	if(0 == m_nStackLen)
	{
		return;
	}
	else
	{
		while(m_pTop)
		{
			StackNode p;
			p = m_pTop->pNext;
			delete m_pTop;
			m_pTop = nullptr;
			m_pTop = p;
		}
		m_nStackLen = 0;
	}
}

StackNode Stack::GetTop() const
{
	return m_pTop;
}

UINT Stack::GetLength() const
{
	return m_nStackLen;
}

void Stack::Pop()
{
	if(nullptr != m_pTop)
	{
		StackNode p;
		p = m_pTop->pNext;
		delete m_pTop;
		m_pTop = nullptr;
		--m_nStackLen;
		m_pTop = p;
	}
	
}

void Stack::Push(int &data)
{
	StackNode p = new SNode;
	p->data = data;
	if(nullptr == m_pTop)
		p->pNext = nullptr;
	else
		p->pNext = m_pTop;
	m_pTop = p;
	++m_nStackLen;
}

void Stack::PrintStack()
{
	if(NULL == m_pTop)
	{
		return;
	}
	else
	{
		int index = 1;
		std::cout << "从栈顶到栈底元素以此为： " << std::endl;
		StackNode temp = m_pTop;
		while(temp)
		{
			std::cout << "第 " << index << " 个元素是： " << temp->data << std::endl;
			temp = temp->pNext;
			++index;
		}
	}
}
