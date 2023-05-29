#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dynamic.cpp"
#include "main.h"
#include "read_api.h"
#include <locale.h>
#include "write_api.h"
#include "things.h"
#define strdup _strdup
#pragma warning(disable : 4996)
using namespace std;
//основная структура данных
List<struct TRec> Data;

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
		puts("3 - Сохранить");
		puts("4 - Сохраненить как");
		puts("5 - Сохраненить зашифрованным");
		puts("6 - Расшифровать файл");
		puts("7 - Выход из программы");
		unsigned opt;
		fflush(stdin); //обнуление входного потока
		scanf("%u", &opt);
		fflush(stdin);
		switch (opt) { //возврат из функции команды
		case 1: return CMD_READ;
		case 2: return CMD_SHOW;
		case 3: return CMD_SAVE;
		case 4: return CMD_SAVE_NAMED;
		case 5: return CMD_ENCRIPT;
		case 6: return CMD_DECRIPT;
		case 7: return CMD_EXIT;
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
		puts("1 - добавить информацию 2 - сортировка данных 3 - редактирование данных 4 - поиск по названию 5 - смена страницы 6 - удаление строки 7 - выход");
		unsigned opt;
		fflush(stdin); //обнуление входного потока
		scanf("%u", &opt);
		fflush(stdin);
		switch (opt) { //возврат из функции команды
		case 1: return CMD_ADD;
		case 2: return CMD_SORT;
		case 3: return CMD_EDIT;
		case 4: return CMD_FIND;
		case 5: return CMD_PAGE;
		case 6: return CMD_DELETE;
		case 7: return CMD_EXIT;
		default: puts("Вы ввели неправильную команду");
			system("pause");
		}
	}
}

int main(int argc, char* argv[])
{
	char* filename;
	if (argc == 2)
	{
		filename = strdup(argv[1]);
		ReadFile(Data, filename);
	}
	setlocale(LC_ALL, "ru-RU");
	eCMD cmd = CMD_NONE;
	unsigned int page;
	bool is_saved = true;
	// цикл для обработки команд основного меню
	while (true)
	{
		if (cmd == CMD_EXIT)
		{
			if (is_saved)
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
				filename_menu(filename);
				ReadFile(Data, filename);
				
				// cout << filename;
				system("pause");
				break;
				
			}
			case CMD_SHOW:
			{
				eCMD cmd2 = CMD_NONE;
				page = 0;
				while (true)
				{
					if (cmd2 == CMD_EXIT) break;
					// cout << filename;
					system("pause");
					ShowFile(Data, page, filename);
					cmd2 = Menu2();					
        			switch (cmd2)
					{
						case CMD_ADD:
            			{   
							ShowFile(Data, page, filename);
                			TRec info = {};
							info.id = Data.size();
							add_menu(info);
							Data.append(info);
							is_saved = false;
							break;
						}
						case CMD_SORT:
						{
							ShowFile(Data, page, filename);
							sort(Data);
							break;
						}
						case CMD_EDIT:
						{
							ShowFile(Data, page, filename);
							edit(Data, page, filename);
							is_saved = false;
							break;
							
						}
						case CMD_PAGE:
						{
							ShowFile(Data, page, filename);
							cout << "Введите номер страницы:" << endl;
							unsigned int n = 0xffffff;
							while (n > Data.size() / 10 + 1)
							{
								cin >> n;
								if (n <= Data.size() / 10 + 1) page = --n;
							}
							break;
						}
						case CMD_DELETE:
						{
							ShowFile(Data, page, filename);
							cout << "Введите номер строки:" << endl;
							unsigned int n = 0;
							while(true)
							{
								cin >> n;
								if (n < Data.size())
								{
									Data.pop(--n);
									break;
								}
							}
							is_saved = false;
							break;
						}
						case CMD_FIND:
						{
							ShowFile(Data, page, filename);
							cout << "Введите строку для поиска:" << endl;
							char info[32];
							fflush(stdin);
							scanf("%[^\n]s", info);
							fflush(stdin);
							List<TRec> Data3 = Data.search(info);
							ShowFile(Data3, 0, filename);
							system("pause");
							break;
						}
            		}
				}
				break;
			}
			case CMD_SAVE:
			{
				is_saved = SaveFile(Data, filename);
				break;
			}
			case CMD_SAVE_NAMED:
			{
				filename_menu(filename);
				is_saved = SaveFile(Data, filename);
				break;
			}
			case CMD_DECRIPT:
			{
				ReadFile(Data, filename, encript_decript());
				break;
			}
			case CMD_ENCRIPT:
			{
				is_saved = SaveFile(Data, filename, encript_decript());
				break;
			}
		}
	}
	puts("Работа закончена");
	system("pause");
	return 0;
}