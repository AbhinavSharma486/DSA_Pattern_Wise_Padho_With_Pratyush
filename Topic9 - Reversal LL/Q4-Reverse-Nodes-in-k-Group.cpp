// * Question :- 25. Reverse Nodes in k-Group
// & Link :- https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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

// reverse ka code
Node *reverse(Node *head, int size)
{
  Node *curr = head;
  Node *prev = NULL;

  while (size--)
  {
    Node *nex = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nex;
  }

  return prev;
}

Node *reverseKGroup(Node *head, int k)
{
  int size = k;
  // Case1: agar list ka head NULL hai to kuch nhi krna hai
  // return head kr do bss
  if (head == NULL)
  {
    return head;
  }

  // Case2: jab list ka head NULL na ho
  Node *left = head;
  Node *right;
  Node *res = NULL;
  Node *prevLeft = NULL;

  // jab tak left null nhi ho jata
  while (true)
  {
    // har iteration me naya group start hoga
    // iss liye right me left ko store kr diya hai
    right = left;

    // Case3: group find krna hai
    // yha check ho rha hi ke given size ke barabar ka group exists krta hai ya nhi
    for (int i = 0; i < size - 1; i++)
    {
      // agar right null jo jaye
      // then iss ka matlab hai ke group incomplete hai
      // iss liye break kr do
      if (right == NULL)
      {
        break;
      }

      // right ko aage badhao taki next group check kr ske
      right = right->next;
    }

    // Case4: Valid group mil gya hai
    if (right)
    {
      // next group ka start nextLeft me store kr diya hai
      Node *nextLeft = right->next;

      // current group reverse kr diya hai
      reverse(left, size);

      // SubCase1: agar previous group exists krta hai to connect kro
      if (prevLeft)
      {
        prevLeft->next = right;
      }

      // -- IMPORTANT : current group ka end update kro
      // reverse ke baad 'left' end ban gya hai
      // iss ko next iteration ke liye store krna pdega
      prevLeft = left;

      // current group ka start ko final answer ka head bna do
      if (res == NULL)
      {
        res = right;
      }

      // next group pr move kro
      left = nextLeft;
    }

    // Case5: Invalid group mil gya hai
    else
    {
      // agar remaining nodes size se chote hai -> reverse nhi krna hai

      // previous group ke end ko directly attach kro
      if (prevLeft)
      {
        prevLeft->next = left;
      }

      // agar pehle group hi invalid tha to res me store kro
      if (res == NULL)
      {
        res = left;
      }

      // agar remaining nodes size se chote hai -> reverse nhi krna hai
      break;
    }
  }

  return res;
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
  int k = 3;

  // reverse the list
  head = reverseKGroup(head, k);

  // IMPORTANT: temp ko new head pe set karo
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " -> ";
    temp = temp->next;
  }

  return 0;
}