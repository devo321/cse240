/*
    Name: Deven Pile
    Class: CSE240
    Time: 2:00 - 2:50
    Asssignment: Assignment 3
    Description:
        Dynamically allocate arrays
        and modify the contents of that array
*/



#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

void OneDMath();
void OneDCharPrcss();
void TwoDCharPrcss();

int RandomInRange (int min, int max);
float CalculateAvg(int* numbers, int size);
void PrintIntArray(int* nums, int size);
void ArraySort(int* arry, int size);
void ArraySort(char* arry, int size);
void Swap(int *num1, int *num2);
void Swap(char *val1, char *val2);
int FindMedian(int* array, int size);
int NonUnique(int* array, int size);
void PrintCharArray(char* chars, int size);
void PrintCharArray(char** chars, int size, int charSize);
int GetLetterFreq(char* letters, int size, char val);
void RemoveCharacter(char* letters, int size, char val);
char GetRandomChar();


/*
    @name   main
    @desc   main method of program
    @param  none
    @return none
*/
int main(){

    int menuNum = 0;          
    //Seed time                                      
    srand(time(0));

    //Main program menu
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

        //Validate User input
        if(inputVal != 1){                                              
            printf("Please enter 1, 2, 3, or 4\n\n");
            //fflush(stdin);
            int c;
            //Clears the standard in buffer
            while ((c = getchar()) != '\n' && c != EOF){ }              
        }
        else{
            menuNum = temp;
            //If Input is vaid, determine case and and call appropriate function
            switch(menuNum){                                            
               case 1:
                    std::cout << "1D Math\n" << std::endl;
                    OneDMath();
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
                    std::cout << "Please enter a valid number\n" << std::endl;
           } 
        }
        

    }
    return 0;
}


/*
    @name   OneDMath
    @desc   Generates an integer array of user defined size, Sorts array,
            Calculates average, Finds median, finds number of unique elements,
            and number of duplicated elements
    @param  none
    @return none
*/
void OneDMath(){
    int arrySize = 0;
    int inputVal;
    int min = 0;
    int max = 0;
    //notValid boolean used in validating input from the user
    bool notValid = true;                                               
    
    printf("Enter array size: ");

    //Validate User input
    while(notValid){                                                    
        inputVal = scanf("%d", &arrySize);
        if(inputVal == 1){
            if(arrySize <= 0){
                printf("Please enter a size greater than 0: ");
                int c;
                //Clear Stdin
                while ((c = getchar()) != '\n' && c != EOF){ }          
                //fflush(stdin);
            }
            else{
                notValid = false;
            }
        }
        else{
            printf("Invalid input\n");
            printf("Enter array size: ");
            int c;
            //Clear standard in for scanf
            while ((c = getchar()) != '\n' && c != EOF){ }              
            //fflush(stdin);
        }
        
    }
    notValid = true;

    printf("Enter min value: ");

    //Validate user input
    while(notValid){                                                    
        inputVal = scanf("%d", &min);
        if(inputVal == 1){
            notValid = false;
        }
        else{
            printf("Invalid input\n");
            printf("Enter min value: ");
            int c;
             //Clear standard in
            while ((c = getchar()) != '\n' && c != EOF){ }             
            //fflush(stdin);
        }
    }

    //Reset notValid
    notValid = true;

    //Get max value for random integers
    printf("Enter max value: ");                                        


    //Validate user input
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
            printf("Invalid Input\n");
            printf("Enter max value: ");
            int c;
            //Clear stdin
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
    //Sort Array
    ArraySort(intArry, arrySize);
    //Print array
    printf("\n");
    PrintIntArray(intArry, arrySize);
    //Print Results
    printf("Average: %.4f\n", CalculateAvg(intArry, arrySize));
    printf("Median: %d\n", FindMedian(intArry, arrySize));
    printf("Unique: %d\n", arrySize - NonUnique(intArry, arrySize));
    printf("Non-Unique: %d\n\n", NonUnique(intArry,arrySize));


    delete[] intArry;
    return;
}



