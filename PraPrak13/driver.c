#include "bintree.c"
#include <stdio.h>

int main()
{
    BinTree root = newTreeNode(1);
        root->left = newTreeNode(2);
        root->right = newTreeNode(3);

        root->left->left = newTreeNode(4);
//        root->left->right = newTreeNode(5);
//        root->right->left = newTreeNode(6);
        root->right->right = newTreeNode(7);
//
//        root->left->left->left = newTreeNode(8);
//        root->left->left->right = newTreeNode(9);
//        root->left->right->left = newTreeNode(10);
//        root->left->right->right = newTreeNode(11);
//        root->right->left->left = newTreeNode(12);
//        root->right->left->right = newTreeNode(13);
//        root->right->right->left = newTreeNode(14);
//        root->right->right->right = newTreeNode(15);

    printPreorder(root);
    printf("\n");
    printTree(root,2);
}
