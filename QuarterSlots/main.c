#include <stdio.h> 
#include <time.h> /* libraries */
#include <stdlib.h>

int main(void) {
    int rand_num;
    int balance = 80; // number of quarters
    int bet = 0;
    float cash = balance * .25;

    printf("Welcome to the Betting Game!\nYou have $20 worth of quarters.\n");
    // printf("\n");
    //printf: prompt user input
    //scanf: collect user input
    //printf: you have this amount of money

    while (balance > 0 ) 
    {
        //print balance
        printf("\nYou have %d quarters ($%.2f).\n", balance, cash);
        printf("Enter the number of quarters to bet (or 0 to cash out): ");
        scanf ("%d", &bet);

        if (bet == 0)
        {
            //cashout
            printf("Cashing out. You ended with $%.2f.\n", cash);
            break;
        }

        if (bet > balance || bet< 0)
        {
            //print invalid bet
            printf("Invalid bet. Please enter a valid number of quarters.\n");
            continue;
        }

        srand(time(NULL));
        rand_num = (rand() % 100) + 1; //sets random number

        if(rand_num <50)
        {
            printf("Reel stopped on the number: %.0d\n", rand_num);
            printf("You lose!\n");
            balance = balance - bet;
            // subtract bet from user money
            continue;
        }
        
        else if (rand_num >= 50 && rand_num <= 74)
        {
            printf("Reel stopped on the number: %0d\n", rand_num);
            printf("You get your money back!\n");
            // player money stays the same
            continue;
        }

        else if (rand_num >=75 && rand_num <= 94)
        {
            printf("Reel stopped on the number: %0d\n", rand_num);
            printf("You double your money!\n");
            balance += (bet * 2);
            continue;
        }
        
        
        
        else
        {
            printf("Reel stopped on the number: %0d\n", rand_num);
            printf("Jackpot! You triple your money!\n");
            balance += (bet *3); 
            continue;
        }



    }


}
