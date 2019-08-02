#include <iostream>
#include <string>
using namespace std;


class House{
public:
	House(){
		m_House = "";
	}
	void step(string strstep){
		m_House += "->" + strstep;
	}
	void PrintResult(){
		cout << m_House << endl;
	}
private:
	string m_House;
};

class HouseBuilder {
public:
	HouseBuilder(){
		pHouse = new House();
	}
	House* GetResult(){
		return pHouse;
	}
	virtual ~HouseBuilder(){}
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual void BuildPart3() = 0;

protected:
	House* pHouse;
};

class StoneHouse : public House{  //具体类的定义

};

class StoneHouseBuilder : public HouseBuilder{ //具体创建细节的实现
public:
	StoneHouseBuilder() :HouseBuilder(){}
protected:
	
	virtual void BuildPart1(){
		pHouse->step("Stone1");
	}
	virtual void BuildPart2(){
		pHouse->step("Stone2");
	}
	virtual void BuildPart3(){
		pHouse->step("Stone3");
	}
};

class WoodHouseBuilder : public HouseBuilder{
public:
	WoodHouseBuilder() :HouseBuilder(){}
protected:
	virtual void BuildPart1(){
		pHouse->step("Wood1");
	}
	virtual void BuildPart2(){
		pHouse->step("Wood2");
	}
	virtual void BuildPart3(){
		pHouse->step("Wood3");
	}
};

class HouseDirector{
	HouseBuilder* pHouseBuilder;
public:

	HouseDirector(){}
	void SetBuilder(HouseBuilder* housebuilder){
		pHouseBuilder = housebuilder;
	}
	House* Construct(){

		pHouseBuilder->BuildPart1();

		for (int i = 0; i < 4; i++){
			pHouseBuilder->BuildPart2();
		}

		pHouseBuilder->BuildPart3();

		return pHouseBuilder->GetResult();
	}
};






