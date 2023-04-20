#include <iostream>
#include "AVL.h"

int main()
{
    AVL avl;

    avl.root = avl.insert(avl.root, 10);
    avl.root = avl.insert(avl.root, 20);
    avl.root = avl.insert(avl.root, 30);
    avl.root = avl.insert(avl.root, 40);
    avl.root = avl.insert(avl.root, 50);
    avl.root = avl.insert(avl.root, 60);
    avl.root = avl.insert(avl.root, 70);
    avl.root = avl.insert(avl.root, 80);
    avl.root = avl.insert(avl.root, 90);
    avl.root = avl.insert(avl.root, 100);

    std::cout << "Arvore AVL:" << std::endl;
    avl.print();

    return 0;
}
