#include <iostream>
#include <list>
using namespace std;

class IProgress{
public:
	virtual void DoProgress(float Value) = 0;
	virtual ~IProgress(){}
};

class FileSplitter{
	int m_fileNumber;
	list<IProgress*> m_progressbarlist;
public:
	FileSplitter(int fileNumber) :
		m_fileNumber(fileNumber){}
	void addIProgress(IProgress* iprogress){
		m_progressbarlist.push_back(iprogress);
	}
	void removeIProgress(IProgress* iprogress){
		m_progressbarlist.remove(iprogress);
	}
	void Split(){
		//1.读取大文件
		//2.分批次向小文件写入
		for (int i = 0; i < m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			list<IProgress*>::iterator itor = m_progressbarlist.begin();
			while (itor != m_progressbarlist.end()){
				(*itor)->DoProgress(progressValue);  /* 通过动态调用函数 */
				itor++;
			}
		}
	}
};


class TextProgressBar :public IProgress{
public:
	void SetValue(float Value){
		cout << Value * 100 << "%" << endl;
	}
};

class ConsoleNotifier :public IProgress{
public:
	virtual void DoProgress(float Value){
		SetValue(Value);
	}
	void SetValue(float Value){
		cout << Value << endl;
	}
};

class MainForm :public IProgress{
	int m_FileNumber;
	TextProgressBar* ProgressBar;
public:
	MainForm(int FileNumber) :m_FileNumber(FileNumber){}
	void Button_clicked(){
		ConsoleNotifier cn;
		FileSplitter splitter(m_FileNumber);
		splitter.addIProgress(this);
		splitter.addIProgress(&cn);
		splitter.Split();
	}
	virtual void DoProgress(float Value){
		ProgressBar->SetValue(Value);
	}
};
