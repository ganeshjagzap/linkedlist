#include <iostream>
#include<string>
using namespace std;

class node
{
public:
    int prn;
    string name;
    node *next;
    node()
    {
        prn = 0;
        name = "";
        next = NULL;
    }
    node(int k, string n)
    {        
        prn = k;
        name = n;
    }
};

class singlylinkedlist
{
public:
    node *head;
    singlylinkedlist()
    {
        head = NULL;
    }
    singlylinkedlist(node *n)
    {
        head = n;
    }

    // 1. check whether node is present or not
    node *nodeexists(int k)
    {
        node *temp = NULL;
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->prn == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // 2. append node at end of the list
    void appendnode(node *n)
    {
        if (nodeexists((n->prn) == NULL))
        {
            cout << "this node is already exist in the list :" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "node appended " << endl;
            }
            else
            {
                node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "node appended " << endl;
            }
        }
    }
    // 3. prepend node
    void prependnode(node *n)
    {
        if (nodeexists((n->prn )!= NULL))
        {
            cout << "the node already exist " << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "node is prepende " << endl;
        }
    }

    // 4. insert node in between
    void insertnode(int k, node *n)
    {
        node *ptr = nodeexists(k);
        if (ptr == NULL)
        {
            cout << "no node exist with this key value " << k << endl;
        }
        else
        {

            if (nodeexists((n->prn) != NULL))
            {
                cout << "node already exsist so you can't insert node of this key value" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "node inserted" << endl;
            }
        }
    }
    //5. delete node
    void deletenode(int k)
    {

        if (head == NULL)
        {
            cout << "linkedlist is already empty " << endl;
        }
        else if (head != NULL)
        {
           if(head->prn==k){
                head = head->next;
            cout << "node deleted" << endl;
           }
            else
        {
            node *temp = NULL;
            node *prevptr = head;
            node *currentptr = head->next;
            while (currentptr != NULL)
            {
                if (currentptr->prn == k)
                {
                    temp = currentptr;
                    currentptr = NULL;
                }
                else
                {
                    currentptr = currentptr->next;
                    prevptr = prevptr->next;
                }
            }
            if (temp != NULL)
            {
                prevptr->next = temp->next;
                cout << "node deleted" << endl;
            }
            else
            {
                cout << "no does not exist " << endl;
            }
        }
       
        }
    }
    // 6. update node
    void updatenode(int k, string d)
    {
        node *ptr = nodeexists(k);
        if (ptr != NULL)
        {
            ptr->name = d;
            cout << "node updated" << endl;
        }
        else
        {
            cout << "node does not exist with this key value " << k << endl;
        }
    }
    // 7. display
    void display()
    {
        if (head == NULL)
        {
            cout << "no node exist" << endl;
        }
        else
        {
            cout << "the values are in the linked list are" << endl;
            node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->prn << " , " << temp->name << ")"
                     << "-->";
                temp=temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    singlylinkedlist s;
    int choice, prn;
    string name;
    do
    {
        cout << "which operation do you want to perform " << endl;
        cout << "0. exist()" << endl;
        cout << "1. append information" << endl;
        cout << "2. prepend information" << endl;
        cout << "3. insert information " << endl;
        cout << "4. delete information of perticular student" << endl;
        cout << "5. update information of perticular student" << endl;
        cout << "6. display information of all student " << endl;
        cout << "7. clear screen " << endl;

        node *n1 = new node();

        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
            cout << "enter the prn and name for the appending the information into the linkedlist" << endl;
            cin >> prn;
            cin >> name;
            n1->prn = prn;
            n1->name =name;
            s.appendnode(n1);
            break;
        case 2:
            cout << "enter the  prn and name for the prepending " << endl;
            cin >> prn;
            cin >> name;
            n1->prn = prn;
            n1->name = name;
            s.prependnode(n1);
            break;
        case 3:
            cout << "enter prn  and name for inserting in the linked list" << endl;
            cin >> prn;
            cin >> name;
            n1->name = name;
            n1->prn = prn;
            s.insertnode(prn, n1);
            break;
        case 4:
            cout << "enter the  prn for the deleting the information " << endl;
            cin >> prn;
            s.deletenode(prn);
            break;
        case 5:
            cout << "enter the prn  and  for name the updating the information of the student " << endl;
            cin >> prn;
            cin >> name;
            s.updatenode(prn, name);
            break;
        case 6:
            cout << "display funcion called \n"<< endl;
            s.display();
            break;
        case 7:
            system("cls");
            break;
        }

    } while (choice != 0);

    return 0;
}