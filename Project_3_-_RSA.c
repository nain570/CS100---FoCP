/*******************************************
** Title: RSA Public-Key Cryptosystem *
********************************************
** Usage: A little complex but practical *
**		  encryption method, used widely *
**		  in today's communication systems *
********************************************
** Platform: Sublime Text 3 *
**			 MingW on CMD *
*******************************************/

#define _CRT_SECURE_NO_WARNINGS //just a VisualStudio thingy
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// FUNCTION PROTOTYPES
int not_prime( int);
int hcf( int,  int);
int findd( int,  int);
void input(char[] ,char []);
// GLOBAL VARIABLE(S)
int arr[100];

// CONVERTING TO UPPERCASE AND MAPPING NUMBERS	
void input(char message[],char msg[]){
	int i,  length =  strlen(message) - 1;
	printf("Input.  |");

	for ( i = 0; i < length; i++){
		printf("\'%2c\'|", message[i]);
	}

	printf("\n        |");

	for ( i = 0; i < length; i++){
		if (isalpha(message[i]))
			message[i] = toupper(message[i]);
		if (message[i] == ' ')  { msg[i] = 26; }
		else if (message[i] == '.')  { msg[i] = 27; }
		else msg[i] = (message[i] - 'A');
	}

	for ( i = 0; i < length; i++){

		printf("\'%2d\'|", msg[i]);
	}
	printf("\n");
}
// CONVERTING NUMBERS BACK TO ALPHABETS AND PRINTING THE OUTPUT
void Output(char message[],char msg[]){
   printf("\nOutput. |");
   int i, length =  strlen(message) - 1;
    for ( i = 0; i < length; i++){

		if (message[i] == ' ')  { msg[i] = 26; }
		else if (message[i] == '.')  { msg[i] = 27; }
		else msg[i] = (message[i] - 'A');
		if (isalpha(message[i])){ message[i] = toupper(message[i]); }
	}

	for ( i = 0; i < length; i++){

		printf("\'%2d\'|", msg[i]);
	}
	printf("\n");
printf("        |");
	for ( i = 0; i < length; i++)
        {
		printf("\'%2c\'|", message[i]);
	}

	printf("\n");

}
void M(char message[]){
	printf("\n     M. |");
	int i, length =  strlen(message) - 1;
	for ( i = 0; i < length; i = i + 2)
	{
		printf("  %c%c |", message[i], message[i + 1]);
	}
	printf("\n");
}
void P(char msg[],char message[]){

	printf("     P. |");
	int length =  strlen(message) - 1;
	msg[length] = 0;

	int i, j = 0;

	for ( i = 0; i < length; i=i+2){

		arr[j] = msg[i] * 100 + msg[i + 1];

		printf(" %4d|", msg[i] * 100 + msg[i + 1]);

		j++;
	}

	arr[j] = '\0';

}
int hcf( int a,  int h) //Check if the number e is co-prime or not.
{
    while(1)
    {	
    	int tmp = a%h;
        if(tmp==0)
        	return h;
        a = h;
        h = tmp;
    }
}
// RSA UTILITY
int findd( int  e,  int phi) //To find the value of d.
{
	int  x, y, u, v, m, n, a, b, q, r;
	x = 0; y = 1;
	u = 1; v = 0;
	for (a = e, b = phi; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n)
	{
		q = b / a;
		r = b % a;
		m = x - (u * q);
		n = y - (v * q);
	}
	return m + x;
}
int not_prime(int pr) { //Checking if the entered number is NOT prime.
	int i, c;
	c = sqrt(pr);
	for (i = 2;i <= c; i++) {
		if(pr%i == 0)
		    return 1; //if NOT prime
	}
	return 0; //if prime
}
int main()
{
    printf("+-----------------------------+\n");
	printf("| RSA Public-key Cryptosystem |\n");
	printf("+-----------------------------+\n");

    int k, i, j;
    char message[100];
    printf("\nEnter the message here:");
    fgets(message, 100, stdin);
    int length = strlen(message) - 1;
    char msg[length];
    int FirstPrime, SecPrime, n, phi, e, gcd, d;
    printf("\n\n+-------------------+\n");
	printf("| I. Key Generation |\n");
	printf("+-------------------+\n");
    printf("Enter first prime number: ");
    scanf("%d", &FirstPrime);
    printf("Enter second prime number: ");
    scanf("%d", &SecPrime);
    if (not_prime(FirstPrime) || not_prime(SecPrime) || SecPrime == FirstPrime)
    {
        printf("Invalid Input.\n");
        return 0;
    }
    n = FirstPrime * SecPrime;
    phi = (FirstPrime -1) * (SecPrime -1);
    printf("F(n): %d\n", phi);
    printf("Choose any number [1 < e < %d] that is co-prime to it: ", phi);
    scanf("%d", &e);
    gcd = hcf(e, phi);
    if (gcd != 1)
    {
        printf("Invalid co-prime entered.\n");
        return 0;
    }
    d = findd(e, phi);
    printf("The d is: %d\n", d);
    printf("\nThe public key is: (%d, %d)\n", e, n);
    printf("The private key is: (%d, %d)\n", d, n);
	int key = 2;
	printf("\n+-------------------------+\n");
	printf("| II. Cipher and Decipher |\n");
	printf("+-------------------------+\n");

	input(message,msg);
	M(message);
	P(msg,message);

	printf("\n     C. |");

	for ( i = 0; arr[i] != '\0'; i++){

		 int num = 1;

		for ( j = 1; j <= e; j++){

			num = num * arr[i];
			num = num % n;
		}

		printf(" %4d|", num);
	}
	printf("\n     D. |"); //Decryption

	for ( i = 0; arr[i] != '\0'; i++){
		 int num = 1;

			num = pow(arr[i], d);
			arr[i] = arr[i] % n;
            printf(" %4d|", arr[i]);
	}
    M(message);
    Output(message, msg);
}
