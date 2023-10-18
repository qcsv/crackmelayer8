
#define _POSIX_C_SOURCE 200809L
#include <md5.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXINPUT 32



int
main(void)
{
	FILE* file;
	int display;
	printf("Welcome to the Voight Kampff Calibration utility.\n Please enter the calibration code.\n");
	unsigned char digest[16];
	const char* string = "1c18d67d18410d5f15dd8b1847c6386e";
	struct MD5Context context;
	char* buffer;
	size_t bufsize = MAXINPUT;
	buffer = malloc(bufsize * sizeof(char));
	getline(&buffer, &bufsize, stdin);
	
	//convert input to hash
	MD5Init(&context);
	MD5Update(&context, buffer, strlen(buffer));
	MD5Final(digest, &context);
	char md5string[33];
	for(int i = 0; i < 16; ++i)
		    sprintf(&md5string[i*2], "%02x", (unsigned int)digest[i]);
	
	if (!strncmp(md5string, string, MAXINPUT))
	{
		file = fopen("../l0rdh3ck3r/blade.txt", "r");
		while (1)
		{
			display = fgetc(file);
			if (feof(file))
				break;
			printf("%c", display);
		}
		exit(EXIT_SUCCESS);
	}


}
