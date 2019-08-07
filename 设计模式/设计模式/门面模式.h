#include <iostream>
#include <string>
using namespace std;

class ILetterProcess{
public:
	//首先要写信的内容
	virtual void writeContext(string context) = 0;
	//其次写信封
	virtual void fillEnvelope(string name,string address) = 0;
	//把信放到信封里
	virtual void letterIntoEnvelope() = 0;
	//邮递
	virtual void sendLetter() = 0;
};

//写信过程的实现
class LetterProcessImp :public ILetterProcess{
public:
	//写信
	virtual void writeContext(string context){
		cout << "填写信的内容..." + context << endl;
	}
	//填写信封
	virtual void fillEnvelope(string name,string address){
		cout << "填写收件人地址与姓名..." + name + address << endl;
	}
	//把信装入到信封之中
	virtual void letterIntoEnvelope(){
		cout << "把信放到信封中..." << endl;
	}
	//邮递
	virtual void sendLetter(){
		cout << "邮递邮件..." << endl;
	}

};


class ModernPost{
public:
	ModernPost(ILetterProcess* letterprocess):m_letterprocess(letterprocess){}
	/* 写信、封装、投递一体化 */
	void sendletter(string context,string name,string address){
		//帮你写信
		m_letterprocess->writeContext(context);
		//帮你写信封
		m_letterprocess->fillEnvelope(name, address);
		//装进信封
		m_letterprocess->letterIntoEnvelope();
		//投递
		m_letterprocess->sendLetter();
	}
private:
	ILetterProcess* m_letterprocess;
};