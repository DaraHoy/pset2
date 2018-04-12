#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Error messege if no command line arguments are given or more than 1 is found
    if (argc != 2)
    {
        printf("Error: ./caesar requires 1 positive integer as a command line argument\n");
        return 1;
    }

    //Converts command line argument to int, key represents the number of character shifts
    int key = atoi(argv[1]) % 26;

    //Prompts user for the string to be encrypted
    string plain = get_string("plaintext: ");

    //Iterates through the provided string converting only alphabet characters
    for (int index = 0; index < strlen(plain); index++)
    {
        //Lowercase rotation
        if (plain[index] >= 'a' && plain[index] <= 'z')
        {
            //Catches overflow
            if (plain[index] + key > 'z')
            {
                plain[index] = 96 + ((plain[index] + key) % 'z');
            }
            else
            {
                plain[index] += key;
            }
        }
        //Uppercase rotation
        if (plain[index] >= 'A' && plain[index] <= 'Z')
        {
            //Catches overflow
            if (plain[index] + key > 'Z')
            {
                plain[index] = 64 + ((plain[index] + key) % 'Z');
            }
            else
            {
                plain[index] += key;
            }
        }
    }
    printf("ciphertext: %s\n", plain);
}
