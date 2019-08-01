#include <iostream>
using namespace std;

class ISplitter{
public:
	virtual void split() = 0;
	virtual ~ISplitter(){}
};

class BinarySplitter : public ISplitter{
public:
	BinarySplitter(){}
	virtual void split(){}
};

class TxtSplitter : public ISplitter{

};

class PictureSplitter : public ISplitter{

};

class VideoSplitter : public ISplitter{

};

class MainForm
{

public:
	void Button1_Click(){

		ISplitter * splitter =
			new BinarySplitter;//ÒÀÀµ¾ßÌåÀà

		splitter->split();
	}
};