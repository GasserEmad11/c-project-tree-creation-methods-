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




// void delete (treenode *ptr)
// {treenode *t;
// treenode *q;
// int x;
// printf ("\nplease enter element you wish to delete\n");
// scanf("%d",&x);
// while (ptr->data!=x)
// { if (ptr->data>x)
// {t=ptr;
// ptr=ptr->left;
// }
// else if (ptr->data<x)
// {t=ptr;
// ptr=ptr->right;
// }
// }
// printf("found the element\n ");
// if (ptr->left==NULL&&ptr->right==NULL)
// {free(ptr);
// }
// else if (ptr->left==NULL&&ptr->data<t->data)
// {t->left=ptr->right;
// }
// else if (ptr->left==NULL&&ptr->data>t->data) 
// {t->right=ptr->right;
// }
// else if (ptr->right==NULL&&ptr->data<t->data)   
// {
// t->left=ptr->left;    
// }
// else if (ptr->right==NULL&&ptr->data>t->data)
// {
// t->right=ptr->left;    
// }
// else {q=ptr;
// ptr=ptr->left;
// while(ptr->right!=NULL)
// {ptr=ptr->right;
// }
// q->data=ptr->data;
// free(ptr);

    
// }
// }


treenode *inorder (treenode *ptr)
{
    while (ptr&&ptr->right!=NULL)
    {ptr=ptr->right;
        
        
    }
    return ptr;
    
    
}


treenode * delete (treenode *ptr,int x)
{treenode *t;
treenode *q;
if (root=NULL)
return NULL;
if (ptr->data>x)
{ptr->left=delete(ptr->left,x);}
else if(ptr->data<x)
{ptr->right=delete (ptr->right,x);}
else {//found the value,steps for deletion below
if (ptr->left==NULL&&ptr->right==NULL)
{free(ptr);
ptr=NULL;
}
else if (ptr->left==NULL)
{t=ptr;
ptr=ptr->right;
free(t);
}
else if (ptr->right==NULL)
{t=ptr;
ptr=ptr->left;
free(t);
}
else {//case of two children
q=inorder(ptr->left);
ptr->data=q->data;
ptr->left=delete(ptr->left,q->data);
}
}
return ptr;
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
    delete(root,25);
    printf ("after deletion \n");
    predisplay(root);
}
