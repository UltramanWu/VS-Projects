#include <iostream>
using namespace std;

enum NetWorkState
{
	NetWork_Open,
	NetWork_Close,
	NetWork_Connected,
};

class NetWorkProcess{
	NetWorkState state;
public:
	void operation1(){
		if (state == NetWork_Open){
			cout << "Make NetWork Connect" << endl;
			state = NetWork_Connected;
		}
		else if (state == NetWork_Close){
			cout << "Make NetWork Open" << endl;
			state = NetWork_Open;
		}
		else{
			cout << "Make NetWork Close" << endl;
			state = NetWork_Close;
		}
	}
	void operation2(){
		if (state == NetWork_Open){
			cout << "Make NetWork Close" << endl;
			state = NetWork_Close;
		}
		else if (state == NetWork_Close){
			cout << "Make NetWork Open and Connect" << endl;
			state = NetWork_Open;
		}
		else{
			cout << "NetWork is Connecting" << endl;
			state = NetWork_Close;
		}
	}
	void operation3(){
		//...
		cout << "Do nothing!" << endl;
	}
};

