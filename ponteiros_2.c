#include <stdio.h>
#include <string.h>

/* gcc -g ponteiros_2.c -o ponteiros_2.exe */

/*
 * Ponteiros... Como usar.
 * 
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int eqpt_ftth_id;
} T_EQPT_FTTH_INFO;

typedef struct T_L_EQPT_FTTH_INFO{
  T_EQPT_FTTH_INFO eqpt_ftth_info;
  struct T_L_EQPT_FTTH_INFO *next;
} T_L_EQPT_FTTH_INFO;

void removeNode(T_L_EQPT_FTTH_INFO **headRef, int eqpt_ftth_id) {
    T_L_EQPT_FTTH_INFO *current = *headRef;
    T_L_EQPT_FTTH_INFO *previous = NULL;
    
    // Caso a lista esteja vazia
    if (current == NULL) {
        return;
    }

    // Caso o nó a ser removido seja o primeiro da lista
    if (current->eqpt_ftth_info.eqpt_ftth_id == eqpt_ftth_id) {
        *headRef = current->next;
        free(current); // Libera a memória do nó removido
        return;
    }

    // Percorre a lista para encontrar o nó a ser removido
    while (current != NULL && current->eqpt_ftth_info.eqpt_ftth_id != eqpt_ftth_id) {
        previous = current;
        current = current->next;
    }

    // Se o nó foi encontrado
    if (current != NULL) {
        previous->next = current->next; // Ajusta o ponteiro 'next' do nó anterior
        free(current); // Libera a memória do nó removido
    }
}

// Função auxiliar para criar um novo nó
T_L_EQPT_FTTH_INFO* createNode(int eqpt_ftth_id) {
	T_L_EQPT_FTTH_INFO *newNode = (T_L_EQPT_FTTH_INFO*)malloc(sizeof(T_L_EQPT_FTTH_INFO));
    if (newNode == NULL) {
        perror("Erro ao alocar memória para o nó");
        exit(EXIT_FAILURE);
    }
    newNode->eqpt_ftth_info.eqpt_ftth_id = eqpt_ftth_id;
    newNode->next = NULL;
    printf("Criando %p \n", newNode);
    return newNode;
}

void appendNode(T_L_EQPT_FTTH_INFO **headRef, int eqpt_ftth_id) {
    T_L_EQPT_FTTH_INFO *newNode = createNode(eqpt_ftth_id);
    
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    T_L_EQPT_FTTH_INFO *current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Função auxiliar para imprimir a lista (para demonstração)
void printList(T_L_EQPT_FTTH_INFO *head) {
    T_L_EQPT_FTTH_INFO *current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("Endereço (%p); id = %d -> ", current, current->eqpt_ftth_info.eqpt_ftth_id);
        current = current->next;
    }
    printf("NULL\n");
}

// Função para liberar a memória da lista
void freeList(T_L_EQPT_FTTH_INFO *head) {
    T_L_EQPT_FTTH_INFO *current = head;
    while (current != NULL) {
        T_L_EQPT_FTTH_INFO *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
	// head
    T_L_EQPT_FTTH_INFO *head = NULL;
    T_L_EQPT_FTTH_INFO *current = NULL;

    int data1 = 10, data2 = 20, data3 = 30;
    appendNode(&head, data1);
    appendNode(&head, data2);
    appendNode(&head, data3);

    printf("Lista head \n");
    printList(head);
    
    current = head;
    while (current != NULL) {
		printf("Buscando (id: %d):\n", current->eqpt_ftth_info.eqpt_ftth_id);
		if (current->eqpt_ftth_info.eqpt_ftth_id == 20) {
			// Anda antes de remover
			current = current->next;
			
			// remove
			printf("Removendo...\n");
			removeNode(&head, 20);
        } else {
          current = current->next;
	    }
    }
    //printf("\nRemovendo o nó com data = %d \n", data2);
    //removeNode(&head, data2);
    //printList(head);

    //printf("\nRemovendo o primeiro nó (data = %d):\n", data1);
    //removeNode(&head, data1);
    //printList(head);

    //printf("\nRemovendo o último nó (data = %d):\n", data3);
    //removeNode(&head, data3);
    printf("Lista head alterada\n");
    printList(head);
    
    

    // Não se esqueça de liberar a memória restante da lista quando terminar!
    freeList(head); // Importante liberar a memória

    return 0;
}
