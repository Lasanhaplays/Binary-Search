#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST.c"

void main()
{
    printf("-----------------------------------------TRABALHO ARVORE BUSCA BINARIA-----------------------------------------\n\n");
    printf("ALUNO: LAZARO JOSE\n");
    printf("MATRICULA: 2018102437\n");
    printf("ESTRUTURA DE DADOS I 2019/02\n");
    printf("\n-----------------------------------------TRABALHO ARVORE BUSCA BINARIA-----------------------------------------\n\n");
    List *lst=createList();
    BST *bst;
    insertLastList(lst,createInfo(45));
    insertLastList(lst,createInfo(39));
    insertLastList(lst,createInfo(56));
    insertLastList(lst,createInfo(12));
    insertLastList(lst,createInfo(34));
    insertLastList(lst,createInfo(78));
    insertLastList(lst,createInfo(32));
    insertLastList(lst,createInfo(10));
    insertLastList(lst,createInfo(89));
    insertLastList(lst,createInfo(54));
    insertLastList(lst,createInfo(67));
    insertLastList(lst,createInfo(81));
    printf("Lista com os valores a serem inseridos na BST:\n");
    printList(lst);
    bst = createBST(createInfo(45));
    insertBST(bst,createInfo(39));
    insertBST(bst,createInfo(56));
    insertBST(bst,createInfo(12));
    insertBST(bst,createInfo(34));
    insertBST(bst,createInfo(78));
    insertBST(bst,createInfo(32));
    insertBST(bst,createInfo(10));
    insertBST(bst,createInfo(89));
    insertBST(bst,createInfo(54));
    insertBST(bst,createInfo(67));
    insertBST(bst,createInfo(81));
    printf("\n\nImprimindo a BST em ordem:\n\n");
    printBST(bst);
    printf("\n\nO menor elemento da BST: %d\n",findLargestElementBST(bst)->inf->value);
    printf("\n\nO maior elemento da BST: %d\n",findLargestElementBST(bst)->inf->value);
    printf("\n\nDeletando o elemento 32 da BST:\n\n");
    deleteBST(bst,createInfo(32));
    printBST(bst);
    printf("\n\n-----------------------------------------FIM DO TRABALHO-----------------------------------------\n\n");
}
