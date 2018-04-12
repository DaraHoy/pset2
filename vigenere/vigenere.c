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

    //rejects keyword if non-alphabetic characters are foun
    for (int i = 0; i < strlen(keyword); i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Error: Keyword must only contain alphabetic characters\n");
            return 1;
        }
    }

    int j = 0;

    //Prompts user for the string to be enciphered
    string plain = get_string("plaintext: ");

    //Iterates through the provided string converting only alphabet characters
    for (int i = 0; i < strlen(plain); i++)
    {
        if (isalpha(plain[i]))
        {
            int mod = j % strlen(keyword);

            if (islower(plain[i]))
            {
                tolower(keyword[mod]);

                if(plain[i] + ((keyword[mod]) - 97) > 122)
                {
                    plain[i] = 96 + ((plain[i] + (keyword[mod] - 97)) % 122);
                    j++;
                }
                else
                {
                    plain[i] += (keyword[mod] - 97);
                    j++;
                }
            }
            else
            {
                toupper(keyword[mod]);

                if(plain[i] + (keyword[mod] - 65) > 90)
                {
                    plain[i] = 64 + ((plain[i] + (keyword[mod] - 65)) % 90);
                    j++;
                }
                else
                {
                    plain[i] += (keyword[mod] - 65);
                    j++;
                }
            }
        }
    }
    printf("ciphertext: %s\n", plain);
}
