#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insertAtHead(Node* &head,Node*& tail,int data){//by reference because i want changes in ll
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    //step1 : create a node
    Node*newNode=new Node(data);
    //step 2 : connect it
    newNode->next=head;
    //step3 : change the head
    
    head=newNode;
}
void insertAtTail(Node*& head,Node*& tail,int data){
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node*newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;
}
int main() {
    Node*head=NULL; 
    //head node null hote hi 
    Node*tail=NULL;
    insertAtHead(head,tail,20);
    insertAtTail(head,tail,77);
    print(head);


}
