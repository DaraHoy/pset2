#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Error messege if no command line arguments are given or more than 1 is found
    if (argc != 2)
    {
        printf("Error: Please provide a keyword\n");
        return 1;
    }

    //Sets command line argument to variable keyword
    string keyword = argv[1];

    //reiects keyword if non-alphabetic characters are foun
    for (int i = 0; i < strlen(keyword); i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Error: Keyword must only contain alphabetic characters\n");
            return 1;
        }
    }

    //Prompts user for the string to be enciphered
    string plain = get_string("plaintext: ");

    //Variable j to hold keyword position
    int j = 0;

    //Iterates through the provided string converting only alphabet characters
    for (int i = 0; i < strlen(plain); i++)
    {
        //Encipher only alphabetic characters
        if (isalpha(plain[i]))
        {
            //mod variable for keyword index cycling
            int mod = j % strlen(keyword);

            //Lowercase rotation
            if (islower(plain[i]))
            {
                //Adjust keyword index to match letter casing
                keyword[mod] = tolower(keyword[mod]);

                //Cycles rotation in case of overflow
                if (plain[i] + ((keyword[mod]) - 'a') > 'z')
                {
                    plain[i] = ('a' - 1) + ((plain[i] + (keyword[mod] - 'a')) % 'z');
                }
                //Letter rotation
                else
                {
                    plain[i] += (keyword[mod] - 'a');
                }
            }

            //Uppercase rotation if letter is NOT lowercase
            else
            {
                //Adjust keyword index to match letter casing
                keyword[mod] = toupper(keyword[mod]);

                //Cycles rotation in case of overflow
                if (plain[i] + (keyword[mod] - 'A') > 'Z')
                {
                    plain[i] = ('A' - 1) + ((plain[i] + (keyword[mod] - 'A')) % 'Z');
                }
                //Rotate letter
                else
                {
                    plain[i] += (keyword[mod] - 'A');
                }
            }

            //Increment keyword index only after an alphabetic character is enciphered
            j++;
        }
    }
    printf("ciphertext: %s\n", plain);
}
