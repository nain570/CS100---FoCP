#include <stdio.h>

void choice(int);

int main(){

    srand(time(NULL));
    int random, your_choice;
    char ch;

    do{
        system("cls"); //clears screen
        printf("** 0 is for Rock **\n");
        printf("** 1 is for Scissors **\n");
        printf("** 2 is for Lizard **\n");
        printf("** 3 is for Paper **\n");
        printf("** 4 is for Spock **\n");

        printf("\nEnter your choice here:");
        if (scanf("%d", &your_choice) != 1) {
            int c;
            while ((c = getchar()) != EOF && c != '\n')
                continue;
            your_choice = -1;
        }
        random = rand() % 5; //random number between 0 & 4
        if((your_choice >= 0) && (your_choice <= 4)){ //check for valid choice

            printf("\nYou chose ");
            choice(your_choice);
            printf("\nYour computer chose ");
            choice(random);

            /*This IF ELSE branching is very crucial,
            try to figure it out yourself how it works*/
            if((random == ((your_choice + 1)%5)) || (random == ((your_choice + 2)%5)))
                printf("\n\n... and you win!!!\n");
            else if((random == ((your_choice + 3)%5)) || (random == ((your_choice + 4)%5)))
                printf("\n\n... and you lose!!!\n");
            else if(random == your_choice)
                printf("\n\nUnfortunately, it's a tie!\n");
        }
        else
            printf("\nWell, this is wrong! Try again with a number from 0 to 4!!\n");

        printf("\nWould you like to play again? (Y/N)?: ");
        scanf(" %c", &ch); //space before % is VERY IMPORTANT, guesses? without Googling

    } while(ch == 'y' || ch == 'Y');

    return 0;
}
//Prints the choice
void choice(int your_choice){
    switch(your_choice){
    case 0:
        printf("ROCK");
        break;
    case 1:
        printf("SCISSORS");
        break;
    case 2:
        printf("LIZARD");
        break;
    case 3:
        printf("PAPER");
        break;
    case 4:
        printf("SPOCK");
        break;
    default:
        printf("----");

    }
}
