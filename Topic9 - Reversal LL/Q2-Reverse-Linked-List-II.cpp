// * Question :- 92. Reverse Linked List II
// & Link :- https://leetcode.com/problems/reverse-linked-list-ii/description/

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
Node *reverseBetween(Node *head, int left, int right)
{
  if (head == NULL || head->next == NULL || left == right)
  {
    return head;
  }

  Node *temp = head;
  Node *before = NULL;
  int pos = 1;

  // neeche wala while loop jab tak chlega pos < left rhega
  while (pos < left)
  {
    // before or temp ko update krte rho jab tak pos == left nhi ho jata hai
    before = temp;
    temp = temp->next;
    pos++;
  }

  // jb pos == left ho jayega
  // iss ka matlab hai ke ab below condition run hogi
  // ab current aa gya hai temp pr
  Node *curr = temp;
  // abhi previous ko null kr diya hai
  Node *prev = NULL;

  // times ka matlab hai ke kitne bar reverse krna hai
  int times = right - left + 1;

  // jab tak times 0 nhi ho jata hai tab tak yeh while loop chlega
  while (times--)
  {
    // yeh below code reverse krta hai
    Node *nex = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nex;
  }

  // edge case :
  // aisa ho skta hai ke left = 1 diya ho
  // means head ko uss ke previous se attach he na krna pde
  if (before)
  {
    before->next = prev;
  }
  else
  {
    head = prev;
  }

  temp->next = curr;

  return head;
}

int main()
{
  Node *n1 = new Node(10);
  Node *n2 = new Node(20);
  Node *n3 = new Node(30);
  Node *n4 = new Node(40);
  Node *n5 = new Node(50);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  Node *head = n1;
  int left = 2, right = 4;

  // reverse the list
  head = reverseBetween(head, left, right);

  // IMPORTANT: temp ko new head pe set karo
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }

  return 0;
}