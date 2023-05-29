#pragma once
//тип enum для реализации режима обработки команд
enum eCMD {
	CMD_EXIT = -1, CMD_NONE, CMD_READ, CMD_SHOW,
	CMD_EDIT, CMD_ADD, CMD_DELETE, CMD_SORT,
	CMD_FIND, CMD_SAVE, CMD_SAVE_NAMED, CMD_CLOSE, CMD_PAGE, CMD_DECRIPT, CMD_ENCRIPT
};

char* cript(char* info, int encript_key);
////константа задает размер статического массива
//const int MAX_SIZE = 1000;
// структура данных
struct TRec {
	int id;
	char* name;
	char* director;
	int year;
	int time;
	float score;

};