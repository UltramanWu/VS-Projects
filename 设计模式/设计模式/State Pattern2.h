#include <iostream>  
using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }  /* ��ȫɾ�� */

/*����Context��*/
class Context;

/*����״̬��:����һ���ӿ��Է�װ��Context��һ���ض�״̬��ص���Ϊ*/
class State
{
public:
	virtual void Handle(Context *pContext) = 0;
};

/*Context�࣬ά��һ��ConcreteState�����ʵ�������ʵ�����嵱ǰ��״̬*/
class Context
{
public:
	Context(State *pState) : m_pState(pState){}

	void Request()
	{
		if (m_pState)
		{
			m_pState->Handle(this);
		}
	}

	void ChangeState(State *pState)
	{
		m_pState = pState;
	}

private:
	State *m_pState; //�����Stateָ����ʵ���ض�״̬��صĹؼ�
};

class ConcreteStateA : protected State
{
public:
	virtual void Handle(Context *pContext)
	{
		cout << "I am concretestateA." << endl;
	}
};

class ConcreteStateB : protected State
{
public:
	virtual void Handle(Context *pContext)
	{
		cout << "I am concretestateB." << endl;
	}
	
};


