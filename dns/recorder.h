#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class recorder
{
protected:
	string domain;
	string ip;
	string owner;
public:
	string getdomain()
	{
		return domain;
	}
	string getip()
	{
		return ip;
	}
	string getowner()
	{
		return owner;
	}
	void setdomain(string in)
	{
		domain = in;
	}
	void setip(string in)
	{
		ip = in;
	}
	void setowner(string in)
	{
		owner = in;
	}
	string tostring()
	{
		string str = "域名："+domain+\
		"\nIP地址："+ip+"\n解析者"+owner;
		return str;
	}
};
bool endwith(string s,string s2)
{
	int len2 = strlen(s2.c_str());
	int len1 = s.size();
	return strcmp(s.c_str()+len1-len2,s2.c_str())==0;
}
static void itoa(int value, char *str)
{
    if (value < 0) //如果是负数,则str[0]='-',并把value取反(变成正整数)
    {
        str[0] = '-';
        value = 0-value;
    }
    int i,j;
    for(i=1; value > 0; i++,value/=10) //从value[1]开始存放value的数字字符，不过是逆序，等下再反序过来
        str[i] = value%10+'0'; //将数字加上0的ASCII值(即'0')就得到该数字的ASCII值
    for(j=i-1,i=1; j-i>=1; j--,i++) //将数字字符反序存放
    {
        str[i] = str[i]^str[j];
        str[j] = str[i]^str[j];
        str[i] = str[i]^str[j];
    }
    if(str[0] != '-') //如果不是负数，则需要把数字字符下标左移一位，即减1
    {
        for(i=0; str[i+1]!='\0'; i++)
            str[i] = str[i+1];
        str[i] = '\0';
    }
}
string getIp()
{
	string st="";
	for(int i = 0; i< 4;++i)
	{
		char buf[40];
		memset(buf,'\0',sizeof(buf));
		itoa(rand()%256,buf);
		st += buf;
		st += ".";
	}
	st.resize(st.size()-1);
	return st;
}
