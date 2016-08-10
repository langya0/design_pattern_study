// 组合模式
// 将整体，部分的结构进行统一处理。
// 场景类中负责树的建立以及  递归遍历整个树。

// ps通过多态方式同一叶子和树枝的接口。
// 让整体-部分一致对待/客户不考虑是否为整体/部分

// eg数据结构的广义表-树，结构。 重点在于接口统一，递归遍历的处理

// 优点：高层调用简单
// 节点自由增加

// 缺点：定义直接使用实现类-冲突依赖倒置

// 使用场景：维护和展示 整体-部分关系，树形菜单，文件和文件夹管理
// 从整体中能够独立出部分模块或者功能的场景

// 组合模式:安全模式---透明模式

// 透明模式中实现：遍历不用强制类型转换。

#include "afxstd.h"

#include <vector>
using namespace std;

class component
{
public:
	virtual void operation()=0;
	virtual bool isLeaf()=0;
};

// yezi
class leaf:public component
{
public:
	leaf()
	{
		Trace("");
	}
	void operation()
	{
		Trace("");
	}
	bool isLeaf()
	{
		return true;
	}
	~leaf()
	{
		Trace("");
	}
};

// shu
class composite:public component
{
protected:
	std::vector<component*> v;
public:
	bool isLeaf()
	{
		return false;
	}
	composite()
	{
		Trace("");
	}
	void add(component* com)
	{
		v.push_back(com);
	}
	void remove(component* com)
	{
		// v.erase();
	}

	void operation()
	{
		Trace("");
	}

	vector<component*>& getChildren()
	{
		return v;
	}

	~composite()
	{
		Trace("");
	}
};

void display(component* root)
{
	
		if(root->isLeaf())
		{
			Trace("");
			root->operation();
		}
		else
		{
			Trace("");
			cout << "branch"<<endl;
			std::vector<component*> v = ((composite*)root)->getChildren();
			for(int i =0; i< v.size();++i)
			display(v[i]);
		}
}

int main(int argc, char const *argv[])
{
	composite *root = new composite();

	// root->operation();
	composite* branch = new composite();
	leaf *lf = new leaf();

	root->add(branch);
	branch->add(lf);

	display(root);
	return 0;
}