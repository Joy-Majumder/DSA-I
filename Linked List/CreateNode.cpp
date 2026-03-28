#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void insert(node *s,int val){
    while(s->next != NULL){
            s= s->next;
    }
    s-> next=(node*)malloc(sizeof(node));
    s->next->data=val;
    s->next->next=NULL;
}

void display(node *s){
    while(s->next != NULL){
        cout<<s->next->data<<" ";
        s=s->next;
    }
    cout<<endl;
}

/*
// this version by faculy bt here we have some issue and bugs which is done memory leaks
//Memory handling - Not freed
// Pointer movement - Always moves
// Duplicate deletion - Fails
// Stability - Risky

void dlt(node *s, int val){
    while(s->next != NULL){
        if(s->next->data==val){
            s->next=s->next->next;   // node removed but not freed
        }
        s=s->next;  //always moves → skips nodes
    }
}
*/


// here is the fixed version

// free(temp)
// Moves only when needed
// Works correctly
// safe

void dlt(node *s, int val){
    while(s->next != NULL){
        if(s->next->data == val){
            node* temp = s->next;     // store node
            s->next = temp->next;     // unlink
            free(temp);               // free memory
        } else {
            s = s->next;              // move ONLY if not deleting
        }
    }
}

void srch(node *s, int val){
    int est = 0;
    while(s->next!= NULL){
        if(s->next->data==val){
            est++;
        }
        s=s->next;
    }
    cout<<est<<endl;
}
// Rabit and tourtoise
void middleNode(node *s){
    node *fast = s;
    node *slow = s;
    while(fast!=NULL || fast->next != NULL){
        fast =fast->next->next;
        slow = slow->next;
    }
    cout<<slow->data<<endl;
}

int main(void){
    node *first = (node*)malloc(sizeof(node));
    node *second = (node*)malloc(sizeof(node));

    first -> data = 2;
    first -> next = second;

    second -> data =3;
    second -> next= NULL;

    // Adding
    node *head = (node*)malloc(sizeof(node));
    head->next=NULL;

    insert(head,2);
    insert(head,3);
    insert(head,4);
    display(head);
    dlt(head,3);
    display(head);
    //search
    insert(head,4);
    insert(head,2);
    insert(head,3);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    insert(head,3);
    insert(head,3);
    insert(head,2);
    display(head);
    srch(head,3);
    middleNode(head);
}
