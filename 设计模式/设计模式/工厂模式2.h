#include <iostream>
using namespace std;

// ʵ�ֻ���
class ISplitter{
public:
	virtual void split() = 0;
	virtual ~ISplitter(){}
};
// ��������
class ISplitterFactory{
public:
	virtual ISplitter* CreateISplitter() = 0;
	virtual ~ISplitterFactory(){}
};
//ʵ������
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

//��������
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

// ��ĵ���
class MainForm
{

public:
	void Button1_Click(){
		ISplitterFactory* factory;
		ISplitter *splitter =factory->CreateISplitter();//����������

		splitter->split();
	}
};