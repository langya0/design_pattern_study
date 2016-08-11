// 桥梁模式：将实现与抽象分离。使得抽象可以进行扩充。
// 当底层接口不稳定，可能存在变化时，通过桥梁模式进行接偶操作，便于扩展
// 优点：抽象，实现分离
// 优秀的扩充能力
// 实现细节对客户透明

// 使用场景：
// 不希望或者不适用继承的场景。层次过度
// 接口不稳定
// 重用性要求高的场景：细粒度

// 意图：对变化进行封装



#include "afxstd.h"

class implementor
{
protected:
	implementor()
	{
		Trace("");
	}
public:
	virtual void operationImp()=0;
	~implementor()
	{
		Trace("");
	}
};

class abstraction
{
protected:
	implementor& imp;
public:
	abstraction(implementor& ab)
	:imp(ab)
	{
		Trace("");
	}
	virtual void operation()=0;
	~abstraction()
	{
		Trace("");
	}
};

class refinedAbstraction:public abstraction
{
public:
	refinedAbstraction(implementor& ab)
	:abstraction(ab)
	{
		Trace("");
	}
	void operation()
	{
		Trace("");
		imp.operationImp();
	}
	~refinedAbstraction()
	{
		Trace("");
	}
};

class concreteImplementor:public implementor
{
public:
	concreteImplementor()
	{
		Trace("");
	}
	~concreteImplementor()
	{
		Trace("");
	}
	void operationImp()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	implementor* imp = new concreteImplementor();
	abstraction* p = new refinedAbstraction(*imp);

	p->operation();
	/* code */
	return 0;
}