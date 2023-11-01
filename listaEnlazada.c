#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo de la lista enlazada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Función para agregar un nodo al final de la lista
void append(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Función para eliminar un nodo por valor
void deleteByValue(Node** head, int value) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

// Función para agregar un nodo al inicio de la lista
void addToFront(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Función para buscar un nodo por su valor
void searchByValue(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            printf("El valor %d existe en la lista.\n", value);
            return;
        }
        current = current->next;
    }
    printf("El valor %d no existe en la lista.\n", value);
}

// Función para imprimir la lista
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Función para obtener el elemento enésimo
void getNElement(Node* head, int index) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            printf("Elemento en el índice %d: %d\n", index, current->data);
            return;
        }
        count++;
        current = current->next;
    }
    printf("No existe un elemento en el índice %d.\n", index);
}

// Función para liberar la memoria de la lista
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Agregar nodos
    append(&head, 10);
    append(&head, 18);
    append(&head, 20);
    append(&head, 28);

    // Imprimir lista
    printf("Lista: ");
    printList(head);

    // Eliminar un nodo por valor
    deleteByValue(&head, 20);
    printf("Después de eliminar el valor 20: ");
    printList(head);

    // Agregar un nodo al inicio
    addToFront(&head, 30);
    printf("Después de agregar 30 al inicio: ");
    printList(head);

    // Agregar un nodo al final
    append(&head, 38);
    printf("Después de agregar 38 al final: ");
    printList(head);

    // Buscar un nodo por valor
    searchByValue(head, 10000);

    // Obtener el elemento enésimo
    getNthElement(head, 2);

    // Liberar la memoria de la lista
    freeList(head);

    return 0 ;

}
