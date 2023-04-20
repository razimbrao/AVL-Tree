#include "Node.h"
#include <iostream>


class AVL
{
    public:
    Node *root;
 
    AVL(){
        root = nullptr;
    };

    ~AVL(){
        delete root;
    };

    int getHeight(Node *N)
    {
        if (N == nullptr)
            return 0;
        return N->height;
    };

    int balanceFactor(Node *N)
    {
        if (N == nullptr)
            return 0;
        return getHeight(N->left) - getHeight(N->right);
    };
    
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
 
        x->right = y;
        y->left = T2;
 
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
 
        return x;
    };

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
 
        y->left = x;
        x->right = T2;
 
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
 
        return y;
    };

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
            return (new Node(value));
 
        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        else
            return node;
 
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
 
        int balance = balanceFactor(node);
 
        if (balance > 1 && value < node->left->value)
            return rightRotate(node);
 
        if (balance < -1 && value > node->right->value)
            return leftRotate(node);
 
        if (balance > 1 && value > node->left->value)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
 
        if (balance < -1 && value < node->right->value)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
 
        return node;
    };

    void print(Node *node, int level)
    {
        if (node != nullptr)
        {
            print(node->right, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "   ";
            std::cout << node->value << std::endl;
            print(node->left, level + 1);
        }
    };

    void print()
    {
        print(root, 0);
    };

    void insert(int value)
    {
        root = insert(root, value);
    };

    Node *minValueNode(Node *node)
    {
        Node *current = node;
 
        while (current->left != nullptr)
            current = current->left;
 
        return current;
    };

    Node *remove(Node *node, int value)
    {
        if (node == nullptr)
            return node;
 
        if (value < node->value)
            node->left = remove(node->left, value);
 
        else if (value > node->value)
            node->right = remove(node->right, value);
 
        else
        {
            if ((node->left == nullptr) || (node->right == nullptr))
            {
                Node *temp = node->left ? node->left : node->right;
 
                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;
                delete temp;
            }
            else
            {
                Node *temp = minValueNode(node->right);
 
                node->value = temp->value;
 
                node->right = remove(node->right, temp->value);
            }
        }
 
        if (node == nullptr)
            return node;
 
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
 
        int balance = balanceFactor(node);
 
        if (balance > 1 && balanceFactor(node->left) >= 0)
            return rightRotate(node);
 
        if (balance > 1 && balanceFactor(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
 
        if (balance < -1 && balanceFactor(node->right) <= 0)
            return leftRotate(node);
 
        if (balance < -1 && balanceFactor(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
 
        return node;
    };
};
