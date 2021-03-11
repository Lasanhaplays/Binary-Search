#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST.h"


//FUNCOES DA LISTA

List *createList()                                                  //Cria uma lista
{
    List *ptr;
    if(ptr=(List*)malloc(sizeof(List))){
        ptr->size=0;
        ptr->first=NULL;
        return ptr;
    }
    return NULL;
}
Node *createNode()                                                  //Cria um no para uma lista
{
    Node *ptr;
    if(ptr=(Node*)malloc(sizeof(Node))){
        ptr->info=NULL;
        ptr->next=NULL;
        return ptr;
    }
    return NULL;
}
Info *createInfo(int i)                                             //Cria uma info para uma lista
{
    Info *ptr;
    if(ptr=(Info *)malloc(sizeof(Info))){
        ptr->value=i;
        return ptr;
    }
    return NULL;
}
bool isEmptyList(List *lst)                                         //Verifica se a lista e vazia
{
    return(!lst|| lst->size == 0);
}
bool insertFirstList(List *lst, Info *inf)                          //Insere na primeira posicao da lista
{
    Node *ptr;
    if(!lst || !(ptr=createNode())) return false;
    ptr->info=inf;
    ptr->next=lst->first;
    lst->first=ptr;
    lst->size++;
    return true;
}
bool insertLastList(List *lst, Info *inf)                           //Insere na ultima posicao da lista
{
    Node *ptr, *aux;
    if(!lst || !(ptr=createNode())) return false;
    ptr->info=inf;

    if(lst->first==NULL)
    {
    	lst->first=ptr;
    }
    else
	{
		aux=lst->first;
		while(aux->next!=NULL) aux=aux->next;
		aux->next=ptr;
	}
	lst->size++;
    return true;
}
void printList(List *lst)                                           //Imprime a lista
{
    Node *ptr;
    if(isEmptyList(lst)) return;
    printf("\n[ ");
    ptr=lst->first;
    while(ptr != NULL)
    {
      printf("(%d) ",ptr->info->value);
      ptr = ptr->next;
    }
	printf(" ]");
}
Info *deleteFirstList(List *lst)                                    //Deleta o primeiro da lista
{
  Node *ptr;
  Info *inf;
  if (!lst) return NULL;
  ptr=lst->first;
  lst->first=ptr->next;
  inf=ptr->info;
  free(ptr);
  lst->size--;
  return inf;
}
Info *deleteLastList(List *lst)                                     //Deleta o ultimo da lista
{
  Node *ptr,*pptr;
  Info *inf;
  if (!lst) return NULL;
  ptr=lst->first;
  if(lst->size==1){
   lst->first=ptr->next;
  }
  else
  {
  	pptr=ptr;
  	ptr=ptr->next;
  	while(ptr->next!=NULL)
	{
  		pptr=ptr;
  		ptr=ptr->next;
	}
	pptr->next=ptr->next;
  }
  inf=ptr->info;
  free(ptr);
  lst->size--;
  return inf;
}

//FUNCOES DA BINTREE

