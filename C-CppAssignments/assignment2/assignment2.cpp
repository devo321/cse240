#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;

int EvensOrOdds(char *name); //forward declaration
int RockPaperScissors(char *name);
int ThinkingOfANumber(char *aName);
int DiceRollShowdown(char *name);
void MiniGameController();
char* GenRandomName();
int RandomInRange(int min, int max);
bool IsEven(int num);
int RollDie(int sides);



int main(){
    int menuNum = -1;
    char term;
    srand(time(0));

    while(menuNum != 0){
        printf("Welcome to the CSE240 Assignment 2!\n");
        printf("Menu:\n");
        printf("1 - CSE240 Mini-Game Collection\n");
        printf("2 - Macros vs Functions Throw-down\n");
        printf("0 - Exit\n");
        printf("Choose an option: ");

        scanf("%d", &menuNum);
        
         if(menuNum == 0 || menuNum == 1 || menuNum == 2){ 
            switch(menuNum){
                case 1:
                    MiniGameController();
                    break;
                case 2:
                    std::cout << "\n" << "Macros vs Functions selected" << "\n" << endl;
                    break;
                case 0:
                    std::cout << "Exit:" << endl;
                    break;
                default:
                    std::cout << "Default Condition met" << endl;
            }
        }
        else{
            printf("------------------------------------\n");
            printf("Please enter 0, 1, or 2\n");
            printf("------------------------------------\n");
            fflush(stdin);
            //menuNum = -1; 
        }
    }
    return 0;
}


int EvensOrOdds(char *name) {
    int nameNum = RandomInRange(0,100);
    int cpuNum = RandomInRange(0,100);
    int gameNum;
    int evenOrOdd;
    int usrNum;
    bool numLoop = true;
    bool boolEvenOrOrdd = true;
    int win = 0;
    /*FILE * inFile;
    char buffer[30];
    inFile = fopen("random_names.txt", "r");

    int i;
    for(i = 0; i < nameNum; i++){
        fscanf(inFile, "%s", buffer);
    }
    fclose(inFile);
    */
    char* buffer = name;
    printf("Even/Odd game!\n");
    printf("Guess even or odd! (0 for even, 1 for odd): ");

    while(boolEvenOrOrdd){
        scanf("%d", &evenOrOdd);
        if(evenOrOdd == 1 || evenOrOdd == 0){
            boolEvenOrOrdd = false;
        }
        else{
            printf("Enter 0 for even, 1 for odd: ");
            fflush(stdin);
        }
    }
    
    printf("Enter a number (between 0 and 100): ");
    while(numLoop){
        
        scanf("%d", &usrNum);
        if(usrNum < 0 || usrNum > 100){
            printf("Enter a number between 0 and 100: ");
            fflush(stdin);
        }
        else{
            numLoop = false;
        }
    }
    gameNum = usrNum + cpuNum;

    printf("%s picked %d\n", buffer, cpuNum);
    printf("%d + %d = %d - ", usrNum, cpuNum, gameNum);

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


int RockPaperScissors(char *name){
    int usrNum;
    bool loopBool = true;
    int nameNum = RandomInRange(0,100);
    int cpuNum = RandomInRange(1, 3);
    int win = 0;
    /*
    FILE * inFile;
    char buffer[30];
    inFile = fopen("random_names.txt", "r");

    int i;
    for(i = 0; i < nameNum; i++){
        fscanf(inFile, "%s", buffer);
    }
    fclose(inFile);
    */
    char* buffer = name;
    printf("Rock, Paper, Scissors game!\n");
    printf("Choose a throw!\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    
    printf("Enter a number (1, 2, or 3): ");
    std::cout<<"Cpu num: " << cpuNum<<endl;
    while(loopBool){
        scanf("%d", &usrNum);
        if(usrNum == 1 || usrNum == 2 || usrNum == 3){
            loopBool = false;
        }
        else{
            printf("Please enter 1, 2, or 3: ");
            fflush(stdin);
        }
    }
    
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





int ThinkingOfANumber(char *aName){
    int usrNum;
    int guesses = 0;
    bool notValid;
    int lower = RandomInRange(0, 1000);
    int upper = RandomInRange(lower + 30, lower + 100);
    int cpuNum = RandomInRange(lower, upper);
    char* name = aName;
    int win = 0;

    printf("Player, Im thinking of a number between %d and %d!\n", lower, upper);
    printf("You have 5 guesses!\n");

    printf("CPU Num = %d\n", cpuNum);

    while(guesses < 5 && guesses != -1){
        printf("What's guess #%d? ", guesses + 1);
        notValid = true;

        while(notValid){
            scanf("%d", &usrNum);
            if(usrNum >= lower && usrNum <= upper){
                notValid = false;
                guesses++;
            }
            else{
                printf("Please enter a number between %d and %d: ", lower, upper);
                fflush(stdin);
            }
        }
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
    if(guesses >= 5){
        printf("You ran out of guesses! Better luck next time!\n\n");
    }

    return win;
}



int DiceRollShowdown(char *name){
    char* cpuName = name;
    int diceSides = 0;
    int diceToRoll =0;
    int playerTotal = 0;
    int cpuTotal = 0;
    bool win = false;
    int i;

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

    int playerRoll[diceToRoll];
    int cpuRoll[diceToRoll];

    
    for(i = 0; i < diceToRoll; i++){
        playerRoll[i] = RollDie(diceSides);
        cpuRoll[i] = RollDie(diceSides);
    }

    printf("Player Rolled:\n");
    for(i = 0; i < diceToRoll; i++){
        printf("%d\n", playerRoll[i]);
        playerTotal += playerRoll[i];
    }
    printf("Total: %d\n\n", playerTotal);

    printf("%s Rolled: \n", cpuName);
    for(i = 0; i < diceToRoll; i++){
        printf("%d\n", cpuRoll[i]);
        cpuTotal += cpuRoll[i];
    }
    printf("Total: %d\n", cpuTotal);

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





int RandomInRange (int min, int max){
    int randomNum;
    randomNum = (rand() % (max - min + 1) + min );
    return randomNum;
}


bool IsEven(int num){
    bool even;
    if(num % 2 == 0){
        even = true;
    }
    else{
        even = false;
    }

    return even;
}

char* GenRandomName(){
    int nameNum = RandomInRange(0, 100);
    FILE * inFile;
    static char name[30];
    inFile = fopen("random_names.txt", "r");

    int i;
    for(i = 0; i < nameNum; i++){
        fscanf(inFile, "%s", name);
    }
    fclose(inFile);

    return name;
}



int RollDie(int sides){
    int result = RandomInRange(1, sides);
    return result;
}




void MiniGameController(){
    int numRounds = 0;
    int randomNum;
    int count = 0;
    int playerScore = 0;
    int cpuScore = 0;
    char *opponent = GenRandomName();
    int win = 0;
    printf("\n\nWelcome to CSE240 Mini-Game Collection!\n");
    printf("I am your opponent %s\n", opponent);
    do{
        printf("How many rounds should we play? (choose an odd number): ");
        scanf("%d", &numRounds);
        fflush(stdin);
    }while(numRounds <= 0 && numRounds % 2 == 0);
    
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

        printf("\nThe score is:\n");
        printf("Player - %d\n", playerScore);
        printf("%s - %d\n\n", opponent, cpuScore);



    }

    if(playerScore > cpuScore){
        printf("You won the Minigames!\n\n");
    }
    else{
        printf("%s won the Minigames! Better luck next time!\n\n",opponent);
    }




    return;
}