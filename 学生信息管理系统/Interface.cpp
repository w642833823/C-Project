#include <iostream>
#include "Interface.h"
using namespace std;

void Interface::Startface()
{
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
		<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<" ������...";
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
	cout<<"                          ѧ �� �� Ϣ �� �� ϵ ͳ "<<endl<<endl;
	cout<<"    ##################################################################"<<endl;
	cout<<"    #                                                                #"<<endl;
	cout<<"    #   1.����ѧ����¼    #   2.ɾ��ѧ����¼   #    3.�޸�ѧ����¼   #"<<endl;
	cout<<"    #   4.�Ҳ�ѧ����¼    #   5.��ʾѧ����¼   #    6.�˳�           #"<<endl;
	cout<<"    #                                                                #"<<endl;
	cout<<"    ##################################################################"<<endl;
	cout<<endl;
	
}

void Interface::Subloadface2()
{
	cout<<endl;
	cout<<"    =======================+++�� - �� - �� - ʾ+++===================="<<endl
		<<"    |    1.����ѧ����¼   |    6.�˳�                                |"<<endl
		<<"    =================================================================="<<endl;
	cout<<endl;
}
void Interface::Subloadface()
{
	cout<<endl<<endl;
	cout<<"    =======================+++�� - �� - �� - ʾ+++===================="<<endl
		<<"    |    1.����ѧ����¼   |    2.ɾ��ѧ����¼    |   3.�޸�ѧ����¼  |"<<endl
		<<"    |    4.�Ҳ�ѧ����¼   |    5.��ʾѧ����¼    |   6.�˳�          |"<<endl
		<<"    =================================================================="<<endl;
	cout<<endl;
}

char Interface::Inputcharface()
{
	char op_char;
	cout<<"��Ҫ�����ļ���?(Y/N):";
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
			cout<<"������Χ..Again:";
			cin>>op_num;
		}
		else
		{
			cout<<"������Ĳ���:";
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
			cout<<"������Χ..Again:";
			cin>>op_num;
		}
		else
		{
			cout<<"������Ĳ���:";
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
	cout<<"������Ҫ���ѧ��������(���˳�,����0):";
	cin>>num;
	return num;
}

int Interface::Delface()
{
	int no;
	cout<<"������ע��ѧ�������(���˳�,����0):";
	cin>>no;
	return no;
}

int Interface::Setface()
{
	int no;
	cout<<"����Ҫ�޸ĵ�ѧ�����(���˳�,����0):";
	cin>>no;
	
	if(no)
	{
		cout<<"������Ҫ�ĵ�ѧ������Ϣ����"<<endl
			<<"(1.ѧ��,2.����,3.��������,4.�Ա�,5.������ò,6�ֻ�����,7.��ͥ��ַ)"<<endl
			<<"�����Ҫȫ���޸�,������0..."<<endl;
		cout<<"����:";
	}
	return no;
}

int Interface::Searchface()
{
	int no;
	cout<<"��������������"<<endl<<"1.ѧ��,2.����,3.�Ա�,4.������ò,5.��ͥ��ַ"<<endl;
	cout<<"����(���˳�,����0):";
	cin>>no;
	
	return no;
}

void Interface::Search_afterface()				//�������
{
	int i;
	cout<<endl;
	for(i = 0;i<36;i++) cout<<"~";
	cout<<"�������";
	for(i = 0;i<36;i++) cout<<"~";
}

void Interface::Mark()							//��ǩ
{
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"                                                                 �����������:"<<endl<<endl
		<<"                                                                  ������  ���"<<endl
		<<"                                                                 ������  ������"<<endl
		<<"                                                               лл֧��  !!!!  "<<endl;
}



