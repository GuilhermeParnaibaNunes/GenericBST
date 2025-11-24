#include "BST.h"

int main(){
  setlocale(LC_ALL, "Portuguese"); // Configura o locale para português do Brasil
  int sel = 1, cErro, val = 0;
  t_BST tree = NULL;
  t_BST *ptree = &tree;
  t_Element element;
  int value;
  astDiv();
  printf("\t\t");
  printAsText("Seja bem-vindo(a) ao nosso Sistema de elemento (BST)!");
  dashDiv();

  while(sel){
    puts("");
    printf("\t******MENU******\n"
           "\t*** (1) - Cadastrar elemento;\n"
           "\t*** (2) - Apagar elemento por valor;\n"
           "\t*** (3) - Exibir elemento por valor;\n"
           "\t*** (4) - Reiniciar sistema;\n"
           "\t*** (5) - Exibir elemento;\n"
           "\t*** (0) - Sair do sistema.\n\t");
    scanf("%d", &sel);
    getchar();
    puts("");
    switch(sel){
      case 1:
        while(!val){
          printAsQuest("Informe o valor do elemento:");
          scanf("%d", &value);
          val = validateValue(value);
        }
        val = 0;
        cErro = setElement(&element, value);
        puts("");
        printAsText(cErro==1? "element criado com sucesso"
               :cErro==0? "Nao foi possivel criar element": "Erro desconhecido");
        cErro = Inserirelement(ptree, element);
        printAsText(cErro==1? "element inserido com sucesso"
               :cErro==0? "Nao foi possivel inserir element": "Erro desconhecido");
        dashDiv();
        break;
      case 2:
        if(isEmpty(tree)){
          printAsText("Arvore vazia!");
          dashDiv();
          break;
        }
        printAsQuest("Qual o valor do elemento que deseja apagar?");
        while(!val){
          puts("");
          printAsQuest("Informe o valor do elemento:");
          scanf("%d", &value);
          val = validateValue(value);
        }
        val = 0;
        setvalue(&element, value); // Garante que o value procurado está no formato correto
        cErro = Removervalue(ptree, element.value);
        puts("");
        printAsText(cErro==1? "element removido com sucesso"
               :cErro==0? "Nao foi possivel remover element": "Erro desconhecido");
        dashDiv();
        break;
      case 3:
        if(isEmpty(tree)){
          printAsText("Arvore vazia!");
          dashDiv();
          break;
        }
        printAsQuest("Qual o value do element que deseja visualizar?");
        while(!val){
          puts("");
          printAsQuest("Informe o value do element:");
          scanf("%d", &value);
          val = validateValue(value);
        }
        val = 0;
        setvalue(&element, value); // Garante que o value procurado está no formato correto
        puts("");
        Exibirelementvalue(tree, element.value);
        dashDiv();
        break;
      case 4:
        if(isVazia(tree)){
          printAsText("Arvore vazia!");
          dashDiv();
          break;
        }
        cErro = ApagaArvore(tree);
        puts("");
        printAsText(cErro==1? "Arvore apagada com sucesso"
               :cErro==0? "Nao foi possivel apagar arvore": "Erro desconhecido");
        tree = NULL; // Reseta a árvore para NULL após apagá-la
        puts("");
        printAsText("Sistema reiniciado com sucesso!");
        dashDiv();
        break;
      case 5:
        if(isVazia(tree)){
          printAsText("Arvore vazia!");
          dashDiv();
          break;
        }
        printf("\n\t*** Escolha a forma de exibir a arvore: ***\n"
               "\t*** (1) - Pre-ordem;\n"
               "\t*** (2) - In-ordem;\n"
               "\t*** (3) - Pos-ordem.\n"
               "\t*** (4) - Exibicao grafica.\n"
               "\t*** (5) - Todas as anteriores.\n"
               "\t*** (0) - Voltar ao menu principal.\n\t");
        scanf("%d", &sel);
        getchar();
        switch(sel){
            case 1:
              printAsText("Exibindo arvore em pre-ordem:");
              puts("");
              ExibirArvorePre(tree);
              break;
            case 2:
              printAsText("Exibindo arvore em in-ordem:");
              puts("");
              ExibirArvoreIn(tree);
              break;
            case 3:
              printAsText("Exibindo arvore em pos-ordem:");
              puts("");
              ExibirArvorePos(tree);
              break;
            case 4:
              printAsText("Exibindo arvore graficamente em pre-ordem:");
              puts("");
              ExibirArvoreGUIRec(tree, "", 1);
              break;
            case 5:
              ExibirArvore(tree);
              break;
            case 0:
              printAsText("Voltando ao menu principal...");
              puts("");
              sel = 1;
              break;
            default:
              printAsText("Insira um valor valido!");
              puts("");
              break;
          }
        dashDiv();
        break;
      case 0:
        printAsText("Até mais!");
        return 1;
      default:
        printAsText("Insira um valor valido");
        break;
    }
  }
}

/*
1 � INSERIR � fornecer value e Nome
2 � REMOVER UM N� � fornecer o value a remover
3 � PESQUISAR � fornecer o value a pesquisar
4 � ESVAZIAR A �RVORE
5 � EXIBIR A �RVORE � tr�s op��es: PR�, IN ou P�S
0 � SAIR
*/

