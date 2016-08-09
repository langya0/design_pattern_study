//抽象工厂模式主要用作产品族的扩展
//因为java语言缺少模板机制，所以抽象工厂的实现是使用工厂模式进行下层分级。
// 对于C++而言，因为产品族依旧是继承于上层父亲，所以祖先指针是可以多态方式处理底层子类的
// #define _NOTRACE
#include "afxstd.h"
class product
{
public:
	virtual void dosomething()=0;
	product()
	{
		Trace("");
	}
	virtual ~product()
	{
		Trace("");
	}
};
class concreteProduct1:public product
{
public:
	virtual void dosomething()
	{
		Trace("");
	}
	concreteProduct1()
	:product()
	{
		Trace("");
	}
	virtual ~concreteProduct1()
	{
		Trace("");
	}
};
class concreteProduct2:public product
{
public:
	virtual void dosomething()
	{
		Trace("");
	}
	concreteProduct2()
	:product()
	{
		Trace("");
	}
	~concreteProduct2()
	{
		Trace("");
	}
};

class concreteProduct2A:public concreteProduct2
{
public:
	void dosomething()
	{
		Trace("");
	}
	concreteProduct2A()
	:concreteProduct2()
	{
		Trace("");
	}
	~concreteProduct2A()
	{
		Trace("");
	}
};
class concreteProduct2B:public concreteProduct2
{
public:
	void dosomething()
	{
		Trace("");
	}
	concreteProduct2B()
	:concreteProduct2()
	{
		Trace("");
	}
		~concreteProduct2B()
	{
		Trace("");
	}
};
class concreteProduct1A:public concreteProduct1
{
public:
	void dosomething()
	{
		Trace("");
	}
	concreteProduct1A()
	:concreteProduct1()
	{
		Trace("");
	}
	~concreteProduct1A()
	{
		Trace("");
	}
};
class concreteProduct1B:public concreteProduct1
{
public:
	void dosomething()
	{
		Trace("");
	}
	concreteProduct1B()
	:concreteProduct1()
	{
		Trace("");
	}
	~concreteProduct1B()
	{
		Trace("");
	}
};

// template<class T>
// class abs_factory
// {
// public:
// 	abs_factory()
// 	{
// 		Trace("");
// 	}
// 	static product* createProduct()
// 	{
// 		return new T();		
// 	}
// 	virtual ~abs_factory()
// 	{
// 		Trace("");
// 	}
// };

class abs_factory
{
protected:
	abs_factory()
	{
		Trace("");
	}
public:
	virtual concreteProduct1* createProduct1()=0;
	virtual concreteProduct2* createProduct2()=0;
	virtual ~abs_factory()
	{
		Trace("");
	}
};

class concretefactoryA:public abs_factory
{
public:
	concretefactoryA()
	:abs_factory()
	{
		Trace("");
	}

	concreteProduct1* createProduct1()
	{
		return new	concreteProduct1A();
	}
	concreteProduct2* createProduct2()
	{
		return new concreteProduct2A();
	}

	~concretefactoryA()
	{
		Trace("");
	}
};
class concretefactoryB:public abs_factory
{
public:
	concretefactoryB()
	:abs_factory()
	{
		Trace("");
	}


	concreteProduct1* createProduct1()
	{
		return new	concreteProduct1B();
	}
	concreteProduct2* createProduct2()
	{
		return new concreteProduct2B();
	}
	~concretefactoryB()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	concretefactoryA fa;
	concretefactoryB fb;

	concreteProduct1 *a1= fa.createProduct1();
	concreteProduct1 *b1= fb.createProduct1();
	concreteProduct2 *a2= fa.createProduct2();
	concreteProduct2 *b2= fa.createProduct2();

	return 0;
}
// int main2(int argc, char const *argv[])
// {
// 	// Trace("");
// 	product *a = abs_factory<concreteProduct1>::createProduct();
// 	a->dosomething();
// 	product *b = abs_factory<concreteProduct2>::createProduct();
// 	b->dosomething();
// 	product *a1 = abs_factory<concreteProduct1A>::createProduct();
// 	a1->dosomething();
// 	product *a2 = abs_factory<concreteProduct2A>::createProduct();
// 	a2->dosomething();
// 	product *b1 = abs_factory<concreteProduct1B>::createProduct();
// 	b1->dosomething();
// 	product *b2 = abs_factory<concreteProduct2B>::createProduct();
// 	b2->dosomething();
// 	return 0;
// }