                                           

#include <bits/stdc++.h>

#define     ll                                 long long int   

#define     ll_in1(a)                          cin>>a

#define     ll_in2(a,b)                        cin>>a>>b

#define     ll_in3(a,b,c)                      cin>>a>>b>>c

#define     take_vector_int(x,o,n)             for(int i=o;i<=n;i++){cin>>x[i];}    
                 
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node(int data){
    this->data=data;
    this->next=NULL;
  }
  void inSertHead(Node* &head,int d)
  {
    Node* temp = new Node(d);
    temp->next = head;
    head=temp;

  }
  void inTail(Node* &tail,int d)
  {
    Node* temp = new Node(d);
    tail->next=temp;
    tail=tail->next;
  }

  void atPos(Node *head,int pos,int d)
  {
    Node* temp = head;
    Node* notun = new Node(d);
    int cnt=0;
    while (cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    notun->next = temp ->next;
    temp->next=notun;
  }

  void print(Node* &head){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    
}
};

int main()
{
   Node* ob = new Node(10);
   Node* head = ob;
   Node* Tail = ob;
   ob->inSertHead(head,20);
   ob->inSertHead(head,30);
   ob->inTail(Tail,5);
   ob->atPos(head,2,3);
   
   ob->print(head);

    return 0;
}
