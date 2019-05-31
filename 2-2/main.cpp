//����ƥ��ļ���
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
//������ѹ��ջ
void Push(Date &s,char a){
    if(s.top-s.base==s.stackSize){
        cout<<"ջ����"<<endl;
        exit(0);
    }
    *s.top=a;
    s.top=s.top+1;
}
//�������Ƴ�ջ
void Pop(Date &s){
    if(s.top==s.base){
        cout<<"��ջ"<<endl;
        exit(0);
    }
    s.top=s.top-1;
    //����ջ��Ԫ��
   // cout<<*s.top<<endl;
}
//�ж�ջ�Ƿ�Ϊ��
int stackEmpty(Date &s){
    if(s.top==s.base) return 1;
    else return 0;
}
//��ȡջ������ͨ���޸�ջ��ָ���ָ�򼴿�
char getTop(Date &s){
    if(s.top!=s.base)
        return *(s.top-1);
}
int main()
{
    Date s;
    Init(s);
    int flag=1;
    char ch;
    cout<<"������һ���ַ�"<<endl;
    cin>>ch;
    while (ch!='#'&& flag) {
        switch(ch){
        case '[':
        case '(':
            Push(s,ch);
            break;
        case ')':
            if(!stackEmpty(s)&&getTop(s)=='(')
                Pop(s);
            else flag=0;
            break;
        case ']':
            if(!stackEmpty(s)&&getTop(s)=='[')
                Pop(s);
            else flag=0;
            break;
        default:
            cout<<"û�����ƥ����"<<endl;
            exit(0);
        }
        cin>>ch;
    }
    if(stackEmpty(s)&&flag) cout<<"ƥ��ɹ�";
    else cout<<"ƥ��ʧ��"<<endl;
}
