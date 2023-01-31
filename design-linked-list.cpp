#include <bits/stdc++.h>
struct Node
{
    int data;
    Node *next;
};
class MyLinkedList
{
public:
    
    Node *head;
    MyLinkedList()
    {
        head = NULL;
    }
   
    int get(int index)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            if (count == index)
            {
                return temp->data;
            }
            count++;
            temp = temp->next;
        }
        return -1;
    }
    void addAtHead(int val)
    {
        Node *temp = new Node();
        temp->data = val;
        temp->next = head;
        head = temp;
    }
    void addAtTail(int val)
    {
        Node *temp = new Node();
        temp->data = val;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *temp1 = head;
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
    }
    void addAtIndex(int index, int val)
    {
        Node *temp = new Node();
        temp->data = val;
        temp->next = NULL;
        if (index == 0)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            Node *temp1 = head;
            int i;
            for (i = 0; i < index - 1; i++)
            {
                temp1 = temp1->next;
            }
            if(temp1 == NULL) return;
            temp->next = temp1->next;
            temp1->next = temp;
        }
    }
     void deleteAtIndex(int index)
    {
        Node *temp = head;
        if (index == 0)
        {
            head = temp->next;
            delete temp;
            return;
        }
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        if(temp == NULL || temp->next == NULL) return;
        Node *temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
    }
};