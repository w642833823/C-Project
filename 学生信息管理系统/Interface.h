#include <string>
#include <iostream>
#include <Windows.h>					//Sleep����,system

using namespace std;


class Interface
{
	
public:
	
	void Startface();					//��������
	void Loadface();					//������
	void Subloadface();					//�ӽ���
	void Subloadface2();				//�ӽ���2
	char Inputcharface();				//��ʾ�����ļ�����
	int  Operateface();					//�����������
	int	 Operateface2();				//�����������2
	int  Addface();						//������Ϣ����
	int  Delface();						//ɾ����Ϣ����
	int  Setface();						//�޸���Ϣ����
	int  Searchface();					//������Ϣ����
	void Search_afterface();			//��������Ϣ��ʾ����
	
	void Mark();						//��ǩ
	
};

