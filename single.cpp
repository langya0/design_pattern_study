// about singleton
// 优点：
// 一个实例，减少内存开销；
// 减少系统开销；
// 避免对一个资源的多重占用；
// 设置全局访问点，优化和贡献资源。

// 缺点：
// 没有接口，扩展性差；
// 不利于测试；
// 与单一职责原则有冲突，单例模式把“要单例”和业务逻辑融合在一个类中。

// 使用场景：
// 要求生成唯一序列号的环境；
// 共享数据或者共享访问点；
// 创建一个对象需要消耗的资源过多，如访问IO和数据库等资源；
// 需要定义大量的静态常量和静态方法（工具类）

// 线程安全问题解决：
// a.利用饿汉模式，直接初始化，线程调用时，没有判断条件
// b.加入sem保护


// #define __NOTRACE
// #define _HANGE //饿汉模式

#include "afxstd.h"
class single
{
protected:
	single();
	static single *_single;
public:
	static single* getinstance();
	virtual ~single();
};

#ifndef _HANGE
single* single::_single = NULL;
#else
single* single::_single = new single();
#endif


single::single()
{
	Trace("");
}
single::~single()
{
	Trace("");
}
single* single::getinstance()
{
#ifndef _HANGE
	if (_single == NULL)
	{
		Trace("_single = NULL,getinstance...");
		_single = new single();
	}
#endif
	return _single;
}

int main(int argc, char const *argv[])
{
	// Trace("");
#ifndef _HANGE
	cout << "hanger model"<<endl;
#endif
	single* ps = single::getinstance();
	single* ps1 = single::getinstance();
	return 0;
}