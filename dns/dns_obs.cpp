#include <iostream>
using namespace std;
#include "recorder.h"
class dnsServer
{
protected:
	dnsServer* upperServer;
public:
	virtual ~dnsServer(){}
	virtual void updata(recorder &domain)
	{
		if (isLocal( domain))
		{
			domain.setip(getIp());
		}
		else
			notifyUpper(domain);
		sign(domain);
	}
	virtual bool isLocal(recorder)=0;
	virtual void sign(recorder&)=0;

	void setUpper(dnsServer* up)
	{
		upperServer = up;
	}
	dnsServer* getUpper()
	{
		return upperServer;
	}
	void notifyUpper(recorder& rec)
	{
		upperServer->updata(rec);
	}
};

class shDnsServer:public dnsServer
{
protected:	
	void sign(recorder& rec)
	{
		rec.setowner("shanghai");
	}
	bool isLocal(recorder rec)
	{
		return	endwith(rec.getdomain(),".sh.cn");
	}
};
class chinaDnsServer:public dnsServer
{
protected:	
	void sign(recorder& rec)
	{
		rec.setowner("zhongguo");
	}
	bool isLocal(recorder rec)
	{
		return	endwith(rec.getdomain(),".cn");
	}
};
class topDnsServer:public dnsServer
{
protected:	
	void sign(recorder& rec)
	{
		rec.setowner("top");
	}
	bool isLocal(recorder rec)
	{
		// return	endwith(rec,".sh.cn");
		return true;
	}
};


int main(int argc, char const *argv[])
{
	dnsServer* top = new topDnsServer();
	dnsServer* cn = new chinaDnsServer();
	dnsServer* sh = new shDnsServer();

	cn->setUpper(top);
	sh->setUpper(cn);
	string domain;
	cout << "============域名解析服务器模式=============="<<endl;
	while(1)
	{
		cout << "请输入域名(输入n结束)#"<<endl;
		cin>>domain;
		if(domain == string("n"))
		{
			return 0;
		}
		recorder rec;
		rec.setdomain(domain);

		sh->updata(rec);
		cout << "--------------域名解析结果-------------------"<<endl;
		cout << (rec.tostring())<<endl;
	}

	return 0;
}