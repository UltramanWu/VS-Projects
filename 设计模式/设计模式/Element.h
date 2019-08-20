#pragma once

class Visitor;

class Element{
public:
	Element();
	virtual ~Element() = 0;

	virtual void accept(Visitor& visitor) = 0;
};

class ElementA :public Element{
public:
	virtual void accept(Visitor& visitor) override;
};

class ElementB :public Element{
public:

	virtual void accept(Visitor& visitor) override;
};