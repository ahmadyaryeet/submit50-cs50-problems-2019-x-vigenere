#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    string k = argv[1];
    int lenk = strlen(k);
    for (int i = 0; i < lenk; i++)
    {
        if(!isalpha(k[i]))
        {
            printf("Invalid key\n");
            return 1;
        }
    }
    
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: ");
    for (int i =0, index = 0, len = strlen(plaintext); i <len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower (plaintext[i]))
            {
                printf("%c", (plaintext[i] - 'a' + toupper(k[index]) - 'A') % 26 + 'a' );
            }
            else if (isupper(plaintext[i]))
            { 
                printf("%c", (plaintext[i] - 'A' + toupper(k[index]) - 'A') % 26 + 'A' );
            }
            index = (index + 1) % lenk;
        }    
        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
}
