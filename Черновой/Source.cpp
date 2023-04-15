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
	string manufactude_date;//дата производства
	string produced_number;// количество выпущенных единиц
	string workshop_number;//номер цеха
	string full_name_employee;// ФИО ответственного по цеху в данный день
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
	cout << "Войти как админ - 1" << endl << "Войти как пользователь - 0" << endl << "Выйти - 3" << endl;
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
			cout << "Введите существующее занчение" << endl;
			break;
		}
	}
}
void admin_auto()
{
	int  m = 0, line_number = 0;
	string add_log, add_pass;
	while (m == 0) {
		cout << "Введите ваш логин" << endl;
		cin >> add_log;
		while (m == 0 && line_number < admin.size())
		{
			if (add_log == admin[line_number].admin_login)
			{
				while (m == 0)
				{
					cout << "Введите ваш пароль" << endl;
					cin >> add_pass;
					if (add_pass == admin[line_number].admin_password)
					{
						cout << "Вы успешно вошли" << endl;
						m = 1;
						administrator_menu();
						break;
					}
					else
					{
						cout << "Вы ввели неверный пароль" << endl;
					}
				}
			}
			else { line_number++; };
		}
		if (line_number >= admin.size()) {
			cout << "Администратор с таким логином не найден" << endl;
			return;
		}
	}
}
void administrator_menu() 
{
	int choise = 0;
	while (choise != 12) {
		cout << "1 - Добавить данные о товаре" << endl;
		cout << "2 - Найти данные о товаре" << endl;
		cout << "3 - Редактировать данные о товаре" << endl;
		cout << "4 - Удалить данные о товаре" << endl;
		cout << "5 - Вывести данные о всех товарах" << endl;
		cout << "6 - Отсортировать данные о товарах" << endl;
		cout << "8 - Добавить пользователя" << endl;
		cout << "9 - Редактировать данные о пользователе" << endl;
		cout << "10 - Удалить данные о пользователе " << endl;
		cout << "11 - Вывести данные о всех пользователях" << endl;
		cout << "12 - Выход" << endl;
		cout << "Введите ваш выбор:";
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
			cout << "До свидания)" << endl;
			break;
		}
		
	}
}


void add_product() 
{
	int i = 0, choise=1;
	string prod;
	while (choise == 1) {
		cout << "Введите название товара " << endl;
		cin.ignore();
		getline(cin, product1[i].product_name);
		cout << "Введите дату производства товара" << endl;
		cin >> product1[i].manufactude_date;
		cout << "Введите количество произведенного товара" << endl;
		cin >> product1[i].produced_number;
		cout << "Введите номер цеха в котором раcпологается товар" << endl;
		cin >> product1[i].workshop_number;
		cout << "Введите ФИО ответственного по цеху в данный день" << endl;
		cin.ignore();
		getline(cin, product1[i].full_name_employee);
		i++;
		cout << "Хотите добавить данные о ещё одном товаре? 1 - да, 0 - нет" << endl;
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
	else cout << "Не удалось открыть файл" << endl;
	output_product_name_file.close();
	ofstream output_manufactude_date_file("manufactude_date.txt");
	if (output_manufactude_date_file.is_open()) {
		for (int i = 0; i < product.size(); i++) {
			output_manufactude_date_file << product[i].manufactude_date << "\n";
		}
	}
	else cout << "Не удалось открыть файл" << endl;
	output_manufactude_date_file.close();
	ofstream output_produced_number_file("produced_number.txt");
	if (output_produced_number_file.is_open()) {
		for (int i = 0; i < product.size(); i++) {
			output_produced_number_file << product[i].produced_number << "\n";
		}
	}
	else cout << "Не удалось открыть файл" << endl;
	output_produced_number_file.close();
	ofstream output_workshop_number_file("workshop_number.txt");
	if (output_workshop_number_file.is_open()) {
		for (int i = 0; i < product.size(); i++) {
			output_workshop_number_file << product[i].workshop_number << "\n";
		}
	}
	else cout << "Не удалось открыть файл" << endl;
	output_workshop_number_file.close();
	ofstream output_full_name_employee_file("full_name_employee.txt");
	if (output_full_name_employee_file.is_open()) {
		for (int i = 0; i < product.size(); i++) {
			output_full_name_employee_file << product[i].full_name_employee << "\n";
		}
	}
	else cout << "Не удалось открыть файл" << endl;
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
	else cout << "Не удалось открыть файл" << endl;
	ifstream read_admin_login_file("admin_login.txt");
	if (read_admin_login_file.is_open()) {
		while (getline(read_admin_login_file, file_line))
		{
			admin[i].admin_login = file_line;
			i++;
		}
	}
	else cout << "Не удалось открыть файл" << endl;
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
	else cout << "Не удалось открыть файл" << endl;
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
	else cout << "Не удалось открыть файл" << endl;
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
	else cout << "Не удалось открыть файл" << endl;
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
	else cout << "Не удалось открыть файл" << endl;
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
	else cout << "Не удалось открыть файл" << endl;
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
	else cout << "Не удалось открыть файл" << endl;
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
