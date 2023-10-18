//Usa as libs time.h e dirent.h que foram incluídas na libTrabalho.h
#include "libTrabalho.h"

// Pega data e hora do sistema
struct tm getSystemTime()
{
	time_t mytime;
	mytime = time(NULL);
	struct tm tm = *localtime(&mytime);
	return tm;
}
