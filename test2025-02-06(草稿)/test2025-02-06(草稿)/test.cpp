#include<iostream>
#include<string>
using namespace std;


//���󣺵�����Ҫ����ΪCPU�����ڼ��㣩���Կ���������ʾ�����ڴ��������ڴ洢��
//��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ����������磺intel��lenovo����
//�����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
//����ʱ��װ��̨��ͬ�ĵ��Խ��й���

//����������������
//1.CPU�ĳ�����
class Cpu
{
public:
	virtual void calculate() = 0;
};
//2.�Կ��ĳ�����
class VideoCard
{
public:
	virtual void display() = 0;
};
//3.�ڴ����ĳ�����
class Memory
{
public:
	virtual void storage() = 0;
};
//�����������
class computer
{
public:
	//���캯���д����������ָ��
	computer(Cpu *c,VideoCard *v,Memory *m)
	{
		m_c = c;
		m_m = m;
		m_v = v;
	}

	//����ÿ����������Ľӿ�
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
//��������̵���
//Intel��Cpu��
class Intel01:public Cpu
{
public:
	void calculate()
	{
		cout << "Intel��Cpu��ʼ������" << endl;
	}
};

//Intel���Կ���
class Intel02 :public VideoCard
{
	void display()
	{
		cout << "Intel���Կ���ʼ������" << endl;
	}
};

//Intel���ڴ���
class Intel03 :public Memory
{
	void storage()
	{
		cout << "Intel���ڴ濪ʼ������" << endl;
	}
};

//Lenovo��Cpu��
class Lenovo01 :public Cpu
{
public:
	void calculate()
	{
		cout << "Lenovo��Cpu��ʼ������" << endl;
	}
};

//Lenovo���Կ���
class Lenovo02 :public VideoCard
{
	void display()
	{
		cout << "Lenovo���Կ���ʼ������" << endl;
	}
};

//Lenovo���ڴ���
class Lenovo03 :public Memory
{
	void storage()
	{
		cout << "Lenovo���ڴ濪ʼ������" << endl;
	}
};

void test01()
{
	//����Cpu�ͺ�
	Cpu* c1 = new Lenovo01;
	//�����Կ��ͺ�
	VideoCard* v1 = new Lenovo02;
	//�����ڴ��ͺ�
	Memory* m1 = new Lenovo03;
	//�����������װ��Ϊ����
	computer* c_c1=new computer (c1,v1,m1);
	//�õ��Թ�������
	c_c1->Dowork();
}

int main()
{
	test01();
	return 0;
}