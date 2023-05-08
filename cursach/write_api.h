#pragma once
#include "main.h"
bool SaveFile(List<TRec> data, char* filename);
void write_new_data(List<TRec> &data, TRec &info);
bool base_sort(List<TRec>& data, int n);
void change_info(List<TRec> &data, int n, TRec &info);
void delete_line_by_index(List<TRec>& data,unsigned int n);