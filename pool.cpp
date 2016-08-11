// 享元模式：对于相似一个系统，如果其内部变量数量不多，但是重复使用时
// 我们可以使用享元模式进行处理
// 当对象实例存在时，从池中获取使用，当不存在时，加入池并返回

// 减少内存使用，提高性能。但是增加了程序复杂性，产生线程安全问题

// 使用场景：
// 系统中存在大量相似对象
// 细粒度对象具有接近的外部状态-内部状态与环境无关/无特定身份
// 需要缓冲池的场景

// 扩展
// 线程安全
// 性能平衡---使用内部类型作为池中 的键值map《k》

// 详元模式：侧重对象共享
// 对象池：侧重对象复用。stl内存池。


#include "afxstd.h"

#include <map>

class flyweight
{
protected:
	string intrinsic; //neibu
	string extrinsic; //waibu
public:
	flyweight(string _ex)
	:extrinsic(_ex)
	{
		Trace("");
	}

	virtual void oper()=0;

	string getIntrinsic()
	{
		return intrinsic;
	}

	void setInstrinsic(string in)
	{
		intrinsic = in;
	}

	~flyweight()
	{
		Trace("");
	}
};

class concreteFlyweight1:public flyweight
{
public:
	concreteFlyweight1(string ex)
	:flyweight(ex)
	{
		Trace("");
	}
	void oper()
	{
		Trace("");
	}
	~concreteFlyweight1()
	{
		Trace("");
	}
};
class concreteFlyweight2:public flyweight
{
public:
	concreteFlyweight2(string ex)
	:flyweight(ex)
	{
		Trace("");
	}
	void oper()
	{
		Trace("");
	}
	~concreteFlyweight2()
	{
		Trace("");
	}
};

class flyweightFactory
{
protected:
	static map<string, flyweight*> pool;
public:
	static flyweight* getFlyweight(const char* ex)
	{
		// map<string, flyweight*>::iterator it = pool.find(ex);
  //       if (it == pool.end())
  //       {
  //           cout << "Creat Flyweight1" << endl;
  //           pool[ex] = new concreteFlyweight1(ex);
  //       }

		if(pool[ex] == NULL)
		{
			pool[ex] = new concreteFlyweight1(ex);
		}
        return pool[ex];
	}

};
map<string, flyweight*> flyweightFactory::pool = std::map<string\
, flyweight*>();


int main(int argc, char const *argv[])
{
	/* code */
	flyweight* f = flyweightFactory::getFlyweight("liang");
	f = flyweightFactory::getFlyweight("li");
	f = flyweightFactory::getFlyweight("hui");
	f = flyweightFactory::getFlyweight("liang");
	f = flyweightFactory::getFlyweight("guo");
	f = flyweightFactory::getFlyweight("guo");

	return 0;
}