#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>						//sort����
#include "Interface.h"						//������
#include "Student.h"						//ѧ����
#include "Fileoperate.h"					//�ı���
using namespace std;

const int student_num = 120 + 1;			//��������

int No = 1;									//���
int Total = 0;								//������

Interface face;								//����
Fileoperate Infile;							//�����ļ������
Fileoperate Outfile;						//�����ļ������

Student stu[student_num];					//ѧ�����������

int  switchfun(int);						//���ܺ���ѡ��
void Allshow();								//��ʾ����ѧ����Ϣ
void Searchshow(int [],int,int,int,int);	//��ʾ������Ϣ
void InFile();								//�����ļ�����
void OutFile();								//�����ļ�����

int main()
{
	int op_num;								//��������
	char op_char;							//ѡ����
	char op_char2;							//�Ƿ񱣴�
	face.Startface();						//��������
	face.Loadface();						//��½����
	
	int flag ,nflag = 0;					//�����ʽ�жϱ��
	do
	{
		flag = 0;
		if(nflag) cout<<"������Χ...Again:"<<endl;
		op_char = face.Inputcharface();
		if(op_char !='Y'&&op_char !='y'&&op_char !='N'&&op_char !='n') 
		{
			flag = 1;
			nflag = 1;
		}
	}while(flag);
	
	if (op_char == 'Y'||op_char =='y')						//ѡ����,�����ļ�
	{
		InFile();											//�����ļ�
		char Sub_op_char;
		nflag = 0;
		do
		{
			flag = 0;
			cout<<"�ѳɹ�����, Ҫ��ʾ������?(Y/N):";
			cin>>Sub_op_char;
			if(Sub_op_char !='Y'&&Sub_op_char !='y'&&Sub_op_char !='N'&&Sub_op_char !='n') 
			{
				flag = 1;
			}
		}while(flag);
		
		if (Sub_op_char == 'Y'||Sub_op_char =='y')			//�Ƿ�����Ѷ����ļ�����Ϣ
		{
			Allshow();										//��ʾ������Ϣ
			face.Subloadface();
		}
		else 
		{
			if(Sub_op_char == 'N'||Sub_op_char =='n') ;     //����ʾ��Ϣ
		}
	}
	else 
	{
		if(op_char == 'N'||op_char =='n');
		face.Subloadface2();
	}
	
	while(1)										//����ִ�й���
	{
		if(Total != 0) op_num = face.Operateface();		//��ȡ������
		else op_num = face.Operateface2();				//��ȡ������
		if(op_num == 6) break;						//����6,����
		switchfun(op_num);							//����ѡ��
		if(Total != 0 ) face.Subloadface();			
		else 
		{
			cout<<endl;
			cout<<"ѧ����Ϊ��!";
			face.Subloadface2();
		}
		
	}	
	cout<<"Ҫ����������?(Y/N):";
	cin>>op_char2;
	
    if(op_char2 == 'Y'||op_char2 == 'y') 
	{
		cout<<endl<<"�ѱ���!"<<endl;
		OutFile();									//�����ļ�
	}
	face.Mark();									//��������߱��
	
	system("pause");
	
	return 0;
}

