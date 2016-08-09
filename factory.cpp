// about factory
// 优点：
// 良好封装，创建产品只需要知道类型就好，具体创建由工厂返回
// 扩展性强，当产品类型增多，代码整体结构并没有太大变化。“拥抱变化”
// 屏蔽产品类，调用者只需要知道产品接口就好
// 典型的解耦框架。高层只需要知道产品的抽象类，符合迪米特法则，依赖倒置原则，里氏替换原则

// 使用场景:
// ①他是new产品的一个替代品
// ②需要灵活地，可扩展的框架是，考虑工厂模式
// ③在异构项目中，可以通过工厂模式实现系统同构化，只需要关进具体的接口接合问题
// ④在测试驱动开发的框架中。可以通过工厂方法将具体测试者所依赖的其他类虚拟出来，从而避免耦合

// eg
// 生成多边形，求解多边形面积。工厂类不需要知道实际的边数。
 

// #define _NOTRACE
#include "afxstd.h"
class product
{
protected:
	product();
public:
	virtual void dosomething()=0;
	// {
	// 	Trace("");
	// }
	virtual ~product()
	{
		Trace("");
	}
};

void product::dosomething()
{
	Trace("");
}
product::product()
{
	Trace("");
}

class concreteproduct1:public product
{
public:
	concreteproduct1()
	{
		Trace("");
	}
	void dosomething()
	{
		// Trace("");
		product::dosomething();
	}
	~concreteproduct1()
	{
		Trace("");
	}
};
class concreteproduct2:public product
{
public:
	concreteproduct2()
	{
		Trace("");
	}
	void dosomething()
	{
		// Trace("");
		product::dosomething();
	}
	~concreteproduct2()
	{
		Trace("");
	}
};

template<class T>
class factory
{
public:
	factory()
	{
		Trace("");
	}
	static product* createProduct();
	void dosomething()
	{
		Trace("");
	}
	~factory()
	{
		Trace("");
	}
};
template <class T>
product* factory<T>::createProduct()
{
	Trace("");
	return new T();
}
int main(int argc, char const *argv[])
{
	product *p2 = factory<concreteproduct2>::createProduct();
	product *p1 = factory<concreteproduct1>::createProduct();
	p1->dosomething();
	p2->dosomething();
	return 0;
}