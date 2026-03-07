// * Question :- 206. Reverse Linked List
// & Link :- https://leetcode.com/problems/reverse-linked-list/description/

#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

Node *reverseList(Node *head)
{
  // prev me NULL store kro 
  Node *prev = NULL;

  // curr me head store kro
  Node *curr = head;

  // jab tak curr NULL nhi ho jaye tab tak
  while (curr != NULL)
  {
    // nex me current ka next store kr liya hai taki baad me use kr ske
    Node *nex = curr->next;

    // current ke next me previous store kr diya hai 
    // taki current apne next ko point na kr ske 
    // apne previous ko point kre
    curr->next = prev;

    // previous me current store kro
    prev = curr;

    // current me next store kr diya hai
    curr = nex;
  }

  // previous ko return kr diya hai kyuki current to Null ho gya hai 
  return prev;
}

int main()
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  Node *head = n1;

  // reverse the list
  head = reverseList(head);

  // IMPORTANT: temp ko new head pe set karo
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }

  cout << "NULL";

  return 0;
}