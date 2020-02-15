#include<stdio.h>
#include<iostream>
#include<ctime>
using namespace std;

void EvensOrOdds(); //forward declaration
void RockPaperScissors();
void ThinkingOfANumber();
int RandomInRange(int min, int max);
bool IsEven(int num);



int main(){
    int menuNum = -1;
    char term;

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
                    std::cout << "\n" << "CSE240 Minigame selected" << "\n" << endl;
                    //EvensOrOdds();
                    //RockPaperScissors();
                    ThinkingOfANumber();
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


void EvensOrOdds() {
    int nameNum = RandomInRange(0,100);
    int cpuNum = RandomInRange(0,100);
    int gameNum;
    int evenOrOdd;
    int usrNum;
    bool numLoop = true;
    bool boolEvenOrOrdd = true;
    FILE * inFile;
    char buffer[30];
    inFile = fopen("random_names.txt", "r");

    int i;
    for(i = 0; i < nameNum; i++){
        fscanf(inFile, "%s", buffer);
    }
    fclose(inFile);
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
        }
        else{
            printf("%s wins this round!\n", buffer);
        }
    }
    else{
        printf("ODD!\n");
        if(evenOrOdd == 1){
            printf("You win this round!\n");
        }
        else{
            printf("%s wins this round!\n", buffer);
        }
    }
    printf("\n");
    printf("\n");



    return;
}


void RockPaperScissors(){
    int usrNum;
    bool loopBool = true;
    int nameNum = RandomInRange(0,100);
    int cpuNum = RandomInRange(1, 3);

    FILE * inFile;
    char buffer[30];
    inFile = fopen("random_names.txt", "r");

    int i;
    for(i = 0; i < nameNum; i++){
        fscanf(inFile, "%s", buffer);
    }
    fclose(inFile);

    printf("Rock, Paper, Scissors game!\n");
    printf("Choose a throw!\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    
    printf("Enter a number (1, 2, or 3): ");
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
                break;
            case 2:         //Paper
                printf("%s picked Paper! %s wins!\n", buffer, buffer);
                break;
            case 3:         //Scissors
                printf("%s picked Scissors! You win!\n", buffer);
                break;
            default:
                printf("Default Condition Reached\n");        
        }
    }
    else if(usrNum == 2){   //Paper
        switch(cpuNum){
            case 1:         //Rock
                printf("%s picked Rock! You win!\n", buffer);
                break;
            case 2:         //Paper
                printf("%s picked Paper! It's a tie!\n", buffer);
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
                break;
            case 3:         //Scissors
                printf("%s picked Scissors! It's a tie!", buffer);
                break;
        }
    }
    



    printf("\n");
    return;
}





void ThinkingOfANumber(){
    int userNum;
    int lower = RandomInRange(0, 1000);
    int upper = RandomInRange(lower + 30, lower + 100);
    return;
}






int RandomInRange (int min, int max){
    int randomNum;
    srand(time(0));
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


