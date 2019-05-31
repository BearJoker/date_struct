//二叉树的相关操作演示
//使用链式存储结构
#include <iostream>

using namespace std;

typedef struct BiTNode{
    char date;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//先序建立二叉树链表
void CreateBiTree(BiTree &T){
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else {
        T=new BiTNode;
        T->date=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
//先序输出
void FirstOrderTraverse(BiTree T){
    if(T){
        cout<<T->date;
        FirstOrderTraverse(T->lchild);
        FirstOrderTraverse(T->rchild);
    }
}
//中序输出
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);
        cout<<T->date;
        InOrderTraverse(T->rchild);
    }
}
//后续输出
void LastOrderTraverse(BiTree T){
    if(T){
        LastOrderTraverse(T->lchild);
        LastOrderTraverse(T->rchild);
        cout<<T->date;
    }
}
//统计节点的个数
int NodeCount(BiTree T){
    if(T==NULL) return 0;
    else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
//计算二叉树的深度
int Depth(BiTree T){
    if(T==NULL) return 0;
    else{
        int m=Depth(T->lchild);
        int n=Depth(T->rchild);
        if(m>n) return(m+1);
        else return (n+1);
    }
}
//计算二叉树中所有的叶子节点
//计算二叉树中所有度为1的节点个数
//计算二叉树中所有度为2的节点个数
//递归调用同一个函数，这样就可以对树进行遍历，当符合要求时，相应的参数要加1
void Get_leaf(BiTree T,int &leaf,int &one,int &two){
    if(T==NULL) return;
    if(T->lchild==NULL&&T->rchild==NULL){
        leaf++;
    }
    if(T->lchild!=NULL&&T->rchild!=NULL){
        two++;
    }
    if((T->lchild==NULL&&T->rchild!=NULL)||(T->lchild!=NULL&&T->rchild==NULL)){
        one++;
    }
    Get_leaf(T->lchild,leaf,one,two);
    Get_leaf(T->rchild,leaf,one,two);
}
int main()
{

    BiTree t;
    CreateBiTree(t);
    cout<<"先序输出"<<endl;
    FirstOrderTraverse(t);
    cout<<endl<<"中序输出"<<endl;
    InOrderTraverse(t);
    cout<<endl<<"后序输出"<<endl;
    LastOrderTraverse(t);
    cout<<endl;
    int count=NodeCount(t);
    cout<<"二叉树的节点的数为："<<count<<endl;
    int depth=Depth(t);
    cout<<"二树杈的深度为："<<depth<<endl;
    int leaf=0;
    int one=0;
    int two=0;
    Get_leaf(t,leaf,one,two);
    cout<<"叶子节点数为："<<leaf<<endl;
    cout<<"度为1的节点数为："<<one<<endl;
    cout<<"度为2的节点数为："<<two<<endl;
}
