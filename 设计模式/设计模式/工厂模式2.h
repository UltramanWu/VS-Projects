#include <iostream>
using namespace std;

// 实现基类
class ISplitter{
public:
	virtual void split() = 0;
	virtual ~ISplitter(){}
};
// 创建基类
class ISplitterFactory{
public:
	virtual ISplitter* CreateISplitter() = 0;
	virtual ~ISplitterFactory(){}
};
//实现子类
class BinarySplitter : public ISplitter{
public:
	BinarySplitter(){}
	virtual void split(){}
};

class TxtSplitter : public ISplitter{
public:
	virtual void split(){}
};

class PictureSplitter : public ISplitter{
public:
	virtual void split(){}
};

class VideoSplitter : public ISplitter{
public:
	virtual void split(){}
};

//创建子类
class BinarySplitterFactory :public ISplitterFactory{
	virtual ISplitter* CreateISplitter(){
		return new BinarySplitter;
	}
};
class TxtSplitterFactory :public ISplitterFactory{
	virtual ISplitter* CreateISplitter(){
		return new TxtSplitter;
	}
};
class PictureSplitterFactory :public ISplitterFactory{
	virtual ISplitter* CreateISplitter(){
		return new PictureSplitter;
	}
};
class VideoSplitterFactory :public ISplitterFactory{
	virtual ISplitter* CreateISplitter(){
		return new VideoSplitter;
	}
};

// 类的调用
class MainForm
{

public:
	void Button1_Click(){
		ISplitterFactory* factory;
		ISplitter *splitter =factory->CreateISplitter();//依赖具体类

		splitter->split();
	}
};