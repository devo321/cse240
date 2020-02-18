#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

//Macro definitions
#define sub_macro(x,y) (x - y)
#define cube_macro(x) (x*x*x)
#define min_macro(x,y) (x <= y ? x : y)
#define odd_macro(a) (a % 2 == 0 ? 0 : 1)

using namespace std;

//Function Prototype/forward declaration
int EvensOrOdds(char *name);
int RockPaperScissors(char *name);
int ThinkingOfANumber(char *aName);
int DiceRollShowdown(char *name);
void MiniGameController();
void MacrosVsFunctions();
char* GenRandomName();
int RandomInRange(int min, int max);
bool IsEven(int num);
int RollDie(int sides);



/*
    @name   main
    @desc   Main function of the program, Contains the menu and seeds the random nunber generator
    @params none
    @return int - returns 0 for successful run
*/
int main(){
    int menuNum = -1;
    char term;
    srand(time(0));

    //Main menu system
    while(menuNum != 0){
        printf("Welcome to the CSE240 Assignment 2!\n");
        printf("Menu:\n");
        printf("1 - CSE240 Mini-Game Collection\n");
        printf("2 - Macros vs Functions Throw-down\n");
        printf("0 - Exit\n");
        printf("Choose an option: ");

        scanf("%d", &menuNum);
        
        //Validates user input 
         if(menuNum == 0 || menuNum == 1 || menuNum == 2){ 
            //Calls appropriate function for user selection
            switch(menuNum){
                case 1:
                    MiniGameController();
                    break;
                case 2:
                    MacrosVsFunctions();
                    break;
                case 0:
                    std::cout << "Exit:" << endl;
                    break;
                default:
                    std::cout << "Default Condition met" << endl;
            }
        }
        else{
            //Displays if user input was invalid, flushes stdin
            printf("------------------------------------\n");
            printf("Please enter 0, 1, or 2\n");
            printf("------------------------------------\n");
            fflush(stdin);
        }
    }
    return 0;
}




/*
    @name   EvensOrOdds
    @desc   Player picks even(0) or odd(1), Then the player is prompted for a numbner. Opponent will generate
            a random number. The numbers are then added together and if the result matches the users guess of even
            or odd the player wins. 
    @param  char *name - pointer to the name value generated in the controller function by the GenRandomName function
    @return int win - Returns 1 for a win, 0 for loss
*/
int EvensOrOdds(char *name) {
    //Function Variables
    int nameNum = RandomInRange(0,100);
    int cpuNum = RandomInRange(0,100);
    int gameNum;
    int evenOrOdd;
    int usrNum;
    bool numLoop = true;
    bool boolEvenOrOrdd = true;
    int win = 0;
    char* buffer = name;
    //Print statements 
    printf("Even/Odd game!\n");
    printf("Guess even or odd! (0 for even, 1 for odd): ");

    //Validates user input and takes even/odd choice 
    while(boolEvenOrOrdd){
        scanf("%d", &evenOrOdd);
        if(evenOrOdd == 1 || evenOrOdd == 0){
            boolEvenOrOrdd = false;
        }
        else{
            //Displays if user input was invalid, flushes stdin
            printf("Enter 0 for even, 1 for odd: ");
            fflush(stdin);
        }
    }

    //Validates user input and takes user num
    printf("Enter a number (between 0 and 100): ");
    while(numLoop){
        
        scanf("%d", &usrNum);
        if(usrNum < 0 || usrNum > 100){
            //Displays if user input was invalid, flushes stdin
            printf("Enter a number between 0 and 100: ");
            fflush(stdin);
        }
        else{
            numLoop = false;
        }
    }
    //Totals cpu and user num
    gameNum = usrNum + cpuNum;

    //Prints each players numbers
    printf("%s picked %d\n", buffer, cpuNum);
    printf("%d + %d = %d - ", usrNum, cpuNum, gameNum);

    //Win/loss logic + Prints who wins
    if(IsEven(gameNum)){
        printf("EVEN!\n");
        if(evenOrOdd == 0){
            printf("You win this round!\n");
            win = 1;
        }
        else{
            printf("%s wins this round!\n", buffer);
        }
    }
    else{
        printf("ODD!\n");
        if(evenOrOdd == 1){
            printf("You win this round!\n");
            win = 1;
        }
        else{
            printf("%s wins this round!\n", buffer);
        }
    }
    printf("\n");
    printf("\n");



    return win;
}




