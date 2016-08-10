// 策略模式

// 在核心算法中，使用策略模式可以进行决策处理
// 对c++而言，通过继承体系中的多态本就是一种策略，其次。仿函数也是策略模式的实现
// 优点：自由切换算法
// 避免多重条件判断
// 扩展性良好

// 缺点：策略数量太多，类冗余
// 所有决策类都需要对外暴露

#include "afxstd.h"

class strategy
{
protected:
	strategy()
	{
		Trace("");
	}
public:
	virtual void algorithmInterface()=0;
	virtual ~strategy()
	{
		Trace("");
	}
};
class concreteStrategy1:public strategy
{
public:
	concreteStrategy1()
	{
		Trace("");
	}

	void algorithmInterface()
	{
		Trace("");
	}

	~concreteStrategy1()
	{
		Trace("");
	}
};

class concreteStrategy2:public strategy
{
public:
	concreteStrategy2()
	{
		Trace("");
	}

	void algorithmInterface()
	{
		Trace("");
	}

	~concreteStrategy2()
	{
		Trace("");
	}
};

class context
{
protected:
	strategy & st;
public:
	context(strategy & _st)
	:st(_st)
	{
		Trace("");
	}	

	void doAnything()
	{
		Trace("");
		st.algorithmInterface();
	}

	~context()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	strategy * st = new concreteStrategy1();
	// strategy * st = new concreteStrategy2();
	context* con = new context(*st);	

	con->doAnything();
	return 0;
}