#include "GenericElement.h"

#ifndef BST_H
#define BST_H

/*Structure named node*/
  // - Field element: node element;
  // - Field rNode: pointer to the right node;
  // - Field lNode: pointer to the left node.
typedef struct node{
    t_Element element;
    struct node * rNode;
    struct node * lNode;
} t_node;

/*t_BST becomes another name to an element nodes pointer*/
typedef t_node * t_BST;

/*Creates a new element node*/
  // - Returns a pointer to the created node;
  // - Takes no parameters.
t_BST newNode();

/*Checks if tree is empty*/
  // - Returnss 1 for true;
  // - Returnss 0 for false;
  // - Receives the tree under analysis.
int isEmpty(t_BST);

/*Inserts a new node into the tree*/
  // - Returns 1 for successful procedure;
  // - Returns 0 for unsuccessful procedure;
  // - Receives the tree for insertion;
  // - Receives the element to be inserted.
int insertElement(t_BST *, t_Element);

/*Removes all nodes of a tree*/
  // - Returns 1 for successful procedure;
  // - Returns 0 for empty tree;
  // - Receives the tree under analysis.
int eraseTree(t_BST);

/*Removes a node by value*/
  // - Returns 1 for successful procedure;
  // - Returns 0 for unsuccessful procedure;
  // - Receives the tree under analysis;
  // - Receives the value of the node to be removed.
int removeValue(t_BST *, int);

/*Searches for a node in the tree by its value*/
  // - Returns the searched element;
  // - Returns NULL for not found element;
  // - Receives the tree under analysis;
  // - Receives the value of the node to be searched.
t_Element searchValue(t_BST *, int);

/*Displays a element by value*/
  // - No return;
  // - Receives the tree;
  // - Receives the value of the node to be displayed.
void displayElementValue(t_BST, int);

/*Displays tree in pre, in and postorder*/
  // - No return;
  // - Receives the tree.
void displayTree(t_BST);

/*Displays tree in preorder*/
  // - No return;
  // - Receives the tree.
void displayTreePre(t_BST);

/*Displays tree in inorder*/
  // - No return;
  // - Receives the tree.
void displayTreeIn(t_BST);

/*Displays tree in postorder*/
  // - No return;
  // - Receives the tree.
void displayTreePos(t_BST);

/*Displays the tree graphically in preorder*/
  // - No return;
  // - Receives the tree.
  // - Receives the prefix for formatting;
  // - Receives whether it is the last node.
void displayTreeGUIRec(t_BST, const int, int);

#endif// BST_H
