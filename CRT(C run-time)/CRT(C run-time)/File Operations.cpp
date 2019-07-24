#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	cout << stdin << endl;
	cout << stdin->_file << endl;
	cout << stdout << endl;
	cout << stdout->_file << endl;
	cout << stderr << endl;
	cout << stderr->_file << endl;
	FILE *fp;
	fopen_s(&fp,"xxx.dat", "wb");
	cout << fp << endl;
	cout << fp->_file << endl;

	fwrite("abcde", 5, 1, fp);
	fclose(fp);
	cout << fp << endl;
	cout << fp->_file << endl;



	system("pause");
	return 0;
}