// 单来源调用：一个产品的生产只能由特定的生产车间生产。不能通过其他方式实现

#include <iostream>
#include <stdio.h>
using namespace std;
#include "../trace.h"
// base只能由driver产生,不能由其他途径产生
// 分解1
// 不能主动建立----protected屏蔽构造
// 留下的问题。可能会由本类静态方法调用产生
// 禁止静态方法。

// 分解2,与可以产生的对象类进行关联
// 方案一：保护继承
// 问题：这样就变成了同时存在了，且driver和base一一对应。需求偏离（特定工厂随时创建实例）

// 方案二：通过this指针进行关联，只要有this指针，那么就可以产生该base
// 此时不能有继承使用，那么只有通过静态方法获取了

// 此时唯一的问题就是临时对象可以生成了。那么应该如何处理呢

// 临时对象据有默认构造行为，所以，我们将构造的默认行为设置为false

class abstractDriver
{
protected:
	bool _canCreate;
	abstractDriver(bool can)
	:_canCreate(can)
	{}
public:
	virtual bool canCreate(){
		return _canCreate;
	}
};

class base
{
protected:
	base()
	{
		Trace("");
	}
public:
	static base* getInstance(abstractDriver*);
};

base* base::getInstance(abstractDriver*dr)
{
	if (dr->canCreate())
		/* code */
		return new base();
	else
		return NULL;
}
class driver:public abstractDriver
{
public:
	driver()
	:abstractDriver(false)
	{
		Trace("");
	}
	base* getInstance()
	{
		_canCreate = true;
		base* p =base::getInstance(this);
		_canCreate = false;
		return p;
	}
};

int main(int argc, char const *argv[])
{
	base* p = base::getInstance(new driver());
	cout << p <<endl;
	p = (driver()).getInstance();
	cout << p <<endl;
	return 0;
}

// // 通过静态方法获取，且依赖driver的this指针。
// // 但是此时也可以通过临时对象driver生成
// class driver;
// class base
// {
// protected:
// 	base()//driver*)
// 	{
// 		Trace("");
// 	}
// public:
// 	static base* getInstance(driver*);
// };

// base* base::getInstance(driver*)
// {
// 	return new base();
// }

// class driver
// {
// public:
// 	base* getInstance()
// 	{
// 		return base::getInstance(this);
// 	}
// };
// int main(int argc, char const *argv[])
// {
	
// 	base * p = (driver()).getInstance();
// 	return 0;
// }


// 实现通过driver产生，但是只因为继承而产生/换句话说，他和driver是一一对应的
// class base
// {
// protected:
// 	base()
// 	{
// 		Trace("");
// 	}
// };
// class driver:protected base
// {
// public:
// 	void test()
// 	{
// 		base b;
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	driver d;
// 	d.test();
// 	return 0;
// }



// 静态方法获取实例
// class base
// {
// protected:
// 	base()
// 	{
// 		Trace("");
// 	}
// public:
// 	static base* getInstance();
// };

// base* base::getInstance()
// {
// 	return new base();
// }
// int main(int argc, char const *argv[])
// {
// 	// base* p = new base();
// 	base * p = base::getInstance();
// 	return 0;
// }
