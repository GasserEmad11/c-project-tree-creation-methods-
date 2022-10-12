#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
int data;
struct treenode *left;
struct treenode *right;
}treenode;
treenode *root;







typedef struct quenode {
treenode **A;
struct quenode *next;
}quenode ;
quenode *front,*tail;


void enqeue (treenode *ptr)
{quenode *q;

if (front==NULL)
{front=(quenode *)malloc(sizeof (quenode));
front->A=ptr;
front->next=NULL;
tail=front;
}
else
{q=(quenode *)malloc (sizeof (quenode));
q->A=ptr;
q->next=NULL;
tail->next=q;
tail=q;
}
    
    
}



void display (treenode *ptr)
{if (ptr!=NULL)
{
    printf("%d\n",ptr->data);
    display (ptr->left);
    display (ptr->right);
}
}





treenode * deque ()
{treenode *t;
quenode *q;    
    
    if (front==NULL)
{printf ("queue is empty");
return ;    
}
else 
{t=front->A;
q=front;
front=front->next;
free(q);
return t;
}
}

int isempty ()
{if (front==NULL)
{
    return 1;
}
else{
    
 return 0;    
}
}







void treecreate ()
{treenode *t;
treenode *pointer;
int x;
    root=(treenode *)malloc (sizeof (treenode));
printf ("please enter root value");
scanf("%d",&root->data);
root->left=NULL;
root->right=NULL;
enqeue (root);
while (!isempty())
{pointer =deque();
//(*pointer)=(treenode *)malloc (sizeof (treenode));
printf ("please enter left child of %d node \n",pointer->data);
scanf ("%d",&x);
if (x==0)
{printf ("no right child \n");
}
else {
t=(treenode*)malloc (sizeof (treenode));
t->data=x;
t->left=NULL;
t->right=NULL;
enqeue (t);
pointer->left=t;
}    
printf ("please enter value of right child of %d node \n",pointer->data);
scanf ("%d",&x);
if (x==0)
{printf ("no left child \n");
}
else  
{t=(treenode *)malloc (sizeof (treenode));
t->data=x;
t->left=NULL;
t->right=NULL;
enqeue (t);
pointer->right=t;
}
}
}


int main ()
{treecreate();
display (root);
    
    
    
}