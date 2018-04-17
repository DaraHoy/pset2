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
    /* PR COMMENT 1
     *  minor thing - take the strlen calc out of the loop in larger cases,
     * but it's fine here as strings here probably won't be that large. However, you
     * could easily adapt this function to read in, for example, the text of a book, and then
     * that optimisation might actually make a difference.
     */
    for (int index = 0; index < strlen(plain); index++)
    {
        //Lowercase rotation
        if (plain[index] >= 'a' && plain[index] <= 'z')
        {
            //Catches overflow
            /* PR COMMENT #2
             *  Running a modulo 26  on "plain[index] + key" would avoid this if/else
             * Something like
                ( ( (plain[index] - 'a') + key) % 26) +'a'
             */
            if (plain[index] + key > 'z')
            {
            /* PR COMMENT 3
             * '96' seems like a magic number here. I get that it's "the value before 'a'",
             * but it's a bit obscure
             */
                plain[index] = 96 + ((plain[index] + key) % 'z');
            }
            else
            {
                plain[index] += key;
            }
        }
        /* PR COMMENT #4
         *  Since this is almost identical to your lower-case example, you probably could
         * break out this code and pass in either '96' or '64' based on case. (Though my other
         * comment on magic numbers suggests an improvement there.)
         */
        //Uppercase rotation
        if (plain[index] >= 'A' && plain[index] <= 'Z')
        {
            //Catches overflow
            if (plain[index] + key > 'Z')
            {
                /* PR COMMENT #5
                 * Same as number 3 but also, if you used the value of upper/lower 'A'
                 * you could write the following line as

                    plain[index] = 'A' + ((plain[index] + key) % 'Z');

                 * which is a bit easier to read
                 */
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
