#include <fstream>
#include <string>
#include "Student.h"								//学生类
const char filename[] = "Studentdata.txt";			//文件名

class Fileoperate
{
public:
	
	int Filecin();													//从文件输入
	int Filecout(Student);											//从文件输入
	void Closefile();												//关闭文件
    void open_in_file();											//打开文件作为输入文件
	void open_out_file();											//打开文件作为输入文件
	Student Getstudent()  { return stu; } 							//返回学生
private:

	fstream file;
	Student stu;													//学生类对象
	int Judge();													//判断能否打开文件函数
};

