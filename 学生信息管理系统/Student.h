#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<windows.h>								//����API
using namespace std;

class Student
{
private:
	
	int	   No;									//���
	string Num;									//ѧ��
	string Name;								//����
	string Birthday;							//��������
	string Sex;									//�Ա�
	string Political_appearance;				//������ò
	string Phone_number;						//�ֻ�����
	string Address;								//��ͥ��ַ
public:
	
	void SetNo(int i)	{	No = i;}			//����ѧ��
	void Setinformation(string,string,string,string,string,string,string);  // �޸ĺ���
	void SetNum();								//�޸�ѧ��			
	void SetName()		{cin>>Name;}			//�޸�����
	void SetBirthday();							//�޸�����
	void SetSex()		{cin>>Sex;}				//�޸��Ա�
	void SetPolitical_appearance()	{cin>>Political_appearance;}			//�޸�������ò
	void SetPhone_number();						//�޸ĵ绰����
	void SetAddress()   {cin>>Address ;}		//�޸ļ�ͥ��ַ
	void Numshow(int,int);						//ѧ�Ÿ�����ʾ
	void Addressshow(int,int);					//��ͥ��ַ������ʾ
	void Show();								//��ͨ��ʾ
	
	string GetNum()		{ return Num;}			//��ȡѧ��
	string GetName()	{ return Name;}			//��ȡ����
	string GetBirthday(){ return Birthday;}		//��ȡ����
	string GetSex()		{ return Sex;}			//��ȡ�Ա�
	string GetPolitical_appearance() { return Political_appearance;}//��ȡ������ò
	string GetPhone_number()		 { return Phone_number;}		//��ȡ�绰����
	string GetAddress()				 { return Address;}				//��ȡ��ͥ��ַ
};



#endif







