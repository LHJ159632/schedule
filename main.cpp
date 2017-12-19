#include <stdio.h>
#include<fstream>
#include "utility.h"										// 实用程序软件包
#include "schedule.h"										// 课程表类

int main(int argc, char *argv[])
{
	try														
	{

		char inFileName[256], outFileName[256];
        
		strcpy(inFileName, "course_inf.txt");			
		ifstream inFile(inFileName);						// 输入流文件

		strcpy(outFileName, "course_scedule.txt");	
		ofstream outFile(outFileName);						// 输出流文件

		cout << "课程信息文件为: " << inFileName << endl << endl;
		cout << "正在排课，请稍候..." << endl << endl;

		Schedule<8> rc(&inFile, &outFile);					// 表示排8学期课(从第1学期到第8学期)
		rc.Read();								// 输入课程信息
		rc.TopologicalOrder();					// 用拓扑排序进行排课
		rc.Write();								// 输出课表

		cout << "排课结束，课表文件为: " << outFileName << endl;
	}
	catch (Error err)							// 捕捉并处理异常
	{
		err.Show();								// 显示异常信息
	}

	system("PAUSE");							// 调用库函数system()
	return 0;									// 返回值0, 返回操作系统
}