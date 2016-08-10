// 优点：关联两个无关类
// 增加类透明，类复用，灵活性

// 使用场景：补救，后期扩展

// 类适配器：通过继承实现适配
// 对象适配器：通过对象层次关联/组合方式

// 适配器模式/补救模式
// 类适配器，对象适配器


#include "afxstd.h"
class adaptee
{
public:
	adaptee()
	{
		Trace("");
	}
	void test1()
	{
		Trace("");
	}
	void test2()
	{
		Trace("");
	}
	void test3()
	{
		Trace("");
	}
	~adaptee()
	{
		Trace("");
	}
};

class adapter
{
protected:
	adaptee adpe;
public:
	adapter(adaptee &ad)
	:adpe(ad)
	{
		Trace("");
	}
	void testa()
	{
		Trace("");
		adpe.test1();
	}
	void testb()
	{
		Trace("");
		adpe.test2();
	}
	~adapter()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	adapter p(*(new adaptee()));
	p.testa();
	p.testb();
	return 0;
}

// // ///////////////////////////////
// // 类适配器
// // 目标接口
// class target
// {
// public:
// 	virtual void dosomething()=0;
// };

// class adaptee
// {
// public:
// 	// adaptee();
// 	void dosomethings()
// 	{
// 		Trace("");
// 	}
// 	// ~adaptee();
// };

// class adapter:protected adaptee,public target
// {
// public:
// 	adapter()
// 	{
// 		Trace("");
// 	}
// 	void dosomething()
// 	{
// 		Trace("");
// 		dosomethings();
// 	}
// 	~adapter()
// 	{
// 		Trace("");
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	adapter* ad = new adapter();
// 	ad->dosomething();
// 	return 0;
// }