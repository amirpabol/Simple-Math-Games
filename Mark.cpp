#include<iostream>
#include "Mark.h"

using namespace std;

//template <class T>
Stack::~Stack(){

StackNode *nodePtr = nullptr;
StackNode *nextNode = nullptr;

nodePtr = Top;
while (nodePtr != NULL) //while there are elements in the stack
{
    nextNode = nodePtr->next; //set temp to point to the current node
    delete nodePtr; //advance stackTop to the next node
    nodePtr = nextNode;//deallocate memory occupied by temp
}
}

//template <class T>
bool Stack::isEmpty()
{
    bool status;

    if(!Top)
        status = true;
    else
        status = false;

    return status;
}

//template <class T>
void Stack::push(Score newScore)
{
    StackNode *newNode =  nullptr;

    newNode =new StackNode;
    newNode->currentscore = newScore;

    if(isEmpty())
    {
        Top = newNode;
        newNode->next=nullptr;
    }
    else
    {
        newNode->next=Top;
        Top=newNode;
    }
}

//template <class T>
void Stack::pop(Score &newScore)
{
    StackNode *temp=nullptr;

    if(isEmpty())
    {
        cout<<"The answer is empty."<<endl;
    }
    else
    {
        newScore = Top->currentscore;
        temp = Top->next;
        delete Top;
        Top = temp;
    }
}