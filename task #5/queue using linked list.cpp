//Group names: Omar Ghalib, Laila Mohamed, Emad Farahat, Kyrillos Tharwat
//Implementation of queue using dynamic linked list

#include <iostream>
using namespace std;
class node
{
    int data;
    node*next;
public:
    node(){};
    int get_data()
    {
        return(data);
    }
    node*get_next()
    {
        return(next);
    }
    void set_data(int x)
    {
        data = x;
    }
    void set_next(node*n)
    {
        next = n;
    }
};
class Queue
{
    node*Front;
    node*Rear;
public:
    Queue()
    {
        node*new_node = new node;
        Rear = new_node;
        Front = new_node;
    }
    void enqueue(int x)
    {
        Rear->set_data(x);
        node*new_node = new node;
        Rear->set_next(new_node);
        Rear = new_node;
    }
    bool Is_empty()
    {
        return(Rear==Front);
    }
    int dequeue()
    {
        if(Is_empty())
        {
            cout<<"Empty Queue.\n";
            return(-1);
        }
        node*tmp = Front;
        Front = Front->get_next();
        int data = tmp->get_data();
        delete tmp;
        return(data);
    }
};
int main()
{
    Queue trial;
    trial.enqueue(10);
    trial.enqueue(200);
    trial.enqueue(5);
    while(!trial.Is_empty())
    cout<<trial.dequeue()<<'\n';
    cout<<trial.dequeue();
    return 0;
}
