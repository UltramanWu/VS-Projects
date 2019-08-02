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
class IDBConnectionFactory{
public:
	virtual IDBConnection* CreateDBConnection() = 0;
};


class IDBCommand{
public:
	virtual void CommandText(string) = 0;
	virtual void SetConnection(IDBConnection*) = 0;
	virtual IDBDataReader* ExecuteReader() = 0;
	~IDBCommand(){}
};
class IDBCommandFactory{
public:
	virtual IDBCommand* CreateDBCommand() = 0;
};


class IDBDataReader{
	public:
	virtual int Read() = 0;
};
class IDataReaderFactory{
public:
	virtual IDBDataReader* CreateDataReader() = 0;
};

/* 具体实现类 */
//支持SQL Server
class SqlConnection : public IDBConnection{
	
};
class SqlConnectionFactory :public IDBConnectionFactory{

};

class SqlCommand : public IDBCommand{

};
class SqlCommandFactory :public IDBCommandFactory{

};

class SqlDataReader : public IDBDataReader{

};
class SqlDataReaderFactory :public IDataReaderFactory{

};

//支持Oracle
class OracleConnection : public IDBConnection{

};

class OracleCommand : public IDBCommand{

};

class OracleDataReader : public IDBDataReader{

};

class EmployeeDAO{
	IDBConnectionFactory* dbConnectionFactory;
	IDBCommandFactory* dbCommandFactory;
	IDataReaderFactory* dataReaderFactory;
public:
	vector<EmployeeDAO> GetEmployees(){
		IDBConnection* connection =
			dbConnectionFactory->CreateDBConnection();
		connection->ConnectionString("...");

		IDBCommand* command =
			dbCommandFactory->CreateDBCommand();
		command->CommandText("...");
		command->SetConnection(connection); //关联性

		IDBDataReader* reader = command->ExecuteReader(); //关联性
		while (reader->Read()){

		}
	}
};