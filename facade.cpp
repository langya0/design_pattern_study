// 门面模式：为子系统提供统一对外接口
// 优点：
// 减少系统的相互依赖
// 提高灵活性
// 提高安全性
// 缺点：
// 不符合开比原则：门面中有各不合理接口，那么智能修改

// 使用场景：
// 为复杂模块提供外界访问接口
// 子系统相对独立---外界访问只需要嘿箱操作
// 预防低水平人员带来的风向扩散：

// ps不符合开闭，显示功能，底层实现也就有限。

// 同一个系统可以有多个门面-权限-对象不同。
// 门面不参与具体业务逻辑
// 可以提供不同的访问路径
#include "afxstd.h"

class subSystem1
{
public:
	subSystem1()
	{
		Trace("");
	}
	void test1()
	{
		Trace("");
	}
	~subSystem1()
	{
		Trace("");
	}
};

class subSystem3
{
public:
	subSystem3()
	{
		Trace("");
	}
	void test3()
	{
		Trace("");
	}
	~subSystem3()
	{
		Trace("");
	}
};

class subSystem2
{
public:
	subSystem2()
	{
		Trace("");
	}
	void test2()
	{
		Trace("");
	}
	~subSystem2()
	{
		Trace("");
	}
};

class facade
{
protected:
	subSystem1& s1;
	subSystem2& s2;
	subSystem3& s3;
public:
	facade(subSystem1& _s1,subSystem2& _s2,subSystem3& _s3)
	:s1(_s1)
	,s2(_s2)
	,s3(_s3)
	{
		Trace("");
	}

	void test3()
	{
		s3.test3();
	}

	void test1()
	{
		s1.test1();
	}
	void test2()
	{
		s2.test2();
	}
	~facade()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	subSystem1 s1;
	subSystem2 s2;
	subSystem3 s3;

	facade f(s1,s2,s3);
	f.test1();
	f.test2();
	f.test3();
	return 0;
}