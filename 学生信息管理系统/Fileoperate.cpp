#include "Fileoperate.h"

int Fileoperate::Judge()				 
{
	if( file.fail() )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void Fileoperate::open_in_file()
{
	file.open(filename, ios::in);
	if( !Judge() )
	{
		exit(1);
	}
}

void Fileoperate::open_out_file()
{
	file.open(filename, ios::out);
	if( !Judge() )
	{
		exit(1);
	}
}

int Fileoperate::Filecin()
{
	string Num1;					//ѧ��
	string Name1;					//����
	string Birthday1;				//��������
	string Sex1;					//�Ա�
	string Political_appearance1;	//������ò
	string Phone_number1;			//�ֻ�����
	string Address1;				//��ͥ��ַ

	if(file.eof())					//�ļ�����,����0
	{
		return 0;
	}
	
	file>>Num1>>Name1>>Birthday1>>Sex1>>Political_appearance1>>Phone_number1>>Address1;

	stu.Setinformation(Num1,Name1,Birthday1,Sex1,Political_appearance1,Phone_number1,Address1);

	return 1;
}

int Fileoperate::Filecout(Student s)
{
	file << s.GetNum() << endl
		 << s.GetName() << endl
		 << s.GetBirthday() << endl
		 << s.GetSex() << endl
		 << s.GetPolitical_appearance() << endl
		 << s.GetPhone_number() << endl
		 << s.GetAddress() <<endl<<endl;
	
	return 1;
}

void Fileoperate::Closefile()
{
	file.close();
}