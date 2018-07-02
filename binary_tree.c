#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int newData)
{
    Node* node = malloc(sizeof(Node));
    node->data = newData;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* root = NULL;

void insertNewNode(int newData)
{
    if (root == NULL)
    {
        root = newNode(newData);
        printf("Root inserted: %d\n", root->data);
        return;
    }
    else
    {
        printf("Traverse %d..\n", newData);

        Node* currentNode = root;
        while (currentNode != NULL)
        {
            if (newData < currentNode->data)
            {
                if (currentNode->left == NULL)
                {
                    currentNode->left = newNode(newData);
                    printf("Left inserted %d\n", currentNode->data);
                    return;
                }

                printf("Go left..\n");
                currentNode = currentNode->left;
            }
            else
            {
                if (currentNode->right == NULL)
                {
                    currentNode->right = newNode(newData);
                    printf("Right inserted %d\n", currentNode->data);
                    return;
                }

                printf("Go right..\n");
                currentNode = currentNode->right;
            }
        }
    }

    printf("Error insert\n");
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node* node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

void postOrder(Node* node)
{
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

int main()
{
    int dataArr[] = { 12, 22, 8, 19, 10, 9, 20, 4, 2, 6 };
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        insertNewNode(dataArr[i]);
    }

    Node* currentNode = root;
    printf("Pre order: ");
    preOrder(currentNode);
    printf("\n");

    currentNode = root;
    printf("In order: ");
    inOrder(currentNode);
    printf("\n");

    currentNode = root;
    printf("Post order: ");
    postOrder(currentNode);
    printf("\n");

    return 0;
}
