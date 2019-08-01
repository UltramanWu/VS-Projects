#include <iostream>
using namespace std;


class Stream{
public:
	virtual void write(){
		cout << "Stream write!" << endl;
	}
	virtual void seek(){
		cout << "Stream Seek!" << endl;
	}
	virtual void read(){
		cout << "Stream Read!" << endl;
	}
	virtual ~Stream(){}
};

class FileStream : public Stream{
public:
	virtual void write(){
		cout << "FileStream write!" << endl;
	}
	virtual void seek(){
		cout << "FlieStream Seek!" << endl;
	}
	virtual void read(){
		cout << "FileStream Read!" << endl;
	}

};

class Newworks :public Stream{
public:
	virtual void write(){
		cout << "NetWorksStream write!" << endl;
	}
	virtual void seek(){
		cout << "NetWorksStream Seek!" << endl;
	}
	virtual void read(){
		cout << "NetWorksStream Read!" << endl;
	}
};

class MemoryStream :public Stream{
public:
	virtual void write(){
		cout << "MemoryStream write!" << endl;
	}
	virtual void seek(){
		cout << "MemoryStream Seek!" << endl;
	}
	virtual void read(){
		cout << "MemoryStream Read!" << endl;
	}
};


class DecoratorStream :public Stream{  /* ��װ�����г����ظ��ĳ�Ա����������ʹ��һ����������װ����̳� */
protected:
	Stream* stream;
public:
	DecoratorStream(Stream *stm) :stream(stm){

	}
};

class CryptoStream :protected DecoratorStream{  /* ʹ����Ϸ�ʽ�������ͼ��Ա��ʹ�ü̳���ͳһ���ӿ� */
public:
	CryptoStream(Stream* stm) :DecoratorStream(stm){  /* ���캯�����������ʹ�ֵ */

	}
	virtual void read(){
		cout << "read_encryption!" << endl;
		stream->read();//���ļ���
	}
	virtual void seek(){
		cout << "seek_encryption!" << endl;
		stream->seek();//��λ�ļ���
	}
	virtual void write(){
		cout << "write_encryption!" << endl;
		stream->write();//д�ļ���
	}
};

class BufferedStream :protected DecoratorStream{
public:
	BufferedStream(Stream* stm) :DecoratorStream(stm){  /* ���캯�����������ʹ�ֵ */

	}
	virtual void read(){
		cout << "read_Buffered!" << endl;
		stream->read();//���ļ���
	}
	virtual void seek(){
		cout << "seek_Buffered!" << endl;
		stream->seek();//��λ�ļ���
	}
	virtual void write(){
		cout << "write_Buffered!" << endl;
		stream->write();//д�ļ���
	}
};
