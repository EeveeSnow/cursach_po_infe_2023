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

char* cript(char* info, int encript_key)
{
    for(int i = 0; i < strlen(info); i++)
    {
        info[i] = info[i] + encript_key;
    }
	return info;
}

void sort(List<struct TRec>& data)
{
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
		n = (base_sort(data, n, type) ? n : 0);
	}
}

void filename_menu(char* &filename)
{
	system("cls"); //очистка экрана
	puts("Выберите название файла:"); //отображение меню
	fflush(stdin); //обнуление входного потока
	cin >> filename;
	filename = strdup(filename);
}

void add_menu(TRec &info)
{
	cout << "Введите данные через ENTER в формате:" << endl;
	// printf("%-s %-s %-s %-s %-s\n", "Имя - 32 символа", "Режисер - 32 символа", "год - 4 символа", "Время - 3 символа", "Оценка - 4 символа");
	fflush(stdin);
	char name[32];
	char director[32];
	int year;
	int time;
	float score;
	printf("%s: ", "Имя - 32 символа");
	scanf("%[^\n]s", name);
	fflush(stdin);
	printf("%s: ", "Режисер - 32 символа");
	scanf("%[^\n]s", director);
	fflush(stdin);
	printf("%s: ", "Год - 4 символа");
	cin >> year;
	fflush(stdin);
	printf("%s: ", "Время - 3 символа");
	cin >> time;
	fflush(stdin);
	printf("%s: ", "Оценка - 4 символа");
	cin >> score;
	fflush(stdin);
	info = {info.id, strdup(name), strdup(director), year, time, score};
	fflush(stdin);
}

void edit_menu(TRec &info, int i)
{
	fflush(stdin);
	switch(i) {
		case 1:
			printf("%s: ", "Имя - 32 символа");
			scanf("%[^\n]s", info.name);
			fflush(stdin);
			break;
		case 2:
			printf("%s: ", "Режисер - 32 символа");
			scanf("%[^\n]s", info.director);
			fflush(stdin);
			break;
		case 3:
			printf("%s: ", "Год - 4 символа");
			cin >> info.year;
			fflush(stdin);
			break;
		case 4:
			printf("%s: ", "Время - 3 символа");
			cin >> info.time;
			fflush(stdin);
			break;
		case 5:
			printf("%s: ", "Оценка - 4 символа");
			cin >> info.score;
			fflush(stdin);
			break;
		default:
			break;
	}
}

void edit(List<TRec> &data, unsigned int page, char* filename)
{
	cout << "Введите номер строки по которую изменить:" << endl;
	fflush(stdin);
	unsigned int n = data.size();
	while (n >= data.size())
	{
		cin >> n;
		n--;
		if (n < data.size())
		{
			ShowFile(data, page, filename);
			TRec info = data.hundler[n];
			unsigned int j = 0;
			while (j < 6)
			{
				ShowFile(data, page, filename);
				cout << "Введите номер строки по котоорой редактировать:" << endl;
				printf("%-s %-s %-s %-s %-s %-s\n", "Имя - 1", "Режисер - 2", "год - 3", "Время - 4", "Оценка - 5", "Выход - 6");
				cin >> j;
				edit_menu(info, j);
				data.hundler[n] = info;
			}
		}	
	}
}

int encript_decript()
{
    cout << "введите ключ шифрованния:";
    int key;
	cin >> key;
    return key;
}