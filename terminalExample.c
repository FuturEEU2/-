#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

void moveCharacter(char *character, char direction);

int main()
{
    char userInput;
    char character = '>';


    /* Example 1: Normal user input without disabling the buffering */
    do
    {
        /* clear the screen */
        system("clear");

        printf("This is an example of using the terminal functions to stop the terminal from buffering the input");
        printf("This is normal input.\nPress A for left, D for right and X to go to the next example\n");

        printf("%c\n", character);

        /* userInput is a single char, not a string. The leading space ignores whitespace characters */
        scanf(" %c", &userInput);

        /* move the character to face a direction */
        moveCharacter(&character, userInput);
    } while (userInput != 'x');


     /* Example 2: User input using the terminal functions to disable the buffering */
    do
    {
        /* clear the screen */
        system("clear");
        printf("This is an example of using the terminal functions to stop the terminal from buffering the input");
        printf("This is non-buffered input\nPress A for left, D for right and X to exit\n");

        printf("%c\n", character);

        /* disable the buffer before input */
        disableBuffer();

        scanf(" %c", &userInput);

        /* enable the buffer after input */
        enableBuffer();

        /* move the character to face a direction */
        moveCharacter(&character, userInput);
    } while (userInput != 'x');

    return 0;
}


/* this is a pass-by-reference function that changes the character based on the direction */
/* note the use of pointers to allow it to change the "character" variable */
void moveCharacter(char* character, char direction)
{
    if(direction == 'a')
    {
        *character = '<';
    }
    else if(direction == 'd')
    {
        *character = '>';
    }
}
