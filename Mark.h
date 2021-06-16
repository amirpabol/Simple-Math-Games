#ifndef MARK_H
#define MARK_H
#include<iostream>
#include "Score.h"

//template <class T>
/*
class StackNode{
        public:

        int currentScore; // Value in the node
        StackNode *next; // Pointer to the next node

        StackNode(int)
        {
            currentScore = 0;
            next=nullptr;
        }
        ~StackNode(){};
        
};*/

//template <class T>
class Stack{
    private:
        struct StackNode{
        Score currentscore; // Value in the node
        StackNode *next; // Pointer to the next node
        };

        StackNode *Top; // Pointer to the stack top

    public:
        
        Stack(){ Top = nullptr;}
        ~Stack();

        bool isEmpty();
        void push(Score);
        void pop(Score &);

};
#endif