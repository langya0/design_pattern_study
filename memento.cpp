// 备忘录模式，提供一种后悔药

// 使用场景：
// 保存恢复状态
// 监控副本场景
// 数据库事物连接

// 注意事项：
// 生命周期（最近备忘，需要主动回收
// 性能：叉，资源消耗在对象创建过程中）

// 备忘录模式，可以将创建回滚工作都由发起人自己完成的。
// 内部保存他的历史状态---链


// 多状态备忘录/链式多点备忘录
// 可以在类内部白村
// class Originator 
// {
// private:
// 　　Originator* _backup;
// 　　string _state;
// public:
// 　　Originator(const Originator& or)
// 　　{}　
// 　　void setState();
// 　　void creatMemento()
// 　　{
// 　　　　_bcakup = new Originator(*this);
// 　　}

// 多状态备忘录--管理员中保存多个状态。
// 回滚根据下标/string进行选择
// 

#define _1
#ifdef	_1
#include  "afxstd.h"

class imemento
{
public:
	virtual string getState()=0;
	virtual void setState(string)=0;
	virtual ~imemento(){}
};
class memento;
class caretaker
{
protected:
	imemento* mem;
public:

	caretaker()
	:mem(NULL)
	{
		Trace("");
	}
	imemento* getmemento()
	{
			Trace("");
		return mem;
	}
	void setmemento(imemento* m)
	{
			Trace("");
		mem->setState(m->getState());
	}
	~caretaker()
	{
		Trace("");
	}
};

class originator
{
protected:
	string state;
public:
	originator()
	{
		Trace("");
	}
	string getState()
	{
		Trace("");
		return state;
	}
	void setState(string st)
	{
		Trace("");
		state = st;
	}
	void creatememento(caretaker& ca)
	{
		Trace("");
		// static imemento* p = new 
		static memento p(state);
		ca.setmemento(&p);
	}
	void restorememento(imemento*mem)
	{
		Trace("");
		state = mem->getState();
	}
friend class caretaker;
private:
	class memento:public imemento
	{
	private:
		string state;
	public:
		memento(string st)
		:state(st)
		{
			Trace("");
		}

		string getState()
		{
			Trace("");
			return state;
		}
		void setState(string st)
		{
			Trace("");
			state = st;
		}

		~memento()
		{
			Trace("");
		}
		
	};
public:
	~originator()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	originator o;
	o.setState("test");
		Trace("");
	caretaker c;
	o.creatememento(c);
	// c.setmemento(o.creatememento());

		Trace("");
	o.setState("fuck");
	o.restorememento(c.getmemento());
		Trace("");

	return 0;
}

#else
// 
#include "afxstd.h"
#include <string>
using namespace std;

class memento
{
protected:
	string state;
public:
	memento()
	{
		Trace("");
	}
	string getState()
	{
		Trace("");
		return state;
	}
	int setState(string st)
	{
		state = st;
	}


	~memento()
	{
		Trace("");
	}
};

// 发起人
class originator
{
protected:
	string state;
public:
	originator()
	{
		Trace("");
	}
	string getState()
	{
		Trace("");
		return	state;
	}
	void setState(string st)
	{
		state = st;
	}

	memento creatememento()
	{
		Trace("");
		return *(new memento());
	}

	void restorememento(memento me)
	{
		Trace("");
		setState(me.getState());
	}

	~originator()
	{
		Trace("");
	}
};

class caretaker
{
protected:
	memento me;
public:
	caretaker()
	{
		Trace("");
	}
	memento getmemento()
	{
		Trace("");
		return me;
	}
	void setmemento(memento _me)
	{
		Trace("");
		me = _me;
	}
	~caretaker()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	originator o;

	caretaker c;

	c.setmemento(o.creatememento());
	// c.setmemento(o.creatememento());

	o.restorememento(c.getmemento());
	o.restorememento(c.getmemento());


	return 0;
}
#endif