#include <iostream>
#include <windows.h>
using namespace std;

class NetWorkProcess;

class NetWorkState{
public:
	NetWorkProcess* Process;
	virtual void Handle() = 0;
	virtual void ChangeState(NetWorkState* State) = 0;
};


class OpenState :public NetWorkState{  /* ¿ªÆô×´Ì¬ */
public:
	virtual void Handle(){
		cout << "System State is Opened!" << endl;
	}
	/*virtual void ChangeState(NetWorkState* State){
		Process->ChangState(State);
		}*/
};

class CloseState :public NetWorkState{  /* ¹Ø±Õ×´Ì¬ */
public:
	virtual void Handle(){
		cout << "System State is Closed!" << endl;
	}
};

class ConnectState :public NetWorkState{  /* Á¬½Ó×´Ì¬ */
	int count = 0;
public:
	ConnectState(){
		count = 0;
	}
	virtual void Handle(){
		while (1){
			cout << "System State is Connected........" << endl;
			Sleep(1 * 1000);
			count++;
			if (count == 5)
				break;
		}
	}
};

class NetWorkProcess{
	NetWorkState* pState;
public:
	NetWorkProcess(NetWorkState* state) :pState(state){}
	void ChangState(NetWorkState* State){
		pState = State;
	}
	virtual void Hand(){
		if (pState)
			pState->Handle();
	}
};


