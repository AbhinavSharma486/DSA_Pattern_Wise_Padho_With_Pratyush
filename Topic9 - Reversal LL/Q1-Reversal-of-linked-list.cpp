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
  // previous hmesha null rhega
  // iss liye prev ko null kr diya hai
  Node *prev = NULL;

  // curr hmesha head pr rhega
  Node *curr = head;

  // jab tak current null nhi jo jata hai
  // tab tak while loop chlega
  while (curr != NULL)
  {
    // current ka next ko nex me store kr liya hai
    // taki baad me iss ko access kr ske
    Node *nex = curr->next;

    // current ka next ko previous me store kr diya hai
    curr->next = prev;

    // previous ko aage badha do jha abhi current hai
    prev = curr;

    // current ko bhe aage badhao
    curr = nex;
  }

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