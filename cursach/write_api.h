#pragma once
#include "main.h"
void WriteFile(List<TRec> data, char* filename);
bool CreateFile(char* filename);
bool SaveFile(List<TRec> data, char* filename);
void write_new_data(List<TRec> &data, TRec info);