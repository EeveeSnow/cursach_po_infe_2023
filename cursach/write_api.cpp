#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "dynamic.cpp"
using namespace std;
#include "write_api.h"

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

// struct TRec WriteFile(TRec data, TRec2 data2)
// {
//     if (data2.is_read)
//     {
//         string info;
//         int i = 0, idn = data.size();
//         system("cls"); //очистка экрана
//         puts("Зпаишите данные в формате");
//         puts("Имя ; Режисер ; год ; продажи ; цена");
//         puts("через пробел. Для сохранения введите: `");
//         fflush(stdin);
//         cin >> info;
//         while (info != (string)"`")
//         {
//             switch (i) 
//             {
//                 case 0:
//                     data.id.append(idn);
//                     data.name.append(info);
//                     break;
//                 case 1:
//                     data.director.append(info);
//                     break;
//                 case 2:
//                     data.year.append(info);
//                     break;
//                 case 3:
//                     data.time.append(info);
//                     break;
//                 case 4:
//                     data.price.append(info);
//                     idn++;
//                     i = -1;
//                     break;
//             }
//             i++;
//             cin >> info;
//         }
//         if (i == 0)
//         {
//             data.is_saved = false;
//             return data;
//         }
//     }
        
// }
void write_new_data(List<TRec> &data, TRec info)
{
    data.append(info);
}

