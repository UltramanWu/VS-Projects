//#include "构建器模式.h"
//
//int main(){
//	HouseDirector* Director = new HouseDirector();
//	HouseBuilder* Bulider1 = new WoodHouseBuilder();
//	HouseBuilder* Builder2 = new StoneHouseBuilder();
//
//	Director->SetBuilder(Bulider1);
//	House* house1 = Director->Construct();
//	house1->PrintResult();
//	cout << endl;
//	Director->SetBuilder(Builder2);
//	House* house2 = Director->Construct();
//	house2->PrintResult();
//	system("pause");
//	return 0;
//}