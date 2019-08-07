#include <iostream>
#include <string>
using namespace std;

class ILetterProcess{
public:
	//����Ҫд�ŵ�����
	virtual void writeContext(string context) = 0;
	//���д�ŷ�
	virtual void fillEnvelope(string name,string address) = 0;
	//���ŷŵ��ŷ���
	virtual void letterIntoEnvelope() = 0;
	//�ʵ�
	virtual void sendLetter() = 0;
};

//д�Ź��̵�ʵ��
class LetterProcessImp :public ILetterProcess{
public:
	//д��
	virtual void writeContext(string context){
		cout << "��д�ŵ�����..." + context << endl;
	}
	//��д�ŷ�
	virtual void fillEnvelope(string name,string address){
		cout << "��д�ռ��˵�ַ������..." + name + address << endl;
	}
	//����װ�뵽�ŷ�֮��
	virtual void letterIntoEnvelope(){
		cout << "���ŷŵ��ŷ���..." << endl;
	}
	//�ʵ�
	virtual void sendLetter(){
		cout << "�ʵ��ʼ�..." << endl;
	}

};


class ModernPost{
public:
	ModernPost(ILetterProcess* letterprocess):m_letterprocess(letterprocess){}
	/* д�š���װ��Ͷ��һ�廯 */
	void sendletter(string context,string name,string address){
		//����д��
		m_letterprocess->writeContext(context);
		//����д�ŷ�
		m_letterprocess->fillEnvelope(name, address);
		//װ���ŷ�
		m_letterprocess->letterIntoEnvelope();
		//Ͷ��
		m_letterprocess->sendLetter();
	}
private:
	ILetterProcess* m_letterprocess;
};