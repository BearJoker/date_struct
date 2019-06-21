#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

typedef struct{
    int weight;
    int parent,lchild,rchild;
}HTNnode,*HuffmanTree;

#endif // HUFFMANTREE_H
