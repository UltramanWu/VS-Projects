//#include "����ģʽ.h"
//
//int main(){
//	/* ��ʹ������ģʽ����Ҫ�û����м�¼���̣�����һ������ͻ��ʵݹ��̾Ͳ���ɹ� */
//	ILetterProcess* LetterProcess = new LetterProcessImp();
//	LetterProcess->writeContext("Hello,It`s me");
//	LetterProcess->fillEnvelope("Job", "Happy Road No.666 , God Province , Heaven");
//	LetterProcess->letterIntoEnvelope();
//	LetterProcess->sendLetter();
//
//	cout << endl;
//	/* ʹ������ģʽ���ӿڶ��û��Ѻã��ʵ�ϵͳ�����û���ȫ���ţ��ʵݹ���ʵ�����ɼ�� */
//	ILetterProcess* letterprocess = new LetterProcessImp();
//	ModernPost* modernpost = new ModernPost(letterprocess);
//	modernpost->sendletter("Hello,It`s me", "Job", "Happy Road No.666 , God Province , Heaven");
//
//	system("pause");
//	return 0;
//}