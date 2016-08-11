// 状态模式：
// 状态中包含环境指针
// 环境中包含状态引用。
// 状态的指向是稳定的。
// c++和java的差异。恶心，某些步骤是可以省略的

// 环境包含状态下的所有行为。
// context-》do --cur-》do --》stat-》setcur-》cur-》do



// 状态模式

#include "afxstd.h"

class context;
class state
{
protected:
	context *con;
	state()
	{
		Trace("");
	}
public:
	virtual void setContext(context*c)=0;
	virtual void handler1()=0;
	virtual void handler2()=0;
	~state()
	{
		Trace("");
	}
};

class context
{
public:
	state& s1;
 	state& s2;
	state* cur;
	context(state&s1,state&s2)
	:s1(s1)
	,s2(s2)
	,cur(NULL)
	{
		s1.setContext(this);
		s2.setContext(this);
		Trace("");
	}
	state* getCur()
	{
		return cur;
	}
	void setCur(state* c)
	{
		Trace("");
		cur = c;
	}
	void handler1()
	{
		Trace("");
		cur->handler1();
	}
	void handler2()
	{
		Trace("");
		cur->handler2();
	}
	~context()
	{
		Trace("");
	}
};

class concreteState1:public state
{
public:
	concreteState1()
	{
		Trace("");
	}
	void setContext(context*c)
	{
		Trace("");
		con = c;
	}
	void handler1()
	{
		Trace("");
	}
	void handler2()
	{
		Trace("");
		 con->setCur(&(con->s2));
		 con->handler2();
	}
	~concreteState1()
	{
		Trace("");
	}
};

class concreteState2:public state
{
public:
	friend class context;
	concreteState2()
	{
		Trace("");
	}
	void setContext(context*c)
	{
		Trace("");
		con = c;
	}
	void handler1()
	{
		Trace("");
		con->setCur(&(con->s1));
		con->handler1();
	}
	void handler2()
	{
		Trace("");
	}
	~concreteState2()
	{
		Trace("");
	}
};


int main(int argc, char const *argv[])
{
	state* s1 = new concreteState1();
	state* s2 = new concreteState2();
	context x(*s1,*s2);
	x.setCur(&(x.s1));
	cout <<endl;
	x.handler2();
	x.handler1();
	return 0;
}