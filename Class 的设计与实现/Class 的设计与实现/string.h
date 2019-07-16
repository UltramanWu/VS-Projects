#ifndef _SSTRING_
#define _SSTRING_
#include <cstring>
using namespace std;
class sstring
{
public:
	sstring(const char* cstr = 0);  /* Ĭ�Ϲ��캯�� */
	sstring(const sstring& str);  /* �������캯�� */
	sstring& operator =(const sstring& str);/* ������ֵ���� */
	~sstring();  /* �������� */

	char* c_str() const;

private:
	char* m_data;  /* ���ڴ洢ͷ����ָ�� */
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

inline sstring::sstring(const sstring& str)  /* ������������ӵ�����£�����ʹ�������������������û����������Ч�ʵ�����������ڴ�ʹ���� */
{
	m_data = new char[strlen(str.m_data)+1 ];
	strcpy_s(m_data, strlen(str.m_data) + 1, str.m_data);
}

inline sstring& sstring::operator=(const sstring& str)  /* ����������value����reference�����ԣ����Ƿ��ص�ֵ�����Ǹ������� */
{
	if (this == &str)  /* ����ڸò�û�н����жϵĻ������е���һ�����������ͬ������µ���ָ����������٣���ʱ�ᱨ�� */
		return *this;

	delete[] m_data;  /* ����ԭ�������ݲ��ͷ�ԭ�����ڴ� */
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