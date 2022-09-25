#include <iostream>                   //vedansh singh
using namespace std;                  //ECE,SID:21105078

//CREATING NODE CLASSS
class Node{
    public:
    string name;
    int age;
    Node*next; 
    Node*prev; 
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; 
        prev=NULL; 
    }
};

void append(Node* &head,string name,int age){

    Node*temp=head;
    Node*n1=new Node(name,age);
    if(temp==NULL){
        head=n1;
    }
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=n1;
        n1->prev=temp;
    }
}

//INSERT DATA AT START OF LINKED LIST
void insert_at_head(Node*&head,string name,int age){

    Node*n1=new Node(name,age);
    n1->next=head;
    head->prev=n1;
    head=n1;
}

//DIPLAY DATA FROM START OF LINKED LIST
void Preceding(Node*head){
    Node*temp=head;
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->next;}
    cout<<endl;
}

//DISPLAY DATA FROM END OF LINKED LIST
void Succeding(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->prev;}
    cout<<endl;
}

//FUNCTION TO DELETE ANY INDEX(0,n-1) EXCLUDING LAST ELEMENT 
void deleteIndex(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//FUNCTION TO DELETE LAST ELEMENT
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    //Initialising an empty linked list
    Node*head=NULL;
	int no_of_family_mem;
	cout<<"Enter Number Of Family Members:";cin>>no_of_family_mem;

	for(int i=1;i<=no_of_family_mem;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";cin.ignore();getline(cin,name);
		cout<<"Enter Family Member "<<i<<" Age:";cin>>age;
		append(head,name,age);
	}
    cout<<endl;
    cout<<"Doubly Linked list with my family members as elements is shown below:"<<endl;
    cout<<endl;
    Preceding(head);
}
//ans 2
//we can link family members according to their ages like in order of  elder to younger members in a family or from younger to elder .
