/*
    Author: Deven Pile
    Date: 4/8/20
    Description: a Vigenere Cipher that encrypts and decrypts a given .txt file using a key phrase


*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <iostream>



/*
    Name: printTable()
    Description: prints the generated table, Used for debugging
    Parameters: none
    Return: none

*/
void printTable(char** table){
    for(int i = 0; i < 94; i++){
        for(int j = 0; j < 94; j++){
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
}

/*
    Name: generateTable()
    Description: Generates the table used for the cipher
    Parameters: none
    Return: a char** array containing the cipher table

*/
char** generateTable(){
    int startingChar = 33; //was 33
    int arraySize = 94; // was 94
    int charLetter = startingChar;;
    int offset = 0;

    static char** array = new char*[arraySize];
    for(int i = 0; i < arraySize; i++){
        array[i] = new char[arraySize];
    }


    for(int i = 0; i < arraySize; i++){
        for(int j = 0; j < arraySize; j++){
            array[i][j] = (char)charLetter;
            if(charLetter > 126){
                charLetter= startingChar;
            }
            else{
                charLetter++;
            }
            if(offset > arraySize){
                offset = 0;
            }
            
        }
        if(offset > arraySize){
            offset = 0;
        }
        else{
            offset++;
        }
        
        charLetter = startingChar;
        charLetter += offset;
  
    }
    return array;
}

/*
    Name: encrypt
    Description: Encrypts the current buffer
    Parameters: char* plaintext -- the plain text being encrypted
                char* key       -- the key being used to encrypt
                char** table    -- table for encrypting
    return:     char* cipher    -- returns encrypted buffer
*/
char* encrypt(char* plainText, char* key, char** table){
    static char cipher[4096];
    int a;
    int b;
    int len = strlen(key);
    for(int i = 0; i < strlen(plainText); i++){
        if((int)plainText[i]>= 33 && (int)plainText[i] <= 126){
            a = (int)plainText[i]-33; //33
            b = (int)key[i%len]-33; //33
            cipher[i] = table[a][b];
        }
        else{
            cipher[i] = plainText[i];
        }
        
    }


    return cipher;
}
/*
    Name: decrypt
    Description: Decrypts the given buffer
    Parameters: char* cipher    -- then encrypted text being decrypted
                char* key       -- the key that was used to encrypt
                char** table    -- table for encrypting/decrypting
    return:     char* decrypted -- returns decrypted buffer
*/
char* decrypt(char* cipher, char* key, char** table){
    static char decrypted[4096];
    int len = strlen(key);
    for(int i = 0; i < strlen(cipher); i++){
        if((int)cipher[i] >= 33 && (int)cipher[i] <= 126){
            bool flag = true;
            int row = (int)key[i%len]-33;
            int col = 0;
            while(flag){
                if((int)table[row][col] == (int)cipher[i]){
                    decrypted[i] = table[0][col];
                    flag = false;
                }
            col++;
            }
        }
        else{
            decrypted[i] = cipher[i];
        }
    }
    return decrypted;
}


/*
    Name: Main
    Description: Main driving method for the program
    Params: int argc, char* argv[]
    return: int -- 0 for success

*/


int main(int argc, char* argv[]){
    char userIn;
    char* encryptOrDecrypt;
    char* inName[40];
    char* outName[40];
    const int BUFFERSIZE = 4096;
    char* key[128];
    char buffer[BUFFERSIZE];
    char* encryptedText;
    char** table = generateTable();

    FILE* inFile;
    FILE* outFile;

    /*
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Select 1 or 2" << std::endl;
    std::cout << "1. Encrypt" << std::endl;
    std::cout << "2. Decrypt" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    scanf("%d", &userIn);
    */

   if(strcmp(argv[1], "-tdb")==0){
       printTable(table);
   }
   else if(argc != 5){
       std::cout << "Usage is: <exe> <key> -e or -d <input filename> <output filename>" << std::endl;
   }
   else{
        *key = argv[1];
        encryptOrDecrypt = argv[2];
        *inName = argv[3];
        *outName = argv[4];
        inFile = fopen(*inName, "r");
        outFile = fopen(*outName, "w");

        if(strcmp(encryptOrDecrypt, "-e") == 0){
            while(fread(buffer, sizeof(buffer),1,inFile)){
                fwrite(encrypt(buffer, *key, table), sizeof(buffer), 1, outFile);
            }
        }
        else if (strcmp(encryptOrDecrypt, "-d") == 0){
            while(fread(buffer, sizeof(buffer), 1, inFile)){
            fwrite(decrypt(buffer, *key, table), sizeof(buffer), 1, outFile);
            }
        }
        else{
            std::cout << "flag options:" << std::endl;
            std::cout <<"-e -> Encrypt"<< std::endl;
            std::cout <<"-d -> Decrypt" << std::endl;
        }

    fclose(inFile);
    fclose(outFile);
   }
    /*
    inFile = fopen(*inName, "r");
    outFile = fopen(*outName, "w");

    if(strcmp(encryptOrDecrypt, "-e") == 0){
        while(fread(buffer, sizeof(buffer),1,inFile)){
            fwrite(encrypt(buffer, *key, table), sizeof(buffer), 1, outFile);
        }
    }
    else if (strcmp(encryptOrDecrypt, "-d") == 0){
        while(fread(buffer, sizeof(buffer), 1, inFile)){
            fwrite(decrypt(buffer, *key, table), sizeof(buffer), 1, outFile);
        }
    }
    else{
        std::cout << "flag options:" << std::endl;
        std::cout <<"-e -> Encrypt"<< std::endl;
        std::cout <<"-d -> Decrypt" << std::endl;
    }

    fclose(inFile);
    fclose(outFile);
*/


    /*
    switch(userIn){
        case 1:
            printf("Enter a key(REMEMBER THIS FOR DECRYPTION): ");
            std::cin >> key;
            printf("Enter input file name: ");
            std::cin >> inName;
            printf("Enter output file name: ");
            std::cin >> outName; 
            inFile = fopen(inName, "r");
            outFile = fopen(outName, "w");
            while(fread(buffer,sizeof(buffer),1,inFile) > 0){
                fwrite(encrypt(buffer, key, table), sizeof(buffer), 1, outFile);
            }
            fclose(inFile);
            fclose(outFile);
            break;
        case 2:
            printf("Enter your key: ");
            std::cin >> key;
            printf("Enter input file name: ");
            std::cin >> inName;
            printf("Enter output file name: ");
            std::cin >> outName;
            inFile = fopen(inName, "r");
            outFile = fopen(outName, "w");
            while(fread(buffer, sizeof(buffer), 1, inFile) > 0){
                fwrite(decrypt(buffer, key, table), sizeof(buffer), 1, outFile);
            }
            fclose(inFile);
            fclose(outFile);
            break;
        default:
            std::cout << "Default condition met" << std::endl;

    }
    */
    for(int i = 0; i < 94; i++){
        delete[] table[i];
    }
    delete[] table;




    return 0;
}