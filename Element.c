#include "Element.h"

int setElement(t_Element *elem, int vl){
  if(!setValue(elem, vl))
    return 0;
  return 1;
}

int setValue(t_Element *elem, int vl){
  if(!validateValue(vl))
    return 0;
  elem->value = vl;
  return 1;
}

int validateValue(int vl){
  return 1;
}


