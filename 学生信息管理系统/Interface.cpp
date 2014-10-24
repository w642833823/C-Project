#include <iostream>
#include "Interface.h"
using namespace std;

void Interface::Startface()
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
		<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<" 启动中...";
	cout<<endl;
	for(int i = 0;i<80;i++)
	{
		Sleep(8);
		cout<<">";
	}
	system("cls");
}

void Interface::Loadface()
{
	cout<<endl<<endl;
	cout<<"                          学 生 信 息 管 理 系 统 "<<endl<<endl;
	cout<<"    ##################################################################"<<endl;
	cout<<"    #                                                                #"<<endl;
	cout<<"    #   1.增加学生记录    #   2.删除学生记录   #    3.修改学生记录   #"<<endl;
	cout<<"    #   4.找查学生记录    #   5.显示学生记录   #    6.退出           #"<<endl;
	cout<<"    #                                                                #"<<endl;
	cout<<"    ##################################################################"<<endl;
	cout<<endl;
	
}

void Interface::Subloadface2()
{
	cout<<endl;
	cout<<"    =======================+++操 - 作 - 提 - 示+++===================="<<endl
		<<"    |    1.增加学生记录   |    6.退出                                |"<<endl
		<<"    =================================================================="<<endl;
	cout<<endl;
}
void Interface::Subloadface()
{
	cout<<endl<<endl;
	cout<<"    =======================+++操 - 作 - 提 - 示+++===================="<<endl
		<<"    |    1.增加学生记录   |    2.删除学生记录    |   3.修改学生记录  |"<<endl
		<<"    |    4.找查学生记录   |    5.显示学生记录    |   6.退出          |"<<endl
		<<"    =================================================================="<<endl;
	cout<<endl;
}

char Interface::Inputcharface()
{
	char op_char;
	cout<<"需要导入文件吗?(Y/N):";
	cin>>op_char;
	return op_char;
}

int Interface::Operateface()
{
	string op_num;
	int flag,nflag = 0 ;
	
	do
	{
		flag = 0;
		if(nflag)
		{
			cout<<"超出范围..Again:";
			cin>>op_num;
		}
		else
		{
			cout<<"输入你的操作:";
			cin>>op_num;
		}
		
		if (op_num.length() != 1) { flag ++; nflag ++;}
		if(op_num[0] >'6'||op_num[0]<'0') { flag ++; nflag ++;}
	}while(flag);
	
	return op_num[0]-'0';
}

int Interface::Operateface2()
{
	string op_num;
	int flag,nflag = 0 ;
	
	do
	{
		flag = 0;
		if(nflag)
		{
			cout<<"超出范围..Again:";
			cin>>op_num;
		}
		else
		{
			cout<<"输入你的操作:";
			cin>>op_num;
		}
		
		if (op_num.length() != 1) { flag ++; nflag ++;}
		if(op_num[0] != '6'&&op_num[0] != '1') { flag ++; nflag ++;}
	}while(flag);
	
	return op_num[0]-'0';
}

int Interface::Addface()
{
	int num;
	cout<<"请输入要添加学生的人数(若退出,输入0):";
	cin>>num;
	return num;
}

int Interface::Delface()
{
	int no;
	cout<<"请输入注销学生的序号(若退出,输入0):";
	cin>>no;
	return no;
}

int Interface::Setface()
{
	int no;
	cout<<"输入要修改的学生序号(若退出,输入0):";
	cin>>no;
	
	if(no)
	{
		cout<<"输入你要改的学生的信息代号"<<endl
			<<"(1.学号,2.姓名,3.出生日期,4.性别,5.政治面貌,6手机号码,7.家庭地址)"<<endl
			<<"如果你要全部修改,则输入0..."<<endl;
		cout<<"代码:";
	}
	return no;
}

int Interface::Searchface()
{
	int no;
	cout<<"输入搜索的类型"<<endl<<"1.学号,2.姓名,3.性别,4.政治面貌,5.家庭地址"<<endl;
	cout<<"类型(若退出,输入0):";
	cin>>no;
	
	return no;
}

void Interface::Search_afterface()				//搜索结果
{
	int i;
	cout<<endl;
	for(i = 0;i<36;i++) cout<<"~";
	cout<<"搜索结果";
	for(i = 0;i<36;i++) cout<<"~";
}

void Interface::Mark()							//标签
{
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"                                                                 本程序参与者:"<<endl<<endl
		<<"                                                                  梁增国  骆慧"<<endl
		<<"                                                                 杨妙云  郭楚贤"<<endl
		<<"                                                               谢谢支持  !!!!  "<<endl;
}



