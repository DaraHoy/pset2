#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //Prompt user for a name
    string name = get_string();
    //iterate through name to find valid initials
    for (int index = 0; index < strlen(name); index++)
    {
        //if letter is in the first index or is preceded by a space, print letter in uppercase
        if (index == 0 || name[index - 1] == 32)
        {
            printf("%c", toupper(name[index]));
        }
    }
    //print next line
    printf("\n");
}