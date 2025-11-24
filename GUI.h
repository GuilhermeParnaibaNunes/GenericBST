#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef GUI_H
#define GUI_H

/*Prints a divider made of '-' on the screen*/
void dashDiv();

/* Prints a divider made of '*' on the screen*/
void astDiv();

/* Prints a given text on the screen in a standard format */
void printAsText(char *);

/* Prints a given input on the screen in a standard question format */
void printAsQuest(char *);

#endif // GUI_H

/* Implement:
 * PrintASText receiving two additional boolean parameters,
 * defining the presence or absence of line breaks before and after the text;
 *
 * Standardized printing for elements of type 'student' to be inserted, removed, or displayed:
 *     VERTICAL   \t\tName: %s | RGM: %s\n
 *     HORIZONTAL \t\tName: %s\n\t\tRGM: %s\n
 *
 * Standardized printing for menus;
 * Correct printing of accents and special characters;
 */
