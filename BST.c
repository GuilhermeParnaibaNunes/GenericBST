#include "GenericElement.h"

/*Displays the tree graphically in preorder*/
  // - No return;
  // - Receives the tree.
  // - Receives the prefix for formatting;
  // - Receives whether it is the last node.
void displayTreeGUIRec(t_BST, const int, int);

#endif// BST_H


#include "BST.h"

t_BST newNode() {
    t_BST novo = (t_BST) malloc(sizeof(t_node));
    if(novo == NULL) {
        printf("\n\t*** Erro ao alocar memória para novo nó. ***");
        return NULL; // Retorna NULL se não conseguir alocar memória
    }
    if (novo) {
        novo->rNode = NULL;
        novo->lNode = NULL;
    }
    return novo;
}

int isEmpty(t_BST) {
    return (tree == NULL);
}

static int compareValue(int v1, int v2) {
    return v1>v2?1:v1<v2?-1:0;
}

int insertElement(t_BST *tree, t_Element element) {
    if (isEmpty(tree)){
        printf("\n\t*** Ponteiro para tree invalido. ***");
        return 0;
    }

    if (*tree == NULL) {
        *tree = newNode();
        if (*tree == NULL){
            return 0; // Retorna 0 se não conseguir alocar memória
        }
        (*tree)->element = element;
        printf("\n\t*** Elemento a ser inserido: ***\n\t\tValor: %d\n\n", (*tree)->element.value);
        return 1;
    }

    /*PRINTS PARA DEBUGAÇÃO DE PROCURA PARA INSERÇÃO*/
    //printf("\n\t*** Tentando inserir element: Valor: %d | value: [%d] ***\n", element.value, element.value);
    //printf("\n\t*** element atual: Valor: %d | value: %d ***\n", (*tree)->element.value, (*tree)->element.value);
    //printf("\n\t*** Comparando value: %d com %d ***\n", element.value, (*tree)->element.value);
    int cmp = compareValue(element.value, (*tree)->element.value);

    if (cmp == 0) {
        puts("");
        printAsText("O valor fornecido ja existe na tree, por isso nao eh possivel inseri-lo.");
        puts("");
        return 0;
    } else if (cmp > 0) {
        return Inserirelement(&(*tree)->rNode, element);
    } else {
        return Inserirelement(&(*tree)->lNode, element);
    }
}

int eraseTree(t_BST tree) {
    if (tree == NULL){
        return 0;
    }

    eraseTree(tree->lNode);
    eraseTree(tree->rNode);
    printf("\n\t*** Apagando element: ***\n\t\tValor: %d\n", tree->element.value);
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
    if(*tree == NULL) {
        printf("\n\t*** Elemento com valor %d nao encontrado. ***", val);
        return 0;
    }

    /*PRINT PARA DEBUGAÇÃO DE PROCURA PARA REMOÇÃO*/
    //printf("\n\t*** Comparando value: %d com [%d] ***\n", value, (*tree)->element.value);
    int cmp = compareValue(val, (*tree)->element.value);

    if (cmp > 0) {
        return removeValue(&(*tree)->rNode, value);
    } else if (cmp < 0) {
        return removeValue(&(*tree)->lNode, value);
    } else {
        printf("\t*** Elemento a ser removido: ***\n\t\tValor: %d\n", (*tree)->element.value, (*tree)->element.value);
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

        // Nó com dois filhos: pegar menor da direita para substituir
        t_BST temp = minimoNo((*tree)->rNode);
        (*tree)->element = temp->element;
        return removeValue(&(*tree)->rNode, temp->element.value);
    }
}

t_element searchValue(t_BST *tree, int value) {
    t_element empty;
    empty->value = -1;

    if (tree == NULL){
        return empty;
    }
    if(*tree == NULL){
        return empty; // Retorna element empty se a árvore for inválida
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
    t_element element = searchValue(&tree, value);
    if (element.value == -1) {
        printf("\n\t*** elemento com value %d nao encontrado. ***\n", value);
        printAsText("Não foi possivel exibir element.");
    } else {
        printf("\t*** elemento encontrado: ***\n\t\tValor: %d\n", element.value);
        printAsText("elemento exibido com sucesso.");
    }
}

void displayTree(t_BST tree) {
    if (tree == NULL) {
        return;
    }
    printf("\n\t*** tree em pre-ordem: ***\n");
    displayTreePre(tree);
    printf("\n\t*** tree em in-ordem: ***\n");
    displayTreeIn(tree);
    printf("\n\t*** tree em pos-ordem: ***\n");
    displayTreePos(tree);
    printf("\n\t*** Exibicao grafica de tree em pre-ordem: ***\n");
    displayTreeGUIRec(tree, "", 1);
    printf("\n\t*** Fim da exibicao de tree ***\n");
}

void displayTreePre(t_BST tree){
    if (tree == NULL) {
        return;
    }
    printf("\t\tValor: %d\n", tree->element.value);
    displayTreePre(tree->lNode);
    displayTreePre(tree->rNode);
}

void displayTreeIn(t_BST tree){
    if (tree == NULL) {
        return;
    }
    displayTreeIn(tree->lNode);
    printf("\t\tValor: %d\n", tree->element.value);
    displayTreeIn(tree->rNode);
}

void displayTreePos(t_BST tree){
    if (tree == NULL) {
        return;
    }
    displayTreePos(tree->lNode);
    displayTreePos(tree->rNode);
    printf("\t\tValor: %d\n", tree->element.value);
}

// Função recursiva auxiliar para exibir a árvore com formatação gráfica
void displayTreeGUIRec(t_BST tree, const char *prefixo, int ehUltimo) {
    if (tree == NULL)
        return;
    printf("%s", prefixo);
    printf("%s", ehUltimo ? "'--- " : "/--- ");
    printf("%d\n", tree->element.value);

    char novoPrefixo[100];
    snprintf(novoPrefixo, sizeof(novoPrefixo), "%s%s", prefixo, ehUltimo ? "    " : "/   ");

    // Se possui os dois filhos, exibe primeiro a esquerda (não é o último) e depois a direita (último)
    if (tree->lNode && tree->rNode) {
        displayTreeGUIRec(tree->lNode, novoPrefixo, 0);
        displayTreeGUIRec(tree->rNode, novoPrefixo, 1);

    // Se tem apenas o filho da esquerda, ele é tratado como o último
    } else if (tree->lNode) {
        displayTreeGUIRec(tree->lNode, novoPrefixo, 1);

    // Se tem apenas o filho da direita, também é o último
    } else if (tree->rNode) {
        displayTreeGUIRec(tree->rNode, novoPrefixo, 1);
    }
    //"/---" é a esquerda
    //"!---" é a direita
}
