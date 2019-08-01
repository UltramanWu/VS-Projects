#include <iostream>
using namespace std;

class Message{  /* 总基类 */
public:
	virtual void Login() = 0;
	virtual void SendMessage() = 0;
	virtual void SendPicture() = 0;

	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~Message(){}  /* 虚函数式析构函数 */
};

// 实现类个数：m
class PCMessage : public Message{  /* PC平台实现函数 */
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

class MobileMessage :public Message{  /* 移动平台实现函数 */
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
class PCMessageLite : public PCMessage{  /* 函数简化版实现 */
public:
	virtual void Login(){
		PCMessage::Connect();
	}
	virtual void SendMessage(){
		PCMessage::WriteText();
	}
	virtual void SendPicture(){
		PCMessage::DrawShape();
	}
};

class PCMessagePerfect :public PCMessage{  /* 函数完整版实现 */
public:
	virtual void Login(){
		PCMessage::PlaySound();
		PCMessage::Connect();
	}
	virtual void SendMessage(){
		PCMessage::PlaySound();
		PCMessage::WriteText();
	}
	virtual void SendPicture(){
		PCMessage::PlaySound();
		PCMessage::DrawShape();
	}
};

class MobileMessageLite : public MobileMessage{ /* 函数简化版实现 */
public:
	virtual void Login(){
		MobileMessage::Connect();
	}
	virtual void SendMessage(){
		MobileMessage::WriteText();
	}
	virtual void SendPicture(){
		MobileMessage::DrawShape();
	}
};

class MobileMessagePerfect :public MobileMessage{ /* 函数完整版实现 */
public:
	virtual void Login(){
		MobileMessage::PlaySound();
		MobileMessage::Connect();

	}
	virtual void SendMessage(){
		MobileMessage::PlaySound();
		MobileMessage::WriteText();
	}
	virtual void SendPicture(){
		MobileMessage::PlaySound();
		MobileMessage::DrawShape();
	}
};
