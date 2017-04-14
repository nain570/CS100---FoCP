/************************************
** Title: Caesar's Cipher *
*************************************
** Usage: An encryption technique *
**	using basic knowledge of *
**	strings. *
************************************/
#define _CRT_SECURE_NO_WARNINGS

/***** LOADING RESOURCES *****/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cipher(unsigned char[], int);

int main(){

	/***** VARIABLE DECLARATION *****/
	unsigned char message[50];
	int key = 0;
	/***** INPUTS *****/
	printf("\nCAESAR'S CIPHER\n" );
	printf("\nEnter the message to encrypt here[not  more than 50 characters]: " );
	fgets(message, 50, stdin); //getting an input message which is to be encrypted

	printf("\nEnter the message key here: ");
	scanf(" %d", &key); //getting key

	while(!(key >= 1 && key <= 25)){ //re-prompting for valid key if key is out of range (invalid)
		printf("\nEnter a VALID key: " );
		scanf(" %d", &key);
	}

	/***** ENCRYPTION *****/
	printf("\nENCYPTING...\n");
	cipher(message, key); //passing message for encryption by using the fact that strings are always passed by reference
	printf("\n%s\n", message); //printing the encrypted message

	/***** DECRYPTION *****/
	printf("\nDECYPTING...\n");
	cipher(message, -key); //passing message for decryption by using the fact that strings are always passed by reference
	printf("\n%s\n", message); 

	system("pause");
	return EXIT_SUCCESS;
}

void cipher(unsigned char message[], int key){
	int length = strlen(message);
	int i = 0;

	for(i = 0; i < length; ++i){

		if(isalpha(message[i])){
			/***** FOR UPPER CASE LETTERS *****/
			if(isupper(message[i])){
				message[i] += key; //adding key

				/***** ENCRYPTION PART *****/
				if(message[i] > 90) //if exceeding ASCII, go round
					message[i] -= 26;

				/***** DECRYPTION PART *****/
				else if(message[i] < 65) //if ASCII is lower than A, go round
					message[i] += 26;
			}
			/***** FOR LOWER CASE LETTERS *****/
			else if(islower(message[i])){
				message[i] += key;

				/***** ENCRYPTION PART *****/
				if(message[i] > 122) ////if exceeding ASCII, go round
					message[i] -= 26;

				/***** DECRYPTION PART *****/
				else if(message[i] < 97) //if ASCII is lower than a, go round
					message[i] += 26;
			}

		}

	}
}
