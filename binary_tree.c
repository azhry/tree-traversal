#include <stdio.h>
#include <stdlib.h>

// Definisikan tipe data untuk merepresentasikan node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Fungsi untuk membuat node baru
Node* newNode(int newData)
{
    Node* node = malloc(sizeof(Node)); // alokasi memori utk node baru
    node->data = newData; // beri data ke node baru
    node->left = NULL; // null-kan terlebih dahulu
    node->right = NULL; // null-kan terlebih dahulu
    return node; // balikkan node yg telah dibuat
}

Node* root = NULL; // inisialiasi node paling atas (root/akar) dengan null

void insertNewNode(int newData)
{
    if (root == NULL) // apakah tree kosong ?
    {
        root = newNode(newData); // jadikan node baru tersebut sebagai akar
        printf("Root inserted: %d\n", root->data);
        return;
    }
    else
    {
        printf("Traverse %d..\n", newData);

        Node* currentNode = root; // inisialisasi variabel pembantu untuk melintasi tree dengan start-nya di akar

        while (currentNode != NULL) // traverse selama currentNode tidak null atau tidak kosong
        {
            if (newData < currentNode->data) // apakah data yang akan dimasukkan lebih kecil dari data yang ada di currentNode
            {
                if (currentNode->left == NULL) // cek apakah left child dari currentNode kosong atau null
                {
                    currentNode->left = newNode(newData); // buat node baru dan jadikan sebagai left child dari currentNode
                    printf("Left inserted %d\n", currentNode->left->data);
                    return;
                }

                printf("Go left..\n");
                currentNode = currentNode->left; // currentNode pergi ke left child
            }
            else
            {
                if (currentNode->right == NULL) // cek apakah right child dari currentNode kosong atau null
                {
                    currentNode->right = newNode(newData); // buat node baru dan jadikan sebagai right child dari currentNode
                    printf("Right inserted %d\n", currentNode->right->data);
                    return;
                }

                printf("Go right..\n");
                currentNode = currentNode->right; // currentNode pergi ke right child
            }
        }
    }

    printf("Error insert\n");
}

void preOrder(Node* node)
{
    if (node == NULL) // base case: preOrder stop
        return;

    printf("%d ", node->data);
    preOrder(node->left); // traverse ke left child
    preOrder(node->right); // traverse ke right child
}

void inOrder(Node* node)
{
    if (node == NULL) // base case: inOrder stop
        return;

    inOrder(node->left); // traverse ke left child
    printf("%d ", node->data);
    inOrder(node->right); // traverse ke right child
}

// base case itu adalah kondisi dimana fungsi rekursif harus berhenti

void postOrder(Node* node)
{
    if (node == NULL) // base case: postOrder stop
        return;

    postOrder(node->left); // traverse ke left child
    postOrder(node->right); // traverse ke right child
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

    Node* currentNode = root; // awali currentNode dari root
    printf("Pre order: ");
    preOrder(currentNode); // tampilkan secara preOrder
    printf("\n");

    currentNode = root; // awali currentNode dari root
    printf("In order: ");
    inOrder(currentNode); // tampilkan secara inOrder
    printf("\n");

    currentNode = root; // awali currentNode dari root
    printf("Post order: ");
    postOrder(currentNode); // tampilkan secara postOrder
    printf("\n");

    return 0;
}
