#include "csci4500utils.h"
#include <unistd.h>

int writeline( int fd, const char *str ) {
	
	const size_t MAXSTRLEN = 256;

	int writing = 1; /* Error Handling Flag */
	int errorFlag = 0; /* Will be checking write(...) return value */
	int charsWritten = 0; /* To make sure we don't hit annoying infinite loops  */
	const char *charToWrite = str;


	while (writing && charsWritten < MAXSTRLEN) {
		if (*charToWrite == '\0' || charsWritten == MAXSTRLEN - 1) {
			const char *endl = "\n";
			write(fd, endl, 1);
			writing = 0;
			continue;	/* effectively a break */
		}
		errorFlag = write(fd, charToWrite, 1);
		if (errorFlag == -1) { /* If error, do nothing and get out */
			return -1;
		}
		charsWritten++;
		charToWrite++;
	}

	return charsWritten;
}
