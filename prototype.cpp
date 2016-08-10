//原型模式是内存拷贝的。所以，只需要实现赋值，不存在深浅拷贝带来的问题
// 那就可以称之为原型模式。在C++中，也就是重载了质变拷贝构造，赋值运算符就好
//是个计较简单的模式了。
//使用场景：
//修改比较多
//构造函数比较繁琐
//线程安全问题。
//样本参照


#include "afxstd.h"

//
class concretePrototype{
public:
	concretePrototype()
	{
		Trace("");
	}
	concretePrototype(const	concretePrototype &con)
	:_mm(con._mm)
	{
		Trace("");
	}

	concretePrototype& operator=(const concretePrototype &con)
	{
		if(this!=&con)
		{
			Trace("");
			this->_mm = con._mm;
		}
		return *this;
	}
	~concretePrototype()
	{
		Trace("");
	}
protected:
	string _mm;
};
int main(int argc, char const *argv[])
{
	concretePrototype x;
	concretePrototype y(x);	
	concretePrototype z = y;	
	z = x;
	return 0;
}