/*
    @name   OneDCharPrcss
    @desc   Generates a string of user defined size, contains options to find freqency of a value, remove a value, and sort the array
    @param  none
    @return none
*/
void OneDCharPrcss(){
    int size;
    int c;
    int menuOpt = 0;
    int scanRtn;
    char letter;
    bool notValid = true;

    printf("How many characters? ");

    //Validate user input
    while(notValid){                                                       
        scanRtn = scanf("%d", &size);
        if(scanRtn != 1){
            printf("Please enter a number:");
            //Clear stdin
            while ((c = getchar()) != '\n' && c != EOF){}
        }
        else{
            notValid = false;
        }

    }
    //Create char array
    char* charArry = new char[size];

    printf("\nFilling the array!\n");

    //Fill array 
    for(int i = 0; i < size; i++){
        charArry[i] = GetRandomChar();
    }
    
    //Print Array
    PrintCharArray(charArry, size);

    //Menu for 1D array processing
    while(menuOpt != 4){
        printf("\n\nWhat would you like to do?\n");
        printf("1.  Check frequency of a letter\n");
        printf("2.  Remove a letter\n");
        printf("3.  Sort\n");
        printf("4.  Return to Main Menu\n");
        printf("Choose an Option: ");

        //Validate user input
        scanRtn = scanf("%d", &menuOpt);
        if(scanRtn != 1){
            printf("Invalid Input\n");
            printf("Please enter 1, 2, 3, or 4: ");
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
        //If user input is valid and within range, Call and do appropriate functions
        else if(menuOpt == 1 ||  menuOpt == 2 || menuOpt == 3 || menuOpt == 4){
            switch(menuOpt){
                case 1:
                    //Check Frequency of a letter
                    printf("What letter? ");
                    while ((c = getchar()) != '\n' && c != EOF){ }
                    scanf("%c", &letter);
                    printf("\n");
                    PrintCharArray(charArry, size);
                    printf("\nThere are %d of the letter %c", GetLetterFreq(charArry, size, letter), letter);
                    break;
                case 2:
                    //Remove a letter
                    printf("What letter? ");
                    while ((c = getchar()) != '\n' && c != EOF){ }
                    scanf("%c", &letter);
                    printf("\n");
                    RemoveCharacter(charArry, size, letter);
                    PrintCharArray(charArry, size);
                    printf("\n%c was removed\n", letter);
                    break;
                case 3:
                    //Sort Array
                    printf("\nSorting!\n");
                    ArraySort(charArry, size);
                    PrintCharArray(charArry, size);
                    break;
                case 4:
                    //Exit 
                    printf("Return to main\n\n");
                    break;



                    
            }
        }
        //If user input is not within range
        else{
            printf("\nPlease enter a 1, 2, 3, or 4: ");
            //Clear Stdin
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
    }


    delete[] charArry;
    return;
}


/*
    @name   TwoDCharPrcss
    @desc   Take Strings from user input, find freq of letters and remove letters
    @param  none
    @return none
*/
void TwoDCharPrcss(){
    int numStrings;
    int maxStringSize;
    int menuOpt = 0;
    char letter;
    bool notValid = true;
    int c;
    
    printf("How many strings do want to enter? ");
    //Validate input
    while(notValid){
        if(scanf("%d", &numStrings) != 1){
            printf("Invaid Input\n");
            printf("How many strings do want to enter?  ");
            //Clear stdin
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
        else{
            notValid = false;
        }
    }

    //Reset notValid
    notValid = true;
    printf("What is the max size of the strings? ");
    //Validate user input
    while(notValid){
        if(scanf("%d", &maxStringSize) != 1){
            printf("Invalid input\n");
            printf("What is the max size of the strings? ");
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
        else{
            //Valid input
            notValid = false;
        }
    }
    //Clear stdin
    while ((c = getchar()) != '\n' && c != EOF){ }

    //reset notValid
    notValid = true;

    //Create 2d Array
    char** myStrings;
    myStrings = new char*[numStrings]();
    for(int i = 0; i < numStrings; i++){
        myStrings[i] = new char[maxStringSize]();
    }

    //Fill array with user defined strings
    for(int i = 0; i < numStrings; i++){
        printf("Enter string    %d: ", i+1);
        std::cin >> myStrings[i];
    }

    
    
    //Menu for this function
    while(menuOpt != 3){
        printf("\nWhat would you like to do?\n");
        printf("1.  Check Frequency of a letter\n");
        printf("2.  Remove a Letter\n");
        printf("3.  Return to main menu\n");
        printf("\nChoose an option: ");
        //Validate input
        if(scanf("%d", &menuOpt) != 1){
            printf("Please enter an integer:");
            //Clear Stdin
            while ((c = getchar()) != '\n' && c != EOF){ }
        }
        else if(menuOpt == 1 || menuOpt == 2 || menuOpt == 3){
            //If Valid and in range, determine user choice and call function 
            switch(menuOpt){
                case 1:
                    //Check Frequency of a Letter
                    printf("Check frequency of a letter\n");
                    printf("What letter? ");
                    //Clear Stdin
                    while ((c = getchar()) != '\n' && c != EOF){ }
                    //Read letter
                    //Note: No validation here, anything the user enters here will be treated as a string
                    scanf("%c", &letter);
                    printf("\n");
                    //Loop through 2d array, calculate and print the frequency of the given letter
                    for(int i = 0; i < numStrings; i++){
                        PrintCharArray(myStrings[i], maxStringSize);
                        printf(" - %d\n", GetLetterFreq(myStrings[i], maxStringSize, letter));
                    }
                    break;
                case 2:
                    //Remove a letter
                    printf("Remove a letter\n");
                    printf("What letter? ");
                    //Clear stdin
                    while ((c = getchar()) != '\n' && c != EOF){ }
                    scanf("%c", &letter);
                    printf("\n");
                    //Loop through array, remove given letter and print the new array values
                    for(int i = 0; i < numStrings; i++){
                        RemoveCharacter(myStrings[i], maxStringSize, letter);
                        PrintCharArray(myStrings[i], maxStringSize);
                        printf("\n");
                    }
                    break;
                case 3:
                    //Exit
                    printf("Exit:\n\n");
                    break;

            }
        }
    }
    for(int i = 0; i < numStrings; i++){
        delete[] myStrings[i];
    }
    delete[] myStrings;

    return;
}




//--------------------
//Supporting Functions
//--------------------


/*
    @name   Calculate Average
    @desc   Calculate the average of an integer array
    @param  int* numbers, int size - integer array, size of array
    @return int average - average of the array values
*/
float CalculateAvg(int* numbers, int size){
    int total = 0;
    float average = 0;
    for(int i = 0; i < size; i++){
        total += numbers[i];
    }
    average = (float)total/(float)size;
    return average;
}


/*
    @name   PrintIntArray
    @desc   Prints the values in an integer array 
    @param  int* nums, int size - int array, array size
    @return none
*/
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

/*
    @name   PrintCharArray   
    @desc   Prints out the values in a character array   
    @param  char* chars, int size - character array, array size
    @return none
*/
void PrintCharArray(char* chars, int size){
    for(int i = 0; i < size; i++){
        printf("%c", chars[i]);
    }
    //printf("\n");
    return;
}

/*
    @name   PrintCharArray
    @desc   Overloaded PrintCharArray, Prints a 2D char array
    @param  char** chars, int size, int charSize - character array, array size, max character length
    @return none
*/
void PrintCharArray(char** chars, int size, int charSize){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < charSize; j++){
            printf("%c", chars[i][j]);     
        }
        //printf(" ");
    }
    //printf("\n");
}


/*
    @name   ArraySort
    @desc   Sorts an array of Integers
    @param  int* arry, int size - integer array, array size
    @return none
*/
void ArraySort(int* arry, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(arry[j] < arry[i]){
                Swap(&arry[i], &arry[j]);
            }
        }
    }
    return;
}

