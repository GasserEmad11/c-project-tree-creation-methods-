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
}treenode ;
treenode *root;




void predisplay (treenode *ptr)
{if (ptr!=NULL)
{printf ("%d\n",ptr->data);
predisplay (ptr->left);
predisplay (ptr->right);
}
    
    
}









void treecreate (treenode *ptr,int key)
{treenode *t;
    if (root==NULL)
{ptr=(treenode *)malloc (sizeof (treenode));
ptr->left=NULL;
ptr->right=NULL;
ptr->data=key;
root=ptr;
return;
}
while (ptr!=NULL)
{if (ptr->data>key)
{t=ptr;
    ptr=ptr->left;
    
}
 else if (ptr->data<key) 
{t=ptr;
    ptr=ptr->right;
}
else
{
return;    
}
}    
ptr=(treenode *)malloc (sizeof (treenode));
ptr->left=NULL;
ptr->right=NULL;
ptr->data=key;    
if (t->data>key)
{t->left=ptr;
    
}
else
{t->right=ptr;
    
    
}
    
}

    
    
void create ()
{int size ;
printf ("please enter size of tree\n");
scanf ("%d",&size);
int arr[size];
for(int i=0;i<size;i++)
{printf ("please enter elements of tree\n");
scanf ("%d",&arr[i]);
}
for(int i=0;i<size;i++)
{
treecreate (root,arr[i]);
}
}    
    












int main()
{
    create ();
    predisplay(root);
}
