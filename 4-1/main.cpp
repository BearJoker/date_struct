//����������ز�����ʾ
//ʹ����ʽ�洢�ṹ
#include <iostream>

using namespace std;

typedef struct BiTNode{
    char date;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//����������������
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
//�������
void FirstOrderTraverse(BiTree T){
    if(T){
        cout<<T->date;
        FirstOrderTraverse(T->lchild);
        FirstOrderTraverse(T->rchild);
    }
}
//�������
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);
        cout<<T->date;
        InOrderTraverse(T->rchild);
    }
}
//�������
void LastOrderTraverse(BiTree T){
    if(T){
        LastOrderTraverse(T->lchild);
        LastOrderTraverse(T->rchild);
        cout<<T->date;
    }
}
//ͳ�ƽڵ�ĸ���
int NodeCount(BiTree T){
    if(T==NULL) return 0;
    else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
//��������������
int Depth(BiTree T){
    if(T==NULL) return 0;
    else{
        int m=Depth(T->lchild);
        int n=Depth(T->rchild);
        if(m>n) return(m+1);
        else return (n+1);
    }
}
//��������������е�Ҷ�ӽڵ�
//��������������ж�Ϊ1�Ľڵ����
//��������������ж�Ϊ2�Ľڵ����
//�ݹ����ͬһ�������������Ϳ��Զ������б�����������Ҫ��ʱ����Ӧ�Ĳ���Ҫ��1
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
    cout<<"�������"<<endl;
    FirstOrderTraverse(t);
    cout<<endl<<"�������"<<endl;
    InOrderTraverse(t);
    cout<<endl<<"�������"<<endl;
    LastOrderTraverse(t);
    cout<<endl;
    int count=NodeCount(t);
    cout<<"�������Ľڵ����Ϊ��"<<count<<endl;
    int depth=Depth(t);
    cout<<"����辵����Ϊ��"<<depth<<endl;
    int leaf=0;
    int one=0;
    int two=0;
    Get_leaf(t,leaf,one,two);
    cout<<"Ҷ�ӽڵ���Ϊ��"<<leaf<<endl;
    cout<<"��Ϊ1�Ľڵ���Ϊ��"<<one<<endl;
    cout<<"��Ϊ2�Ľڵ���Ϊ��"<<two<<endl;
}
