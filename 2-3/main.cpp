//���ʽ��ֵ δ���
#include <iostream>
#define SIZE 20
using namespace std;

typedef struct
{
   char *base;
   char *top;
   int stackSize;
}Date;
//��ʼ��ջ
void Init(Date &s){
    s.base=new char[SIZE];
    if(!s.base){
        cout<<"�ڴ����ʧ��"<<endl;
        exit(0);
    }
    s.top=s.base;
    s.stackSize=SIZE;
}
void Push(Date &s,char a){
    if(s.top-s.base==s.stackSize){
        cout<<"ջ����"<<endl;
        exit(0);
    }
    *s.top=a;
    s.top=s.top+1;
}
void Pop(Date &s){
    if(s.top==s.base){
        cout<<"��ջ"<<endl;
        exit(0);
    }
    s.top=s.top-1;
   // cout<<*s.top<<endl;
}
int stackEmpty(Date &s){
    if(s.top==s.base) return 1;
    else return 0;
}
char getTop(Date &s){
    if(s.top!=s.base)
        return *(s.top-1);
}
int main()
{
    Date OPTR,OPND;
    Init(OPTR);
    Init(OPND);
    Push(OPTR,'#');
    char a;
    cin>>a;
    while (ch!='#'||getTop(OPTR)!='#'){
        if(!In(ch)){
            Push(OPND,ch);
            cin>>ch;
        }
        switch (Precde(getTop(OPTR),ch)) {
        case '<':
            Push(OPTR,ch);
            cin<<ch;
            break;
        case '>':
            Pop(OPTR,theta);
        default:
            break;
        }
    }
}
