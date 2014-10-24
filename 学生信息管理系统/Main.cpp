#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>						//sort函数
#include "Interface.h"						//界面类
#include "Student.h"						//学生类
#include "Fileoperate.h"					//文本类
using namespace std;

const int student_num = 120 + 1;			//人数上限

int No = 1;									//序号
int Total = 0;								//总人数

Interface face;								//界面
Fileoperate Infile;							//读入文件类对象
Fileoperate Outfile;						//读出文件类对象

Student stu[student_num];					//学生类对象数组

int  switchfun(int);						//功能函数选择
void Allshow();								//显示所有学生信息
void Searchshow(int [],int,int,int,int);	//显示搜索信息
void InFile();								//读入文件函数
void OutFile();								//读出文件函数

int main()
{
	int op_num;								//操作序数
	char op_char;							//选择数
	char op_char2;							//是否保存
	face.Startface();						//启动界面
	face.Loadface();						//登陆界面
	
	int flag ,nflag = 0;					//输入格式判断标记
	do
	{
		flag = 0;
		if(nflag) cout<<"超出范围...Again:"<<endl;
		op_char = face.Inputcharface();
		if(op_char !='Y'&&op_char !='y'&&op_char !='N'&&op_char !='n') 
		{
			flag = 1;
			nflag = 1;
		}
	}while(flag);
	
	if (op_char == 'Y'||op_char =='y')						//选择是,读入文件
	{
		InFile();											//读入文件
		char Sub_op_char;
		nflag = 0;
		do
		{
			flag = 0;
			cout<<"已成功导入, 要显示资料吗?(Y/N):";
			cin>>Sub_op_char;
			if(Sub_op_char !='Y'&&Sub_op_char !='y'&&Sub_op_char !='N'&&Sub_op_char !='n') 
			{
				flag = 1;
			}
		}while(flag);
		
		if (Sub_op_char == 'Y'||Sub_op_char =='y')			//是否浏览已读入文件的信息
		{
			Allshow();										//显示所有信息
			face.Subloadface();
		}
		else 
		{
			if(Sub_op_char == 'N'||Sub_op_char =='n') ;     //不显示信息
		}
	}
	else 
	{
		if(op_char == 'N'||op_char =='n');
		face.Subloadface2();
	}
	
	while(1)										//程序执行过程
	{
		if(Total != 0) op_num = face.Operateface();		//获取操作数
		else op_num = face.Operateface2();				//获取操作数
		if(op_num == 6) break;						//输入6,跳出
		switchfun(op_num);							//功能选择
		if(Total != 0 ) face.Subloadface();			
		else 
		{
			cout<<endl;
			cout<<"学生数为零!";
			face.Subloadface2();
		}
		
	}	
	cout<<"要保存数据吗?(Y/N):";
	cin>>op_char2;
	
    if(op_char2 == 'Y'||op_char2 == 'y') 
	{
		cout<<endl<<"已保存!"<<endl;
		OutFile();									//读出文件
	}
	face.Mark();									//程序参与者标记
	
	system("pause");
	
	return 0;
}

