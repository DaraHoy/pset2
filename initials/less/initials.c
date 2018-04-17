#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/* PEER REVIEW
 *  All good. My only thought is that you're checking index==0 on every pass.
 *  In a larger test case, it might be better to 1) take the strlen check out of the loop
 *  and 2) to do a "'0' case" and handle the "first name" separately, then
 *  subsequent names in a loop starting at 1 instead of 0, something like

    int len = strlen(name);
    printf("%c", toupper(name[0]));   // handles the always 0-based first name
    for(x=1; x<....)
        printf(....)

 * But for only a few names, it hardly matters.
 */
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