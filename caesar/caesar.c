#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    //Converts command line arguments to int key, number of rotations
    int key = atoi(argv[1]) % 26;

    //Error messege if no command line arguments are given or more than 1 is found
    if(argc < 2 || argc > 2 || key < 0)
    {
        printf("Error: caesar requires one positive integer as a command line argument\n");
        return 1;
    }
    //Prompts user for a string to be encrypted
    string plain = get_string("plaintext: ");
    //Iterates through string and converts valid characters
    for(int index = 0; index < strlen(plain); index++)
    {
        //lowercase rotation
        if(plain[index] >= 'a' && plain[index] <= 'z')
        {
            //catches overflow
            if(plain[index] + key > 'z')
            {
                plain[index] = 96 + ((plain[index] + key) % 'z');
            }
            else
            {
                plain[index] += key;
            }
        }
        //lowercase rotation
        if(plain[index] >= 'A' && plain[index] <= 'Z')
        {
            //catches overflow
            if(plain[index] + key > 'Z')
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

// $ ./caesar 13
// plainindex:  hello, world
// cipherindex: uryyb, jbeyq