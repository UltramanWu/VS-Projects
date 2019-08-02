#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 抽象类 */
//数据库访问有关的基类
class IDBConnection{
public:
	virtual void ConnectionString(string) = 0;
	~IDBConnection(){}
};

class IDBCommand{
public:
	virtual void CommandText(string) = 0;
	virtual void SetConnection(IDBConnection*) = 0;
	virtual IDBDataReader* ExecuteReader() = 0;
	~IDBCommand(){}
};

class IDBDataReader{
public:
	virtual int Read() = 0;
};

/* 抽象工厂类：创建一系列相互依赖且绕过常规创建（new）的对象 */
class IDBFactory{
public:
	virtual IDBConnection* CreateDBConnection() = 0;
	virtual IDBCommand* CreateDBCommand() = 0;
	virtual IDBDataReader* CreateDataReader() = 0;
};


/* 具体实现类 */
//支持SQL Server
class SqlConnection : public IDBConnection{

};

class SqlCommand : public IDBCommand{

};

class SqlDataReader : public IDBDataReader{

};

class SqlDBFactory :public IDBFactory{
public:
	virtual IDBConnection* CreateDBConnection() = 0;
	virtual IDBCommand* CreateDBCommand() = 0;
	virtual IDBDataReader* CreateDataReader() = 0;
};

//支持Oracle
class OracleConnection : public IDBConnection{

};

class OracleCommand : public IDBCommand{

};

class OracleDataReader : public IDBDataReader{

};

class OracleDBFactory :public IDBFactory{
public:
	virtual IDBConnection* CreateDBConnection() = 0;
	virtual IDBCommand* CreateDBCommand() = 0;
	virtual IDBDataReader* CreateDataReader() = 0;
};

class EmployeeDAO{
	IDBFactory* dbFactory;

public:
	vector<EmployeeDAO> GetEmployees(){
		IDBConnection* connection =
			dbFactory->CreateDBConnection();
		connection->ConnectionString("...");

		IDBCommand* command =
			dbFactory->CreateDBCommand();
		command->CommandText("...");
		command->SetConnection(connection); //关联性

		IDBDataReader* reader = command->ExecuteReader(); //关联性
		while (reader->Read()){

		}
	}
};