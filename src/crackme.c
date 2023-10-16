//crackme.c
//basic layer eight reverse engineering introduction

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINPUT 32
int 
main(void)
{
	//Getline includes the newline character so this is a hacky workaround for now
	//Ideally this password will be stored in something other than plaintext
	char* not_the_password = "CantHackMyLayerEight\n";
	char* buffer;
	size_t bufsize = MAXINPUT;
	buffer = malloc(bufsize * sizeof(char));
	printf("Enter password: ");
	
	
	getline(&buffer, &bufsize, stdin);

	if (!strncmp(buffer, not_the_password, MAXINPUT))
	{
		printf("Correct Password!\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("INCORRECT PASSWORD!\n");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "Reached end of program");
	return 0;
}
