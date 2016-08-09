//父类定义方法流程，子类差异实现
//对于父类定义的方法流程，子类可以有钩子/句柄确定是否执行
// 优点：
// 封装变化，拥抱变化，扩展性，维护性，行为父类控制，子类实现。///父类依赖子类

// 使用场景：
// 子类共有方法相同。逻辑相同。
// 核心算法
// 重构

// #define	_NOTRACE
#include "afxstd.h"

class templateMethod
{
public:
	templateMethod(bool ischose = true)
	:_ischose(ischose)
	{
		Trace("");
	}
	void run()
	{
		before();

		first();

		if(_ischose)
		{
			chose();
		}

		second();

		after();
	}
protected:
	void before()
	{
		Trace("");
	}
	void after()
	{
		Trace("");
	}
public:
	virtual void first()=0;
	virtual void second()=0;
	virtual void setchose(bool ischose)=0;
	virtual void chose()=0;
	virtual ~templateMethod()
	{
		Trace("");
	}
protected:
	bool _ischose;
};
class concreteMethod1:public templateMethod
{
public:
	void first()
	{
		Trace("");
	}
	void chose()
	{
		Trace("");
	}
	void setchose(bool ischose)
	{
		_ischose = ischose;
	}
	void second()
	{
		Trace("");
	}
	concreteMethod1(bool ischose = false)
	:templateMethod(ischose)
	{
		Trace("");
	}
	virtual ~concreteMethod1()
	{
		Trace("");
	}
};
class concreteMethod2:public templateMethod
{
public:
	void first()
	{
		Trace("");
	}
	void second()
	{
		Trace("");
	}
	void chose()
	{
		Trace("");
	}
	concreteMethod2(bool ischose = true)
	:templateMethod(ischose)
	{
		Trace("");
	}
	void setchose(bool ischose)
	{
		_ischose = ischose;
	}
	virtual ~concreteMethod2()
	{
		Trace("");
	}
};
int main(int argc, char const *argv[])
{
	templateMethod* p1 = new concreteMethod1();
	templateMethod* p2 = new concreteMethod2();

	p1->run();
	p2->run();
	cout << "setchose"<<endl;
	p2->setchose(false);
	p2->run();
	return 0;
}

