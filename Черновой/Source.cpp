#include <string>
#include <vector> 
#include <fstream>
#include <iostream>
#include <iterator> 
#include <Windows.h>
#include <algorithm>
using namespace std;
struct administrator
{
	string admin_login;
	string admin_password;
};
vector <administrator> admin;
struct products
{
	string product_name;
	string manufactude_date;//���� ������������
	string produced_number;// ���������� ���������� ������
	string workshop_number;//����� ����
	string full_name_employee;// ��� �������������� �� ���� � ������ ����
};
vector<products> product;
vector<products> product1;
void display_menu();
void admin_auto();
void administrator_menu();
void add_product();
void write_product_to_file();
void write_admin_to_file();
//void write_product_to_vector();

void display_menu() {
	int choise;
	cout << "����� ��� ����� - 1" << endl << "����� ��� ������������ - 0" << endl << "����� - 3" << endl;
	cin >> choise;
	while (choise != 3) {
		switch (choise) {
		case 1:
			admin_auto();
			break;
		case 2:
			break;
		case 3:
			
			break;
		default:
			cout << "������� ������������ ��������" << endl;
			break;
		}
	}
}
void admin_auto()
{
	int  m = 0, line_number = 0;
	string add_log, add_pass;
	while (m == 0) {
		cout << "������� ��� �����" << endl;
		cin >> add_log;
		while (m == 0 && line_number < admin.size())
		{
			if (add_log == admin[line_number].admin_login)
			{
				while (m == 0)
				{
					cout << "������� ��� ������" << endl;
					cin >> add_pass;
					if (add_pass == admin[line_number].admin_password)
					{
						cout << "�� ������� �����" << endl;
						m = 1;
						administrator_menu();
						break;
					}
					else
					{
						cout << "�� ����� �������� ������" << endl;
					}
				}
			}
			else { line_number++; };
		}
		if (line_number >= admin.size()) {
			cout << "������������� � ����� ������� �� ������" << endl;
			return;
		}
	}
}
void administrator_menu() 
{
	int choise = 0;
	while (choise != 12) {
		cout << "1 - �������� ������ � ������" << endl;
		cout << "2 - ����� ������ � ������" << endl;
		cout << "3 - ������������� ������ � ������" << endl;
		cout << "4 - ������� ������ � ������" << endl;
		cout << "5 - ������� ������ � ���� �������" << endl;
		cout << "6 - ������������� ������ � �������" << endl;
		cout << "8 - �������� ������������" << endl;
		cout << "9 - ������������� ������ � ������������" << endl;
		cout << "10 - ������� ������ � ������������ " << endl;
		cout << "11 - ������� ������ � ���� �������������" << endl;
		cout << "12 - �����" << endl;
		cout << "������� ��� �����:";
		cin >> choise;
	
		switch (choise) {
		case 1:
			add_product();
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
		
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
			
			break;
		case 10:
			
			break;
		case 11:
		
			break;
		case 12:
			cout << "�� ��������)" << endl;
			break;
		}
		
	}
}


void add_product() 
{
	int i = 0, choise=1;
	string prod;
	while (choise == 1) {
		cout << "������� �������� ������ " << endl;
		cin.ignore();
		getline(cin, product1[i].product_name);
		cout << "������� ���� ������������ ������" << endl;
		cin >> product1[i].manufactude_date;
		cout << "������� ���������� �������������� ������" << endl;
		cin >> product1[i].produced_number;
		cout << "������� ����� ���� � ������� ��c���������� �����" << endl;
		cin >> product1[i].workshop_number;
		cout << "������� ��� �������������� �� ���� � ������ ����" << endl;
		cin.ignore();
		getline(cin, product1[i].full_name_employee);
		i++;
		cout << "������ �������� ������ � ��� ����� ������? 1 - ��, 0 - ���" << endl;
		cin >> choise;
		if (choise == 0) {
			write_product_to_file();
			administrator_menu();
		}
	}
}

