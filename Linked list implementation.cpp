//Group names: Omar Ghalib, Laila Mohamed, Emad Farahat, Kyrillos Tharwat
//Linked list implementation and data of type student
#include <iostream>
using namespace std;
struct student
    {
        int id;
        string name;
        float grade;
    };
class node
{
    student data;
    node*next;
public:
    node(){};
    void set_data(student c)
    {
        data = c;
    }
    void set_next(node*n)
    {
        next = n;
    }
    student get_data()
    {
        return(data);
    }
    node*get_next()
    {
        return(next);
    }
};

class linked_list
{
    node*head;
public:
    linked_list()
    {head=NULL;}
    void insert_first(student data)
    {
        //insert node at the beginning of the list
        node*new_node = new node;
        new_node->set_data(data);
        new_node->set_next(head);
        head = new_node;
    }
    void insert_last(student data)
    {
        //insert a node at the end of the list
        node*new_node = new node;
        new_node->set_data(data);
        new_node->set_next(NULL);
        if(head==NULL)
            head = new_node;
        else
        {
            node*tmp = head;
            while(tmp->get_next()!=NULL)
                tmp = tmp->get_next();
            tmp->set_next(new_node);
        }
    }
    void insert_after_certain_node(student data_inserted,student data_predloc)
    {
        if(head==NULL)
        {
            cout<<"Empty list!\n";
            return;
        }
        node*tmp = head;
        while(tmp->get_data().id!=data_predloc.id&&tmp->get_data().name!=data_predloc.name&&tmp->get_data().grade!=data_predloc.grade)
        {
            tmp = tmp->get_next();
            if(tmp==NULL)
            {
                cout<<"Data to insert after not found.\n";
                return;
            }
        }
        node*new_node = new node;
        new_node->set_data(data_inserted);
        new_node->set_next(tmp->get_next());
        tmp->set_next(new_node);
    }
    void delete_head()
    {
        //delete head node
        if(head==NULL)
        {
            cout<<"Empty list.\n";
            return;
        }
        node*tmp = head;
        head = head->get_next();
        delete tmp;
    }
    void delete_last()
    {
        if (head==NULL)
        {
            cout<<"Empty list!";
            return;
        }
        if(head->get_next()==NULL)
        {
            node*tmp=head;
            head=NULL;
            delete tmp;
            return;
        }
        node*cur = head;node*prev;
        while(cur->get_next()!=NULL)
        {
            prev = cur;
            cur = cur->get_next();
        }
        prev->set_next(NULL);
        delete cur;
    }
    void delete_node(student data)
    {
        //Delete a certain node with known data
        if(head==NULL)
        {
            cout<<"Empty list\n";
            return;
        }
        if(head->get_data().id==data.id&&head->get_data().name==data.name&&head->get_data().grade==data.grade)
        {
            node*cur = head;
            head = head->get_next();
            delete cur;
            return;
        }
        node*cur = head;
        node*prev;
        while(cur->get_data().id!=data.id&&cur->get_data().name!=data.name&&cur->get_data().grade!=data.grade)
        {
            prev = cur;
            cur = cur->get_next();
            if (cur==NULL)
            {
                cout<<"Data not found";
                return;
            }
        }
        prev->set_next(cur->get_next());
        delete cur;
    }
    void print_list()
    {
        node*tmp = head;
        if(head==NULL)
        {
            cout<<"Empty list !\n";
            return;
        }
        while(tmp!=NULL)
        {
            cout<<"student id: "<<tmp->get_data().id<<"\tname: "<<tmp->get_data().name<<"\tgrade: "<<tmp->get_data().grade<<'\n';
            tmp = tmp->get_next();
        }
        cout<<"NULL\n";
    }
};
int main()
{
    student a = {1,"Ahmed",50};
    student b = {2,"Ali",40};
    student c = {3,"Ibrahim",45};
    linked_list trial;
    trial.insert_last(a);
    trial.insert_last(b);
    trial.insert_last(c);
    cout<<"list after inserting last a,b,c:\n ";
    trial.print_list();
    trial.delete_head();
    cout<<"list after deleting head : \n";
    trial.print_list();
    cout<<"list after inserting first a :\n";
    trial.insert_first(a);
    trial.print_list();
    trial.delete_node(b);
    cout<<"list after deleting b : \n";
    trial.print_list();
    trial.insert_after_certain_node(b,a);
    cout<<"list after inserting b after a: \n";
    trial.print_list();
    trial.delete_last();
    cout<<"list after deleting last element: \n";
    trial.print_list();
    return 0;
}
