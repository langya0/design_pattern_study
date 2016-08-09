// 1.1代理模式
// 代练封装游戏play行为，在play前后进行自定义处理，比如登录，计时，收费等
// 时刻记住，依赖倒置原则。依赖抽象/接口
#include "afxstd.h"
class realSubject
{
public:
	realSubject()
	{
		Trace("");
	}
	void playgame()
	{
		Trace("");
	}
	~realSubject()
	{
		Trace("");
	}
};
class Proxy
{
protected:
	realSubject &player;
	Proxy()
	:player(*(new realSubject))
	{
		Trace("");
	}

public:
	virtual void playgame()=0;

	virtual ~Proxy()
	{
		Trace("");
	}
};

class concreteProxy1:public Proxy
{
public:
	concreteProxy1()
	:Proxy()
	{
		Trace("");
	}
	void playgame()
	{
		before1();
		player.playgame();
		after1();
	}
	~concreteProxy1()
	{
		Trace("");
	}
protected:
	void before1()
	{
		Trace("");
	}
	void after1()
	{
		Trace("");
	}
};
class concreteProxy2:public Proxy
{
public:
	concreteProxy2()
	:Proxy()
	{
		Trace("");
	}
	void playgame()
	{
		before2();
		player.playgame();
		after2();
	}
	~concreteProxy2()
	{
		Trace("");
	}
protected:
	void before2()
	{
		Trace("");
	}
	void after2()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	Proxy* p1 = new concreteProxy1;
	p1->playgame();
	cout << endl;
	Proxy* p2 = new concreteProxy2;
	p2->playgame();
	return 0;
}