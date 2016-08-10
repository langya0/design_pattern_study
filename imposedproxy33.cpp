// 普通代理：用户知道有代理存在即可。实现，真实用户中通过指针判断，是否生成真实用户
// 强制代理：用户必须通过代理进行访问。实现，真实用户包含代理指针，代理包含真实用户
// 对强制代理的实现，

// client不能new代理，只能
// a生成真实用户，
// b通过真实用户获取代理。
// c通过代理进行访问

// 代理的拦截过滤，通过代理内部接口进行逻辑判断，增强功能等
class iproxy
{
protected:
	iproxy(){}
    virtual void count()=0;
public:
	~iproxy(){}
};

#include "afxstd.h"

class iGmeplayer
{
protected:
	iGmeplayer()
	{
		Trace("");
	}
public:
	virtual void login(string user,string passwd)=0;
	virtual void killBoss()=0;
	virtual void upgrade()=0;
	////真实用户可以找到自己的代理
	virtual iGmeplayer* getProxy()=0;
	virtual ~iGmeplayer()
	{
		Trace("");
	}
	
};

class GameplayerProxy: public iGmeplayer,public iproxy
{
protected:
	iGmeplayer* gamePlayer;
public:
	void count()
	{
		cout << "赚钱了"<<endl;
	}
	GameplayerProxy(iGmeplayer* _gameplayer)
	:gamePlayer(_gameplayer)
	{
		Trace("");
	}

	iGmeplayer* getProxy()
	{
		return this;
	}

	void killBoss()
	{
		Trace("");
		gamePlayer->killBoss();
	}
	void login(string user,string passwd)
	{
		gamePlayer->login(user,passwd);
		Trace("");
	}
	void upgrade()
	{
		gamePlayer->upgrade();
		Trace("");
		count();
	}
	~GameplayerProxy()
	{
		Trace("");
	}
};
class Gameplayer:public iGmeplayer
{
protected:
	string name;
	iGmeplayer* my_proxy;
public:
	Gameplayer(string _name)
	:name(_name)
	{
		Trace("");
	}

	iGmeplayer* getProxy()
	{
		my_proxy = new GameplayerProxy(this);
		return my_proxy;
	}

	void killBoss()
	{
		if(my_proxy)
		{
			Trace("");
		}
		else
		{
			Trace("please using proxy");
		}
	}
	void login(string user,string passwd)
	{
		if (my_proxy)
		{
			Trace("");
		}
		else
		{
			Trace("please using proxy");
		}
	}
	void upgrade()
	{
		if (my_proxy)
		{
			Trace("");
		}
		else
		{
			Trace("please using proxy");
		}
	}

	~Gameplayer()
	{
		Trace("");
	}
	
};

int main(int argc, char const *argv[])
{
	//游戏娱乐只能通过代理进行。
	iGmeplayer* player = new Gameplayer("zhangsan");
	iGmeplayer* proxy = player->getProxy();

	proxy->login("zhangsan","passwd");
	proxy->killBoss();
	proxy->upgrade();
	return 0;
}
int main1(int argc, char const *argv[])
{
	//真实用户不得直接进行游戏，必须确定有代理存在
	iGmeplayer* player = new Gameplayer("zhangsan");
	player->login("zhangsan","passwd");
	player->killBoss();
	player->upgrade();
	return 0;
}