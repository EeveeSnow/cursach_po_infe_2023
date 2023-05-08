#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dynamic.cpp"
using namespace std;
#include "write_api.h"
#include <string.h>

bool SaveFile(List<TRec> data, char* filename)
{
    FILE* file = fopen(filename, "w");
        // Записываем строки в файла по одной, пока не достигнем конца массива строк
    char ch = ';';
    for (int i = 0; i < data.size() - 1; i++)
    {
        char line[32+32+4+8+4+5];
        for(int j = 0; j < 32; i++)
        {
            line[j] = data.hundler[i].name[j];
        }
        line[32] = ch;
        for(int j = 0; j < 32; i++)
        {
            line[33+ j] = data.hundler[i].director[j];
        }
        line[64] = ch;
        for(int j = 0; j < 4; i++)
        {
            line[65+ j] = data.hundler[i].year[j];
        }
        line[68] = ch;
        for(int j = 0; j < 8; i++)
        {
            line[69 + j] = data.hundler[i].director[j];
        }
        line[76] = ch;
        for(int j = 0; j < 4; i++)
        {
            line[77 + j] = data.hundler[i].director[j];
        }
        line[80] = ch;
        fputs(line, file);
    }
    // Закрываем файл
    fclose(file);
    return true;
}

void write_new_data(List<TRec> &data, TRec &info)
{
    data.append(info);
}

bool base_sort(List<TRec>& data, int n)
{
    int h = 0;
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
                h = strcmp(data.hundler[j].year, data.hundler[j + 1].year);
                break;
            case 4:
                h = strcmp(data.hundler[j].time, data.hundler[j + 1].time);
                break;
            case 5:
                h = strcmp(data.hundler[j].score, data.hundler[j + 1].score);
                break;
            default:
                return false;
                break;
            }
            if (h > 0)
            {
                struct TRec hundler = data.hundler[j];
                data.hundler[j] = data.hundler[j + 1];
                data.hundler[j + 1] = hundler;
            }
        }
    }
    return true;
}

void change_info(List<TRec>& data,unsigned int n, TRec &info)
{
    data.hundler[n] = info;
}

void delete_line_by_index(List<TRec>& data,unsigned int n)
{
    data.pop(n);
}