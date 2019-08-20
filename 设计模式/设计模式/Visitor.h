#pragma once

#include "Element.h"

class Visitor{
public:
	Visitor();
	virtual ~Visitor() = 0;

	virtual void visitElementA(ElementA& element) = 0;
	virtual void visitElementB(ElementB& element) = 0;
};

class Visitor1 :public Visitor{
public:
	virtual void visitElementA(ElementA& element) override;
	virtual void visitElementB(ElementB& element) override;
};

class Visitor2 :public Visitor{
public:
	virtual void visitElementA(ElementA& element) override;
	virtual void visitElementB(ElementB& element) override;
};

