#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dynamic.cpp"
#include "main.h"
#include "read_api.h"
#include <locale.h>
#include "write_api.h"
#define strdup _strdup
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

void add_menu(TRec &info)
{
	cout << "Введите данные через ENTER в формате:" << endl;
	printf("%-s %-s %-s %-s %-s\n", "Имя - 32 символа", "Режисер - 32 символа", "год - 4 символа", "Время - 3 символа", "Оценка - 4 символа");
	fflush(stdin);
	char name[32];
	char director[32];
	int year;
	int time;
	float score;
	scanf("%[^\n]s", name);
	fflush(stdin);
	scanf("%[^\n]s", director);
	fflush(stdin);
	cin >> year >> time >> score;
	info = { info.id, strdup(name),strdup(director), year, time, score};
	fflush(stdin);
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
		fflush(stdin);
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
							info.id = Data.size();
							add_menu(info);
							Data.append(info);
							break;
						}
						case CMD_SORT:
						{
							ShowFile(Data, page);
							int n = 0;
							int type = 0;
							cout << "Для сортировки по возрастанию введите 1 или -1 для сортировки в обратном порядке." << endl;
							while(type != -1 && type != 1)
							{
								cin >> type;
								fflush(stdin);
							}
							cout << "Введите номер строки по котоорой сортировать:" << endl;
							printf("%-s %-s %-s %-s %-s\n", "Имя - 1", "Режисер - 2", "год - 3", "Время - 4", "Оценка - 5");
							fflush(stdin);
							while (!n)
							{
								cin >> n;
								fflush(stdin);
								n = (base_sort(Data, n, type) ? n : 0);
							}
							break;
						}
						case CMD_EDIT:
						{
							ShowFile(Data, page);
							cout << "Введите номер строки по которую изменить:" << endl;
							fflush(stdin);
							unsigned int n = Data.size();
							while (n >= Data.size())
							{
								cin >> n;
								n--;
								if (n < Data.size())
								{
									ShowFile(Data, page);
									TRec info = {};
									info.id = n;
									add_menu(info);
									Data.hundler[n] = info;
								}	
							}
							break;
							
						}
						case CMD_PAGE:
						{
							ShowFile(Data, page);
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
							ShowFile(Data, page);
							cout << "Введите номер строки:" << endl;
							unsigned int n = 0xffffff;
							cin >> n;
							Data.pop(n - 1);
							break;
						}
						case CMD_FIND:
						{
							ShowFile(Data, page);
							cout << "Введите строку для поиска:" << endl;
							char info[32];
							fflush(stdin);
							scanf("%[^\n]s", info);
							fflush(stdin);
							List<TRec> Data2 = Data.search(info);
							ShowFile(Data2, 0);
							system("pause");
							break;
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