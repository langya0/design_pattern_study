//普通代理，用户必须知道代理的存在，单不知道谁是具体代理

#include "afxstd.h"
#include <stdlib.h>

class iGamePlayer
{
protected:
	iGamePlayer()
	{
		Trace("");
	}
public:
	virtual void login()=0;
	virtual void killBoss()=0;
	virtual void upgrade()=0;

	virtual ~iGamePlayer()
	{
		Trace("");
	}
};

//
class ptrExcption:public exception
{
public:
	ptrExcption(const int err,const char* errmsg)
	:_err(err)
	,_errmsg(errmsg)
	{}
	const char* what() const throw ()
	// virtual const char * what()const
	{
		cout << _err <<endl;
		cout << _errmsg<<endl;
	}
	virtual ~ptrExcption()throw()
	{}
protected:
	int _err;
	string _errmsg;
};

class GamePlayerProxy;
class GamePlayer:public iGamePlayer
{
public:
	GamePlayer(const GamePlayerProxy*ip,const string &user,const string &_passwd,const int& _grade)
	:name(user)
	,passwd(_passwd)
	,grade(_grade)
	{
		if(ip==NULL)
		{
			 // throw new ptrExcption(2,"can't create!");			
			exit(4);
		}
		else
		{
			Trace("");
		}
	}

	void login()
	{
		Trace("");
	}
	void killBoss()
	{
		Trace("");
	}
	void upgrade()
	{
		Trace("");
	}

	~GamePlayer()
	{
		Trace("");
	}
protected:
	string name;
	string passwd;
	int grade;
};

class GamePlayerProxy
{
public:
	GamePlayerProxy(const string &name,const string &passwd,const int &grade)
	:player(new GamePlayer(NULL,name,passwd,grade))
	{
		Trace("");
	}
	void play()
	{
		player->login();
		player->killBoss();
		player->upgrade();
	}
	~GamePlayerProxy()
	{
		Trace("");
	}
protected:
	iGamePlayer * player;
};

int main(int argc, char const *argv[])
{

	GamePlayerProxy gp("zhangsan","passwd",10);
	gp.play();

	return 0;
}