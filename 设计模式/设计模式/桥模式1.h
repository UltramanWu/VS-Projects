#include <iostream>
using namespace std;

class Message{  /* �ܻ��� */
public:
	virtual void Login() = 0;
	virtual void SendMessage() = 0;
	virtual void SendPicture() = 0;

	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~Message(){}  /* �麯��ʽ�������� */
};

// ʵ���������m
class PCMessage : public Message{  /* PCƽ̨ʵ�ֺ��� */
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

class MobileMessage :public Message{  /* �ƶ�ƽ̨ʵ�ֺ��� */
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

/* ҵ�����m */

// ��ĸ�����1+n+n*m
class PCMessageLite : public PCMessage{  /* �����򻯰�ʵ�� */
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

class PCMessagePerfect :public PCMessage{  /* ����������ʵ�� */
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

class MobileMessageLite : public MobileMessage{ /* �����򻯰�ʵ�� */
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

class MobileMessagePerfect :public MobileMessage{ /* ����������ʵ�� */
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
