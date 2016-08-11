// 观察者模式：发布模式，黑板模式--自动通知

// 定义一种一对多的依赖关系，当一个对象状态改变，依赖者都得到通知并更新

// 被观察者包含监控者信息，当执行某动作时，进行notify
// 观察者收到信息进行自定义更新

// 优点：建立一套触发机制，主动触发。类比责任连/被动触发
// 责任链过程：消息在原信息基础上更新，观察者：消息是两个节点协商的

// 使用场景：关联行为（可拆分）
// 事件多级触发
// 跨系统信息交换：消息队列处理机制

// 问题：广播链过长
// 异步处理问题：
// 被观察者较多，触发响应--异步处理（消息队列）


// 改进
// 观察者和被观察者之间的消息沟通：在updata中增加参数observer，msg
// 观察者响应方式：// 多线程异步架构/缓存技术同步架构
// 被观察者自己做主。


#include "afxstd.h"
#include <vector>
using namespace std;

class observer
{
protected:
	observer()
	{
		Trace("");
	}
public:
	virtual void update()=0;
	virtual ~observer()
	{
		Trace("");
	}
};
class concreteObserver1:public observer
{
public:
	concreteObserver1()
	{
		Trace("");
	}
	void update()
	{
		Trace("");
	}
	~concreteObserver1()
	{
		Trace("");
	}
};
class concreteObserver2:public observer
{
public:
	concreteObserver2()
	{
		Trace("");
	}
	void update()
	{
		Trace("");
	}
	~concreteObserver2()
	{
		Trace("");
	}
};


class subject
{
protected:
	subject()
	{
		Trace("");
	}
public:
	~subject()
	{
		Trace("");
	}
	virtual void attach(observer*)=0;
	virtual void detach(observer*)=0;
	virtual bool notify()=0;
};

class concreteSubject:public subject
{
	vector<observer*> v;
public:
	void attach(observer* ob)
	{
		v.push_back(ob);
	}
	void detach(observer* ob)
	{
		Trace("");
	}
	bool notify()
	{
		Trace("");
		for (int i = 0; i < v.size(); ++i)
		{
			v[i]->update();
		}
	}

	void dosomething()
	{
		Trace("");
		notify();
	}
	concreteSubject()
	{
		Trace("");
	}
	~concreteSubject()
	{
		Trace("");
	}
};


int main(int argc, char const *argv[])
{
	observer* s1 = new concreteObserver1();
	observer* s2 = new concreteObserver2();

	// subject* s = new concreteSubject();
	concreteSubject s;
	s.attach(s1);
	s.attach(s2);
	s.dosomething();
	return 0;
}