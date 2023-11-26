#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;
typedef struct BST {
    Node *root;
    Node* (*find)(int val, struct BST* bst);
    void (*insert)(int val, struct BST* bst);
    void (*free)(struct BST* bst);
} BST;

Node *new_Node(int val);
BST* new_BST();
Node* _find(int val, BST *bst);
void _insert(int val, BST *bst);
void _free_bst(BST *bst);
void _free_node(Node *node);
int split(int a);

int main() {
    int a; scanf("%d", &a);
    BST *bst = new_BST(new_Node(a));
    while(a >= 10) {
        a = split(a);
        if (bst->find(a, bst)) {
            printf("0\n");
            return 0;
        }
        bst->insert(a, bst);
    }
    if (a == 1) printf("1\n");
    else printf("0\n");
    
    bst->free(bst);
    return 0;
}

int split(int a) {
    int ans = 0;
    while (a) {
        ans += (a % 10) * (a % 10);
        a /= 10;
    }
    return ans;
}

Node* new_Node(int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL; node->right = NULL;
    return node;
}

BST* new_BST(Node* root) {
    BST *bst = (BST*)malloc(sizeof(BST));
    bst->root = root;
    bst->find = _find;
    bst->insert = _insert;
    bst->free = _free_bst;
    return bst;
}

Node* _find(int val, BST *bst) {
    Node *cur = bst->root;
    while (cur) {
        if (cur->val == val) return cur;
        else if (cur->val > val) cur = cur->left;
        else cur = cur->right;
    }
    return NULL;
}

void _insert(int val, BST *bst) {
    Node *cur = bst->root;
    while (cur) {
        if (cur->val == val) return;
        else if (cur->val > val) {
            if (cur->left) cur = cur->left;
            else {
                cur->left = new_Node(val);
                return;
            }
        }
        else {
            if (cur->right) cur = cur->right;
            else {
                cur->right = new_Node(val);
                return;
            }
        }
    }
    return;
}

void _free_bst(BST *bst) {
    _free_node(bst->root);
    free(bst);
    return;
}

void _free_node(Node *node) {
    if (!node) return;
    _free_node(node->left);
    _free_node(node->right);
    free(node);
    return;
}