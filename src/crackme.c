//crackme.c
//basic layer eight reverse engineering introduction
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <b64/cencode.h>
#include <b64/cdecode.h>
#define MAXINPUT 32


void 
base64_encode_wrapper(const char* input, char* output) 
{
    base64_encodestate state;
    base64_init_encodestate(&state);
    int length = strlen(input);

    // Encode the input block by block
    int encoded_length = base64_encode_block(input, length, output, &state);
    
    // Complete the encoding
    encoded_length += base64_encode_blockend(output + encoded_length, &state);
    
//remove newline character?? hack
    if (encoded_length > 0 && output[encoded_length - 1] == '\n') {
        output[encoded_length - 1] = '\0';
        encoded_length--;
    }

    // Null-terminate the encoded string
    output[encoded_length] = '\0';
}


int 
main(void)
{
	FILE* file;
	int display;
	char* not_the_password = "Q2FudEhhY2tNeUxheWVyRWlnaHQ=";
	char* buffer;
	char* riddlein;
	size_t bufsize = MAXINPUT;
	riddlein = malloc(bufsize * sizeof(char));
	printf("Do you feel that there's a part of you that's missing? Interlinked.\n");
	getline(&riddlein, &bufsize, stdin);
	if (!strncasecmp(riddlein, "interlinked\n", MAXINPUT))
	{
		printf("When you're not performing your duties do they keep you in a little box? Cells.\n");
		getline(&riddlein, &bufsize, stdin);
		if (!strncasecmp(riddlein, "cells\n", MAXINPUT))
		{
			printf("What's it like to hold the hand of someone you love? Interlinked.\n");
			getline(&riddlein, &bufsize, stdin);
			if (!strncasecmp(riddlein, "interlinked\n", MAXINPUT))
			{
			printf("You get a strange feeling that you might be doing something too early...\n\n");
			file = fopen("../l0rdh3ck3r/pass.txt", "r");
			while (1)
			{
				display = fgetc(file);
				if (feof(file))
					break;
				printf("%c", display);
			}
				printf("\"We're done... Layer 8, you can pick up your bonus.\"\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				printf("You're not even close to baseline.\n");
				exit(EXIT_FAILURE);
			}
	}
		else
		{
				printf("You're not even close to baseline.\n");
				exit(EXIT_FAILURE);
		}
	}

	else if (!strncasecmp(riddlein, "OVERRIDE\n", MAXINPUT))
	{
		printf("Override key accepted.\n");
		buffer = malloc(bufsize * sizeof(char));
	printf("Enter password: ");
	
	
        	ssize_t input_length = getline(&buffer, &bufsize, stdin);

		if (input_length > 0 && buffer[input_length - 1] == '\n') 
    		{
		buffer[input_length - 1] = '\0';
		input_length--;
		}

    char encoded_input[MAXINPUT * 2];  // Adjust the size accordingly
    base64_encode_wrapper(buffer, encoded_input);


//printf("E:%s", encoded_input);
		if (!strncmp(encoded_input, not_the_password, MAXINPUT))
		{
		printf("Correct Password!\n");
		file = fopen("../l0rdh3ck3r/info.txt", "r");
		while (1)
		{
			display = fgetc(file);
			if (feof(file))
				break;
			printf("%c", display);
		}
		exit(EXIT_SUCCESS);

		}
		else
		{
		printf("INCORRECT PASSWORD!\n");
		exit(EXIT_FAILURE);
		}
	
	}
	
	//false prompt
	else 
	{
		printf("You're not even close to baseline.\n");
		printf("Enter password: ");
        	getline(&buffer, &bufsize, stdin);
		printf("INCORRECT PASSWORD!\n");
		exit(EXIT_FAILURE);
	}


	fprintf(stderr, "Reached end of program");
	exit(EXIT_FAILURE);
}
