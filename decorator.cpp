// 装饰模式decorator
// 优点：装饰类和被装饰类可独立发展，不耦合
// 是继承的一个替代品
// 可以动态扩展一个实现类的功能
// 缺点：洋葱一层层

// 使用场景：
// 动态扩展功能/附加功能
// 动态给对象增加功能，功能可以再撤销

// vs继承(静态功能增加)--动态功能增加。扩展性

#include "afxstd.h"

class component
{
protected:
	component()
	{
		Trace("");
	}
public:
	virtual void operation()=0;
	~component()
	{
		Trace("");
	}
};
class concreteComponent:public component
{
public:
	concreteComponent()
	{
		Trace("");
	}
	void operation()
	{
		Trace("");
	}

	~concreteComponent()
	{
		Trace("");
	}
};

class decorator:public component
{
protected:
	component &com;
public:
	decorator(component& _com)
	:com(_com)
	{
		Trace("");
	}
	void operation()
	{
		Trace("");
		com.operation();
	}
	~decorator()
	{
		Trace("");
	}
};

class concreteDecorator:public decorator
{
public:
	concreteDecorator(component& _com)
	:decorator(_com)
	{
		Trace("");
	}

	void operation()
	{
		Trace("");
		method();
		decorator::operation();
	}

	void method()
	{
		Trace("");
	}
	~concreteDecorator()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	component * com = new concreteComponent();

	com = new concreteDecorator(*com);
	com->operation();

	return 0;
}