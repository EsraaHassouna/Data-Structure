#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};

typedef struct LinkedList
{
    Node *head, *tail;

}LinkedList;

Node *head = NULL, *tail = NULL;


void Add(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->Next = newNode;
        newNode->Prev = tail;
        tail = newNode;
    }
}

void Display()
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d   ", current->Data);
        current = current->Next;
    }
}

Node* GetNodeByData(int data)
{
    Node *current = head;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        current = current->Next;
    }

    return NULL;
}

void Remove(int data)
{
    Node *node = GetNodeByData(data);

    if(node == NULL)
        return;

    if(node == head)
    {
        if(head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->Next;
            head->Prev = NULL;
        }
    }
    else if(node == tail)
    {
        tail = tail->Prev;
        tail->Next = NULL;
    }
    else
    {

        node->Prev->Next = node->Next;
        node->Next->Prev = node->Prev;
    }

    free(node);
}

void InsertAfter(int data, int afterData){

    Node *node = GetNodeByData(afterData);

    if (node == head||node == tail){
        Add(data);

    }else {
        Node *newNode = malloc(sizeof(Node));
        newNode->Data = data;
        newNode->Prev = newNode->Next = NULL;

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->Next = node->Next;
            node->Next->Prev = newNode;
            node->Next = newNode;
            newNode->Prev = node;
        }

    }
};

int GetCount(){

    Node *current = head;
    int i=0;

        while(current != NULL)
        {
            current = current->Next;
            i++;
        }

    return i;
};

int GetDataByIndex(int index){

    Node *current = head;
    int i;

    int len =GetCount();

    if (len>index && index>=0){
        for(i=0;i<index;i++)
        {
            current = current->Next;
        };

        printf("\n%d",current->Data);

        return 1;

    }else{

        printf("undefined");

        return 0;
    }

};

#endif // LINKEDLIST_H
