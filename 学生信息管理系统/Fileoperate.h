#include <fstream>
#include <string>
#include "Student.h"								//ѧ����
const char filename[] = "Studentdata.txt";			//�ļ���

class Fileoperate
{
public:
	
	int Filecin();													//���ļ�����
	int Filecout(Student);											//���ļ�����
	void Closefile();												//�ر��ļ�
    void open_in_file();											//���ļ���Ϊ�����ļ�
	void open_out_file();											//���ļ���Ϊ�����ļ�
	Student Getstudent()  { return stu; } 							//����ѧ��
private:

	fstream file;
	Student stu;													//ѧ�������
	int Judge();													//�ж��ܷ���ļ�����
};

