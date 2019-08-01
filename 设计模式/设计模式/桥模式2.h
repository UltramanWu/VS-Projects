#include <iostream>
using namespace std;

class MessageImp{
public:
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~MessageImp(){}  /* 虚函数式析构函数 */
};

class Message{  /* 总基类 */
protected:
	MessageImp* messageImp;
public:
	Message(MessageImp* Imp) :messageImp(Imp){}
	virtual void Login() = 0;
	virtual void SendMessage() = 0;
	virtual void SendPicture() = 0;

	virtual ~Message(){}  /* 虚函数式析构函数 */
};

// 实现类个数：n
class PCMessageImp : public MessageImp{  /* PC平台实现函数 */
public:
	virtual void PlaySound(){
		cout << "PC_PlaySound" << endl;
	}
	virtual void DrawShape(){
		cout << "PC_DrawShape" << endl;
	}
	virtual void WriteText(){
		cout << "PC_WriteText" << endl;
	}
	virtual void Connect(){
		cout << "PC_Connect" << endl;
	}
};

class MobileMessageImp :public MessageImp{  /* 移动平台实现函数 */
public:
	virtual void PlaySound(){
		cout << "Mobile_PlaySound" << endl;
	}
	virtual void DrawShape(){
		cout << "Mobile_DrawShape" << endl;
	}
	virtual void WriteText(){
		cout << "Mobile_WriteText" << endl;
	}
	virtual void Connect(){
		cout << "Mobile_Connect" << endl;
	}
};

/* 业务抽象m */
// 类的个数：1+n+n*m

class MessageLite : protected Message{  /* 函数简化版实现 */

public:
	MessageLite(MessageImp* Imp) :Message(Imp){}
	virtual void Login(){
		messageImp->Connect();
	}
	virtual void SendMessage(){
		messageImp->WriteText();
	}
	virtual void SendPicture(){
		messageImp->DrawShape();
	}
};

class MessagePerfect :protected Message{  /* 函数完整版实现 */
public:
	MessagePerfect(MessageImp* Imp) :Message(Imp){}
	virtual void Login(){
		messageImp->PlaySound();
		messageImp->Connect();
	}
	virtual void SendMessage(){
		messageImp->PlaySound();
		messageImp->WriteText();
	}
	virtual void SendPicture(){
		messageImp->PlaySound();
		messageImp->DrawShape();
	}
};
