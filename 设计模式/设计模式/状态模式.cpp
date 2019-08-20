//#include "State Pattern2.h"
//#include "State2.h"
//
//int main()
//{
//	State *pStateA = new ConcreteStateA();//初始化两个具体状态类对象
//	State *pStateB = new ConcreteStateB();
//	Context *pContext = new Context(pStateA); //将具体状态类对象交由Context类管理
//
//	pContext->Request();//Context类根据对象状态，调用该对象的特定函数Request
//	pContext->ChangeState(pStateB); //改变对象状态
//	pContext->Request();
//
//	SAFE_DELETE(pContext);
//	SAFE_DELETE(pStateB);
//	SAFE_DELETE(pStateA);
//
//	/*NetWorkState *pStateOpen = new OpenState;
//	NetWorkState *pStateClose = new CloseState();
//	NetWorkState *pStateConnect = new ConnectState();
//	NetWorkProcess *pProcess = new NetWorkProcess(pStateClose);
//
//	pProcess->Hand();
//	pProcess->ChangState(pStateOpen);
//	pProcess->Hand();
//	pProcess->ChangState(pStateConnect);
//	pProcess->Hand();*/
//
//	system("pause");
//	return 0;
//}