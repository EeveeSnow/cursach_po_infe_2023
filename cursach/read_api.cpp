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
using namespace std;

void ReadFile(List<TRec> &data, char* filename)
{
	FILE* file = fopen(filename, "r");
    if (file != NULL) {
        data.clear();
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file) != NULL)
        {
        buffer[strcspn(buffer, "\n")] = '\0';
        struct TRec info = {};
        char* token;
        token = strtok(buffer, ";");
        unsigned int n = 0;
        while (token != NULL) {
            switch (n)
            {
                case 0:
                {
                    info.name = token;
                    break;
                }
                case 1:
                {
                    info.director = token;
                    break;
                }
                case 2:
                {
                    info.year = token;
                    break;
                }
                case 3:
                {
                    info.time = token;
                    break;
                }
                case 4:
                {
                    info.score = token;
                    break;
                }
            }
            token = strtok(NULL, ";");
            n++;
        }
        
        data.append(info);
        info = {};
        cout << data.hundler[0].score << " " << data.size() << endl; 
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

void ShowFile(List<TRec> &data,unsigned int page)
{
    system("cls");
    cout << "Количество строк: " << data.size() << "            " << "Страница: " << page + 1 << " из: " << data.size() / 10 + 1 << endl;
    cout << "---------------------------------------------------------------------" << endl;
    printf("| %-32s | %-32s | %-4s | %-7s | %-4s |\n", "Имя", "Режисер", "год", "Время", "Оценка");
    for (int i = page*10; i < data.size(); i++)
    {
        cout << "---------------------------------------------------------------------" << endl;
        printf("| %-32s | %-32s | %4s | %3s | %4s |\n", data.hundler[i].name, data.hundler[i].director, data.hundler[i].year, data.hundler[i].time, data.hundler[i].score);
    }
    cout << "---------------------------------------------------------------------" << endl;
}
