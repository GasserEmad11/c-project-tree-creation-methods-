/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
int data;
struct treenode *left;
struct treenode *right;
    
    
}treenode;
treenode *root;

typedef struct stack {
treenode **A;
int size;
int top;
}stack;
stack *buff;




void buffcreate (size)
{buff=(stack *)malloc (sizeof (stack));
buff->size=size;
buff->top=-1;
buff->A=(treenode **)malloc (size*sizeof(treenode));
}




void display (treenode *ptr)
{if (ptr!=NULL)
{printf ("%d\n",ptr->data);
display (ptr->left);
display (ptr->right);
    
    
}
    
    
}






 void push (treenode *ptr)
{if(buff->top==buff->size-1)
{printf ("buff is full\n");
return ;
}
else
{buff->A[++buff->top]=ptr;
    
    
    
}
}


treenode *pop ()
{
    if (buff->top==-1)
{printf ("buff is empty\n");
return ;
}
else 
{return buff->A[buff->top--];
    
    
}
}


treenode *topvalue ()
{treenode *t;
    if (buff->top==-1)
{t=(treenode *)malloc (sizeof (treenode));
t->left=t->right=NULL;
t->data=1000;
return t;
    
    
}
else 
{return buff->A[buff->top];
    
    
}
    
    
    
}






void treecreate (int arr [],int size)
{treenode *t;
treenode *p;
int i =0;
int n=size;
while (i<n)
    {if (root==NULL)
{root=(treenode *)malloc (sizeof (treenode));
root->data=arr[i++];
root->left=root->right=NULL;
p=root;
}
else if (p->data>arr[i])
{t=(treenode *)malloc (sizeof (treenode));
t->data=arr[i++];
t->left=t->right=NULL;
push (p);
p->left=t;
p=t;
}
else if (p->data<arr[i]&&topvalue()->data>arr[i])
{t=(treenode *)malloc (sizeof (treenode));
t->data=arr[i++];
t->left=t->right=NULL;
push (p);
p->right=t;
p=t;
}
else 
{p=pop();
    
    
    
}
  }    
}


void create ()
{int size ;
printf ("please enter size of tree\n");
scanf ("%d",&size);
buffcreate(size);
int arr[size];
for (int i=0;i<size;i++)
{printf ("please enter elements of tree in its preorder \n");
scanf ("%d",&arr[i]);
}
treecreate(arr,size);    
    
    
    
}








int main()
{create ();
display (root);

    
}
