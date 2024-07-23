#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string input_choose;
string path;
string text;

bool ReadBinaryFile(string& text, string path, char stop = (char)EOF);
bool WriteBinaryFile(string text, string path, bool overwrite);
bool CheckFile(string path);

int main()
{
	while (true)
	{
		cin.clear();
		system("cls");
		cout << "1 --> ��ȡ  2 --> ����д��  3 --> ׷��д��" << endl;
		cout << "��ѡ��";
		getline(cin, input_choose);
		if (input_choose == "1")
		{
			cout << "�ļ���ַ��";
			getline(cin, path);
			if (CheckFile(path))
			{
				ReadBinaryFile(text, path);
				cout << "----------------------------------------------------------------------------------" << endl;
				cout << text << endl;
				cout << "----------------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "���棺�ļ����𻵻򲻴��ڣ�" << endl;
			}
			system("pause");
		}
		else if (input_choose == "2")
		{
			cout << "�ļ���ַ��";
			getline(cin, path);
			if (CheckFile(path))
			{
				cout << "���棺д���ԭ�ļ����ݻᱻ����, ���������" << endl;
				cout << "��Tab+Enter�˳���д��" << endl;
				cout << "----------------------------------------------------------------------------------" << endl;
				string text;
				getline(cin, text, '\t');
				WriteBinaryFile(text, path, true);
				cout << "----------------------------------------------------------------------------------" << endl;
				cout << "д��ɹ���" << endl;
			}
			else
			{
				cout << "���棺�ļ����𻵻򲻴��ڣ�" << endl;
			}
			system("pause");
		}
		else if (input_choose == "3")
		{
			cout << "�ļ���ַ��";
			getline(cin, path);
			if (CheckFile(path))
			{
				cout << "���棺д������ݽ��Զ�׷�ӵ��ļ�ĩβ" << endl;
				cout << "��Tab+Enter�˳���д��" << endl;
				cout << "----------------------------------------------------------------------------------" << endl;
				string text;
				getline(cin, text, '\t');
				WriteBinaryFile(text, path, false);
				cout << "----------------------------------------------------------------------------------" << endl;
				cout << "д��ɹ���" << endl;
			}
			else
			{
				cout << "���棺�ļ����𻵻򲻴��ڣ�" << endl;
			}
			system("pause");
		}
	}

	return 0;
}

bool ReadBinaryFile(string& text, string path, char stop)
{
	ifstream ifs;
	ifs.open(path, ios::in | ios::binary);
	if (ifs.is_open())
	{
		getline(ifs, text, stop);
		ifs.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool WriteBinaryFile(string text, string path, bool overwrite)
{
	ofstream ofs;
	if (overwrite)
	{
		ofs.open(path, ios::out | ios::binary);
	}
	else
	{
		ofs.open(path, ios::out | ios::app | ios::binary);
	}
	if (ofs.is_open())
	{
		int len = text.size();
		ofs.write(reinterpret_cast<char*>(&len), sizeof(int));
		ofs.write(text.c_str(), len);
		ofs.close();
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckFile(string path)
{
	ifstream f(path.c_str());
	bool b = f.good();
	f.close();
	return b;
}