#ifndef _SSTRING_
#define _SSTRING_
#include <cstring>
using namespace std;
class sstring
{
public:
	sstring(const char* cstr = 0);  /* 默认构造函数 */
	sstring(const sstring& str);  /* 拷贝构造函数 */
	sstring& operator =(const sstring& str);/* 拷贝赋值函数 */
	~sstring();  /* 析构函数 */

	char* c_str() const;

private:
	char* m_data;  /* 用于存储头结点的指针 */
};

inline sstring::sstring(const char* cstr )
{
	if (cstr)
	{
		m_data = new char[strlen(cstr) + 1];
		strcpy_s(m_data, strlen(cstr)+1,cstr );
	}
	else
	{
		m_data = new char[1];
		m_data = "\0";
	}
}

inline sstring::sstring(const sstring& str)  /* 如果函数不复杂的情况下，尽量使用内联函数，这种设置会在提高运行效率的情况下增大内存使用量 */
{
	m_data = new char[strlen(str.m_data)+1 ];
	strcpy_s(m_data, strlen(str.m_data) + 1, str.m_data);
}

inline sstring& sstring::operator=(const sstring& str)  /* 返回类型是value还是reference都可以，但是返回的值必须是该种类型 */
{
	if (this == &str)  /* 如果在该步没有进行判断的话，进行到下一步会把两者相同的情况下的所指向的数据销毁，此时会报错 */
		return *this;

	delete[] m_data;  /* 销毁原来的数据并释放原来的内存 */
	m_data = new char[strlen(str.m_data) + 1];
	strcpy_s(m_data,strlen(m_data)+1, str.m_data);
	return *this;
}


inline sstring::~sstring()
{
	delete[] m_data;
}

inline char* sstring::c_str() const
{
	return m_data;
}


#endif