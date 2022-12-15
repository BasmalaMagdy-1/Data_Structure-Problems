

#include <iostream>
using namespace std;
template<class T>
class Node
{

public:
    T data;
    Node * next;

    Node(T data)
    {
        next=NULL;
        this->data=data;
    }

};

template<class T>

class queue
{
    Node<T> *head,*tail;
    int siz;
public:
    queue()
    {
        head=tail=NULL;
        siz=0;
    }
    queue(const queue <T> &q)
    {
        head= q.head;
        tail=q.tail;
    }
    void push(T data)
    {
        Node<T>* temp=new Node<T>(data);

        //if the queue is empty make head and tail pointing to the new node
        if(tail==NULL)
        {
            head=tail=temp;

        }
            /*if queue wasn't empty
             * we make new node make last node pointing to it
             * make tail pointing to this node
             */
        else
        {
            tail->next=temp;
            tail=temp;
        }
        siz++;

    }
    void push(Node<T>* n)
    {
        if(tail==NULL)
        {
            head=tail=n;

        }
        else
        {
            tail->next=n;
            tail=n;
        }
        siz++;
    }


    Node<T>* pop()
    {
        //if queue is empty cout massage
        if(head==NULL)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            //store previous head in tep nod and move head to next node then delete temp(previous head)
            Node<T>* temp;
            temp=head;
            head=head->next;

            //If front becomes NULL so the queue becomes empty so we make the tail equal null
            if(head==NULL)
            {
                tail=NULL;
            }
            temp->next=NULL;
            delete temp;

        }


        siz--;

    }

    bool isFull()
    {
        return false;
    }

    bool empty()
    {
        if(head==tail&&head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        return siz;
    }

    T front()
    {
        return head->data;
    }
    T back()
    {
        return tail->data;
    }





};



template<class T>
class stack
{
queue<T>q;
public:
    void push(T data)
    {
        q.push(data);
        int size=q.size();

        for(int i=0;i<size-1;i++)
        {
            int temp=q.front();
            q.push(temp);
            q.pop();

        }
    }

    void pop()
    {
        if(q.empty())
        {
            cout<<"No elements to pop"<<endl;
        }
        else
        {
            q.pop();
        }
    }
    int top()
    {
        if(q.empty())
        {
            cout<<"Empty stack :)"<<endl;
            return 0;
        }
        else
        {
            return q.front();
        }
    }

    bool empty()
    {
        return q.empty();
    }
    int size()
    {
        return q.size();
    }

};

int main()
{

stack<int >s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(100);
s.push(500);
s.pop();
s.pop();
cout<<s.top()<<endl;

}