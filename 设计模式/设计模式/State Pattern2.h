#include <iostream>  
using namespace std;

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }  /* 安全删除 */

/*声明Context类*/
class Context;

/*抽象状态类:定义一个接口以封装与Context的一个特定状态相关的行为*/
class State
{
public:
	virtual void Handle(Context *pContext) = 0;
};

/*Context类，维护一个ConcreteState子类的实例，这个实例定义当前的状态*/
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
	State *m_pState; //这里的State指针是实现特定状态相关的关键
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


