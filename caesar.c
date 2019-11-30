#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(int Key, string text);

int main(int argc, string argv[])
{
    string userInput = argv[1];
    if (argc == 2) //check if there is exactly 2 inputs of strings
    {
        bool check;
        for (int i = 0; i < strlen(userInput); i++) //check if all characters in the second string input are all numbers
        {
            check = isdigit(userInput[i]);
        }
        if (check == true) //if passed the check
        {
            int key = atoi(argv[1]); //assign key as an integer value converted from user's string input
            string plaintext = get_string("plaintext:  "); //prompt for the user's input of text that needs to be ciphered
            caesarCipher(key, plaintext); //execute cipher function
        }
        else
        {
            printf("Usage: ./caesar key\n"); //gives user correct instruction for the input
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n"); //gives user correct instruction for the input
        return 1;
    }
}

void caesarCipher(int Key, string text) //prints the ciphered text based on the rotation of the characters in user's text input alphabetically according to user's input of a key that marks the number of rotation
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z') //check if the single character in the loop belongs to the cap'd group
        {
            printf("%c", (65 + ((text[i] - 65 + Key) % 26))); //calculate and print the new character
        }
        else if (text[i] >= 'a' && text[i] <= 'z') //check if the single character in the loop belongs to the lowercased group
        {
            printf("%c", (97 + ((text[i] - 97 + Key) % 26)));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