/*
    @name   ArraySort
    @desc   Overloaded Array sort, Sorts an array of characters
    @param  char* arry, int size - character array, array size
    @return none
*/
void ArraySort(char* arry, int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arry[j] < arry[i]){
                Swap(&arry[i], &arry[j]);
            }
        }
    }

    return;
}

/*
    @name   Swap
    @desc   Swaps two integer values
    @param  int* num1, int* num2 - integers to be swapped
    @return none
*/
void Swap(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    return;
}

/*
    @name   Swap
    @desc   Overloaded Swap, swaps to Character values
    @param  char* val1, char* val2 - characters to be swapped
    @return none
*/
void Swap(char* val1, char* val2){
    char temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return;
}

/*
    @name   FindMedian
    @desc   Finds the median of an array of integers
    @param  int* array, int size - int array, array size
    @return int value of the median 
*/
int FindMedian(int* array, int size){
    if(size % 2 == 0){
        return (array[(size-1)/2] + array[size/2])/2;
    }
    else{
        return array[size/2];
    }
}

/*
    @name   NonUnique
    @desc   Counts the number of non unique integers in an array 
    @param  int* array, int size - int array, size of array
    @return nonUnique  - number of non unique elements in the array
*/
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

/*
    @name   GetRandomChar
    @desc   Returns a random character value using their ASCII values
    @param  none 
    @return random character
*/
char GetRandomChar(){
    return 'a' + rand()%26;
}

/*
    @name   GetLetterFreq
    @desc   Counts the number of a certain letter in a character array
    @param  char* letters, int size, char val - character array, array size, character searched for
    @return int freq - Number of letters found
*/
int GetLetterFreq(char* letters, int size, char val){
    int freq = 0;
    val = (char)tolower(val);

    for(int i = 0; i < size; i++){
        if(tolower(letters[i]) == val){
            freq++;
        }
    }
    return freq;
}


/*
    @name   RemoveCharacter
    @desc   Overloaded Array sort, Sorts an array of characters
    @param  char* arry, int size - Character Array, size of array
    @return none
*/
void RemoveCharacter(char* letters, int size, char val){
    int i = 0;
    int j = 0;
    for(i = 0; i < size; i++){
        if(tolower(letters[i]) != val){
            letters[j] = letters[i];
            j++;
        }
    }
    letters[j] = '\0';
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