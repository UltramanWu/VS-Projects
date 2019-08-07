//#include "门面模式.h"
//
//int main(){
//	/* 不使用门面模式，需要用户自行记录过程，过程一旦出错就会邮递过程就不会成功 */
//	ILetterProcess* LetterProcess = new LetterProcessImp();
//	LetterProcess->writeContext("Hello,It`s me");
//	LetterProcess->fillEnvelope("Job", "Happy Road No.666 , God Province , Heaven");
//	LetterProcess->letterIntoEnvelope();
//	LetterProcess->sendLetter();
//
//	cout << endl;
//	/* 使用门面模式，接口对用户友好，邮递系统不对用户完全开放，邮递过程实现轻松简便 */
//	ILetterProcess* letterprocess = new LetterProcessImp();
//	ModernPost* modernpost = new ModernPost(letterprocess);
//	modernpost->sendletter("Hello,It`s me", "Job", "Happy Road No.666 , God Province , Heaven");
//
//	system("pause");
//	return 0;
//}