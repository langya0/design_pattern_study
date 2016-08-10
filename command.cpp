// 命令模式：老板下达命令abc，经理进行任务分发。然后执行者进行执行。
// 这个过程，
// 老板也就client，定义命令，以及下层经理。
// invoker作为经理，进行执行分发执行
// 每个命令内部含有具体的执行者（reciver）。reciver封装使得client屏蔽底层实现（我不关注这个）
// 

// 优点：分离命令下达与执行过程，便于扩展。维护。

#include "afxstd.h"

//接收者
class receiver
{
protected:
	receiver()
	{
		Trace("");
	}
public:
	virtual void dosomething()=0;
	~receiver()
	{
		Trace("");
	}
};
class concreteReceiver1:public receiver
{
public:
	void dosomething()
	{
		Trace("");
	}	
};
class concreteReceiver2:public receiver
{
public:
	void dosomething()
	{
		Trace("");
	}	
};

class command
{
protected:
	command()
	{
		Trace("");
	}
public:
	virtual void excute()=0;
	virtual ~command()
	{
		Trace("");
	}
};

class concreteCommand1:public command
{
protected:
	receiver &rec;
public:
	concreteCommand1()
	:rec(*(new concreteReceiver1()))
	{
		Trace("");
	}
	void excute()
	{
		rec.dosomething();
	}
	~concreteCommand1()
	{
		Trace("");
	}
};
class concreteCommand2:public command
{
protected:
	receiver &rec;
public:
	concreteCommand2()
	:rec(*(new concreteReceiver2()))
	{
		Trace("");
	}
	void excute()
	{
		rec.dosomething();
	}
	~concreteCommand2()
	{
		Trace("");
	}
};


// 调用者
class invoker
{
protected:
	command* _cmd;
public:
	invoker(command* cmd)
	:_cmd(cmd)
	{
		Trace("");
	}	
	void setCommand(command* cmd)
	{
		_cmd = cmd;
	}
	void exec()
	{
		_cmd->excute();
	}
	~invoker()
	{
		Trace("");
	}
};
int main(int argc, char const *argv[])
{
	command* cmd = new concreteCommand1();
	invoker in(cmd);
	in.exec();
	cout << endl;
	// command* cmd1 = new concreteCommand2();
	// invoker in1(cmd1);
	// in1.exec();
	in.setCommand(new concreteCommand2());
	in.exec();
	return 0;
}