#include <iostream>
#include <map>
#include <stack>
using namespace std;

class Expression{
public:
	virtual int interpreter(map<char, int> var) = 0;
	virtual ~Expression(){}
};

/* �������ʽ */
class VarExpression :public Expression{
	char Key;
public:
	VarExpression(const char& key) :Key(key){
	}
	int interpreter(map<char, int> var) override{
		return var[Key];
	}

};

/* ���ű��ʽ */
class SymbolExpression :public Expression{
	//�����������������
protected:
	Expression* left;
	Expression* right;
public:
	SymbolExpression(Expression* left, Expression* right) :left(left), right(right){

	}

};

/* ���ű��ʽ */
class AddExpression :public SymbolExpression{
public:
	AddExpression(Expression* left, Expression* right) :SymbolExpression(left, right){}

	int interpreter(map<char, int> var) override{
		/*cout << typeid(*left).name() << endl;
		cout << typeid(*right).name() << endl;*/
		return left->interpreter(var) + right->interpreter(var);  /* ͨ����̬���� */
	}
};

class SubExpression :public SymbolExpression{
public:
	SubExpression(Expression* left, Expression* right):SymbolExpression(left,right){}

	int interpreter(map<char, int> var) override {
		/*cout << typeid(*left).name() << endl;
		cout << typeid(*right).name() << endl;*/
		return left->interpreter(var) - right->interpreter(var);  /* ͨ����̬���� */
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
				/* �ӷ����� */
				left = expStack.top();
				//expStack.pop();
				right = new VarExpression(expStr[++i]);
				expStack.push(new AddExpression(left, right));
				break;
			case '-':
				/* �������� */
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


/* �ռ��ͷź��� */
void release(Expression* expression){

}

