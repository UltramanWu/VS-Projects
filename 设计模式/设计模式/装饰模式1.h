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

class CryptoFileStream :public FileStream{		/* 针对具体的流操作进行附加的操作，会导致大量的代码重复 */
public:
	void read(){
		cout << "read_encryption!" << endl;
		FileStream::read();//读文件流
	}
	void seek(){
		cout << "seek_encryption!" << endl;
		FileStream::seek();//定位文件流
	}
	void write(){
		cout << "write_encryption!" << endl;
		FileStream::write();//写文件流
	}
};