BST *createBST(Info *inf)                                           //Cria uma BST
{
    BST *bst;
    if(!inf) return NULL;
    if(bst=(BST*)malloc(sizeof(BST)))
    {
        bst->inf = inf;
        bst->left = bst->right = NULL;
        return bst;
    }
    return NULL;
}
BST *leftBST(BST *bst)                                              //Retorna a subarvore esquerda da BST
{
    if(!bst) return NULL;
    return bst->left;
}
BST *rightBST(BST *bst)                                             //Retorna a subarvore direita a BST
{
    if(!bst) return NULL;
    return bst->right;
}
Info *rootBST(BST *bst)                                             //Retorna a inf da raiz de uma BST
{
    if(!bst) return NULL;
    return bst->inf;
}
int isEmptyBST(BST *bst)                                            //Verifica se a BST esta vazia
{
    if(!bst) return 1;
    return 0;
}
BST *searchBST(BST *bst,Info *inf)                                  //Procura a info informada dentro da BST
{
    if(!bst || !inf) return NULL;
    if(bst->inf->value == inf->value) return bst;
    else if(bst->inf->value > inf->value) return searchBST(leftBST(bst),inf);
    else return searchBST(rightBST(bst),inf);
}
void destroyBST(BST *bst)                                           //Apaga a BST
{
    if(!bst) return;
    destroyBST(leftBST(bst));
    destroyBST(rightBST(bst));
    free(bst->inf);
    free(bst);
    return;
}
int heightBST(BST *bst)                                             //Retorna a altura de uma BST
{
    int l,r;
    if(!bst) return 0;
    l=1+heightBST(leftBST(bst));
    r=1+heightBST(rightBST(bst));
    if(r>l) return r;
    return l;
}
void auxPreOrder(BST *bst,List *lst)                                //Auxilia e insere em uma lista as infos de uma BST em pre ordem
{
    Info *tempinfo;
    tempinfo = bst->inf;
    if(!tempinfo) return;
    insertLastList(lst,tempinfo);
    auxPreOrder(leftBST(bst),lst);
    auxPreOrder(rightBST(bst),lst);
    return;
}
void auxinOrder(BST *bst,List *lst)                                 //Auxilia e insere em uma lista as infos de uma BST em ordem
{
    Info *tempinfo;
    tempinfo = bst->inf;
    if(!tempinfo) return;
    auxPreOrder(leftBST(bst),lst);
    insertLastList(lst,tempinfo);
    auxPreOrder(rightBST(bst),lst);
    return;
}
void auxPostOrder(BST *bst,List *lst)                               //Auxilia e insere em uma lista as infos de uma BST em pos ordem
{
    Info *tempinfo;
    tempinfo = bst->inf;
    if(!tempinfo) return;
    auxPreOrder(leftBST(bst),lst);
    auxPreOrder(rightBST(bst),lst);
    insertLastList(lst,tempinfo);
    return;
}
List *preOrderTraversalBST(BST *bst)                                //Insere em pre ordem em uma lista as infos de uma BST
{
    List *lst=createList();
    Info *tempInfo;
    if(!bst||!lst) return NULL;
    tempInfo = bst->inf;
    if(!tempInfo) return NULL;
    insertLastList(lst,tempInfo);
    auxPreOrder(leftBST(bst),lst);
    auxPreOrder(rightBST(bst),lst);
    return lst;
}
List *inOrderTraversalBST(BST *bst)                                 //Insere em ordem em uma lista as infos de uma BST
{
    Info *tempInfo;
    List *lst=createList();
    if(!lst||bst) return NULL;
    tempInfo = bst->inf;
    if(!tempInfo) return NULL;
    auxinOrder(leftBST(bst),lst);
    insertLastList(lst,tempInfo);
    auxinOrder(rightBST(bst),lst);
    return lst;
}
List *postOrderTraversalBST(BST *bst)                               //Insere em pos ordem em uma lista as infos de uma BST
{
    List *lst=createList();
    Info *tempInf;
    if(!lst||bst) return NULL;
    tempInf = bst->inf;
    if(!tempInf) return NULL;
    auxPostOrder(leftBST(bst),lst);
    auxPostOrder(rightBST(bst),lst);
    insertLastList(lst,tempInf);
    return lst;
}
List *leftListBST(List *preOrder,List *left)                       //Retorna uma lista com as folhas a esquerda da raiz
{
    List *lst = createList();
    Node *aux;
    if(!lst||!left) return NULL;
    aux = left->first;
    if(aux == NULL) return NULL;
    while (aux->info->value != preOrder->first->info->value || aux != NULL)
    {
        insertLastList(lst,deleteFirstList(left));
        aux = aux->next;
    }
    if(aux->next == NULL) return NULL;
    insertLastList(lst,deleteFirstList(left));
    return lst;
}
List *rightListBST(List *preOrder,List *right)                     //Retorna uma lista com as folhas a direita da raiz
{
    List *lst = createList();
    Node *aux;
    if(!lst||!right) return NULL;
    deleteFirstList(right);
    aux = right->first;
    if(aux == NULL) return NULL;
    while (aux != NULL)
    {
        insertLastList(lst,deleteFirstList(right));
        aux = aux->next;
    }
    return lst;
}
BST *insertBST(BST *bst,Info *inf)                                  //Insere uma indo na BST
{
    if(!bst) return createBST(inf);
    if(bst->inf->value > inf->value) bst->left = insertBST(leftBST(bst),inf);
    else bst->right = insertBST(rightBST(bst),inf);
    return bst;
}
BST *findLargestElementBST(BST *bst)                                //Busca o maior elemento da BST
{
    if(isEmptyBST(bst)||isEmptyBST(rightBST(bst))) return bst;
    else return findLargestElementBST(rightBST(bst));
}
BST *findSmallestElementBST(BST *bst)                               //Busca o maior elemento da BST
{
    if(isEmptyBST(bst)||isEmptyBST(leftBST(bst))) return bst;
    else return findSmallestElementBST(leftBST(bst));
}
BST *mostRightBST(BST *bst)                                         //Retorna a folha mais a direita da arvore
{
    if(!bst) return NULL;
    if(!(rightBST(bst))) return bst;
    else return mostRightBST(rightBST(bst));
}
BST *mostLeftBST(BST *bst)                                          //Retorna a folha mais a esquerda da arvore
{
    if(!bst) return NULL;
    if(!(leftBST(bst))) return bst;
    else return mostLeftBST(leftBST(bst));
}
BST *deleteBST(BST *bst,Info *inf)                                  //Deleta uma info de uma BST
{
    if(!bst) return NULL;
    if(bst->inf->value > inf->value) bst->left = deleteBST(leftBST(bst),inf);
    else if(bst->inf->value < inf->value) bst->right = deleteBST(rightBST(bst),inf);
    else
    {
        if(bst->left == NULL)
        {
            BST *temp = rightBST(bst);
            free(bst->left);
            free(bst);
            return temp;
        }
        else if(bst->right == NULL)
        {
            BST *temp = leftBST(bst);
            free(bst->inf);
            free(bst);
            return temp;
        }
        BST *temp = findSmallestElementBST(rightBST(bst));
        bst->inf = temp->inf;
        bst->right = deleteBST(rightBST(bst),temp->inf);
    }
    return bst;
}
void printBSTaux(BST *bst)                                          //Auxilia a impressao da arvore
{
    if(!bst) return;
    printBSTaux(leftBST(bst));
    printf("%d ",bst->inf->value);
    printBSTaux(rightBST(bst));
    return;
}
void printBST(BST *bst)                                             //Imprime a arvore
{
    if(!bst) return;
    printBSTaux(leftBST(bst));
    printf("%d ",bst->inf->value);
    printBSTaux(rightBST(bst));
}
int totalExternalNodes(BST *bst)                                   //Calcula o numero de nos externos da arvore
{
    if(!bst) return 0;
    else if(!(bst->left) && !(bst->right)) return 1;
    else return(totalExternalNodes(bst->left)+totalExternalNodes(bst->right))
}
int totalInternalNodes(BST *bst)                                   //Calcula o numero de nos internos da arvore
{
    if(!bst) return 0;
    else if(!(bst->left) && !(bst->right)) return 0;
    else return(1+(totalInternalNodes(bst->left)+totalInternalNodes(bst->right)))
}
int isOrderedBST(BST *bst)                                          //Verifica se a bst é ordenada
{
    if(!bst || !(bst->left) && !(bst->right)) return 1;
    else
    {
        return (isOrderedBST(bst->left) && isOrderedBST(bst->right) && (!bst->left || ((findLargestElementBST(bst->left))->inf < bst->inf) && (!bst->right || (findSmallestElementBST(bst->right)->inf > bst->right))))
    }

}
