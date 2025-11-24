#include "BST.h"

int main(){
  int sel = 1, errorCode, val = 0;
  t_BST tree = NULL;
  t_BST *pTree = &tree;
  t_Element element;
  int value;
  astDiv();
  printf("\t\t");
  printAsText("Welcome to the generic Binary Search Tree system!");
  dashDiv();

  while(sel){
    puts("");
    printf("\t******MENU******\n"
           "\t*** (1) - Insert new element;\n"
           "\t*** (2) - Delete element by value;\n"
           "\t*** (3) - Display element by value;\n"
           "\t*** (4) - Reset system;\n"
           "\t*** (5) - Display tree options;\n"
           "\t*** (0) - Exit system.\n\t");
    scanf("%d", &sel);
    getchar();
    puts("");
    switch(sel){
      case 1:
        while(!val){
          printAsQuest("Enter the element value:");
          scanf("%d", &value);
          val = validateValue(value);
        }
        val = 0;
        errorCode = setElement(&element, value);
        puts("");
        printAsText(errorCode==1? "Element successfully created"
               :errorCode==0? "Could not create element": "Unknown error");
        errorCode = insertElement(pTree, element);
        printAsText(errorCode==1? "Element successfully inserted"
               :errorCode==0? "Could not insert element": "Unknown error");
        dashDiv();
        break;
      case 2:
        if(isEmpty(tree)){
          printAsText("Empty tree!");
          dashDiv();
          break;
        }
        while(!val){
          puts("");
          printAsQuest("Enter the element value to be removed:");
          scanf("%d", &value);
          val = validateValue(value);
        }
        val = 0;
        errorCode = removeValue(pTree, value);
        puts("");
        printAsText(errorCode==1? "Element successfully removed"
               :errorCode==0? "Could not remove element": "Unknown error");
        dashDiv();
        break;
      case 3:
        if(isEmpty(tree)){
          printAsText("Empty tree!");
          dashDiv();
          break;
        }
        while(!val){
          puts("");
          printAsQuest("Enter the element value to be searched:");
          scanf("%d", &value);
          val = validateValue(value);
        }
        val = 0;
        puts("");
        displayElementValue(tree, value);
        dashDiv();
        break;
      case 4:
        if(isEmpty(tree)){
          printAsText("Empty tree!");
          dashDiv();
          break;
        }
        errorCode = eraseTree(tree);
        puts("");
        printAsText(errorCode==1? "Tree successfully erased"
               :errorCode==0? "Could not erase tree": "Unknown error");
        tree = NULL; // Resets the tree to NULL after erasing it
        puts("");
        printAsText("System successfully restarted!");
        dashDiv();
        break;
      case 5:
        if(isEmpty(tree)){
          printAsText("Empty tree!");
          dashDiv();
          break;
        }
        printf("\n\t*** Choose the tree display method: ***\n"
               "\t*** (1) - Preorder;\n"
               "\t*** (2) - Inorder;\n"
               "\t*** (3) - Postorder;\n"
               "\t*** (4) - Graphic display;\n"
               "\t*** (5) - All of the above;\n"
               "\t*** (0) - Back to main menu.\n\t");
        scanf("%d", &sel);
        getchar();
        switch(sel){
            case 1:
              printAsText("Displaying tree in preorder:");
              puts("");
              displayTreePre(tree);
              break;
            case 2:
              printAsText("Displaying tree in inorder:");
              puts("");
              displayTreeIn(tree);
              break;
            case 3:
              printAsText("Displaying tree in postorder:");
              puts("");
              displayTreePos(tree);
              break;
            case 4:
              printAsText("Displaying tree graphically in preorder:");
              puts("");
              displayTreeGUIRec(tree, "", 1);
              break;
            case 5:
              displayTree(tree);
              break;
            case 0:
              printAsText("Returning to main menu...");
              puts("");
              sel = 1;
              break;
            default:
              printAsText("Insert a valid value!");
              puts("");
              break;
          }
        dashDiv();
        break;
      case 0:
        printAsText("See you later!");
        return 1;
      default:
        printAsText("Insert a valid value");
        break;
    }
  }
}

