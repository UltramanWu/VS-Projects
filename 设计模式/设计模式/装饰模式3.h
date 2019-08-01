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


class DecoratorStream :public Stream{  /* 当装饰类中出现重复的成员变量，可以使用一个基类来让装饰类继承 */
protected:
	Stream* stream;
public:
	DecoratorStream(Stream *stm) :stream(stm){

	}
};

class CryptoStream :protected DecoratorStream{  /* 使用组合方式对流类型记性辨别，使用继承来统一化接口 */
public:
	CryptoStream(Stream* stm) :DecoratorStream(stm){  /* 构造函数进行流类型传值 */

	}
	virtual void read(){
		cout << "read_encryption!" << endl;
		stream->read();//读文件流
	}
	virtual void seek(){
		cout << "seek_encryption!" << endl;
		stream->seek();//定位文件流
	}
	virtual void write(){
		cout << "write_encryption!" << endl;
		stream->write();//写文件流
	}
};

class BufferedStream :protected DecoratorStream{
public:
	BufferedStream(Stream* stm) :DecoratorStream(stm){  /* 构造函数进行流类型传值 */

	}
	virtual void read(){
		cout << "read_Buffered!" << endl;
		stream->read();//读文件流
	}
	virtual void seek(){
		cout << "seek_Buffered!" << endl;
		stream->seek();//定位文件流
	}
	virtual void write(){
		cout << "write_Buffered!" << endl;
		stream->write();//写文件流
	}
};
