#include <iostream>
#include <list>
#include <string>
using namespace std;

class ProgressBar{
public:
	void SetValue(float Value){
		cout << Value*100 << "%" << endl;
	}
};

class FileSplitter{
	int m_fileNumber;
	ProgressBar* m_progressbar;
public:
	FileSplitter(int fileNumber) :
		m_fileNumber(fileNumber){}
	void Split(){
		//1.��ȡ���ļ�
		//2.��������С�ļ�д��
		for (int i = 0; i < m_fileNumber;i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			m_progressbar->SetValue(progressValue);
		}
	}
};

