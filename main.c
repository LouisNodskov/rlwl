#include <stdio.h>
#include <stdlib.h>
#include "csci4500utils.h"

int main( void ) {
	const int bufsz = 80;
	char inbuf[80];
	char outbuf[80];
	int rval;

	writeline(1, "Enter a line of text and hit [Enter]:");

	while(1) {
		rval = readline(0, inbuf, bufsz);
		
		if (rval > 0) {
			sprintf(outbuf, "%s", inbuf);
			writeline(1, outbuf);
		}
		else if (rval == 0) {
			writeline(1, "EOF condition detected.");
			break;
		}
		else {
			writeline(1, "ERROR: writeline()!");
			break;
		}
	}

	exit(EXIT_SUCCESS);
}

