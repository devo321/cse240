#include<iostream>

using namespace std;


int main(){
    bool exit = false;
    int menuNum;

    while(menuNum != 0){
        printf("Welcome to the CSE240 Assignment 2!\n");
        printf("Menu:\n");
        printf("1 - CSE240 Mini-Game Collection\n");
        printf("2 - Macros vs Functions Throw-down\n");
        printf("0 - Exit\n");
        printf("Choose an option: ");
        scanf("%d", &menuNum);

        switch(menuNum){
            case 1:
                std::cout << "CSE240 Minigame selected" << endl;
                break;
            case 2:
                std::cout << "Macros vs Functions" << endl;
                break;
            case 0:
                std::cout << "Exit:" << endl;
                break;
            default:
                std::cout << "Default Condition met" << endl;
        }
        


    }
    

    return 0;
}