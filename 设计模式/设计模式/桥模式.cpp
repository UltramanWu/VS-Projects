//#include "桥模式1.h"
#include "桥模式2.h"
int main(){

	/*MobileMessagePerfect* s1 = new MobileMessagePerfect;
	s1->Login();
	s1->SendMessage();
	s1->SendPicture();*/

	PCMessageImp* s1 = new PCMessageImp;
	//运行时装配
	MessageLite * s2 = new MessageLite(s1);
	MessagePerfect* s3 = new MessagePerfect(s1);
	s2->Login();
	s2->SendMessage();
	s2->SendPicture();
	cout << endl;
	s3->Login();
	s3->SendMessage();
	s3->SendPicture();

	system("pause");
	return 0;
}