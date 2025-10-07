#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
}node;

node* root = NULL;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

node* createBT()
{
    int data;
    printf("enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    node* temp = createNode(data);

    printf("enter left child of %d:\n", data);
    temp->lchild = createBT();

    printf("enter right child of %d:\n", data);
    temp->rchild = createBT();

    return temp;
}

void inorder()
{

}

void postorder()
{

}

void preorder()
{

}

int findParent(node* r, int data)
{
    if(r==NULL)
    {
        printf("tree contains no nodes\n");
        return -1;
    }

    if(r->data==data)
    {
        printf("root node does not have a parent\n");
        return -1;
    }

    if(r->lchild!=NULL && r->lchild->data==data)
        return r->data;

    if(r->rchild!=NULL && r->rchild->data==data)
        return r->data;

    int leftSubtree = findParent(r->lchild, data);
    if(leftSubtree != -1)
        return leftSubtree;

    int rightSubtree = findParent(r->rchild, data);
    if(rightSubtree != -1)
        return rightSubtree;
}

void findDepth()
{

}

node* findAddress(node* r, int data) {
    if (r == NULL)
        return NULL;

    if (r->data == data)
        return r;

    node* leftResult = findAddress(r->lchild, data);
    if (leftResult != NULL)
        return leftResult;

    node* rightResult = findAddress(r->rchild, data);
    if (rightResult != NULL)
        return rightResult;

    return NULL;
}


void findAncestors(node* r, int data, node* ar)
{
    if(ar == NULL)
        return;
    if(r == ar)
        return;
    int parentData = findParent(ar, data);
    printf("%d\t", parentData);
    node* padd = findAddress(ar, parentData);
    findAncestors(padd, parentData, ar);
}

int countLeafNodes()
{

}

int main()
{
    int cnt = 1, ch, td;
    printf("enter values as indicated to create the binary tree.\n");
        root = createBT();
    /*do
    {
        printf("enter choice:\n1. create fresh binary tree\n2. inorder traversal\n3. postorder traversal\n4. preorder traversal\n5. find parent of specific node\n6. find depth of tree\n7. find ancestors of specific node\n8. find number of leaf nodes\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("enter values as indicated to create the binary tree.\n");
                    root = createBT();
            break;

            case 2: printf("inorder traversal of binary tree: ");
                    inorder();
                    printf("\n");
            break;

            case 3: printf("postorder traversal of binary tree: ");
                    postorder();
                    printf("\n");
            break;

            case 4: printf("preorder traversal of binary tree: ");
                    preorder();
                    printf("\n");
            break;

            case 5: printf("enter data to find parent of:\n");
                    scanf("%d", td);
                    int p = findParent(root, td);
                    printf("parent of %d is: %d\n", td, p);
            break;

            case 6: printf("depth of binary tree: ");
                    findDepth();
                    printf("\n");
            break;

            case 7: printf("enter data to find ancestors of:\n");
                    scanf("%d", td);
                    findAncestors(NULL, td, root);
                    printf("\n");
            break;

            case 8: printf("number of leaf nodes in binary tree: ");
                    int ln = countLeafNodes();
                    printf("number of leaf nodes: %d\n", ln);
            break;

            default: printf("invalid choice!\n");
        }

        printf("enter 1 to continue and 0 to stop.\n");
        scanf("%d", &cnt);
    }while(cnt != 0);*/
    return 0;
}
