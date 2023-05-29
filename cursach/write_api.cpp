#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dynamic.cpp"
using namespace std;
#include "write_api.h"
// #include "things.h"
#include <string.h>

bool SaveFile(List<TRec> &data, char* filename, int encript_key)
{
    FILE* file = fopen(filename, "w");
        // Записываем строки в файла по одной, пока не достигнем конца массива строк
    for (int i = 0; i < data.size(); i++)
    {
        char line[128];
        sprintf(line, "%s;%s;%d;%d;%2.2f", data.hundler[i].name, data.hundler[i].director, data.hundler[i].year, data.hundler[i].time, data.hundler[i].score);
        sprintf(line, "%s\n", cript(line, encript_key));
        fputs(line, file);
    }
    // Закрываем файл
    fclose(file);
    return true;
}

bool base_sort(List<TRec>& data, int n, int type)
{
    float h = 0;
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.size() - 1; j++)
        {
            switch (n)
            {
            case 1:
                h = strcmp(data.hundler[j].name, data.hundler[j + 1].name);
                break;
            case 2:
                h = strcmp(data.hundler[j].director, data.hundler[j + 1].director);
                break;
            case 3:
                h = data.hundler[j].year - data.hundler[j + 1].year;
                break;
            case 4:
                h = data.hundler[j].time - data.hundler[j + 1].time;
                break;
            case 5:
                h = data.hundler[j].score - data.hundler[j + 1].score;
                break;
            default:
                return false;
                break;
            }
            if (h*type > 0)
            {
                struct TRec hundler = data.hundler[j];
                data.hundler[j] = data.hundler[j + 1];
                data.hundler[j + 1] = hundler;
            }
        }
    }
    return true;
}

