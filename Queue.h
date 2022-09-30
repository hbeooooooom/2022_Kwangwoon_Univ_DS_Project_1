#ifndef QUEUE_H
#define QUEUE_H
#include"ImageNode.h"
#ifndef NULL
#define NULL    0
#endif
// This queue is Refernce code (Do Not Use directly)
template<class T> class Queue
{
public:
    int front;
    int rear;
    int size; //Free to define (recommand 100 or 200)
    T *val;

    Queue(){
        val = new T[size];
        //Needs extra init
    }
    ~Queue()
    {
        delete[] val;
    }

    void push(T value) {
        // input data
    }

    void pop() {
        //Change Front
    }

    bool empty() {
        //Check its empty or not
    }

    bool isFull() {
        //Check queue is full or not
    }
};
class Loaded_List{
    private:
     Loaded_List_Node* head;

     public:
     void make_list(string name, string num);//make liked list
}


#endif
