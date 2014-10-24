#include <string>
#include <iostream>
#include <Windows.h>					//Sleep函数,system

using namespace std;


class Interface
{
	
public:
	
	void Startface();					//启动界面
	void Loadface();					//主界面
	void Subloadface();					//子界面
	void Subloadface2();				//子界面2
	char Inputcharface();				//提示导入文件界面
	int  Operateface();					//操作输入界面
	int	 Operateface2();				//操作输入界面2
	int  Addface();						//增加信息界面
	int  Delface();						//删除信息界面
	int  Setface();						//修改信息界面
	int  Searchface();					//搜索信息界面
	void Search_afterface();			//搜索后信息显示界面
	
	void Mark();						//标签
	
};

