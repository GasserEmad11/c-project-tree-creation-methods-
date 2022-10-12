/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>



typedef struct treenode {
int data ;
struct treenode *left;
struct treenode *right;
}treenode;



void display (treenode *ptr)
{if (ptr!=NULL)
{//printf("%d\n",ptr->data);
display (ptr->left);
printf ("%d\n",ptr->data);
display (ptr->right);
    
}    
    
    
    
}






int search (int x,int arr[])
{int i=0;
    while (i!=x)
{i++;
    
}
return i;    
    
    
    
}











treenode * treecreate ( int inorder[],int preorder[],int start,int end)
{if (start>end)
return NULL;
treenode *t;
static int preindex=0;
int inindex=0;
t=(treenode *)malloc (sizeof (treenode ));
t->data=preorder[preindex];
preindex++;
if (start==end)
return t;
inindex=search (preindex,inorder);
t->left=treecreate (inorder,preorder,start,inindex-1);
t->right=treecreate (inorder,preorder,inindex+1,end);
return t;    
}


    
    
    
    
    
    
    
    
    
    
    
    













int main()
{int arr1[]={3,9,20,15,7};
int arr2[] ={9,3,15,20,7};
treenode *t;
t=treecreate (arr2,arr1,0,4);
display(t);
}
