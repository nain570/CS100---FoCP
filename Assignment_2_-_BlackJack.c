****************************************************************

	Title: Black Jack Cards Game
	Usage: Using random numbers to play mind games
	Learning Perspective: How to use Random Number Generator
						  How to use While LOOP
						  How to use Conditional Statements

***************************************************************

	Technology: Coded on Sublime Text 3,
				run on MingW GCC using Windows PowerShell

****************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(){

	/* >>>>>	Variable Declaration	<<<<< */

	int player_card_1, player_card_2, dealer_card_1, dealer_card_2, player_total, dealer_total, player_temp_card, dealer_temp_card;

	/*  card 1 and card 2 will hold the first cards assigned to both the player and the dealer.
		total will hold the sum of all the cards of both player and the dealer.
		temp will hold any value generated when player or dealer chooses to HIT */

	char choice;

	// choice will hold the choice of player to either hit or stay

	srand(time(NULL)); //pseudo-seed for rand() OR reset

	printf("Welcome to BlackJack!! where the luck matters......\n");
	printf("Behold! and get ready to test how lucky you are!!\n");
	printf("and scratch your heads while playing, because this is where luck and mind matter A LOT!\n");
	printf("\nGame starts NOW!!\n\n");

	/* >>>>>	Alloting Random Cards to the Player and the  Dealer	<<<<< */

	player_card_1 = rand()%10 + 2;
	player_card_2 = rand()%10 + 2;

	dealer_card_1 = rand()%10 + 2;
	dealer_card_2 = rand()%10 + 2;

	/*  above is simplified version of 'rand() % (max_num + 1 - min_num) + min_num'
		as the max num is 11 and min is 2 (already known) */

	/* >>>>>	Summing Cards' Values	<<<<< */

	player_total = player_card_1 + player_card_2;
	dealer_total = dealer_card_1 + dealer_card_2;

	/* >>>>>	Printing Values		<<<<< */

	printf("\nYou get a %d and a %d.\n", player_card_1, player_card_2);
	printf("Your total is %d.\n", player_total);

	printf("\nDealer gets a %d and a hidden card!\n", dealer_card_1);
	printf("Dealer's total is hidden, too....\n");

	printf("\nLet the fun begin..............!\n\n");

	/* >>>>>	Drawing More Cards Upon Choices		<<<<< */

	//keep asking for choice if not busted
	while(player_total <= 21){
		printf("\nWould you like to \"hit\" or \"stay\"? (H/S) ");
		scanf(" %c", &choice); // space before format specifier ignores white spaces i.e., line feed, space, tabs etc.
		choice = tolower(choice); //changing to lowercase avoids extra conditions

		if(choice == 'h'){
			player_temp_card = rand()%10 + 2; //another random card
			player_total += player_temp_card;
			printf("\nGreat Nerve! You chose to HIT, and drew %d.\n", player_temp_card);
			printf("Your total is now %d.\n", player_total);
		}
		else if(choice == 's'){
			printf("Intersting choice!!\n");
			break; //don't ask to choose if 'stayed'
		}
		if(player_total >21 ){
			printf("You're BUSTED and Dealer WINS!!!\n");
            goto end; //if busted, lose!!
        }
	} //while ends

	//ball is in dealers's court now
	printf("\nOkay... Dealer's turn now!\n");
	printf("\nDealer's hidden card was %d and his total was %d.\n", dealer_card_2, dealer_total);

	//dealer keeps hitting if below 17
	while(dealer_total <= 16){
		dealer_temp_card = rand()%10 + 2; //another random card
		dealer_total += dealer_temp_card;
		printf("\nDealer chooses to HIT and draws a %d.\n", dealer_temp_card);
		printf("\nHis total is now %d.\n", dealer_total);
	}

	printf("\nDealer stays.\n");

	//final totals
	printf("\nYour Total: %d\n", player_total);
	printf("Dealer's Total: %d\n\n", dealer_total);

	/* >>>>>	RESULT is here!		<<<<< */
	if(dealer_total >21)
		printf("Dealer is BUSTED and you WIN!!!\n");
	else if(dealer_total > player_total)
		printf("Dealer WINS!!!\n");
	else if(player_total > dealer_total)
		printf("You WIN!!!\n");
	else if(player_total == dealer_total)
		printf("Dealer WINS the TIE!!!\n");
	end:
	system("pause"); //delay before closing the program (NOT supported by some compilers)
	return 0; //exiting success
}
