#pragma once
//тип enum для реализации режима обработки команд
enum eCMD {
	CMD_EXIT = -1, CMD_NONE, CMD_READ, CMD_SHOW,
	CMD_EDIT, CMD_ADD, CMD_DELETE, CMD_SORT,
	CMD_FIND, CMD_SAVE, CMD_SAVE_NAMED, CMD_CLOSE, CMD_PAGE
};
////константа задает размер статического массива
//const int MAX_SIZE = 1000;
// структура данных
struct TRec {
	int id;
	char* name;
	char* director;
	char* year;
	char* time;
	char* score;

};

struct TRec2{
	char Filename[32];
	bool is_saved;
	bool is_read;
};