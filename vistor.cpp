// 访问者模式：
// 迭代器模式的扩展（访问用类型element）;访问不同类型对象
// 可以在visitConcreteElement中进行统计/判断等扩展处理
// 在accpt中选择可以访问者，并将accpet设置为protected

// 使用：
// 遍历
// 不相干的功能进行整合

// 扩展：
// 统计功能实现
// 多个访问者-
// 多个被访问者
// 适合重构使用，将逻辑进行整理
// 单分派/多分派----重载/多态


#include "afxstd.h"

class Element;
class vistor
{
protected:
	vistor()
	{
		Trace("");
	}
public:
	virtual void visitConcreteElement(Element* ele)=0;
	virtual ~vistor()
	{
		Trace("");
	}
};
class Element
{
protected:
	Element()
	{
		Trace("");
	}
	virtual void accpt(vistor* vis) = 0;
public:
	virtual void dosomething()=0;
	virtual ~Element()
	{
		Trace("");
	}
};

class concreteElement:public Element
{
public:
	concreteElement()
	{
		Trace("");
	}
	void dosomething()
	{
		Trace("");
	}
	~concreteElement()
	{
		Trace("");
	}
protected:
	void accpt(vistor* vis)
	{
		Trace("");
		vis->visitConcreteElement(this);
	}
};

class concreteVisitor:public vistor
{
public:
	concreteVisitor()
	{
		Trace("");
	}
	void visitConcreteElement(Element* ele)
	{
		Trace("");
		ele->dosomething();
	}
	~concreteVisitor()
	{
		Trace("");
	}
	
};


// int main1(int argc, char const *argv[])
// {
// 	vistor* vis = new concreteVisitor();
// 	Element* ele = new concreteElement();

// 	ele->accpt(vis);
// 	return 0;
// }
int main(int argc, char const *argv[])
{
	vistor* vis = new concreteVisitor();
	Element* ele = new concreteElement();

	vis->visitConcreteElement(ele);
	return 0;
}