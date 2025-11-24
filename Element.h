#include "GUI.h"

#ifndef ELEMENT_H
#define ELEMENT_H

typedef struct Element
{
    int value;
} t_Element;

/*Sets a new Element*/
// - Return 1 for successful procedure;
// - Return 0 for unsuccessful procedure;
// - Receives element pointer;
// - Receives the value attribute of element.
int setObject(t_Element *, int);

/*Sets the Object value*/
// - Return 1 for successful procedure;
// - Return 0 for unsuccessful procedure;
// - Receives element pointer;
// - Receives the element value;
// - Verifies validity of value using "validateValue" function.
int setValue(t_Element *, int);

/*Verifies given value:*/
// - Return 1 for valid value;
// - Return 0 for unvalid value;
// - Receives supposed value.
int validateValue(int);

#endif // ALUNO_H
