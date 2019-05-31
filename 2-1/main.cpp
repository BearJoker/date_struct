//����ջʵ�ֶ����ơ��˽��ơ�ʮ�����ƵĻ���ת��
//˳��ջ
//ʱ�䣺2019/04/11

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

//��ʼ��ջ
void Init(SqStack &s){
    s.base=new Elem[SIZA];
    if(!s.top) {
        cout<<"�����ڴ治�ɹ�";
        exit(0);
    }
    s.top=s.base;
    s.stacksize=SIZA;
}
//��ջ
void push(SqStack &s,int n){
    if(s.top-s.base==s.stacksize){
        cout<<"ջ��";
        exit(0);
    }
    s.top->num=n;
    s.top=s.top+1;
}
//��ջ
void pop(SqStack &s){
    if(s.top==s.base){
        cout<<"��ջ";
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
        cout<<"����һ������";
        cin>>n;
        a=n;
        while(n){
            push(s,n%8);
            n=n/8;
        }
        cout<<"�����İ˽���Ϊ��";
        while(s.top!=s.base){
            pop(s);
        }
        cout<<endl;
        while(a){
            push(s,a%2);
            a=a/2;
        }
        cout<<"�����Ķ�����Ϊ��";
        while(s.top!=s.base){
            pop(s);
        }
       /* while(b){
            push(s,b%16);
            b=b/16;
        }
        cout<<"������ʮ������Ϊ��";
        while(s.top!=s.base){
            pop(s);
        }*/
        cout<<endl<<endl;
    }
}
