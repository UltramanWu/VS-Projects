#include <iostream>
#include <map>
#include <stack>
using namespace std;

class Expression{
public:
	virtual int interpreter(map<char, int> var) = 0;
	virtual ~Expression(){}
};

/* 变量表达式 */
class VarExpression :public Expression{
	char Key;
public:
	VarExpression(const char& key) :Key(key){
	}
	int interpreter(map<char, int> var) override{
		return var[Key];
	}

};

/* 符号表达式 */
class SymbolExpression :public Expression{
	//运算符左右两个参数
protected:
	Expression* left;
	Expression* right;
public:
	SymbolExpression(Expression* left, Expression* right) :left(left), right(right){

	}

};

/* 符号表达式 */
class AddExpression :public SymbolExpression{
public:
	AddExpression(Expression* left, Expression* right) :SymbolExpression(left, right){}

	int interpreter(map<char, int> var) override{
		/*cout << typeid(*left).name() << endl;
		cout << typeid(*right).name() << endl;*/
		return left->interpreter(var) + right->interpreter(var);  /* 通过多态调用 */
	}
};

class SubExpression :public SymbolExpression{
public:
	SubExpression(Expression* left, Expression* right):SymbolExpression(left,right){}

	int interpreter(map<char, int> var) override {
		/*cout << typeid(*left).name() << endl;
		cout << typeid(*right).name() << endl;*/
		return left->interpreter(var) - right->interpreter(var);  /* 通过多态调用 */
	}
};

Expression* analyse(string expStr){

	stack<Expression*> expStack;
	Expression* left = nullptr;
	Expression* right = nullptr;
	for (int i = 0; i < expStr.size(); i++){
		switch (expStr[i])
		{
			case '+':
				/* 加法运算 */
				left = expStack.top();
				//expStack.pop();
				right = new VarExpression(expStr[++i]);
				expStack.push(new AddExpression(left, right));
				break;
			case '-':
				/* 减法运算 */
				left = expStack.top();
				//expStack.pop();
				right = new VarExpression(expStr[++i]);
				expStack.push(new SubExpression(left, right));
				break;
			default:
				expStack.push(new VarExpression(expStr[i]));
		}
	}
	Expression* expression = expStack.top();
	return expression;
}


/* 空间释放函数 */
void release(Expression* expression){

}

