#include "Student.h"
#include <iostream>
using namespace std;

void Student::Setinformation(string num,string name,string birthday,string sex,
							 string political_app,string phone_num,string address)
{
	Num = num;
	Name = name;
	Birthday = birthday;
	Sex = sex;
	Political_appearance = political_app;
	Phone_number = phone_num;
	Address = address;
}
void Student::SetNum()
{
	int flag,nflag = 0;
	string num;
	
	do
	{
		flag = 0;
		if (nflag) cout<<"格式错误..Again:";
		cin>>num;
		for(int i = 0;i<num.length();i++)
		{
			if(num[i] > '9'||num[i] < '0') 
			{
				flag = 1;
				nflag++;
				break;
			}
		}
		
	}while(flag);
	if(!flag) Num = num;
}

void Student::SetBirthday()
{
int flag,nflag = 0;
	string birthday;
	
	do
	{
		flag = 0;
		if (nflag) cout<<"格式错误..Again:";
		cin>>birthday;
		for(int i = 0;i<birthday.length();i++)
		{
			if((birthday[i] > '9'||birthday[i] < '0')&&birthday[i]!='/') 
			{
				flag = 1;
				nflag++;
				break;
			}
		}
		
	}while(flag);
	
	if(!flag) Birthday = birthday;
}

void Student::SetPhone_number()
{
	int flag,nflag = 0;
	string phone_number;
	
	do
	{
		flag = 0;
		if (nflag) cout<<"格式错误..Again:";
		cin>>phone_number;
		for(int i = 0;i<phone_number.length();i++)
		{
			if(phone_number[i] > '9'||phone_number[i] < '0') 
			{
				flag = 1;
				nflag++;
				break;
			}
		}
		
	}while(flag);
	
	if(!flag) Phone_number = phone_number;
}
void Student::Numshow(int Begin,int End)
{
	cout<<"序号:"<<No<<endl;
	cout<<"学号";
	HANDLE ohandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for(int i = 0;i<Begin;i++) cout<<Num[i];
	SetConsoleTextAttribute(ohandle,BACKGROUND_INTENSITY);			//背景高亮
	
	for(i = Begin;i<End;i++) cout<<Num[i];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),		//恢复默认系统颜色
		FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_BLUE);  
	for(i = End;i<Num.length();i++) cout<<Num[i];
	cout<<"   "
		<<"姓名:"<<Name<<"    " 
		<<"出生日期:"<<Birthday<<"  "
		<<"性别:"<<Sex<<"  "
		<<"政治面貌:"<<Political_appearance<<endl
		<<"手机号码:"<<Phone_number<<"  ";
	cout<<endl<<endl;
}

void Student::Addressshow(int Begin,int End)
{
	cout<<"序号:"<<No<<endl
		<<"学号"<<Num<<"   "
		<<"姓名:"<<Name<<"    " 
		<<"出生日期:"<<Birthday<<"  "
		<<"性别:"<<Sex<<"  "
		<<"政治面貌:"<<Political_appearance<<endl
		<<"手机号码:"<<Phone_number<<"  ";
	HANDLE ohandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for(int i = 0;i<Begin;i++) cout<<Address[i];
	SetConsoleTextAttribute(ohandle,BACKGROUND_INTENSITY);				//背景高亮
	
	for(i = Begin;i<End;i++) cout<<Address[i];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),			//恢复默认系统颜色
		FOREGROUND_RED| FOREGROUND_GREEN| FOREGROUND_BLUE);  
	for(i = End;i<Address.length();i++) cout<<Address[i];
	cout<<endl<<endl;
}

void Student::Show()									//普通方式显示信息
{
	cout<<"序号:"<<No<<endl
		<<"学号"<<Num<<"   "
		<<"姓名:"<<Name<<"    " 
		<<"出生日期:"<<Birthday<<"  "
		<<"性别:"<<Sex<<"  "
		<<"政治面貌:"<<Political_appearance<<endl
		<<"手机号码:"<<Phone_number<<"  "
		<<"家庭地址:"<<Address<<endl<<endl;
}
