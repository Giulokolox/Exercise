#include "raylib.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct list_node
{
    int data;
    unsigned int count;
    struct list_node *prev;
    struct list_node *next;
}Node;

//it is used to keep the count of the list, if I remove an element in the list it recalculates 
void list_count(Node **head) 
{
    int count = 0;
    Node *current_node = *head;
    while (current_node != NULL)
    {
        current_node->count = count;
        current_node = current_node-> next;
        count++;
    }
    
}

// to give the list a tail
Node *list_get_tail(Node **head)
{
    Node *current_node = *head;
    Node *last_node = NULL;
    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

Node *list_append (Node **head, Node *item) //oltre al next c è anche il prev da calcolare
{
    Node *tail = list_get_tail (head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    list_count(head);
    return item;
}

//remove a piece on the list
void list_remove(Node **head, int num)
{
    Node *current_node = *head;
    Node *prev_node = NULL;
    Node *next_node = NULL;
    Node *tail = list_get_tail (head);
    if (current_node != NULL && current_node->data == num)
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(current_node);
        return;
    }
    while (current_node && current_node->data != num)
    {
        current_node = current_node->next;
    }

    if (current_node == NULL)
    {
        printf("Data not found\n");
        return;
    }
    prev_node = current_node->prev;
    next_node = current_node->next;
    if (next_node == NULL)
    {
        prev_node->next = NULL;
    }
    else
    {
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }    
    free(current_node);
    list_count(head);
    return;
}
//to create node 
int create_node(Node **head, int num, int count)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = num;
    node->count = count;
    list_append(head, node);
    count++;
    return count;
}

//to print the list but in reverse
void list_print(Node **head)
{
    Node *current_node = *head;
    printf("\n");
    while (current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

//to add a node after the indicated node
void list_append_After (Node **head, int item, int num)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = num;
    Node *current_node = *head;
    Node *next_node = NULL;
    Node *tail = list_get_tail (head);
    if (tail != NULL && tail->data == item)
    {
        tail->next = node;
        node->prev = tail;
        node->next = NULL;
        list_count(head);
        return;
    }
    while (current_node != NULL && current_node->data != item)
    {
        current_node = current_node->next;
    }
    if (current_node == NULL)
    {
        printf("\n element not found");
        return;
    }

    next_node = current_node->next;
    node->prev = current_node;
    current_node->next = node;
    node->next = next_node;
    next_node->prev = node;
    list_count(head);
    return;

}

//to add a node before the indicated node
void list_append_Before (Node **head, int item, int num)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = num;
    Node *current_node = *head;
    Node *prev_node = NULL;
    Node *tail = list_get_tail (head);
    if (current_node != NULL && current_node->data == item)
    {
        prev_node = current_node;
        *head = node;
        node->prev = NULL;
        node->next = prev_node;
        prev_node->prev = node;
        list_count(head);
        return;
    }

    while (current_node != NULL && current_node->data != item)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL)
    {
        printf("\n element not found");
        return;
    }
    current_node->prev = node;
    node->next = current_node;
    prev_node->next = node;
    node->prev = prev_node;
    list_count(head);
    return;

}

//list shuffle method
void list_shuffle(Node **head, int num)
{
    Node *tail = list_get_tail(head);
    int count = tail->count;

    for (int i = 0; i < num; i++)
    {
        int firstNodeCount = GetRandomValue(0, count);
        int secondNodeCount;

        do {
            secondNodeCount = GetRandomValue(0, count);
        } while (secondNodeCount == firstNodeCount);

        Node *firstNode = NULL, *secondNode = NULL;

        // Find the first node
        Node *current_node = *head;
        while (current_node && current_node->count != firstNodeCount)
        {
            firstNode = current_node;
            current_node = current_node->next;
        }

        // Find the second node
        current_node = *head;
        while (current_node && current_node->count != secondNodeCount)
        {
            secondNode = current_node;
            current_node = current_node->next;
        }

        // Swap the nodes
        if (firstNode && secondNode && firstNode != secondNode)
        {
            // Update previous pointers
            if (firstNode->prev)
                firstNode->prev->next = secondNode;
            else
                *head = secondNode;

            if (secondNode->prev)
                secondNode->prev->next = firstNode;
            else
                *head = firstNode;

            // Update next pointers
            if (firstNode->next)
                firstNode->next->prev = secondNode;
            
            if (secondNode->next)
                secondNode->next->prev = firstNode;

            // Swap prev pointers
            Node *tempPrev = firstNode->prev;
            firstNode->prev = secondNode->prev;
            secondNode->prev = tempPrev;

            // Swap next pointers
            Node *tempNext = firstNode->next;
            firstNode->next = secondNode->next;
            secondNode->next = tempNext;
        }

        list_count(head);
        list_print(head);
    }
}

int main(int argc, char** argv)
{
    int num;
    int listCount = 0;
    time_t unixTime;
    time(&unixTime);
    SetRandomSeed(unixTime);

    Node *head = NULL;
    listCount = create_node(&head, 1, listCount);
    listCount = create_node(&head, 2, listCount);
    listCount = create_node(&head, 3, listCount);
    listCount = create_node(&head, 4, listCount);
    listCount = create_node(&head, 5, listCount);
    listCount = create_node(&head, 6, listCount);

    list_print(&head);
    printf("\nInsert the number that you want to remove: ");
    scanf_s("%d", &num);
    list_remove(&head, num);
    list_print(&head);
    printf("\n Add an element after another: ");
    list_append_After(&head, 5, 3);
    list_print(&head);
    printf("\n Add an element before another: ");
    list_append_Before(&head, 1, 0);
    list_print(&head);
    printf("\n");
    list_shuffle(&head, 4);

    return 0;
}
