#include "Element.h"
#include "Visitor.h"

Element::Element(){}
Element::~Element(){}

void ElementA::accept(Visitor& visitor){
	visitor.visitElementA(*this);
}
void ElementB::accept(Visitor& visitor){
	visitor.visitElementB(*this);
}

