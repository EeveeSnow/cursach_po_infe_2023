#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include "dynamic.cpp"
#include "main.h"
#include <sstream>
#include "read_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "things.h"
#define strdup _strdup
using namespace std;

void ReadFile(List<TRec> &data, char* filename, int encript_key)
{
	FILE* file = fopen(filename, "r");
    if (file != NULL) {
        data.clear();
        char buffer[1024];
        unsigned int j = 0;
        while (fgets(buffer, sizeof(buffer), file) != NULL)
        {
        buffer[strcspn(buffer, "\n")] = '\0';
        struct TRec info = {};
        sprintf(buffer, "%s", cript(buffer, encript_key * -1));
        char* token;
        token = strtok(buffer, ";");
        unsigned int n = 0;
        while (token != NULL) {
            switch (n)
            {
                case 0:
                {
                    info.name = strdup(token);
                    break;
                }
                case 1:
                {
                    info.director = strdup(token);
                    break;
                }
                case 2:
                {
                    info.year = atoi(token);
                    break;
                }
                case 3:
                {
                    info.time = atoi(token);
                    break;
                }
                case 4:
                {
                    info.score = atof(token);
                    break;
                }
            }
            token = strtok(NULL, ";");
            n++;
        }
        info.id = j++;
        data.append(info);
        info = {};
    }
    }
    else {
        // Выводим сообщение об ошибке, если файл не удалось открыть
        std::cerr << "Невозможно прочитать: " << filename << std::endl;
        system("pause");
    }
    // Закрываем файл
    fclose(file);
}

void ShowFile(List<TRec> &data, unsigned int page, char* filename)
{
    system("cls");
    cout << "Количество строк: " << data.size() << "            " << "Страница: " << page + 1 << " из: " << data.size() / 10 + 1 << "            " << "Имя файла: " << filename << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    printf("| %-3s | %-35s | %-39s | %-7s | %-10s | %-4s |\n", "#", "Имя", "Режисер", "год", "Время", "Оценка");
    for (int i = page*10; i < (page+1)*10 && i < data.size(); i++)
    {
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        printf("| %-3d | %-32.32s | %-32.32s | %4.4d | %7.3d | %2.2f |\n", data.hundler[i].id + 1, data.hundler[i].name, data.hundler[i].director, data.hundler[i].year, data.hundler[i].time, data.hundler[i].score);
    }
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
}