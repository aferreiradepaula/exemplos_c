#include <stdio.h>
#include <string.h>

/* gcc -g ponteiros.c -o ponteiros.exe */

/*
 * Ponteiros... Como usar.
 * 
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    void *data; // Ponteiro para os dados armazenados
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void removeNode(LinkedList *list, Node *nodeToRemove) {
    if (list == NULL || list->head == NULL || nodeToRemove == NULL) {
        return; // Lista vazia ou nó inválido
    }

    Node *current = list->head;
    Node *previous = NULL;

    // Caso o nó a ser removido seja o primeiro da lista
    if (current == nodeToRemove) {
        list->head = current->next;
        free(current); // Libera a memória do nó removido
        return;
    }

    // Percorre a lista para encontrar o nó a ser removido
    while (current != NULL && current != nodeToRemove) {
        previous = current;
        current = current->next;
    }

    // Se o nó foi encontrado
    if (current == nodeToRemove) {
        previous->next = current->next; // Ajusta o ponteiro 'next' do nó anterior
        free(current); // Libera a memória do nó removido
    }
    // Se o nó não foi encontrado, não faz nada
}

// Função auxiliar para criar um novo nó
Node* createNode(void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Erro ao alocar memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função auxiliar para imprimir a lista (para demonstração)
void printList(LinkedList *list) {
    Node *current = list->head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%p -> ", current->data); // Imprime o endereço dos dados
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList myList;
    myList.head = NULL;

    int data1 = 10, data2 = 20, data3 = 30;
    Node *node1 = createNode(&data1);
    Node *node2 = createNode(&data2);
    Node *node3 = createNode(&data3);

    myList.head = node1;
    node1->next = node2;
    node2->next = node3;

    printf("Lista original:\n");
    printList(&myList);

    printf("\nRemovendo o nó com data = %d (endereço %p):\n", data2, &data2);
    removeNode(&myList, node2);
    printList(&myList);

    printf("\nRemovendo o primeiro nó (data = %d, endereço %p):\n", data1, &data1);
    Node *headToRemove = myList.head;
    if (headToRemove != NULL) {
        removeNode(&myList, headToRemove);
    }
    printList(&myList);

    printf("\nRemovendo o último nó (data = %d, endereço %p):\n", data3, &data3);
    // Para remover o último nó, precisamos encontrá-lo
    Node *current = myList.head;
    Node *lastNode = NULL;
    if (current != NULL) {
        while (current->next != NULL) {
            current = current->next;
        }
        lastNode = current;
    }
    if (lastNode != NULL) {
        removeNode(&myList, lastNode);
    }
    printList(&myList);

    // Não se esqueça de liberar a memória restante da lista quando terminar!
    Node *currentFree = myList.head;
    while (currentFree != NULL) {
        Node *temp = currentFree;
        currentFree = currentFree->next;
        free(temp);
    }

    return 0;
}
