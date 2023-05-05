#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dynamic.cpp"
#include "main.h"
#include "read_api.h"
#include <locale.h>
#include "write_api.h"
#pragma warning(disable : 4996)
using namespace std;


//основная структура данных
List<struct TRec> Data;
TRec2 Data2;

void filename_menu()
{
	system("cls"); //очистка экрана
	puts("Выберите название файла:"); //отображение меню
	fflush(stdin); //обнуление входного потока
	cin >> Data2.Filename;
}

eCMD Menu()
{
	//цикл для вывода меню, если ввели неправильно команду
	while (true)
	{
		setlocale(LC_ALL, "ru-RU");
		system("cls"); //очистка экрана
		puts("Выберите действие:"); //отображение меню
		puts("1 - Открыть файл");
		puts("2 - Просмотр и Редактирование данных");
		puts("3 - Сохраненить");
		puts("4 - Сохраненить как");
		puts("5 - Выход из программы");
		unsigned opt;
		fflush(stdin); //обнуление входного потока
		scanf("%u", &opt);
		switch (opt) { //возврат из функции команды
		case 1: return CMD_READ;
		case 2: return CMD_SHOW;
		case 3: return CMD_SAVE;
		case 4: return CMD_SAVE_NAMED;
		case 5: return CMD_EXIT;
		default: puts("Вы ввели неправильную команду");
			system("pause");
		}
	}
}

eCMD Menu2()
{
	//цикл для вывода меню, если ввели неправильно команду
	while (true)
	{
		setlocale(LC_ALL, "ru-RU");
		puts("Выберите действие:"); //отображение меню
		puts("1 - добавить информацию   5 - выход");
		unsigned opt;
		fflush(stdin); //обнуление входного потока
		scanf("%u", &opt);
		switch (opt) { //возврат из функции команды
		case 1: return CMD_ADD;
		case 5: return CMD_EXIT;
		default: puts("Вы ввели неправильную команду");
			system("pause");
		}
	}
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru-RU");
	eCMD cmd = CMD_NONE;
	unsigned int page = 0;
	Data2.is_saved = true;
	// цикл для обработки команд основного меню
	while (true)
	{
		if (cmd == CMD_EXIT)
		{
			if (Data2.is_saved)
			{
				break;
			}
			else
			{
				puts("Сохраните данные перед закрытием");
				system("pause");
			}
		} //выход из цикла
		cmd = Menu(); //отображение меню и ввод команд
		// вызов функции для соответствующей команды
		switch (cmd)
		{
			case CMD_READ:
			{
				filename_menu();
				ReadFile(Data, Data2.Filename);
				cout << Data.size() << " " << Data.hundler[0].name<< " " << Data.hundler[1].name << " " << Data.hundler[0].score;
				system("pause");
				break;
				
			}
			case CMD_SHOW:
			{
				eCMD cmd2 = CMD_NONE;
				while (true)
				{
					if (cmd2 == CMD_EXIT) break;
					ShowFile(Data, page);
					cmd2 = Menu2();
        			switch (cmd2)
					{
						case CMD_ADD:
            			{   
							ShowFile(Data, page);
                			TRec info = {};
                			cout << "Введите данные через ENTER в формате:" << endl;
                			printf("%-s %-s %-s %-s %-s\n", "Имя - 32 символа", "Режисер - 32 символа", "год - 4 символа", "Время - 3 символа", "Оценка - 4 символа");
                			fflush(stdin);
							fgets(info.name, 32, stdin);
							fgets(info.director, 32, stdin);
							fgets(info.year, 4, stdin);
							fgets(info.time, 3, stdin);
							fgets(info.score, 4, stdin);
							write_new_data(Data, info);
							system("pause");
						}
                
            		}
				}
				break;
			}
			case CMD_SAVE:
			{
				Data2.is_saved = SaveFile(Data, Data2.Filename);
				break;
			}
			case CMD_SAVE_NAMED:
			{
				filename_menu();
				Data2.is_saved = SaveFile(Data, Data2.Filename);
				break;
			}
		}
	}
	puts("Работа закончена");
	system("pause");
	return 0;
}