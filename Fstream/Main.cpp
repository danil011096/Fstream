#include <iostream>
#include <fstream>
#include <string>

void print_file(std::string path){
	static std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << "���������� �����:\n--------------------\n";
		char sym;
		while (in.get(sym))
			std::cout << sym;
		in.close();
	}
	std::cout << "\n--------------------\n";
}

bool into_file(std::string path, std::string str, int pos) {
	static std::fstream out;
	out.open(path, std::ios::in);
	if (!out.is_open()) 
		return false;

	std::string file;
	std::string temp;
	while (std::getline(out, temp))
		file += temp + '\n';
	out.close();

	out.open(path, std::ios::out);
	if (!out.is_open())
		return false;

	for (size_t/*unsigned long long*/ i = 0; i < file.size(); ++i)
	{
		if (i == pos)
			out << str;
		out << file[i];
	}

	out.close();
	return true;
}


int main () {
	system("chcp 1251>null");
		int n;
		std::string path = "file.txt";

		// ����� fstream
		/*std::fstream fs;
		fs.open(path, std::ios::app | std::ios::in);
	
		if (fs.is_open())
		{
			std::cout << "���� ������.\n";	
			
			// ������ ������ � ����
			
			std::cout << "������� ������ -> ";
			std::string msg;
			std::getline(std::cin, msg);
			fs << msg << '\n';

			fs.seekg(0, std::ios::beg);

			// ������ ������ �� �����

			std::cout << "���������� �����:\n--------------------\n";
			char sym;
			while (fs.get(sym))
				std::cout << sym;
			std::cout << "--------------------\n";
			fs.close();
		}
		else
			std::cout << "������ �������� �����.\n";*/

		// ������� "������ � �������� �����"
		/*print_file(path);
		std::cout << "������� ������ -> ";
		std::string str;
		std::getline(std::cin, str);
		std::cout << "������� ������� -> ";
		std::cin >> n;
		if (into_file(path, str, n)) {
			std::cout << "������ ���������. �������� ����:\n";
			print_file(path);
			std::cout << std::endl;
		}
		std::cout << "������!\n";*/

		// ������ 1. ������ ���� �� �����
		std::cout << "������ 1.\n���������� �����:\n";
		const char date_path[] = "date.txt";
		print_file(date_path);
		std::ifstream in;
		in.open(date_path);
		if (in.is_open())
		{
			std::string date;
			in >> date;
			in.close();

			int m_index = date.find('.') + 1;
			int y_index = date.rfind('.') + 1;


			int day = std::stoi(date);
			int month = std::stoi(date.substr(m_index));
			int year = std::stoi(date.substr(y_index));

			std::cout << "����:\t" << day << std::endl;
			std::cout << "�����:\t" << month << std::endl;
			std::cout << "���:\t" << year << std::endl;
		}



;		return 0;
}