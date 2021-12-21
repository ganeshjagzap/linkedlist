/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include<iostream>
#include <string>

using namespace std;

class Node {
  public:
    int prn;
  string name;
  Node * next;

  Node() {
    prn = 0;
    name = "";
    next = NULL;
  }
  Node(int k, int d) {
    prn = k;
    name = d;
  }
};

class SinglyLinkedList {
  public:
    Node * head;

  SinglyLinkedList() {
    head = NULL;
  }
  SinglyLinkedList(Node * n) {
    head = n;
  }

  // 1. CHeck if node exists using key value
  Node * nodeExists(int k) {
    Node * temp = NULL;

    Node * ptr = head;
    while (ptr != NULL) {
      if (ptr -> prn == k) {
        temp = ptr;
      }
      ptr = ptr -> next;

    }
    return temp;
  }

  // 2. Append a node to the list
  void appendNode(Node * n) {
    if (nodeExists(n -> prn) != NULL) {
      cout << "Node Already exists with key value : " << n -> prn << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Appended" << endl;
      } else {
        Node * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        cout << "Node Appended" << endl;
      }
    }

  }
  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node * n) {
    if (nodeExists(n -> prn) != NULL) {
      cout << "Node Already exists with key value : " << n -> prn << ". Append another node with different Key value" << endl;
    } else {
      n -> next = head;
      head = n;
      cout << "Node Prepended" << endl;
    }
  }

  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {
      if (nodeExists(n -> prn) != NULL) {
        cout << "Node Already exists with key value : " << n -> prn << ". Append another node with different Key value" << endl;
      } else {
        n -> next = ptr -> next;
        ptr -> next = n;
        cout << "Node Inserted" << endl;
      }
    }
  }

  // 5. Delete node by unique key
  void deleteNodeByKey(int k) {
    if (head == NULL) {
      cout << "Singly Linked List already Empty. Cant delete" << endl;
    } else if (head != NULL) {
      if (head ->prn == k) {
        head = head -> next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      } else {
        Node * temp = NULL;
        Node * prevptr = head;
        Node * currentptr = head -> next;
        while (currentptr != NULL) {
          if (currentptr -> prn == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }
        if (temp != NULL) {
          prevptr -> next = temp -> next;
          cout << "Node UNLINKED with keys value : " << k << endl;
        } else {
          cout << "Node Doesn't exist with key value : " << k << endl;
        }
      }
    }

  }
  // 6th update node
  void updateNodeByKey(int k, string d) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr -> name = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }

  }

  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Singly Linked List";
    } else {
      cout << endl << "Singly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp -> prn << "," << temp -> name << ") --> ";
        temp = temp -> next;
      }
    }

  }
  void concate(SinglyLinkedList l1,SinglyLinkedList l2){
      Node*a=l1.head;
      Node*b=l2.head;
      while(true)
      {
          if(a->next==NULL){
           a->next=b;
           cout<<"concatenation occured"<<endl;
           break;
          }
          else{
              a=a->next;
          }
      }
      

  }

};

int main() {

  SinglyLinkedList s ,s1;
  int option;
  string name;
  int prn , k1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen"  << endl;
    cout<<"8. append node into second linked list"<<endl<<endl;
    cout<<"9 . concate both linked list"<<endl;

    cin >> option;
    Node * n1 = new Node();
 

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> k1;
      cin >> name;
      n1 -> prn = k1;
      n1 -> name = name;
      s.appendNode(n1);
    
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> k1;
      cin >> name;
      n1 -> prn = k1;
      n1 -> name = name;
      s.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> k1;
      cin >> name;
      n1 -> prn = k1;
      n1 -> name = name;

      s.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> k1;
      cin >> name;
      s.updateNodeByKey(k1, name);

      break;
    case 6:
      s.printList();

      break;
    case 7:
      system("cls");
      break;
    case 8:
     cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> k1;
      cin >> name;
      n1 -> prn = k1;
      n1 -> name = name;
      s1.appendNode(n1);
      case 9:
      s.concate(s,s1);
      s.printList();
      

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}