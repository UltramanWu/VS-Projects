#include "Visitor.h"
#include <iostream>
using namespace std;


Visitor::Visitor(){}
Visitor::~Visitor(){}

void Visitor1::visitElementA(ElementA& element){
	cout << "Visitor1 is visiting ElementA" << endl;
}

void Visitor1::visitElementB(ElementB& element){
	cout << "Visitor1 is visiting ElementB" << endl;
}

void Visitor2::visitElementA(ElementA& element){
	cout << "Visitor2 is visiting ElementA" << endl;
}

void Visitor2::visitElementB(ElementB& element){
	cout << "Visitor2 is visiting ElementB" << endl;
}