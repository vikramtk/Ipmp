#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedlist{
    Node * head;
    
    public:
    
    linkedlist(){head=NULL;}
    
    void insert(int n){
        Node * newnode = new Node(n);
        if(head==NULL)
        head=newnode;
        else
        {
            Node * cur=head;
            while(cur->next != NULL)
            cur=cur->next;
            cur->next=newnode;
        }
    }
    
    void deletenode(int pos){
        Node *del,*cur=head;
        if(head==NULL)
        cout<<"List is empty\n";
        
        else if(pos==1)
        {
            head=head->next;
            delete cur;
        }
        
        else{
        for(int i=1;i<pos-1;i++)
        cur=cur->next;
        if(cur==NULL){
            cout<<"Invalid position";
            return;
        }
        del=cur->next;
        cur->next=cur->next->next;
        delete del;
        }
    }
    
    void deletelist(){
        while(head!=NULL)
        {
            Node *cur=head;
            head=head->next;
            delete cur;;
        }
    }
    
    void print(){
        Node*cur=head;
        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur=cur->next;
        }
    }
    
    int length()
    {
        int count=0;
        Node*cur=head;
        while(cur!=NULL)
        {
            count++;
            cur = cur->next;
        }
        return count;
    }
    
    int search(int n)
    {
        Node*cur=head;
        int pos=0;
        while(cur!=NULL)
        {
            pos++;
            if(cur->data==n)
                return pos;
            cur=cur->next;
        }
        return pos;
    }
};

int main()
{
    linkedlist L;
    L.insert(1);
    L.insert(2);
    L.insert(3);
    cout<<"Length is "<<L.length()<<endl;
    cout<<"List is ";
    L.print();
    cout<<endl;
    L.deletenode(1);
    cout<<"Length is "<<L.length()<<endl;
    cout<<"List is ";
    L.print();
    
    cout<<"\nSearching 3\n";
    if(L.search(3))
    cout<<"Found\n";
    else
    cout<<"Not found\n";
    
    L.deletelist();
    cout<<"After deleting list,length = "<<L.length();
    return 0;
}
