#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort();
void selectionSort();
void insertionSort();
void menu();
void treePrint();
void treeFree();


void menu(int *saida){
    printf(
    "Escolha uma opção:\n"
    "1 - Mostrar código desordenado\n"
    "2 - bubbleSort\n"
    "3 - selectionSort\n"
    "4 - insertionSort\n"
    "5 - Arvore Binária\n"
    "6 - Sair\n"
    );
    scanf("%d", saida);
}

void bubbleSort(int *arra, int tam){
    int i, j, aux;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j ++){
            if(arra[j] > arra[j + 1]){
                aux = arra[j];
                arra[j] = arra[j + 1];
                arra[j + 1 ] = aux;
            }
        }
    }
}

void selectionSort(int *arra, int tam) {
 for (int i = 0; i < tam - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < tam; j++)
      if (arra[j] < arra[min]) min = j;

    if (min != i)
    {
      int temp = arra[i];
      arra[i] = arra[min];
      arra[min] = temp;
    }
  }
} 

void insertionSort(int *arra, int tam){
    int x, y, value;
    for(x = 1; x < tam; x++){
        value = arra[x];
        for(y = x - 1; y >= 0 && arra[y] > value; y--){
            arra[y+1] = arra[y];
        }
        arra[y+1] = value;
    }
}

struct item{
   int cod; 
};

typedef struct item Item;

struct node{
    Item item;
    struct node *esq;
    struct node *dir;
};

typedef struct node Node;

Node *init(){
    return NULL;
}

void arvSaida(Node *root){
    if(root != NULL){
        printf("%d \n", root->item.cod);
        arvSaida(root->esq);
        arvSaida(root->dir);
    }
}

void arvLiberar(Node *root){
    if(root != NULL){
        arvLiberar(root->esq);
        arvLiberar(root->dir);
        free(root);
    }
}

Item itemCreate(int cod){
    Item item;
    item.cod = cod;
    return item;
}

Node *arvInserir(Node *root, Item x){
    if(root == NULL){
        Node *aux = (Node*)malloc(sizeof(Node));
        aux->item = x;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    }
    else
    {
        if(x.cod > root->item.cod){
            root->dir = arvInserir(root->dir, x);
        }
        else if(x.cod < root->item.cod){
            root->esq = arvInserir(root->esq, x);
        }
    }
    return root;
}

int main() {
    int v = 100, i = 0, j, igual, op, op2, k;
    int num0[v], num1[v], num2[v], num3[v], num4[v];
    
    while(i < 100){
        num0[i] = rand() % 1001;
        igual = 0;
        for(j = 0; j < i; j++){
            if(num0[j] == num0[i])
                igual = 1;
        }
        if(igual == 0)
            i++;
    }

    for(i = 0; i < 100; i++){
        num1[i] = num0[i];
        num2[i] = num0[i];
        num3[i] = num0[i];
        num4[i] = num0[i];
    }

    while(1){
        menu(&op);
        // Gerar números aleatórios pra o usuário
        if (op == 1) {
            for(i = 0; i < 100; i++){
                printf("[%d]: %d\n", i, num0[i]);
            }
            printf("Numeros aleatorios");
            printf("\n\n");
        // BubleSort neste bloco
        } else if (op == 2) {
            clock_t tic = clock();
            bubbleSort(num1, v);
            clock_t toc = clock();
            for(i = 0; i < 100; i++){
                printf("[%d]: %d\n", i, num1[i]);
            }
            printf("BubbleSort\n");
            printf("O tempo de execução foi de: %f segundos", (double)(toc - tic)/ CLOCKS_PER_SEC);
            printf("\n\n");
        // Selection neste bloco
        } else if (op == 3) {  
            clock_t tic = clock();
            selectionSort(num2, v);
            clock_t toc = clock();
            for(i = 0; i < 100; i++){
                printf("[%d]: %d\n", i, num2[i]);
            }
            printf("SelectionSort");
            printf("O tempo de execução foi de: %f segundos", (double)(toc - tic)/ CLOCKS_PER_SEC);
            printf("\n\n");
        // InsertionSort neste bloco
        } else if (op == 4) {
            clock_t tic = clock();
            insertionSort(num3, v);
            clock_t toc = clock();
            for(i = 0; i < 100; i++){
                printf("[%d]: %d\n", i, num3[i]);
            }
            printf("InsertionSort");
            printf("O tempo de execução foi de: %f segundos", (double)(toc - tic)/ CLOCKS_PER_SEC);
            printf("\n\n");
            
        } else if (op == 5) {
            Node *root = init();
            for(k = 0; k < 100; k++){
                root = arvInserir(root, itemCreate(num3[k]));
            }
            arvSaida(root);
            printf("Digite 1 para ver os elementos da árvore em ordem\n");
            scanf("%d", &op2);
            
            if(op2 == 1){
                insertionSort(num4, v);
                for(i = 0; i < 100; i++){
                    printf("%d\n", num4[i]);
                }
                printf("Merecemos os 5 pontos pra casa!\n");
            }
            arvLiberar(root);
        } else if (op == 6) {
            printf("Obrigado jogador, saindo... Da o 10 pra gente Fausto :D\n");
            break;
        }
    }
    return 0;
}