int switchfun(int op_num)
{
	int i;
	int num;										//��ӽ��������
	string Num1;									//ѧ��
	string Name1;									//����
	string Birthday1;								//��������
	string Sex1;									//�Ա�
	string Political_appearance1;					//������ò
	string Phone_number1;							//�ֻ�����
	string Address1;
	if (op_num == 1)
	{
		num = face.Addface();						//��ȡ��ӽ��������
		if(num == 0) { cout<<"���˳�,���������..."; getchar(); getchar(); return 0;}
		for(i = 0;i<num;i++)
		{
			cout<<"�����"<<i+1<<"��ѧ����Ϣ:\n";
			cout<<endl;
			cout<<"ѧ��:";
			cin>>Num1;
			cout<<"����:";
			cin>>Name1;
			cout<<"��������:";
			cin>>Birthday1;
			cout<<"�Ա�:";
			cin>>Sex1;
			cout<<"������ò:";
			cin>>Political_appearance1;
			cout<<"�ֻ�����:";
			cin>>Phone_number1;
			cout<<"��ͥ��ַ:";
			cin>>Address1;
			cout<<endl;
			Total ++;
			stu[Total-1].SetNo(Total);			//�������	
			stu[Total-1].Setinformation(Num1,Name1,Birthday1,Sex1,Political_appearance1,
										  Phone_number1,Address1);
		}

		if(i == num) cout<<"������!"<<endl;
	}
	else if(op_num == 2)
	{
		int no;										//ɾ�����������
		no = face.Delface();						//��ȡɾ�����������
		if(no == 0) { cout<<"���˳�,���������..."; getchar(); getchar(); return 0;}
		for (i = no;i<Total;i++) { stu[i].SetNo(i);stu[i-1] = stu[i];}
		cout<<endl<<"ɾ����ѧ����Ϣ�ɹ�!"<<endl;
		cout<<"���������...";
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
		no = face.Setface();						//��ȡ�޸Ľ��������
		if(no == 0) { cout<<"���˳�,�����������..."; getchar(); getchar(); return 0;}
		getchar();					
		gets(info);
		int l = strlen(info);
		i = 0;
		while(i<l)									//�ַ������׼��
		{
			if(info[i]>='0'&&info[i]<='9') a[k++] = info[i]-'0';
			if(a[k-1]==0) { flag = 1; break;}
			i++;
		}
		
		sort(a,a+k);								//����
		if(flag)									//���������,�޸�ȫ����Ϣ
		{
			cout<<"ѧ��:";
			cin>>Num1;
			cout<<"����:";
			cin>>Name1;
			cout<<"��������:";
			cin>>Birthday1;
			cout<<"�Ա�:";
			cin>>Sex1;
			cout<<"������ò:";
			cin>>Political_appearance1;
			cout<<"�ֻ�����:";
			cin>>Phone_number1;
			cout<<"��ͥ��ַ:";
			cin>>Address1;
			cout<<endl;
			stu[no-1].Setinformation(Num1,Name1,Birthday1,Sex1,Political_appearance1,Phone_number1,Address1);
		}
		else 
		{
			for(i = 0;i<k;i++)
			{
				switch(a[i])						//�޸Ĳ�����Ϣ
				{
				case 1: 
					{
						cout<<"����ѧ��:";
						stu[no-1].SetNum();
						break;
					}
				case 2:
					{
						cout<<"��������:";
						stu[no-1].SetName();
						break;
					}
				case 3:
					{
						cout<<"�����������:";
						stu[no-1].SetBirthday();
						break;
					}
				case 4:
					{
						cout<<"�����Ա�:";
						stu[no-1].SetSex();
						break;
					}
				case 5:
					{
						cout<<"����������ò:";
						stu[no-1].SetPolitical_appearance();
						break;
					}
				case 6:
					{
						cout<<"�����ֻ�����:";
						stu[no-1].SetPhone_number();
						break;
					}
				case 7:
					{
						cout<<"�����ͥ��ַ:";
						stu[no-1].SetAddress();
						break;
					}
				}
			}
		}
		
		cout<<endl<<endl<<"�����, �޸ĺ�:"<<endl;		//����޸ĺ���Ϣ
		for(i= 0;i<80;i++) cout<<"-"; 
		stu[no-1].Show();
		for(i= 0;i<80;i++) cout<<"-"; cout<<endl;
		cout<<"�����������...";
		getchar();getchar();
		
	}
	else if(op_num == 4)
	{
		int no;
		int Begin,End;							//��ʼ,����λ��
		int num = 0;									//������������������
		string Ss;										//��ʱ����

		no = face.Searchface();							//��ȡ�������������
		if(no == 0) { cout<<"���˳�,�����������..."; getchar(); getchar(); return 0;}
		int flag = 0;
		
		switch(no)
		{
		case 1:											//��ѧ������
			{
				cout<<"����ؼ���:";
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
				if(!flag) cout<<"û�������Ϣ!"<<endl;
				else 
				{
					cout<<endl<<"����"<<num<<"�������Ϣ!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		case 2:											//����������
			{
				cout<<"����ؼ���:";
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
				if(!flag) cout<<"û�������Ϣ!"<<endl;
				else 
				{
					cout<<endl<<"����"<<num<<"�������Ϣ!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		case 3:												//���Ա�����
			{
				cout<<"����ؼ���:";
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
				if(!flag) cout<<"û�������Ϣ!"<<endl;
				else 
				{
					cout<<endl<<"����"<<num<<"�������Ϣ!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		case 4:												//��������ò����
			{
				cout<<"����ؼ���:";
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
				if(!flag) cout<<"û�������Ϣ!"<<endl;
				else 
				{
					cout<<endl<<"����"<<num<<"�������Ϣ!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		case 5:													//����ͥ��ַ����
			{
				cout<<"����ؼ���:";
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
				if(!flag) cout<<"û�������Ϣ!"<<endl;
				else 
				{
					cout<<endl<<"����"<<num<<"�������Ϣ!"<<endl;
					num = 0;
					for(i = 0;i<80;i++) cout<<"~"; 
				}
				break;
			}
		}
		cout<<"���������..."; getchar();getchar();
	}
	else if(op_num == 5)									//��ʾ������Ϣ
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
	cout<<"��ʾ���";
	for(i = 0;i<36;i++) cout<<"~";
	for(i = 0;i<Total;i++) 
		stu[i].Show();
	for(i = 0;i<80;i++) cout<<"~";
	cout<<"�����������....";
	getchar();getchar();
}


void InFile()
{
	int i;
	Infile.open_in_file(); 
	int total = 0;			
	while(Infile.Filecin())							//���ļ��е��������ݵ���ѧ��������
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
	
	for(i = 0; i < Total; i++)						//��ѧ�������е����ݶ��뵽�ļ���
	{
		Outfile.Filecout(stu[i]);
	}
	Outfile.Closefile();							
}

