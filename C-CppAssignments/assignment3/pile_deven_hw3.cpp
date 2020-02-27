#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

void oneDMath();
int RandomInRange (int min, int max);
float CalculateAvg(int* numbers, int size);
void PrintIntArray(int* nums, int size);
void ArraySort(int* arry, int size);
void swap(int *num1, int *num2);
int FindMedian(int* array, int size);
int NonUnique(int* array, int size);




int main(){

    int menuNum = 0;
    srand(time(0));

    while(menuNum != 4){
        printf("Welcome to assignment 3!\n");
        printf("Menu:\n");
        printf("1 - 1D Math\n");
        printf("2 - Single Dimension Character Processing\n");
        printf("3 - Two-D Character Processing\n");
        printf("4 - Exit\n");
        printf("Choose an option: ");

        int inputVal = scanf("%d", &menuNum);
        if(inputVal == 1){
           switch(menuNum){
               case 1:
                    std::cout << "1D Math\n" << std::endl;
                    oneDMath();
                    break;
                case 2:
                    std::cout << "Single Dimention Character Processing\n" << std::endl;
                    break;
                case 3:
                    std::cout << "Two-D Character Processing\n" << std::endl;
                    break;
                case 4:
                    std::cout << "Exit\n" << std::endl;
                    break;
                default:
                    std::cout << "Please enter a single digit number\n" << std::endl;
           } 
        }
        else{
            printf("Please enter 1, 2, 3, or 4\n\n");
            fflush(stdin);
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
                fflush(stdin);
            }
            else{
                notValid = false;
            }
        }
        else{
            printf("Please enter an integer value: ");
            fflush(stdin);
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
            fflush(stdin);
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
            fflush(stdin);
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

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;

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



int RandomInRange (int min, int max){
    //Function Variables
    int randomNum;
    //Generates a random number
    randomNum = (rand() % (max - min + 1) + min );
    return randomNum;
}