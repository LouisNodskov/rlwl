#include "csci4500utils.h"
#include <unistd.h>
#include <stdio.h>

int readline( int fd, char *buf, int bufsz ) {
	
	int chread = 0;
	int retval;
	
	while(chread < bufsz) {
		retval = read(fd, buf, 1);
		if (*buf == '\n') {
			*buf = '\0';
			chread++;
			break;
		}
		if (retval == 0) {
			return 0; /* EOF Detected */
		}
		if (retval == -1) {
			return -1; /* Error Detected */
		}
		chread++;
		buf++;
	}
	return chread;
}
	
