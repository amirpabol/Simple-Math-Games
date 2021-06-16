#ifndef GROUPQUEUE_H
#define GROUPQUEUE_H
#include "Group.h"

class GroupQueue
{
    private:
        struct Queue
        {
            Group groupname;
            Queue *next;
        };
        Queue *front;
        Queue *rear;
        int count; 

    public:
        GroupQueue()
        {
            front = NULL;
            rear = NULL;
            count = 0;
        }
        void enqueue(Group name)
        {
            Queue *newnode;

            newnode = new Queue;
            newnode->groupname = name;
            newnode->next = nullptr;

            if(isEmpty())
            {
                front = newnode;
                rear = newnode;
            }
            else
            {
                rear->next = newnode;
                rear = newnode;
            }

            count++;
        }
        void dequeue(Group &name)
        {
            Queue *temp;

            if(isEmpty())
                cout<<"The queue is empty.\n";
            else
            {
                name = front->groupname;
                temp = front;
                front = front->next;
                delete temp;

                count--;
            }
        }
        bool isEmpty() const
        {
            bool status;

            if(count>0)
                status =false;
            else
                status = true;
            return status;
        }
        ~GroupQueue()
        {
            Group name;
            while(!isEmpty())
                dequeue(name);
        }
};
#endif