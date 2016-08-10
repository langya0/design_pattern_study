//同事角色有自发行为/依赖中介行为
//同事必须确定是否通过中介，所以构造注入
//中介可以选则同事，所以set方式注入依赖

//中介者依赖具体同事类，而非抽象

//具体同事类自发行为自己处理。
// 依赖行为调用内部中介方法
// 中介方法处理融合逻辑
#include "afxstd.h"
class colleague2;
class colleague1;

class mediator
{
protected:
	colleague2* pc2;
	colleague1* pc1;
public:
	colleague1* getc1()
	{
		return	pc1;
	}
	colleague2* getc2()
	{
		return	pc2;
	}
	void setc1(colleague1* c1)
	{
		pc1 = c1;
	}
	void setc2(colleague2* c2)
	{
		pc2 = c2;
	}

protected:
	friend class colleague1;
	friend class colleague2;
	virtual void dosomething1()=0;
	virtual void dosomething2()=0;
	mediator(){
		Trace("");
	}
	~mediator(){
		Trace("");
	}
};
class colleague
{
protected:
	mediator& _me;
	colleague(mediator & me)
	:_me(me)
	{
		Trace("");
	}
public:
	virtual ~colleague()
	{
		Trace("");
	}
};

class colleague1:public colleague
{
public:
	colleague1(mediator& me)
	:colleague(me)
	{
		Trace("");
	}

	void selfMethod2()
	{
		Trace("");
	}
	void selfMethod1()
	{
		Trace("");
	}
	void depMethod1()
	{
		Trace("");
		_me.dosomething1();
	}
	~colleague1()
	{
		Trace("");
	}
};

class colleague2:public colleague
{
public:
	colleague2(mediator& me)
	:colleague(me)
	{
		Trace("");
	}
	void selfMethod2()
	{
		Trace("");
	}
	void selfMethod1()
	{
		Trace("");
	}
	void depMethod2()
	{
		Trace("");
		_me.dosomething2();
	}
	~colleague2()
	{
		Trace("");
	}
};

class concreteMediator:public mediator
{
public:
	concreteMediator()
	{
		Trace("");
	}
	~concreteMediator()
	{
		Trace("");
	}
	void dosomething1()
	{
		Trace("");
		pc1->selfMethod1();
		pc2->selfMethod2();
	}
	void dosomething2()
	{
		Trace("");
		pc1->selfMethod1();
		pc2->selfMethod2();
	}
	
};
int main(int argc, char const *argv[])
{
	mediator* me = new concreteMediator();

	colleague1* c1 = new colleague1(*me);
	colleague2* c2 = new colleague2(*me);
	me->setc1(c1);
	me->setc2(c2);

	// me->dosomething1();
	// me->dosomething2();

	c1->depMethod1();
	c1->selfMethod1();


	// c1->test();
	// c2->test();
	return 0;
}