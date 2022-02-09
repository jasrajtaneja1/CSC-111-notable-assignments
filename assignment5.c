//csc 111 assignment 5, created casino dice game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ROLL 1
#define MAX_ROLL 6
#define MIN_BET 5

int get_bet(int bankroll);
int play_again();
int compute_winnings(int num_matches, int bet);
int get_guess();
void roll_dice(int* die1, int* die2, int* die3);
int count_matches(int guess, int die1, int die2, int die3);
int play_round(int bet);
void play_game(int* bankroll);

int main(void) {
    // we have called srand with a constant value 0 for testing purposes
    // with this call, you will always get the same sequence of numbers generated
    // this allows you to anticipate what the dice rolls will be and let you test play_game more easily
    //srand(0);



    // instead of using call srand(0) as shown above:
    // use this call srand(time(0)) to mimic a new set of random numbers every time you play the game
    // this is a much more real game that you can get your friends to play
  srand(time(0));




int bankroll = 500000;
printf("You have $%d to play with",bankroll);
printf("\n");
play_game(&bankroll);



    return 0;
}


// Write your function defintions here:
//Purpose:To prompt the user for valid betting amount
//Parameters: int = bankroll
//Returns: int - get_amount


int get_bet(int bankroll) {

    int get_amount;

    printf("What is your betting amount: \n");

     scanf("%d",&get_amount);

    while(get_amount< MIN_BET || get_amount>bankroll) {

        printf("What is your betting amount: \n");

        scanf("%d", &get_amount);

    }
return get_amount;



}

//Purpose:To ask the user if they would like to play again, with input from 1 or 0
//Parameters: None
//Returns: int - 1 or 0


int play_again() {
    int play_number;
    printf("Do you want to play again, enter 1 for yes, 0 for no : \n");
    scanf("%d", &play_number);

    while (play_number < 0 || play_number > 1) {


        printf("Do you want to play again, enter 1 for yes, 0 for no : \n");

        scanf("%d", &play_number);


        if (play_number == 0) {
            return 0;

        } else  {

            if (play_number == 1) {

                return 1;
            }
        }


    }
}


//Purpose:To calculate the winnings from number of matches won  and the bet
//Parameters: int = num_matches, bet
//Returns: int - money_won


int compute_winnings(int num_matches, int bet){

    int money_won;




    printf("\n");

    if(num_matches==1){

        money_won = bet;

    }

    else if(num_matches==2){

        money_won = 2*bet;
    }
    else if(num_matches==3){

            money_won= 10*bet;

        }
    else {

        if(num_matches==0){
            money_won = -1*bet;
        }
    }


    return money_won;


}

//Purpose:To prompt the user for a valid guess from 1-6
//Parameters: None
//Returns: int - the users guess


int get_guess(){

    int guess;

  printf("Please enter a valid dice roll guess, 1-6: ");
  scanf("%d", &guess);
  printf("\n");

  while(guess<MIN_ROLL || guess>MAX_ROLL){
      printf("Please enter a valid dice roll guess, 1-6: ");
      scanf("%d", &guess);
      printf("\n");


  }
  return guess;

}

//Purpose:To calculate a number which acts like a dice roll, from 1-6 inclusive
//Parameters: int* - die1,die2,die3




void roll_dice(int* die1, int* die2, int* die3){

    *die1 = rand()%MAX_ROLL+MIN_ROLL;
   printf("%d, ",*die1);


    *die2 = rand()%MAX_ROLL+MIN_ROLL;
     printf("%d, ",*die2);

    *die3 =  rand()%MAX_ROLL+MIN_ROLL;
     printf("%d",*die3);
}

//Purpose:To count the amount of dice that matched the guess
//Parameters: int = guess,die1,die2,die3
//Returns: int - correct guess count


int count_matches(int guess, int die1, int die2, int die3) {

    int correctguess_count=0;

    if(guess==die1){
        correctguess_count++;

    }
    if(guess==die2){
        correctguess_count++;
    }

    if(guess==die3){
            correctguess_count++;
        }


    return correctguess_count;
}
//Purpose:To compute one round of the "chuck a luck"  game with a pre detemined bet
//Parameters: int = bet
//Returns: int - money_won



int play_round(int bet){


    printf("\n");
   int guess = 0;
   guess =  get_guess();
   printf("\n");

    int die1;
    int die2;
    int die3;

    roll_dice(&die1,&die2,&die3);
    printf("\n");
    int num_matches = 0;

    num_matches = count_matches(guess,die1,die2,die3);
    printf("\n");


   int money_won;

   money_won = compute_winnings(num_matches,bet);
   printf("\n");
   return money_won;

}
//Purpose:Lets the user play the full game of Chuck-a-luck until their bankroll goes to zero
//Parameters: int* bankroll




 void play_game(int* bankroll) {




    while(*bankroll>=MIN_BET && (play_again() == 1)) {



        int bet = get_bet(*bankroll);

     int money_won = play_round(bet);

     *bankroll = money_won + *bankroll;

     printf("Your bankroll is $%d",*bankroll);
     printf("\n");

    }
    printf("Thanks for playing! Come back soon!");
}
