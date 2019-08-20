#include "interpreter.h"

int main(){
	string expStr = "a+b-c+d-e";
	map<char, int> var;
	var.insert(make_pair('a', 5));
	var.insert(make_pair('b', 2));
	var.insert(make_pair('c', 1));
	var.insert(make_pair('d', 6));
	var.insert(make_pair('e', 10));

	Expression* expression = analyse(expStr);
	int result = expression->interpreter(var);

	cout << result << endl;
	//cout << typeid(expression).name() << endl;
	release(expression);

	system("pause");
	return 0;
}