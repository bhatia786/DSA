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
    ~Node(){
    cout<<"Node deleted:"<<this->data<<endl;
    }
};
int printlen(Node*& head){
    Node*temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void print(Node*& head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insertAtHead(Node*& head,Node*& tail,int data){
    if(head==NULL){ //first node adding
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node*newNode=new Node(data);
    newNode->next=head;
    head=newNode;
}
void insertAtTail(Node*& head,Node*& tail,int data){
    if(tail==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node*newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;
}
void insertAtPosition(Node*&head,Node*&tail,int data,int pos){
    if(head==NULL){
        Node*newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    if(pos==0){
        insertAtHead(head,tail,data);
        return;
    }
    if(pos>=printlen(head)){
        insertAtTail(head,tail,data);
        return;
    }
    int i=1;
    Node*prev=head;
    while(i<pos){
        prev=prev->next;
        i++;
    }
    Node*newNode=new Node(data);
    Node*curr=prev->next;
    newNode->next=curr;
    prev->next=newNode;


}
void deleteNode(Node*&head,Node*&tail,int pos){
    if(head==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    if(pos>printlen(head)){
        cout<<"position out of linked list"<<endl;
        return;
    }
    if(pos==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    if(pos==printlen(head)){
        Node*prev=head;
        int i=1;
        while(i<pos-1){
            prev=prev->next;
            i++;
        }
        Node*temp=tail;
        prev->next=NULL;
        tail=prev;
        delete temp;
        return;
    }
    Node*prev=head;
    int i=1;
    while(i<pos-1){
        prev=prev->next;
        i++;
    }
    Node*curr=prev->next;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;


}
int main() {
    Node*head=NULL;
    Node*tail=NULL;
    insertAtHead(head,tail,30);
    insertAtPosition(head,tail,20,0);
    insertAtTail(head ,tail,40);
    insertAtTail(head ,tail,10);
    insertAtTail(head ,tail,80);
    print(head);
    cout<<endl;
    deleteNode(head,tail,4);
    print(head);
    
}
