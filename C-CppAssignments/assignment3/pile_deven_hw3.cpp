#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

void oneDMath();
void OneDCharPrcss();
void TwoDCharPrcss();

int RandomInRange (int min, int max);
float CalculateAvg(int* numbers, int size);
void PrintIntArray(int* nums, int size);
void ArraySort(int* arry, int size);
void ArraySort(char* arry, int size);
void swap(int *num1, int *num2);
void swap(char *val1, char *val2);
int FindMedian(int* array, int size);
int NonUnique(int* array, int size);
void PrintCharArray(char* chars, int size);
void PrintCharArray(char** chars, int size, int charSize);
int getLetterFreq(char* letters, int size, char val);
void removeCharacter(char* letters, int size, char val);
char GetRandomChar();




int main(){

    int menuNum = 0;
    //int inputVal;
    srand(time(0));

    while(menuNum != 4){
        int inputVal;
        int temp;
        printf("Welcome to assignment 3!\n");
        printf("Menu:\n");
        printf("1 - 1D Math\n");
        printf("2 - Single Dimension Character Processing\n");
        printf("3 - Two-D Character Processing\n");
        printf("4 - Exit\n");
        printf("Choose an option: ");

        inputVal = scanf("%d", &temp);

        if(inputVal != 1){
            printf("Please enter 1, 2, 3, or 4\n\n");
            //fflush(stdin);
            int c;
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
        else{
            menuNum = temp;
            switch(menuNum){
               case 1:
                    std::cout << "1D Math\n" << std::endl;
                    oneDMath();
                    break;
                case 2:
                    std::cout << "Single Dimention Character Processing\n" << std::endl;
                    OneDCharPrcss();
                    break;
                case 3:
                    std::cout << "Two-D Character Processing\n" << std::endl;
                    TwoDCharPrcss();
                    break;
                case 4:
                    std::cout << "Exit\n" << std::endl;
                    break;
                default:
                    std::cout << "Please enter a single digit number\n" << std::endl;
           } 
        }
        

    }




    return 0;
}



void oneDMath(){
    int arrySize = 0;
    int inputVal;
    int min = 0;
    int max = 0;
    bool notValid = true;
    
    printf("Enter array size: ");

    while(notValid){
        inputVal = scanf("%d", &arrySize);
        if(inputVal == 1){
            if(arrySize <= 0){
                printf("Please enter a size greater than 0: ");
                int c;
                while ((c = getchar()) != '\n' && c != EOF){ }
                //fflush(stdin);
            }
            else{
                notValid = false;
            }
        }
        else{
            printf("Please enter an integer value: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF){ }
            //fflush(stdin);
        }
        
    }
    notValid = true;

    printf("Enter min value: ");

    while(notValid){
        inputVal = scanf("%d", &min);
        if(inputVal == 1){
            notValid = false;
        }
        else{
            printf("Please enter an integer for min value: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF){ }
            //fflush(stdin);
        }
    }

    notValid = true;

    printf("Enter max value: ");

    while(notValid){
        inputVal = scanf("%d", &max);
        if(inputVal == 1){
            if(max > min){
                notValid = false;
            }
            else{
                printf("Enter a max value bigger than min val: ");
            }
        }
        else{
            printf("Enter an integer: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF){ }
                
            //fflush(stdin);
        }
    }


    //Create array
    int* intArry = new int[arrySize];

    //Fill Array
    for(int i = 0; i < arrySize; i++){
        intArry[i] = RandomInRange(min, max);
    }
    
    //PrintIntArray(intArry, arrySize);
    ArraySort(intArry, arrySize);
    PrintIntArray(intArry, arrySize);
    printf("Average: %.4f\n", CalculateAvg(intArry, arrySize));
    printf("Median: %d\n", FindMedian(intArry, arrySize));\
    printf("Unique: %d\n", arrySize - NonUnique(intArry, arrySize));
    printf("Non-Unique: %d\n\n", NonUnique(intArry,arrySize));


    return;
}




void OneDCharPrcss(){
    int size;
    int c;
    int menuOpt = 0;
    int scanRtn;
    char letter;
    bool notValid = true;
    printf("How many characters? ");

    while(notValid){
        scanRtn = scanf("%d", &size);
        if(scanRtn != 1){
            printf("Please enter a number:");
            while ((c = getchar()) != '\n' && c != EOF){}
        }
        else{
            notValid = false;
        }

    }

    char* charArry = new char[size];

    printf("\nFilling the array!\n");

    for(int i = 0; i < size; i++){
        charArry[i] = GetRandomChar();
    }
    
    PrintCharArray(charArry, size);

    while(menuOpt != 4){
        printf("\nWhat would you like to do?\n");
        printf("1.  Check frequency of a letter\n");
        printf("2.  Remove a letter\n");
        printf("3.  Sort\n");
        printf("4.  Return to Main Menu\n");
        printf("Choose an Option: ");
        scanRtn = scanf("%d", &menuOpt);
        if(scanRtn != 1){
            printf("Please enter 1, 2, 3, or 4: ");
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
        else if(menuOpt == 1 ||  menuOpt == 2 || menuOpt == 3 || menuOpt == 4){
            switch(menuOpt){
                case 1:
                    printf("What letter? ");
                    while ((c = getchar()) != '\n' && c != EOF){ }
                    scanf("%c", &letter);
                    printf("\n");
                    PrintCharArray(charArry, size);
                    printf("There are %d of the letter %c", getLetterFreq(charArry, size, letter), letter);
                    break;
                case 2:
                    printf("What letter? ");
                    while ((c = getchar()) != '\n' && c != EOF){ }
                    scanf("%c", &letter);
                    printf("\n");
                    //Remove funct goes here
                    removeCharacter(charArry, size, letter);
                    PrintCharArray(charArry, size);
                    printf("%c was removed\n", letter);
                    break;
                case 3:
                    printf("Sorting!\n");
                    ArraySort(charArry, size);
                    PrintCharArray(charArry, size);
                    break;
                case 4:
                    printf("Return to main\n\n");
                    break;



                    
            }
        }
        else{
            printf("Please enter a 1, 2, 3, or 4: ");
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
    }
    return;
}



void TwoDCharPrcss(){
    int numStrings;
    int maxStringSize;
    bool notValid = true;
    int c;
    
    printf("How many strings do want to enter? ");
    while(notValid){
        if(scanf("%d", &numStrings) != 1){
            printf("Please enter an integer: ");
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
        else{
            notValid = false;
        }
    }

    notValid = true;
    printf("What is the max size of the strings? ");
    while(notValid){
        if(scanf("%d", &maxStringSize) != 1){
            printf("Please enter an integer: ");
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
        else{
            notValid = false;
        }
    }
    while ((c = getchar()) != '\n' && c != EOF){ }

    notValid = true;

    char** myStrings;
    myStrings = new char*[numStrings];
    for(int i = 0; i < numStrings; i++){
        myStrings[i] = new char[maxStringSize];
        std::cin >> myStrings[i];
    }
    
    PrintCharArray(myStrings, numStrings, maxStringSize);

    /*for(int i = 0; i < numStrings; i++){
        for(int j = 0; j < maxStringSize; j++){
            if(myStrings[i][j] != '\0' && myStrings[i][j] != 'P'){
                printf("%c", myStrings[i][j]);
                
            }
        }
        printf("\n\n");
    }
    */
    //PrintCharArray(myStrings, numStrings, maxStringSize);
    



    return;
}





//Supporting Functions
float CalculateAvg(int* numbers, int size){
    int total = 0;
    float average = 0;
    for(int i = 0; i < size; i++){
        total += numbers[i];
    }
    average = (float)total/(float)size;
    return average;
}

void PrintIntArray(int* nums, int size){
    for(int i = 0; i < size; i++){
        if(i == 0){
            printf("[%d",nums[i]);
        }
        else if(i == size-1){
            printf(" - %d]", nums[i]);
        }
        else{
            printf(" - %d", nums[i]);
        }
    }
    printf("\n");
    return;
}

void PrintCharArray(char* chars, int size){
    for(int i = 0; i < size; i++){
        printf("%c", chars[i]);
    }
    printf("\n");
    return;
}

void PrintCharArray(char** chars, int size, int charSize){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < charSize; j++){
            if(chars[i][j] != '\0'){ //&& chars[i][j] != 'P'){
                printf("%c", chars[i][j]);
                
            }
        }
        printf("\n\n");
    }
}


void ArraySort(int* arry, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arry[j] < arry[i]){
                swap(&arry[i], &arry[j]);
            }
        }
    }
    return;
}

void ArraySort(char* arry, int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arry[j] < arry[i]){
                swap(&arry[i], &arry[j]);
            }
        }
    }

    return;
}

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    return;
}

void swap(char *val1, char *val2){
    char temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return;
}

int FindMedian(int* array, int size){
    if(size % 2 == 0){
        return (array[(size-1)/2] + array[size/2])/2;
    }
    else{
        return array[size/2];
    }
}

int NonUnique(int* array, int size){
    int nonUnique = 0;
    for(int i = 1; i < size; i++){
        for(int j = 0; j < i; j++){
            if(array[i] == array[j]){
                nonUnique++;
                break;
            }
        }
    }
    return nonUnique;
    
}

char GetRandomChar(){
    return 'a' + rand()%26;
}


int getLetterFreq(char* letters, int size, char val){
    int freq = 0;
    val = (char)tolower(val);

    for(int i = 0; i < size; i++){
        if(letters[i] == val){
            freq++;
        }
    }
    return freq;
}


void removeCharacter(char* letters, int size, char val){
    int i = 0;
    int j = 0;
    for(i = 0; i < size; i++){
        if(letters[i] != val){
            letters[j] = letters[i];
            j++;
        }
    }
    letters[j] = '\0';
}

int RandomInRange (int min, int max){
    //Function Variables
    int randomNum;
    //Generates a random number
    randomNum = (rand() % (max - min + 1) + min );
    return randomNum;
}