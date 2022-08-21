#include <iostream>

using namespace std;

//1- Queue with Linked List

class Node
{
public:
    int data;
    Node* next;
public:
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class QueueLinkedList
{
private:
    Node* fronte;
    Node* rear;
public:
    QueueLinkedList()
    {
        fronte = rear = NULL;
    }

    bool isempty()
    {
        return fronte == NULL;
    }

    void enqueue(int item)
    {
        Node* newnode = new Node(item);

        if(isempty())
            fronte = rear = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void display()
    {
        if(isempty())
        {
            cout << "the queue is empty, no items to display\n";
            return;
        }

        Node* temp = fronte;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";

    }

    int dequeue()
    {
        int dv;
        if(isempty())
        {
            cout << "queue is empty\n";
            dv = -1;
        }
        else if(fronte == rear)
        {
            dv = fronte->data;
            Node* del = fronte;
            fronte = rear = NULL;
            delete del;
        }
        else
        {
            Node* delptr = fronte;
            dv = fronte->data;
            fronte = fronte->next;
            delete delptr;
        }
        return dv;

    }

    int peek() {return fronte->data;}
    int backe() {return rear->data;}

    int counte()
    {
        int c = 0;

        if(isempty())
            return 0;

        Node* temp = fronte;
        while(temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }

    bool isfound(int k)
    {
        if(isempty())
        {
            cout << "empty\n";
            return false;
        }

        Node* temp = fronte;
        while(temp != NULL)
        {
            if(temp->data == k)
                return true;
            else
                temp = temp->next;
        }
        return false;
    }

    void cleare()
    {
        while(!isempty())
        {
            dequeue();
        }
    }

    bool isfull()
    {
        Node* newnode = new Node(0);
        if(newnode == NULL)
            return true;
        else
            return false;
    }

};
//-----------------------------------------//

//2- Queue with array
const int sizing = 20;

class QueueArray
{
private:
    int first;
    int last;
    int len;
    int items[sizing];
public:
    QueueArray()
    {
        first = last = len = 0;
    }

    bool isempty()
    {
        return len == 0;
    }

    bool isfull()
    {
        return len == sizing;
    }

    void enqueue(int item)
    {
        if(isempty())
        {
            items[last] = item;
        }
        else
        {
            last++;
            items[last] = item;
        }
        len++;
    }

    void dequeue()
    {
        if(isempty())
        {
            cout << "queue is empty\n";
            return;
        }

        first++;
    }

    int peek(){return items[first];}
    int backitem(){return items[last];}

    void display()
    {
        for(int i = first; i <= last; i++)
            cout << items[i] << " ";
        cout << "\n";
    }
};

//-------------------------------------------//
//3- Circular queue with array

class CirQueue
{
private:
    int siz;
    int length;
    int fronte;
    int rear;
    int* items;
public:
    CirQueue(int as)
    {
        siz = as;
        length = 0;
        fronte = 0;
        rear = as - 1;
        items = new int[siz];
    }

    bool isempty()
    {
        return length == 0;
    }

    bool isfull()
    {
        return length == siz;
    }

    void enqueue(int k)
    {
        if(isfull())
        {
            cout << "queue is full\n";
            return;
        }

        /*if(isempty())
        {
            items[fronte] = k;
            rear = (rear+1) % siz;
            length++;
            return;
        }*/

        rear = (rear + 1) % siz;
        items[rear] = k;
        length++;
    }

    void dequeue()
    {
        if(isempty())
        {
            cout << "queue is empty\n";
            return;
        }

        fronte = (fronte + 1) % siz;
        length--;
    }

    int getfront()
    {
        return items[fronte];
    }

    int getrear()
    {
        return items[rear];
    }

    void display()
    {
        if(fronte < rear)
        {
            for(int i = fronte; i < rear+1; i++)
                cout << items[i] << " ";
            cout << "\n";
            return;
        }
        else if(fronte > rear)
        {
            for(int i = fronte; i != rear+1; i = (i+1)%siz)
                cout << items[i] << " ";
            cout << "\n";
            return;
        }
        else
            cout << items[fronte] << endl;
    }

    int searche(int k)
    {
        int index = -1;
        for(int i = fronte; i != rear+1; i = (i+1)%siz)
        {
            if(items[i] == k)
            {
                index = i;
                break;
            }
        }
        return index;
    }


};

int main()
{
    CirQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();
    cout << "\n";

    q.dequeue();
    q.display();

    cout << q.searche(10) << endl;
    cout << q.searche(20) << endl;
    //-----------------------------//

    QueueLinkedList qls;

    qls.enqueue(1);
    qls.enqueue(2);
    qls.enqueue(3);
    qls.enqueue(4);

    qls.display();
    qls.dequeue();
    qls.display();
    cout << qls.isfound(2) << endl;
    //-----------------------------------------//

    QueueArray qarr;

    qarr.enqueue(100);
    qarr.enqueue(200);
    qarr.enqueue(300);
    qarr.enqueue(400);

    qarr.display();
    qarr.dequeue();
    qarr.display();
    cout << qarr.peek() << endl;
    cout << qarr.backitem();
    return 0;
}
