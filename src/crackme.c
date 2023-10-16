//crackme.c
//basic layer eight reverse engineering introduction

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <b64/cencode.h>
#define MAXINPUT 32

void base64_encode_wrapper(const char* input, char* output) {
    base64_encodestate state;
    base64_init_encodestate(&state);
    int length = strlen(input);

    // Encode the input block by block
    int encoded_length = base64_encode_block(input, length, output, &state);
    
    // Complete the encoding
    encoded_length += base64_encode_blockend(output + encoded_length, &state);
    
    // Null-terminate the encoded string
    output[encoded_length] = '\0';
}




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
	char encoded_input[MAXINPUT * 2];  // Adjust the size accordingly
    	base64_encode_wrapper(buffer, encoded_input);
	printf("%s\n", encoded_input);
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
