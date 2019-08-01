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

class CryptoFileStream :public FileStream{		/* ��Ծ�������������и��ӵĲ������ᵼ�´����Ĵ����ظ� */
public:
	void read(){
		cout << "read_encryption!" << endl;
		FileStream::read();//���ļ���
	}
	void seek(){
		cout << "seek_encryption!" << endl;
		FileStream::seek();//��λ�ļ���
	}
	void write(){
		cout << "write_encryption!" << endl;
		FileStream::write();//д�ļ���
	}
};

