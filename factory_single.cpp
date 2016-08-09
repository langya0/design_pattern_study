//////工厂模式扩展，工厂模式替换单例模式，增加扩展性
// 工厂包含单例基类指针，

// #define _NOTRACE
#include "afxstd.h"
class singleton
{
// protected:
public:
	singleton()
	{
		Trace("");
	}
public:
	virtual void dosomething()
	{
		Trace("");
	}
	virtual ~singleton()
	{
		Trace("");
	}
};

class sin:public singleton
{
public:
	sin()
	:singleton()
	{
		Trace("");
	}

	virtual void dosomething()
	{
		Trace("");
	}
	~sin()
	{
		Trace("");
	}
};
class sin1:public singleton
{
public:
	sin1()
	:singleton()
	{
		Trace("");
	}

	void dosomething()
	{
		Trace("");
	}
	~sin1()
	{
		Trace("");
	}
};

template<class T>
class factory_single
{
protected:
	 static singleton* _singleton;
public:
	factory_single()
	{
		Trace("");
	}
	static singleton* getSingleton();
	~factory_single()
	{
		Trace("");
	}
};

template<class T>
singleton* factory_single<T>::getSingleton()
{
	Trace("");
	if (_singleton == NULL)
	{
		_singleton = new T();
	}
	return _singleton;
}

template<class T>
singleton* factory_single<T>::_singleton = NULL;

int main(int argc, char const *argv[])
{
	// singleton* s1 = factory_single<singleton>::getSingleton();
	singleton* s3 = factory_single<singleton>::getSingleton();
	singleton* s2 = factory_single<sin>::getSingleton();
	singleton* s1 = factory_single<sin1>::getSingleton();
	s1->dosomething();
	s3->dosomething();
	s2->dosomething();
	return 0;
}