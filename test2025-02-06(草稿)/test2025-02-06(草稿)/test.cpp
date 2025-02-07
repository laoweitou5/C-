#include<iostream>
#include<string>
using namespace std;


//需求：电脑主要部件为CPU（用于计算），显卡（用于显示），内存条（用于存储）
//将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如：intel和lenovo厂商
//创作电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
//测试时组装三台不同的电脑进行工作

//抽象出各个零件的类
//1.CPU的抽象类
class Cpu
{
public:
	virtual void calculate() = 0;
};
//2.显卡的抽象类
class VideoCard
{
public:
	virtual void display() = 0;
};
//3.内存条的抽象类
class Memory
{
public:
	virtual void storage() = 0;
};
//抽象出电脑类
class computer
{
public:
	//构造函数中传入三个零件指针
	computer(Cpu *c,VideoCard *v,Memory *m)
	{
		m_c = c;
		m_m = m;
		m_v = v;
	}

	//调用每个零件工作的接口
	void Dowork()
	{
		m_c->calculate();
		m_v->display();
		m_m->storage();
	}

	Cpu *m_c;
	VideoCard* m_v;
	Memory* m_m;

};
//抽象出厂商的类
//Intel的Cpu类
class Intel01:public Cpu
{
public:
	void calculate()
	{
		cout << "Intel的Cpu开始工作了" << endl;
	}
};

//Intel的显卡类
class Intel02 :public VideoCard
{
	void display()
	{
		cout << "Intel的显卡开始工作了" << endl;
	}
};

//Intel的内存类
class Intel03 :public Memory
{
	void storage()
	{
		cout << "Intel的内存开始工作了" << endl;
	}
};

//Lenovo的Cpu类
class Lenovo01 :public Cpu
{
public:
	void calculate()
	{
		cout << "Lenovo的Cpu开始工作了" << endl;
	}
};

//Lenovo的显卡类
class Lenovo02 :public VideoCard
{
	void display()
	{
		cout << "Lenovo的显卡开始工作了" << endl;
	}
};

//Lenovo的内存类
class Lenovo03 :public Memory
{
	void storage()
	{
		cout << "Lenovo的内存开始工作了" << endl;
	}
};

void test01()
{
	//创建Cpu型号
	Cpu* c1 = new Lenovo01;
	//创建显卡型号
	VideoCard* v1 = new Lenovo02;
	//创建内存型号
	Memory* m1 = new Lenovo03;
	//将三个零件组装成为电脑
	computer* c_c1=new computer (c1,v1,m1);
	//让电脑工作起来
	c_c1->Dowork();
}

int main()
{
	test01();
	return 0;
}