#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ������ */
//���ݿ�����йصĻ���
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

/* ���󹤳��ࣺ����һϵ���໥�������ƹ����洴����new���Ķ��� */
class IDBFactory{
public:
	virtual IDBConnection* CreateDBConnection() = 0;
	virtual IDBCommand* CreateDBCommand() = 0;
	virtual IDBDataReader* CreateDataReader() = 0;
};


/* ����ʵ���� */
//֧��SQL Server
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

//֧��Oracle
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
		command->SetConnection(connection); //������

		IDBDataReader* reader = command->ExecuteReader(); //������
		while (reader->Read()){

		}
	}
};