/**************************************************
** Simple Mad Lib game program to print a short  **
** comical story by filling in the words provided**
** by the user.                                  **
***************************************************
**      Author: Raja Hasnain Anwar               **
***************************************************
**      Reg. No.: 192135                         **
***************************************************
**      Section: BSCS-6B                         **
***************************************************
**   Purpose: To make programming a fun filled   **
**       activity by making funny games!         **
***************************************************
**  How to use: Enter the words when you are     **
**     prompted to, and then see the magic!      **
***************************************************
***************************************************
**            Story: WEIRD DAY                   **
**          Credit: madglibs.com                 **
**************************************************/
/*>>>>>>>>>> preprocessors to add header files and global variable <<<<<<<<<<*/
#include <stdio.h>
#include <stdlib.h>

#define STR_LNGTH 100 //equal string length for all

int main(){
    /* Variable Declaration */
    char noun1[STR_LNGTH], adjective1[STR_LNGTH], noun2[STR_LNGTH], noun3[STR_LNGTH], noun4[STR_LNGTH],
    verb1[STR_LNGTH], adjective2[STR_LNGTH], verb2[STR_LNGTH],adverb1[STR_LNGTH], verb3[STR_LNGTH],
    noun5[STR_LNGTH], adjective3[STR_LNGTH], adverb2[STR_LNGTH];

    printf("** WARNING!! Make sure your inputs aren't larger than 100 characters **\n");
    printf("\tEnter RANDOM words as there's no win or loss; just fun!\n");
/*>>>>>>>>>> Getting words <Start> <<<<<<<<<<*/
// asking the user to enter specific kinds of words and saving them in variables
    printf("Enter a NOUN here: ");
    scanf("%s", noun1);

    printf("Enter an ADJECTIVE here: ");
    scanf("%s", adjective1);

    printf("Enter a PLURAL NOUN here: ");
    scanf("%s", noun2);

    printf("Enter the FIRST name of a PERSON here: ");
    scanf("%s", noun3);

    printf("Enter a PLACE here: ");
    scanf("%s", noun4);

    printf("Enter an ADJECTIVE here: ");
    scanf("%s", adjective2);

    printf("Enter a VERB ENDING IN \"ING\" here: ");
    scanf("%s", verb1);

    printf("Enter an ADVERB here: ");
    scanf("%s", adverb1);

    printf("Enter a PAST VERB here: ");
    scanf("%s", verb2);

    printf("Enter an ADVERB here: ");
    scanf("%s", adverb2);

    printf("Enter a VERB ENDING IN \"ING\" here: ");
    scanf("%s", verb3);

    printf("Enter the FIRST NAME OF A MODEL here: ");
    scanf("%s", noun5);

    printf("Enter an ADJECTIVE here: ");
    scanf("%s", adjective3);
/*>>>>>>>>>> Getting words </end> <<<<<<<<<<*/

/*>>>>>>>>>> Printing the Mad Lib story <<<<<<<<<<*/
// printing the non-sense story by added words entered by the users
    printf("\nHere's your \"WEIRD DAY\" story:\n");
    printf("\t\"Once there was a %s. It had %s\n", noun1, adjective1);
    printf("\t %s! One day, it met %s on the side of %s.\n",noun2, noun3, noun4);
    printf("\t It was very %s; they both looked like hobos!\n", adjective2);
    printf("\t All of the sudden they started %s really %s.\n", verb1, adverb1);
    printf("\t They %s really %s! %s started %s\n", verb2, adverb2, noun3, verb3);
    printf("\t with %s. They looked really %s!\"\n",noun5, adjective3);

    system("pause"); // waiting for a keypress before ending the program

    return EXIT_SUCCESS; // ending program with SUCCESS status
}
