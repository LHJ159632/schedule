#include <stdio.h>
#include<fstream>
#include "utility.h"										// ʵ�ó��������
#include "schedule.h"										// �γ̱���

int main(int argc, char *argv[])
{
	try														
	{

		char inFileName[256], outFileName[256];
        
		strcpy(inFileName, "course_inf.txt");			
		ifstream inFile(inFileName);						// �������ļ�

		strcpy(outFileName, "course_scedule.txt");	
		ofstream outFile(outFileName);						// ������ļ�

		cout << "�γ���Ϣ�ļ�Ϊ: " << inFileName << endl << endl;
		cout << "�����ſΣ����Ժ�..." << endl << endl;

		Schedule<8> rc(&inFile, &outFile);					// ��ʾ��8ѧ�ڿ�(�ӵ�1ѧ�ڵ���8ѧ��)
		rc.Read();								// ����γ���Ϣ
		rc.TopologicalOrder();					// ��������������ſ�
		rc.Write();								// ����α�

		cout << "�ſν������α��ļ�Ϊ: " << outFileName << endl;
	}
	catch (Error err)							// ��׽�������쳣
	{
		err.Show();								// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");							// ���ÿ⺯��system()
	return 0;									// ����ֵ0, ���ز���ϵͳ
}