void write_product_to_file() {
	ofstream output_product_name_file("product_name.txt");
	if (output_product_name_file.is_open()) {
		for (int i = 0; i < product.size(); i++) {
			output_product_name_file << product[i].product_name << "\n";
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	output_product_name_file.close();
	ofstream output_manufactude_date_file("manufactude_date.txt");
	if (output_manufactude_date_file.is_open()) {
		for (int i = 0; i < product.size(); i++) {
			output_manufactude_date_file << product[i].manufactude_date << "\n";
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	output_manufactude_date_file.close();
	ofstream output_produced_number_file("produced_number.txt");
	if (output_produced_number_file.is_open()) {
		for (int i = 0; i < product.size(); i++) {
			output_produced_number_file << product[i].produced_number << "\n";
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	output_produced_number_file.close();
	ofstream output_workshop_number_file("workshop_number.txt");
	if (output_workshop_number_file.is_open()) {
		for (int i = 0; i < product.size(); i++) {
			output_workshop_number_file << product[i].workshop_number << "\n";
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	output_workshop_number_file.close();
	ofstream output_full_name_employee_file("full_name_employee.txt");
	if (output_full_name_employee_file.is_open()) {
		for (int i = 0; i < product.size(); i++) {
			output_full_name_employee_file << product[i].full_name_employee << "\n";
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	output_full_name_employee_file.close();
}
void write_admin_to_file() {
	string file_line;
	int i = 0;
	ofstream admin_login_file("admin_login.txt");
	ofstream admin_password_file("admin_password.txt");
	if (admin_login_file.is_open())
	{
		admin_login_file << "adminlogin";
		admin_password_file << "admin123";
		admin_login_file.close();
		admin_password_file.close();
	}
	else cout << "�� ������� ������� ����" << endl;
	ifstream read_admin_login_file("admin_login.txt");
	if (read_admin_login_file.is_open()) {
		while (getline(read_admin_login_file, file_line))
		{
			admin[i].admin_login = file_line;
			i++;
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	read_admin_login_file.close();
	i = 0;
	ifstream read_admin_password_file("admin_password.txt");
	if (read_admin_password_file.is_open()) {
		while (getline(read_admin_password_file, file_line))
		{
			admin[i].admin_password = file_line;
			i++;
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	read_admin_password_file.close();
}

/*
void write_product_to_vector() {
	int i = 0;
	string file_line;
	ifstream product_name_file("product_name.txt");
	i = 0;
	if (product_name_file.is_open()) {
		while (getline(product_name_file, file_line))
		{
			product[i].product_name = file_line;
			i++;
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	product_name_file.close();
	i = 0;
	ifstream manufactude_date_file("manufactude_date.txt");
	if (manufactude_date_file.is_open()) {
		while (getline(manufactude_date_file, file_line))
		{
			product[i].manufactude_date = file_line;
			i++;
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	manufactude_date_file.close();
	i = 0;
	ifstream produced_number_file(".txt");
	if (produced_number_file.is_open()) {
		while (getline(produced_number_file, file_line))
		{
			product[i].produced_number = file_line;
			i++;
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	produced_number_file.close();
	i = 0;
	ifstream workshop_number_file(".txt");
	if (workshop_number_file.is_open()) {
		while (getline(workshop_number_file, file_line))
		{
			product[i].workshop_number = file_line;
			i++;
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	workshop_number_file.close();
	i = 0;
	ifstream full_name_employee_file(".txt");
	if (full_name_employee_file.is_open()) {
		while (getline(full_name_employee_file, file_line))
		{
			product[i].full_name_employee = file_line;
			i++;
		}
	}
	else cout << "�� ������� ������� ����" << endl;
	full_name_employee_file.close();
}
*/
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	admin.resize(1);
	product.resize(8);
	string file_line;
	int i = 0;
	write_admin_to_file();
	//write_product_to_vector();
	display_menu();

}
