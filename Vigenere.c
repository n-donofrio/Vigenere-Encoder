/*
| Encrypting a plaintext file using the Vigenere cipher
|
| Author: Nicholas Donofrio
| Language: C
|
| To Compile: gcc -o Vigenere Vigenere.c
|
| To Execute: c -> ./Vigenere kX.txt pX.txt
| where kX.txt is the keytext file
| and pX.txt is plaintext file
|
| Note: All input files are simple 8 bit ASCII input
*/

  
// Libraries 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants
const int CHAR = 3000; // Max size of char
const int pLENGTH = 512; // Length of the array
  

int main(int argc, char *argv[]) 
{
    // Variables
    char Key[CHAR]; // Characters for key text
    char Plain[CHAR]; // characters for plain text
    int i = 0;      // for loop counter
    int j;         // for loop counter
    int counter = 0; // while loop counter

    // Check if user has entered the correct number of arguments
    if(argc < 3)
    {
      fprintf(stderr, "Usage: %s <KeyFile> <PlaintextFile>\n", argv[0]);
      exit(0);
    }

    // Opens files
    FILE * keyFile = fopen(argv[1], "r");
    FILE * plainFile = fopen(argv[2], "r");

    // Store characters
    int kFile = getc(keyFile);
    int pFile = getc(plainFile);

    // Store valid characters to file
    while (kFile != EOF) 
    {
      if (isalpha(kFile)) 
      {
        Key[i] = tolower(kFile);
        i++;
      }
      
      kFile = getc(keyFile);
    }
  
    Key[i] = '\0';

    i = 0;
  
    // Store valid characters to plain
    while (pFile != EOF) 
    {
      if (isalpha(pFile))
      {
        Plain[i] = tolower(pFile);
        i++;
      }
      
      pFile = getc(plainFile);
    }
  
    Plain[i] = '\0';

    // Get length
    int plainLength = strlen(Plain);
    int keyLength = strlen(Key);

    // loop thru each array of 512
    if (plainLength < pLENGTH) 
    {
      for (i = plainLength; i < pLENGTH; i++) 
      {
        Plain[i] = 'x';
      }
      
      Plain[i] = '\0';
    }
  
    Plain[pLENGTH] = '\0';

    plainLength = strlen(Plain);

    char newKey[plainLength], cipherText[plainLength];

    // Generate new key
    for (i = 0, j = 0; i < plainLength; i++) 
    {
      if (j == keyLength)
      {
        j = 0;
      }
      
      newKey[i] = Key[j];
      j++;
    }
  
    newKey[i] = '\0';

    // Encryption
    for (i = 0; i < plainLength; i++) 
    {
      // Formula
      cipherText[i] = (((Plain[i] - 'a') + (newKey[i] - 'a')) % 26 + 'a');
    }
  
    cipherText[i] = '\0';

    // Vignere
    printf("\n\nVigenere Key:\n");
    while (counter < keyLength) 
    {
      if (counter % 80 == 0) 
      {
        printf("\n");
      }
      
      printf("%c", Key[counter]);
      counter++;
    }

    counter = 0;
  
    // Plaintext
    printf("\n\n\nPlaintext:\n");
  
    while (counter < plainLength)
      {
        if (counter % 80 == 0) 
        {
          printf("\n");
        }
        
        printf("%c", Plain[counter]);
        counter++;

    }
  
    counter = 0;

    // Cipher
    printf("\n\n\nCiphertext:\n\n");
  
    while (counter < plainLength)
      {
        
        printf("%c", cipherText[counter]);
        counter++;
        
        if (counter % 80 == 0) 
        {
          printf("\n");
        }
    }
  
    printf("\n");
  
    return 0;
}
