// 实现一个动态代理的首要条件：被代理类必须实现一个接口
// 运行时模板确定被代理的对象，同时aop方式加入前置通知。
// 分层设计，handler代理指定对象行为。
// dynamic处理前置通知。返回给客户的实质是个handler

#include "afxstd.h"
class Subject
{
protected:
	Subject()
	{
		Trace("");
	}
public:
	virtual void dosomething(const string &str)=0;
	~Subject()
	{
		Trace("");
	}
};
class RealSubject1:public Subject
{
public:
	RealSubject1()
	{
		Trace("");
	}
	void dosomething(const string& str)
	{
		cout << "test"<<endl;
		cout << str <<endl;
	}
};
class RealSubject2:public Subject
{
public:
	RealSubject2()
	{
		Trace("");
	}
	void dosomething(const string& str)
	{
		cout << str <<endl;
	}
};

class InvocationHandler
{
public:
	InvocationHandler()
	{
		Trace("");
	}
	virtual void run(string args)=0;
	~InvocationHandler()
	{
		Trace("");
	}
	
};
//动态代理的handler类
class myInvocationHandler: public InvocationHandler
{
protected:
	//被代理的对象
	Subject * obj;
public:
	//通过构造函数传递一个对象
	myInvocationHandler(Subject* _obj)
	:obj(_obj)
	{
		Trace("");
	}
	// proxy->method(orgs);
	void run(string args)
	{
		// method.invoke(obj,args);
		obj->dosomething(args);
	}

	~myInvocationHandler()
	{
		Trace("");
	}

};

class iAdvice
{
public:
	iAdvice()
	{
		Trace("");
	}
	virtual void exec()=0;
	~iAdvice()
	{
		Trace("");
	}
	
};
class BeforeAdvice1:public iAdvice
{
public:
	void exec()
	{
		Trace("i am a BeforeAdvice11111111111111");
	}
};
class BeforeAdvice2:public iAdvice
{
public:
	void exec()
	{
		Trace("i am a BeforeAdvice2222222222222");
	}
};

template <class T>
class dynamicProxy
{
public:
	dynamicProxy()
	{
		Trace("");
	}
	~dynamicProxy()
	{
		Trace("");
	}
	static InvocationHandler* newProxyInstance()
	{
		if (true)
		{
			(new BeforeAdvice1())->exec();
		}
		return new myInvocationHandler(new T());
	}

};
// aop 连接点，执行行为/通知。横切面编程



int main(int argc, char const *argv[])
{
//	Subject *sub = new RealSubject();

	// InvocationHandler* handler = new myInvocationHandler(sub);
	// handler->run("tset");

	InvocationHandler*proxy =\
	 	dynamicProxy<RealSubject1>::newProxyInstance();
	proxy->run("test");
	cout << endl;

	InvocationHandler*proxy2 =\
	 	dynamicProxy<RealSubject2>::newProxyInstance();
	proxy2->run("twerwr");
	return 0;
}