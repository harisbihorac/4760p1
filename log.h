/*
 *
 * Modified from book UNIX systems prog by Robbins/Robbins.
 * char type was added to specify type of message: informatinal (INFO), warning (WARN), 
 * error (ERROR), or fatal (FATAL).
 */

#include <time.h>

typedef struct data_struct {
	time_t time; 	// Time stamp
	char type;   	// Message type (I/W/E/F)
	char *string;	// Message string
} data_t;

int addmsg(data_t data, char *ofile, int sec);
void addTime(data_t data);
char addType(data_t data);
void clearlog(data_t data);
char *getlog(data_t data);
int savelog(data_t data, char *file);