int switchfun(int op_num)
{
	int i;
	int num;										//添加界面操作数
	string Num1;									//学号
	string Name1;									//姓名
	string Birthday1;								//出生日期
	string Sex1;									//性别
	string Political_appearance1;					//政治面貌
	string Phone_number1;							//手机号码
	string Address1;
	if (op_num == 1)
	{
		num = face.Addface();						//获取添加界面操作数
		if(num == 0) { cout<<"已退出,任意键继续..."; getchar(); getchar(); return 0;}
		for(i = 0;i<num;i++)
		{
			cout<<"输入第"<<i+1<<"个学生信息:\n";
			cout<<endl;
			cout<<"学号:";
			cin>>Num1;
			cout<<"姓名:";
			cin>>Name1;
			cout<<"出生日期:";
			cin>>Birthday1;
			cout<<"性别:";
			cin>>Sex1;
			cout<<"政治面貌:";
			cin>>Political_appearance1;
			cout<<"手机号码:";
			cin>>Phone_number1;
			cout<<"家庭地址:";
			cin>>Address1;
			cout<<endl;
			Total ++;
			stu[Total-1].SetNo(Total);			//设置序号	
			stu[Total-1].Setinformation(Num1,Name1,Birthday1,Sex1,Political_appearance1,
										  Phone_number1,Address1);
		}

		if(i == num) cout<<"添加完成!"<<endl;
	}
	else if(op_num == 2)
	{
		int no;										//删除界面操作数
		no = face.Delface();						//获取删除界面操作数
		if(no == 0) { cout<<"已退出,任意键继续..."; getchar(); getchar(); return 0;}
		for (i = no;i<Total;i++) { stu[i].SetNo(i);stu[i-1] = stu[i];}
		cout<<endl<<"删除该学生信息成功!"<<endl;
		cout<<"任意键继续...";
		getchar();getchar();
		Total --;	
	}
	else if(op_num == 3)
	{
		int no;
		char info[128];
		int a[14];
		int k = 0;
		
		int flag = 0;
		no = face.Setface();						//获取修改界面操作数
		if(no == 0) { cout<<"已退出,按任意键继续..."; getchar(); getchar(); return 0;}
		getchar();					
		gets(info);
		int l = strlen(info);
		i = 0;
		while(i<l)									//字符输入标准化
		{
			if(info[i]>='0'&&info[i]<='9') a[k++] = info[i]-'0';
			if(a[k-1]==0) { flag = 1; break;}
			i++;
		}
		
		sort(a,a+k);								//排序
		if(flag)									//如果输入零,修改全部信息
		{
			cout<<"学号:";
			cin>>Num1;
			cout<<"姓名:";
			cin>>Name1;
			cout<<"出生日期:";
			cin>>Birthday1;
			cout<<"性别:";
			cin>>Sex1;
			cout<<"政治面貌:";
			cin>>Political_appearance1;
			cout<<"手机号码:";
			cin>>Phone_number1;
			cout<<"家庭地址:";
			cin>>Address1;
			cout<<endl;
			stu[no-1].Setinformation(Num1,Name1,Birthday1,Sex1,Political_appearance1,Phone_number1,Address1);
		}
		else 
		{
			for(i = 0;i<k;i++)
			{
				switch(a[i])						//修改部分信息
				{
				case 1: 
					{
						cout<<"输入学号:";
						stu[no-1].SetNum();
						break;
					}
				case 2:
					{
						cout<<"输入姓名:";
						stu[no-1].SetName();
						break;
					}
				case 3:
					{
						cout<<"输入出生日期:";
						stu[no-1].SetBirthday();
						break;
					}
				case 4:
					{
						cout<<"输入性别:";
						stu[no-1].SetSex();
						break;
					}
				case 5:
					{
						cout<<"输入政治面貌:";
						stu[no-1].SetPolitical_appearance();
						break;
					}
				case 6:
					{
						cout<<"输入手机号码:";
						stu[no-1].SetPhone_number();
						break;
					}
				case 7:
					{
						cout<<"输入家庭地址:";
						stu[no-1].SetAddress();
						break;
					}
				}
			}
		}
		
		cout<<endl<<endl<<"已完成, 修改后:"<<endl;		//输出修改后信息
		for(i= 0;i<80;i++) cout<<"-"; 
		stu[no-1].Show();
		for(i= 0;i<80;i++) cout<<"-"; cout<<endl;
		cout<<"按任意键继续...";
		getchar();getchar();
		
	}
	else if(op_num == 4)
	{
		int no;
		int Begin,End;							//开始,结束位置
		int num = 0;									//符合搜索条件的人数
		string Ss;										//临时对象

		no = face.Searchface();							//获取搜索界面操作数
		if(no == 0) { cout<<"已退出,按任意键继续..."; getchar(); getchar(); return 0;}
		int flag = 0;
		
		switch(no)
		{
		case 1:											//按学号搜索
			{
				cout<<"输入关键字:";
				cin>>Num1;
				
				for( i = 0;i<Total;i++)
				{
					Ss = stu[i].GetNum();
					Begin = Ss.find(Num1,0);
					if(Begin != string::npos) 
					{
						End = Num1.length() + Begin;
						flag ++;
						if(flag == 1) face.Search_afterface();
						stu[i].Numshow(Begin,End);
						num++;
					}
				}
				if(!flag) cout<<"没此相关信息!"<<endl;
				else 
				{
					cout<<endl<<"共有"<<num<<"条相关信息!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		case 2:											//按名字搜索
			{
				cout<<"输入关键字:";
				cin>>Name1;
				
				for( i = 0;i<Total;i++)
				{
					Ss = stu[i].GetName();
					Begin = Ss.find(Name1,0);
					if(Begin != string::npos) 
					{
						flag ++;
						if(flag == 1) face.Search_afterface();
						stu[i].Show();
						num++;
					}
				}
				if(!flag) cout<<"没此相关信息!"<<endl;
				else 
				{
					cout<<endl<<"共有"<<num<<"条相关信息!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		case 3:												//按性别搜索
			{
				cout<<"输入关键字:";
				cin>>Sex1;
				
				for( i = 0;i<Total;i++)
				{
					Ss = stu[i].GetSex();
					Begin = Ss.find(Sex1,0);
					if(Begin != string::npos) 
					{
						flag ++;
						if(flag == 1) face.Search_afterface();
						stu[i].Show();
						num++;
					}
				}
				if(!flag) cout<<"没此相关信息!"<<endl;
				else 
				{
					cout<<endl<<"共有"<<num<<"条相关信息!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		case 4:												//按政治面貌搜索
			{
				cout<<"输入关键字:";
				cin>>Political_appearance1;
				
				for( i = 0;i<Total;i++)
				{
					Ss = stu[i].GetPolitical_appearance();
					Begin = Ss.find(Political_appearance1,0);
					if(Begin != string::npos) 
					{
						flag ++;
						if(flag == 1) face.Search_afterface();
						stu[i].Show();
						num++;
					}
				}
				if(!flag) cout<<"没此相关信息!"<<endl;
				else 
				{
					cout<<endl<<"共有"<<num<<"条相关信息!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		case 5:													//按家庭地址搜索
			{
				cout<<"输入关键字:";
				cin>>Address1;
				
				for( i = 0;i<Total;i++)
				{
					Ss = stu[i].GetAddress();
					Begin = Ss.find(Address1,0);
					
					if(Begin != string::npos) 
					{
						End = Address1.length() + Begin;
						flag ++;
						if(flag == 1) face.Search_afterface();
						stu[i].Addressshow(Begin,End);
						num++;
					}
				}
				if(!flag) cout<<"没此相关信息!"<<endl;
				else 
				{
					cout<<endl<<"共有"<<num<<"条相关信息!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		}
		cout<<"任意键继续..."; getchar();getchar();
	}
	else if(op_num == 5)									//显示所有信息
	{
		Allshow();
	}
	return 1;
}	

void Allshow()
{
	int i;
	cout<<endl;
	for(i = 0;i<36;i++) cout<<"~";
	cout<<"显示结果";
	for(i = 0;i<36;i++) cout<<"~";
	for(i = 0;i<Total;i++) 
		stu[i].Show();
	for(i = 0;i<80;i++) cout<<"~";
	cout<<"继续按任意键....";
	getchar();getchar();
}


void InFile()
{
	int i;
	Infile.open_in_file(); 
	int total = 0;			
	while(Infile.Filecin())							//把文件中的所有数据导入学生对象中
	{
		
		stu[total++] = Infile.Getstudent();
	}
	Total = total -1 ;
	for (i = 0;i<Total;i++) stu[i].SetNo(i+1);
	Infile.Closefile(); 
}
void OutFile()
{
	int i;
	Outfile.open_out_file();                         
	
	for(i = 0; i < Total; i++)						//把学生对象中的数据读入到文件中
	{
		Outfile.Filecout(stu[i]);
	}
	Outfile.Closefile();							
}

