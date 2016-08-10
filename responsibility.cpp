// 责任链模式
// eg对于一份入党申请书，要获取最终的结果，就得通过各层级的审核评估，同意，签字。
// 那么我们就可以利用责任链模式进行处理。入党人不需要关心申请表的具体填补过程，只需要等待最终结果。
// 所以各层部门只需要判断是否是自己权限等级内的事物，然后进行处理，并交给下一级别。


#include "afxstd.h"
#include <stdlib.h>

// zhixing zhe


class Level
{
protected:
	int _level;
public:
	Level(int le)
	:_level(le)
	{}
	bool operator==(const Level& le)
	{
		return _level == le._level;
	}
};

class request
{
protected:
	Level le;
public:
	request(int _le)
	:le(_le)
	{}
	Level getHandlerLevel()
	{
		return le;
	}
	~request()
	{}
};

class response
{
protected:
	request _res;
public:
	 // 处理者返回的数据
	response(request res)
	:_res(res)
	{}
};
class handler
{
protected:
	class handler* nextHandler;
public:
	response* handleMessage(request _request)
	{
		Trace("");
		response* res = NULL;
		if(getHandlerLevel() == _request.getHandlerLevel())
		{

			Trace("");
			res = echo(_request);
		}
		else 
		{

			Trace("");
			if(nextHandler!=NULL)
			{
				res = nextHandler->handleMessage(_request);
			}
			else
			{
				cout << "nobody can do it" <<endl;
				exit(4);
			}
		}
	}
	void setNext(handler* _han)
	{
		nextHandler = _han;
	}
protected:
	virtual Level getHandlerLevel()=0;
	virtual response* echo(request res)=0;
};

class concreteHandler1:public handler
{
protected:
	response *echo(request res)
	{
		Trace("concreteHandler1");
		return new response(res);
	}
	Level getHandlerLevel()
	{
		Trace("");
		return *(new Level(1));
	}
};
class concreteHandler2:public handler
{
protected:
	response *echo(request res)
	{
		Trace("concreteHandler2");
		return new response(res);
	}
	Level getHandlerLevel()
	{
		Trace("");
		return *(new Level(2));
	}
};

class concreteHandler3:public handler
{
protected:
	response *echo(request res)
	{
		Trace("concreteHandler3");
		return new response(res);
	}
	Level getHandlerLevel()
	{
		Trace("");
		return *(new Level(3));
	}
};

int main(int argc, char const *argv[])
{
	handler* h1 = new concreteHandler1();
	handler* h2 = new concreteHandler2();
	handler* h3 = new concreteHandler3();

	// set oder
	h1->setNext(h2);
	h2->setNext(h3);

	response* res = h1->handleMessage(*(new request(4)));

	return 0;
}