/*
    @name   RockPaperScissors
    @desc   Player chooses Rock (1), Paper(2), or Scissors(3) as does the opponent.
            Winner of the round is announced at the end.
    @param  char *name - pointer to the name value generated in the controller function by the GenRandomName function
    @return int win - Returns 1 for a win, 0 for loss, -1 for a tie
*/
int RockPaperScissors(char *name){
    //Function Variables
    int usrNum;
    bool loopBool = true;
    int nameNum = RandomInRange(0,100);
    int cpuNum = RandomInRange(1, 3);
    int win = 0;
    char* buffer = name;
    //Print statements 
    printf("Rock, Paper, Scissors game!\n");
    printf("Choose a throw!\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    
    printf("Enter a number (1, 2, or 3): ");
    //std::cout<<"Cpu num: " << cpuNum<<endl;
    //Validates user input and takes user input
    while(loopBool){
        scanf("%d", &usrNum);
        if(usrNum == 1 || usrNum == 2 || usrNum == 3){
            loopBool = false;
        }
        else{
            //Displays if user input was invalid, flushes stdin
            printf("Please enter 1, 2, or 3: ");
            fflush(stdin);
        }
    }

    //Win/Loss/Tie logic
    if(usrNum == 1){        //Rock
        switch(cpuNum){
            case 1:         //Rock
                printf("%s picked Rock! It's a tie!\n", buffer);
                win = -1;
                break;
            case 2:         //Paper
                printf("%s picked Paper! %s wins!\n", buffer, buffer);
                break;
            case 3:         //Scissors
                printf("%s picked Scissors! You win!\n", buffer);
                win = 1;
                break;
            default:
                printf("Default Condition Reached\n");        
        }
    }
    else if(usrNum == 2){   //Paper
        switch(cpuNum){
            case 1:         //Rock
                printf("%s picked Rock! You win!\n", buffer);
                win = 1;
                break;
            case 2:         //Paper
                printf("%s picked Paper! It's a tie!\n", buffer);
                win = -1;
                break;
            case 3:         //Scissors
                printf("%s picked Scissors! %s wins!\n", buffer, buffer);
                break;
            default:
                printf("Default Condition Reached\n");   
        }
    }
    else{                   //Scissors
        switch(cpuNum){
            case 1:         //Rock 
                printf("%s picked Rock! %s wins!\n", buffer, buffer);
                break;
            case 2:         //Paper
                printf("%s picked Paper! You Win!\n", buffer);
                win = 1;
                break;
            case 3:         //Scissors
                printf("%s picked Scissors! It's a tie!\n", buffer);
                win = -1;
                break;
        }
    }
    



    printf("\n");
    return win;
}




/*
    @name   ThinkingOfANumber
    @desc   Opponent "Thinks" of a number within a range
            The values are a minimum of 30 apart but no
            farther apart than 100. Player then has 5
            chances to guess the number. The opponent
            provides feedback on if the users guessed number
            is higer or lower than the number "thought" of
    @param  char *name - pointer to the name value generated in the controller function by the GenRandomName function
    @return int win - Returns 1 for a win, 0 for loss
*/
int ThinkingOfANumber(char *aName){
    //Function Variables
    int usrNum;
    int guesses = 0;
    bool notValid;
    int lower = RandomInRange(0, 1000);
    int upper = RandomInRange(lower + 30, lower + 100);
    int cpuNum = RandomInRange(lower, upper);
    char* name = aName;
    int win = 0;
    
    //Print Statements
    printf("Player, Im thinking of a number between %d and %d!\n", lower, upper);
    printf("You have 5 guesses!\n");

    //printf("CPU Num = %d\n", cpuNum);

    //While loop controls user guesses
    while(guesses < 5 && guesses != -1){
        printf("What's guess #%d? ", guesses + 1);
        notValid = true;

        //Validates user input and takes user inputs
        while(notValid){
            scanf("%d", &usrNum);
            if(usrNum >= lower && usrNum <= upper){
                notValid = false;
                guesses++;
            }
            else{
                //Displays if user input was invalid, flushes stdin
                printf("Please enter a number between %d and %d: ", lower, upper);
                fflush(stdin);
            }
        }
        //Game logic
        if(usrNum < cpuNum){
            printf("My number is higher!\n");
        }
        else if(usrNum > cpuNum){
            printf("My number is lower!\n");
        }
        else {
            printf("You guessed it! You guessed %d and I thought of %d!\n\n", usrNum, cpuNum);
            guesses  = -1;
            win = 1;
        }
        

    }
    //Displays when you run out of guesses
    if(guesses >= 5){
        printf("You ran out of guesses! Better luck next time!\n\n");
    }

    return win;
}




/*
    @name   DiceRollShowdown
    @desc   Asks user how many and what size dice to roll.
            The player and opponent then roll the same number
            of die, the values are summed, and the player with 
            the higher number wins the game. 
    @param  char *name - pointer to the name value generated in the controller function by the GenRandomName function
    @return int win - Returns 1 for a win, 0 for loss, -1 for a tie
*/
int DiceRollShowdown(char *name){
    //Function Variables
    char* cpuName = name;
    int diceSides = 0;
    int diceToRoll =0;
    int playerTotal = 0;
    int cpuTotal = 0;
    int win = 0;
    int i;
    //Print statements
    printf("Dice Roll Showdown!\n");
    printf("How many sides do the dice have (enter a positive number > 0): ");
    while(diceSides <= 0){
        scanf("%d", &diceSides);
        if(diceSides <= 0){
            printf("Enter a positive number > 0: ");
            fflush(stdin);
        }
    }
    printf("How many dice will each player roll? ");
    while(diceToRoll <= 0){
        scanf("%d", &diceToRoll);
        if(diceToRoll <= 0){
            printf("Enter a positive number > 0: ");
            fflush(stdin);
        }
    }

    //Creates arrays to hold the dice rolls of each player
    int playerRoll[diceToRoll];
    int cpuRoll[diceToRoll];

    //Rolls the die for each player
    for(i = 0; i < diceToRoll; i++){
        playerRoll[i] = RollDie(diceSides);
        cpuRoll[i] = RollDie(diceSides);
    }

    //Prints player rolls and total 
    printf("Player Rolled:\n");
    for(i = 0; i < diceToRoll; i++){
        printf("%d\n", playerRoll[i]);
        playerTotal += playerRoll[i];
    }
    printf("Total: %d\n\n", playerTotal);

    //Prints CPU rolls and total
    printf("%s Rolled: \n", cpuName);
    for(i = 0; i < diceToRoll; i++){
        printf("%d\n", cpuRoll[i]);
        cpuTotal += cpuRoll[i];
    }
    printf("Total: %d\n", cpuTotal);

    //Game win/loss logic 
    if(playerTotal > cpuTotal){
        printf("Player Wins!\n");
        win = 1;
    }
    else if(playerTotal < cpuTotal){
        printf("%s Wins!\n", cpuName);
    }
    else{
        printf("It's a tie!\n");
        win = -1;
    }


    return win;
}




/*
    @name   RandomInRange
    @desc   Generates a random number within an upper and lower limit
    @param  int min, int max - Lower and upper bounds of the number generation
    @return int randomNum - Random number generated between min and max
*/
int RandomInRange (int min, int max){
    //Function Variables
    int randomNum;
    //Generates a random number
    randomNum = (rand() % (max - min + 1) + min );
    return randomNum;
}




/*
    @name   IsEven
    @desc   Determines if the value passed to the function
            is even
    @param  int num - value to determine even/odd
    @return bool even - Returns true if the number is even, false if the number is odd
*/
bool IsEven(int num){
    //Function Variables
    bool even;

    //Even or odd logic
    if(num % 2 == 0){
        even = true;
    }
    else{
        even = false;
    }

    return even;
}




/*
*    @name   GenRandomName
*    @desc   Pulls a random name from a text file containing 100 names
*    @param  None
*    @return char name - A character array containing a random name pulled from the text file
*/
char* GenRandomName(){
    //Function variables and File IO
    int nameNum = RandomInRange(0, 100);
    FILE * inFile;
    static char name[30];
    inFile = fopen("random_names.txt", "r");

    //Pulls random name from file and returns it
    int i;
    for(i = 0; i < nameNum; i++){
        fscanf(inFile, "%s", name);
    }
    fclose(inFile);

    return name;
}




/*
    @name   RollDie
    @desc   Calls the RandomInRange function to generate a random number
            between 1 and the number of sides the user has defined the \
            die to have
    @param  int sides - Number of sides the dice has
    @return int result - The random number that the die had landed on from the roll

*/
int RollDie(int sides){
    int result = RandomInRange(1, sides);
    return result;
}




/*
*    @name   MiniGameController
*    @desc   Function is called to act as the main control for the mini-games.
*            A random opponent name is generated and a random game is picked
*            for the player to play. The controller keeps track of the score
*            and determines the winner of the games based on each participants
*            score over the rounds played, number of rounds are determined by 
*            the player
*    @param  None
*    @return None
*/
void MiniGameController(){
    //Function Variables
    int numRounds = 0;
    int randomNum;
    int count = 0;
    int playerScore = 0;
    int cpuScore = 0;
    char *opponent = GenRandomName();
    int win = 0;
    //Print Statemnets
    printf("\n\nWelcome to CSE240 Mini-Game Collection!\n");
    printf("I am your opponent %s\n", opponent);

    //Validates user input
    do{
        printf("How many rounds should we play? (choose an odd number): ");
        scanf("%d", &numRounds);
        fflush(stdin);
    }while(numRounds <= 0 && numRounds % 2 == 0);
    
    //Randomly selects the game that will be played
    while(count < numRounds){
        randomNum = RandomInRange(1,4);
        switch(randomNum){
            case 1: 
                win = EvensOrOdds(opponent);
                break;
            case 2:
                win = RockPaperScissors(opponent);
                break;
            case 3:
                win = ThinkingOfANumber(opponent);
                break;
            case 4:
                win = DiceRollShowdown(opponent);
                break;
            default:
                printf("Default Reached in Minigame Controller");
                
        }
        //Score tally logic
        if(win == 1){
            playerScore++;
            count++;
        }
        else if (win == 0){
            cpuScore++;
            count++;
        }
        else if(win == -1){
            count++;
        }

        //Determines if you can win the game early, (winning 2 out of 3 ends the game)
        if(playerScore != 0){
            if(((numRounds % playerScore) + playerScore == numRounds )){
                count = numRounds;
            }
        }
        if(cpuScore != 0){
            if(((numRounds % cpuScore) + cpuScore == numRounds )){
                count = numRounds;
            }
        }
        //Prints the score at the end of each round of games
        printf("\nThe score is:\n");
        printf("Player - %d\n", playerScore);
        printf("%s - %d\n\n", opponent, cpuScore);



    }
    //Win/Loss logic
    if(playerScore > cpuScore){
        printf("You won the Minigames!\n\n");
    }
    else{
        printf("%s won the Minigames! Better luck next time!\n\n",opponent);
    }




    return;
}


// Below are the functions for Macros Vs Functions showdown



/* 
*    @name subf
*    @desc   Subtracts two integer values that are passed to it
*    @param  int a, int b - values to be subtracted
*    @return int - result of the subraction
*/
int subf(int a, int b){
    return a - b;
}




/*
*    @name cubef
*    @desc   Cubes the integer value passed to it
*    @param  int a - the value to be cubed
*    @return int - the result of the cubing of the function
*
*/
int cubef(int a){
    return a * a * a;
}




/*
*    @name minf
*    @desc   Finds and returns the minimum value of the two params
*    @params int a, int b - values to be compared to determine the lower value
*    @return int - the lower or minimum value between the two integers
*/
int minf(int a, int b){
    if(a <= b){
        return a;
    }
    else{
        return b;
    }
}



/*
    @name   oddf
    @desc   Determines if the paramter value passed to the function is odd
    @param  int a - value to be deemed odd or even
    @return int - returns 0 for even, 1 for odd
*/
int oddf(int a){
    if(a % 2 == 0){
        return 0;
    }
    else{
        return 1;
    }
}




/*
*    @name MacrosVsFunctions
*    @desc   Calls and displays the output of functions and macros for the Functions vs Macros menu option
*            Numbers being used by the functions and macros are reset after each function/macro call
*    @param  No parameters
*    @return No return type    
*
*
*/
void MacrosVsFunctions(){
    int num1 = 10;
    int num2 = 17;
    int ans;

    printf("\nMacros Vs Functions\n");

    //Sub
    ans = subf(num1, num2);
    num1 = 10;
    num2 = 17;
    printf("subf(num1, num2) = %d\n",ans);

    //ans = sub_macro(num1, num2);
    printf("sub_macro(num1, num2) = %d\n", sub_macro(num1, num2));
    num1 = 10;
    num2 = 17;

    ans = subf(num1++, num2--);
    printf("subf(num1++, num2--) = %d\n", ans);
    num1 = 10;
    num2 = 17;

    printf("sub_macro(num1++, num2--) = %d\n", sub_macro(num1++, num2--));
    num1 = 10;
    num2 = 17;

    //Cube
    ans = cubef(num1);
    printf("cubef(num1) = %d\n", ans);
    num1 = 10;
    num2 = 17;

    printf("cube_macro(num1) = %d\n", cube_macro(num1));
    num1 = 10;
    num2 = 17;

    ans = cubef(--num1);
    printf("cubef(--num1) = %d\n", ans);
    num1 = 10;
    num2 = 17;

    printf("cube_macro(--num1) = %d\n", cube_macro(--num1));
    num1 = 10;
    num2 = 17;

    
    //Min
    ans = minf(num1, num2);
    printf("minf(num1, num2) = %d\n", ans);
    num1 = 10;
    num2 = 17;

    printf("min_macro(num1, num2) = %d\n", min_macro(num1, num2));
    num1 = 10;
    num2 = 17;

    ans = minf(--num1, --num2);
    printf("minf(--num1, --num2) = %d\n", ans);
    num1 = 10;
    num2 = 17;

    printf("min_macro(--num1, --num2) = %d\n", min_macro(--num1, --num2));
    num1 = 10;
    num2 = 17;

    //Odd
    ans = oddf(num1);
    printf("oddf(num1) = %d\n", ans);
    num1 = 10;
    num2 = 17;

    printf("odd_macro(num1) = %d\n", odd_macro(num1));
    num1 = 10;
    num2 = 17;

    ans = oddf(num1++);
    printf("oddf(num1++) = %d\n", ans);
    num1 = 10;
    num2 = 17;

    printf("odd_macro(num1++) = %d\n\n" , odd_macro(num1++));
    num1 = 10;
    num2 = 17;

    return;
}


/*
    Macros can produce different and sometimes incorrect output compared to functions because they're not type checked
    They also can show side effects as demonstrated with the cube function, where the results should have been the same
    but since the macro wasnt compiled but preprocessed. Due to them being pre processed they're faster but the speed comes
    at the cost of being less reliable than a traditional function.


*/