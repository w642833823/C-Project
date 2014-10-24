#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<windows.h>								//调用API
using namespace std;

class Student
{
private:
	
	int	   No;									//序号
	string Num;									//学号
	string Name;								//姓名
	string Birthday;							//出生日期
	string Sex;									//性别
	string Political_appearance;				//政治面貌
	string Phone_number;						//手机号码
	string Address;								//家庭地址
public:
	
	void SetNo(int i)	{	No = i;}			//设置学号
	void Setinformation(string,string,string,string,string,string,string);  // 修改函数
	void SetNum();								//修改学号			
	void SetName()		{cin>>Name;}			//修改姓名
	void SetBirthday();							//修改生日
	void SetSex()		{cin>>Sex;}				//修改性别
	void SetPolitical_appearance()	{cin>>Political_appearance;}			//修改政治面貌
	void SetPhone_number();						//修改电话号码
	void SetAddress()   {cin>>Address ;}		//修改家庭地址
	void Numshow(int,int);						//学号高亮显示
	void Addressshow(int,int);					//家庭地址高亮显示
	void Show();								//普通显示
	
	string GetNum()		{ return Num;}			//获取学号
	string GetName()	{ return Name;}			//获取姓名
	string GetBirthday(){ return Birthday;}		//获取生日
	string GetSex()		{ return Sex;}			//获取性别
	string GetPolitical_appearance() { return Political_appearance;}//获取政治面貌
	string GetPhone_number()		 { return Phone_number;}		//获取电话号码
	string GetAddress()				 { return Address;}				//获取家庭地址
};



#endif







