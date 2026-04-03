// * Question :- 61. Rotate List
// & Link :- https://leetcode.com/problems/rotate-list/description/

#include <iostream>
#include <vector>
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
Node *rotateRight(Node *head, int k)
{
  // agar head == NULL hai to kuch nhi krna hai
  if (head == NULL)
  {
    return head;
  }

  // list ke size ko find krna hai
  Node *last = head;
  int n = 1;

  // jab tak last ka next null nhi ho jata hai tab tak yeh loop chlega
  // or n ko increase krta rhega
  // or last ko aage badhata rhega
  while (last->next != NULL)
  {
    n++;
    last = last->next;
  }

  // given k ko n se mod kr do
  // taki agar k > n se to bhe shi answer mile
  k = k % n;

  // or agar k == 0 hai to kuch nhi krna hai
  if (k == 0)
  {
    return head;
  }

  // last ke next ko head se connect kro
  last->next = head;

  // new head ko find kro
  int count = 1;
  Node *t = head;

  while (t != NULL)
  {
    if (count == n - k)
    {
      break;
    }
    count++;

    t = t->next;
  }

  // new head ko store kr lo
  Node *res = t->next;

  // new tail ke next ko null kr do
  t->next = NULL;

  // new head ko return kr diya hai
  return res;
};
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
  int k = 2;

  // rotate list by k places
  head = rotateRight(head, k);

  // IMPORTANT: temp ko new head pe set kro
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }

  return 0;
}