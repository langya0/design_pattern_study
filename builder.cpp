//行为一致，顺序有差异
//子类封装自定义顺序。父类依次执行
//封装成员函数指针。

//typedef void (clas::*pFUNC)();
//pFUNC p = &clas::fun;
//((*this).*p)();
// this->*p();

//增加导演类，具体结构类型增加concreteBuilder。
//对上1版本中main中的顺序设置进行封装。
//1main中定义导演，导演接活，要哪个类型。
// 2对具体类型，导演内部引用的builder进行setPart。
// 然后返回该类型的实例

// #define	_NOTRACE
#include "afxstd.h"
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

#define _DIRECTOR

#ifdef _DIRECTOR

class Product
{
typedef void (Product::*pFUNC)();

protected:
	void oder1()
	{
		Trace("");
	}
	void oder2()
	{
		Trace("");
	}
	void oder3()
	{
		Trace("");
	}
	void oder4()
	{
		Trace("");
	}
	void init()
	{
		func["oder1"] = &Product::oder1;
		func["oder2"] = &Product::oder2;
		func["oder3"] = &Product::oder3;
		func["oder4"] = &Product::oder4;
	}
public:
	Product(vector<string>& st)
	:oder(st)
	{
		Trace("");
		init();
	}
	void run()
	{
		std::vector<string>::iterator it = oder.begin();		
		for(;it != oder.end();++it)
		{
			// ((*this).*func[*it])();
			(this->*func[*it])();
		}
	}
	virtual ~Product()
	{
		Trace("");
	}
protected:
	vector<string> oder;
	unordered_map<string,pFUNC> func;
};
class builder
{
protected:
	builder()
	{
		Trace("");
	}

public:
	virtual void setPart()=0;
	Product* buildProduct()
	{
		setPart();
		return new Product(oder);
	}

	virtual ~builder()
	{
		Trace("");
	}
protected:
	vector<string> oder;	//to savePartOder
};

class concreteBuilder:public builder
{
public:
	concreteBuilder()
	{
		Trace("");
	}

	void setPart()
	{
		oder.clear();

		oder.push_back("oder1");
		oder.push_back("oder2");
		oder.push_back("oder1");
		oder.push_back("oder3");
	}

	~concreteBuilder()
	{
		Trace("");
	}
};
//导演
class director
{
protected:
	builder & build;
public:
	director(builder & bu)
	:build(bu)
	{
		Trace("");
	}
	Product* buildProduct()
	{
		build.setPart();
		return build.buildProduct();
	}
	~director()
	{}
};

int main(int argc, char const *argv[])
{
	director dir(*(new concreteBuilder()));
	Product* pr = dir.buildProduct();
	pr->run();
	return 0;
}


#else
// class builder;
class builder
{
public:
typedef void (builder::*pFUNC)();
	builder()
	{
		Trace("");
		init();
	}

	virtual ~builder()
	{
		Trace("");
	}
	void run()
	{
		// for(int i = 0 ; i < oder.size();i++)
		// {
		// 	if(oder[i] == string("oder1"))
		// 		oder1();
		// 	if(oder[i] == string("oder2"))
		// 		oder2();
		// 	if(oder[i] == string("oder3"))
		// 		oder3();
		// 	if(oder[i] == string("oder4"))
		// 		oder4();
		// }
		std::vector<string>::iterator it = oder.begin();		
		for(;it != oder.end();++it)
		{
			// ((*this).*func[*it])();
			(this->*func[*it])();
		}
	}
	virtual bool mkoder(vector<string> &v){}
protected:
	void oder1()
	{
		Trace("");
	}
	void oder2()
	{
		Trace("");
	}
	void oder3()
	{
		Trace("");
	}
	void oder4()
	{
		Trace("");
	}
	void init()
	{
		func["oder1"] = &builder::oder1;
		func["oder2"] = &builder::oder2;
		func["oder3"] = &builder::oder3;
		func["oder4"] = &builder::oder4;
	}
protected:
	vector<string> oder;
	unordered_map<string,pFUNC> func;
};

class concreteBuilder1:public builder
{
public:
	concreteBuilder1()
	{
		Trace("");
	}
	bool mkoder(vector<string> &st)
	{
		oder = st;
	}
	virtual ~concreteBuilder1()
	{
		Trace("");
	}
};
class concreteBuilder2:public builder
{
public:
	concreteBuilder2()
	{
		Trace("");
	}
	bool mkoder(vector<string> &st)
	{
		oder = st;
	}
	virtual ~concreteBuilder2()
	{
		Trace("");
	}
};

int main(int argc, char const *argv[])
{
	builder* p1 = new concreteBuilder1();
	vector<string> v;
	v.push_back("oder1");
	v.push_back("oder2");
	v.push_back("oder3");
	v.push_back("oder4");
	p1->mkoder(v);
	p1->run();

	cout << endl;
	v.clear();
	v.push_back("oder1");
	v.push_back("oder3");
	v.push_back("oder2");
	v.push_back("oder4");
	p1->mkoder(v);
	p1->run();
	// builder* p2 = new concreteMethod2();
	return 0;
}
#endif

