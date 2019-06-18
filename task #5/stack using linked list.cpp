//Group names: Omar Ghalib, Laila Mohamed, Emad Farahat, Kyrillos Tharwat
//Implementation of stack using dynamic linked list

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
class Stack
{
    node*top;
public:
    Stack()
    {
        top=NULL;
    }
    bool is_empty()
    {
        return(top==NULL);
    }
    void push(int x)
    {
        node*new_node = new node;
        new_node->set_data(x);
        new_node->set_next(top);
        top = new_node;
    }
    int pop()
    {
        if(is_empty())
        {
            cout<<"Stack underflow";
            return(-1);
        }
        node*tmp = top;
        int data= tmp->get_data();
        top = top->get_next();
        delete tmp;
        return(data);
    }
    void make_empty()
    {
        node*tmp;
        while(top!=NULL)
        {
            tmp = top;
            top= top->get_next();
            delete tmp;
        }
    }
};
int main()
{
    Stack trial;
    trial.push(10);
    trial.push(50);
    trial.push(60);
    cout<<trial.pop()<<'\n';
    trial.make_empty();
    cout<<trial.pop();
    return 0;
}
