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

class CryptoStream :public Stream{  /* ʹ����Ϸ�ʽ�������ͼ��Ա��ʹ�ü̳���ͳһ���ӿ� */
	Stream* stream;
public:
	CryptoStream(Stream* stm) :stream(stm){  /* ���캯�����������ʹ�ֵ */

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

class BufferedStream :public Stream{
	Stream* stream;
public:
	BufferedStream(Stream* stm) :stream(stm){  /* ���캯�����������ʹ�ֵ */

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
