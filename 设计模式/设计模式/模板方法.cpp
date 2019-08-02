#include <iostream>
using namespace std;

//程序库开发人员
class Library{
public:
	void Step1(){
		cout << "Step1" << endl;
	}
	void Step3(){
		cout << "Step3" << endl;
	}
	void Step5(){
		cout << "Step4" << endl;
	}
};
//应用程序开发人员
class Application{
public:
	bool Step2(){
		return true;
	}
	void Step4(){
		cout << "Step4" << endl;
	}
};


int main()
{
	Library lib;
	Application app;

	lib.Step1();
	if (app.Step2()){
		lib.Step3();
	}
	for (int i = 0; i < 4; i++){
		app.Step4();
	}
	lib.Step5();
	system("pause");
	return 0;
}