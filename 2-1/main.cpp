//利用栈实现二进制、八进制、十六进制的互相转化
//顺序栈
//时间：2019/04/11

#include <iostream>
#define SIZA 30

using namespace std;
typedef struct{
    int num;
}Elem;
typedef struct
{
    Elem *top;
    Elem *base;
    int stacksize;
}SqStack;

//初始化栈
void Init(SqStack &s){
    s.base=new Elem[SIZA];
    if(!s.top) {
        cout<<"分配内存不成功";
        exit(0);
    }
    s.top=s.base;
    s.stacksize=SIZA;
}
//进栈
void push(SqStack &s,int n){
    if(s.top-s.base==s.stacksize){
        cout<<"栈满";
        exit(0);
    }
    s.top->num=n;
    s.top=s.top+1;
}
//出栈
void pop(SqStack &s){
    if(s.top==s.base){
        cout<<"空栈";
        exit(0);
    }
    s.top=s.top-1;
    cout<<s.top->num;
}
int main()
{
    SqStack s;
    Init(s);
    int n,a;
    for(int x=0;x<5;x++){
        cout<<"输入一个数：";
        cin>>n;
        a=n;
        while(n){
            push(s,n%8);
            n=n/8;
        }
        cout<<"该数的八进制为：";
        while(s.top!=s.base){
            pop(s);
        }
        cout<<endl;
        while(a){
            push(s,a%2);
            a=a/2;
        }
        cout<<"该数的二进制为：";
        while(s.top!=s.base){
            pop(s);
        }
       /* while(b){
            push(s,b%16);
            b=b/16;
        }
        cout<<"该数的十六进制为：";
        while(s.top!=s.base){
            pop(s);
        }*/
        cout<<endl<<endl;
    }
}
