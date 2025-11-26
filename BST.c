  #include "BST.h"

  t_BST newNode() {
      t_BST newN = (t_BST) malloc(sizeof(t_node));
      if (newN == NULL) {
          printf("\n\t*** Error: allocating memory for new node failed. ***");
          return NULL; // Returns NULL if allocating memory fails
      }
      if (newN) {
          newN->rNode = NULL;
          newN->lNode = NULL;
      }
      return newN;
  }

  int isEmpty(t_BST tree) {
      return (tree == NULL);
  }

  static int compareValue(int v1, int v2) {
      return v1>v2?1:v1<v2?-1:0;
  }

  int insertElement(t_BST *tree, t_Element element) {
      if (isEmpty(tree)){
          printf("\n\t*** Invalid tree pointer. ***");
          return 0;
      }

      if (*tree == NULL) {
          *tree = newNode();
          if (*tree == NULL){
              return 0; // Returns 0 if allocating memory fails
          }
          (*tree)->element = element;
          printf("\n\t*** To be inserted element: ***\n\t\tValue: %d\n\n", (*tree)->element.value);
          return 1;
      }

    /*DEBUG PRINTS FOR SEARCH DURING INSERTION*/
      //printf("\n\t*** Trying to insert element: Value: %d ***\n", element.value);
      //printf("\n\t*** Current element: Value: %d ***\n", (*tree)->element.value);
      //printf("\n\t*** Comparing value: %d with %d ***\n", element.value, (*tree)->element.value);
      int cmp = compareValue(element.value, (*tree)->element.value);

      if (cmp == 0) {
          puts("");
          printAsText("The given value is already on the tree, thus it cannot be inserted.");
          puts("");
          return 0;
      } else if (cmp > 0) {
          return insertElement(&(*tree)->rNode, element);
      } else {
          return insertElement(&(*tree)->lNode, element);
      }
  }

  int eraseTree(t_BST tree) {
      if (tree == NULL){
          return 0;
      }

      eraseTree(tree->lNode);
      eraseTree(tree->rNode);
      printf("\n\t*** Erasing element: ***\n\t\tValue: %d\n", tree->element.value);
      free(tree);
      return 1;
  }

  static t_BST minNode(t_BST node) {
      while (node && node->lNode != NULL) {
          node = node->lNode;
      }
      return node;
  }

  int removeValue(t_BST *tree, int val) {
      if (tree == NULL){
          return 0;
      }
      if (*tree == NULL) {
          printf("\n\t*** Element with value: %d not found. ***", val);
          return 0;
      }

    /* DEBUG PRINT FOR SEARCH DURING REMOVAL */
      //printf("\n\t*** Comparing value: %d with [%d] ***\n", value, (*tree)->element.value);
      int cmp = compareValue(val, (*tree)->element.value);

      if (cmp > 0) {
          return removeValue(&(*tree)->rNode, val);
      } else if (cmp < 0) {
          return removeValue(&(*tree)->lNode, val);
      } else {
          printf("\t*** To be removed element: ***\n\t\tValue: %d\n", (*tree)->element.value);
          // Nó encontrado, remover
          if ((*tree)->lNode == NULL) {
              t_BST temp = (*tree)->rNode;
              free(*tree);
              *tree = temp;
              return 1;
          } else if ((*tree)->rNode == NULL) {
              t_BST temp = (*tree)->lNode;
              free(*tree);
              *tree = temp;
              return 1;
          }

          // Two children node: takes the lowest from the right subtree to replace
          t_BST temp = minNode((*tree)->rNode);
          (*tree)->element = temp->element;
          return removeValue(&(*tree)->rNode, temp->element.value);
      }
  }

  t_Element searchValue(t_BST *tree, int value) {
      t_Element empty;
      empty.value = -1;

      if (tree == NULL){
          return empty;
      }
      if (*tree == NULL){
          return empty; // Returns empty element for invalid tree
      }

      int cmp = compareValue(value, (*tree)->element.value);

      if (cmp == 0) {
          return (*tree)->element;
      } else if (cmp > 0) {
          return searchValue(&(*tree)->rNode, value);
      } else {
          return searchValue(&(*tree)->lNode, value);
      }
  }

  void displayElementValue(t_BST tree, int value) {
      t_Element element = searchValue(&tree, value);
      if (element.value == -1) {
          printf("\n\t*** Element with value %d not found. ***\n", value);
          printAsText("Could not display element.");
      } else {
          printf("\t*** Element found: ***\n\t\tValue: %d\n", element.value);
          printAsText("Element shown successfully.");
      }
  }

  void displayTree(t_BST tree) {
      if (tree == NULL) {
          return;
      }
      printf("\n\t*** Preorder tree: ***\n");
      displayTreePre(tree);
      printf("\n\t*** Inorder tree: ***\n");
      displayTreeIn(tree);
      printf("\n\t*** Postorder tree: ***\n");
      displayTreePos(tree);
      printf("\n\t*** Level tree: ***\n");
      displayTreeLevel(tree);
      printf("\n\t*** Pre-order tree graphic display: ***\n");
      displayTreeGUIRec(tree, "", 1);
      printf("\n\t*** End of tree display ***\n");
  }

  static int getHeight(t_BST tree){
    if(tree == NULL)
      return 0;

    int lHeight = getHeight(tree->lNode);
    int rHeight = getHeight(tree->rNode);

    return 1+(lHeight>rHeight?lHeight:rHeight);
  }

  void displayTreeLevel(t_BST tree){
    int height = getHeight(tree);

    for(int lvl = 0; lvl < height; lvl++){
      printf("\t\tLevel [%d]: ", lvl);
      displayTreeLevelPrint(tree, lvl);
      printf("\n");
    }
  }

  void displayTreeLevelPrint(t_BST tree, int level){
    if(tree == NULL)
      return;
    if(level == 0){
      printf("%d ", tree->element.value);
    }else{
      displayTreeLevelPrint(tree->lNode, level-1);
      displayTreeLevelPrint(tree->rNode, level-1);
    }
  }

  void displayTreePre(t_BST tree){
      if (tree == NULL) {
          return;
      }
      printf("\t\tValue: %d\n", tree->element.value);
      displayTreePre(tree->lNode);
      displayTreePre(tree->rNode);
  }

  void displayTreeIn(t_BST tree){
      if (tree == NULL) {
          return;
      }
      displayTreeIn(tree->lNode);
      printf("\t\tValue: %d\n", tree->element.value);
      displayTreeIn(tree->rNode);
  }

  void displayTreePos(t_BST tree){
      if (tree == NULL) {
          return;
      }
      displayTreePos(tree->lNode);
      displayTreePos(tree->rNode);
      printf("\t\tValue: %d\n", tree->element.value);
  }

  // Auxiliary recursive function to display the tree with graphical formatting.
  void displayTreeGUIRec(t_BST tree, const char *prefix, int isLast) {
      if (tree == NULL)
          return;

      printf("%s", prefix);
      printf("%s", isLast ? "'--- " : "/--- ");
      printf("%d\n", tree->element.value);

      char newPrefix[100];
      snprintf(newPrefix, sizeof(newPrefix), "%s%s", prefix, isLast ? "    " : "/   ");

      // If it has both children, display the left one first (not the last) and then the right one (last)
      if (tree->lNode && tree->rNode) {
          displayTreeGUIRec(tree->lNode, newPrefix, 0);
          displayTreeGUIRec(tree->rNode, newPrefix, 1);

      // If it has only the left child, treat it as the last
      } else if (tree->lNode) {
          displayTreeGUIRec(tree->lNode, newPrefix, 1);

      // If it has only the right child, also treat it as the last
      } else if (tree->rNode) {
          displayTreeGUIRec(tree->rNode, newPrefix, 1);
      }

      // "/---" is the left child
      // "'---" is the right child
  }
