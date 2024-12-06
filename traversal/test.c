#include <stdio.h>
#include <stdlib.h>

// 2分木のノードを表す構造体
struct Node {
    int data;               // ノードの値
    struct Node* left;      // 左部分木へのポインタ
    struct Node* right;     // 右部分木へのポインタ
};

// 新しいノードを作成する関数
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 前順走査 (Pre-order Traversal)
void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data); // 親ノードを訪問
    preOrder(root->left);      // 左部分木を再帰的に走査
    preOrder(root->right);     // 右部分木を再帰的に走査
}

// 間順走査 (In-order Traversal)
void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);       // 左部分木を再帰的に走査
    printf("%d ", root->data); // 親ノードを訪問
    inOrder(root->right);      // 右部分木を再帰的に走査
}

// 後順走査 (Post-order Traversal)
void postOrder(struct Node* root) {
    if (root == NULL) return;
    postOrder(root->left);     // 左部分木を再帰的に走査
    postOrder(root->right);    // 右部分木を再帰的に走査
    printf("%d ", root->data); // 親ノードを訪問
}

int main() {
    // サンプルツリーの構築
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // 各走査の結果を表示
    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
