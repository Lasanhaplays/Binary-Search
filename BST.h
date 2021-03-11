//TADS LISTA E BST

typedef struct                                                      //Struct Info servindo tanto para a lista quanto para a BST
{
    int value;
}Info;
typedef struct bstno                                                //Struct BST
{
    struct bstno *left;
    Info *inf;
    struct bstno *right;
}BST;
typedef struct tnode                                                //Struct No da lista
{
    struct tnode *next;
    Info *info;
}Node;
typedef struct                                                      //Struct cabeca da lista
{
	int size;
	Node *first;
}List;

//PROTOTIPOS DAS FUNCOES DA LISTA

List *createList();                                                 //Cria uma lista
Node *createNode();                                                 //Cria um no para uma lista
Info *createInfo(int i);                                            //Cria uma info para uma lista
bool isEmptyList(List *lst);                                        //Verifica se a lista e vazia
bool insertFirstList(List *lst, Info *inf);                         //Insere na primeira posicao da lista
bool insertLastList(List *lst, Info *inf);                          //Insere na ultima posicao da lista
void printList(List *lst);                                          //Imprime a lista
Info *deleteFirstList(List *lst);                                   //Deleta o primeiro da lista
Info *deleteLastList(List *lst);                                    //Deleta o ultimo da lista

//PROTOTIPOS DAS FUNCOES DA BINTREE

BST *createBST(Info *inf);                                           //Cria uma BST
BST *leftBST(BST *bst);                                              //Retorna a subarvore esquerda da BST
BST *rightBST(BST *bst);                                             //Retorna a subarvore direita a BST
Info *rootBST(BST *bst);                                             //Retorna a inf da raiz de uma BST
int isEmptyBST(BST *bst);                                            //Verifica se a BST esta vazia
BST *searchBST(BST *bst,Info *inf);                                  //Procura a info informada dentro da BST
void destroyBST(BST *bst);                                           //Apaga a BST
int heightBST(BST *bst);                                             //Retorna a altura de uma BST
void auxPreOrder(BST *bst,List *lst);                                //Auxilia e insere em uma lista as infos de uma BST em pre ordem
void auxinOrder(BST *bst,List *lst);                                 //Auxilia e insere em uma lista as infos de uma BST em ordem
void auxPostOrder(BST *bst,List *lst);                               //Auxilia e insere em uma lista as infos de uma BST em pos ordem
List *preOrderTraversalBST(BST *bst);                                //Insere em pre ordem em uma lista as infos de uma BSTT
List *inOrderTraversalBST(BST *bst);                                 //Insere em ordem em uma lista as infos de uma BST
List *postOrderTraversalBST(BST *bst);                               //Insere em pos ordem em uma lista as infos de uma BST
List *leftListBST(List *preOrder,List *left);                        //Retorna uma lista com as folhas a esquerda da raiz
List *rightListBST(List *preOrder,List *left);                       //Retorna uma lista com as folhas a direita da raiz
BST *insertBST(BST *bst,Info *inf);                                  //Insere uma info na BST
BST *findLargestElementBST(BST *bst);                                //Busca o maior elemento da BST
BST *findSmallestElementBST(BST *bst);                               //Busca o maior elemento da BST
BST *mostRightBST(BST *bst);                                         //Retorna a folha mais a direita da arvore
BST *mostLeftBST(BST *bst);                                          //Retorna a folha mais a esquerda da arvore
BST *deleteBST(BST *bst,Info *inf);                                  //Deleta uma info de uma BST;
void printBSTaux(BST *bst);                                          //Auxilia a funcao que imprime a arvore
void printBST(BST *bst);                                             //Imprime a arvore
int totalExternalNodes(BST *bst);                                    //Calcula o numero de nos externos da arvore
int totalInternalNodes(BST *bst);                                    //Calcula o numero de nos internos da arvore
int isOrderedBST(BST *bst);                                          //Verifica se a bst é ordenada
