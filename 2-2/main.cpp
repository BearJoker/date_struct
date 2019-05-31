//括号匹配的检验
#include <iostream>
#define SIZE 20
using namespace std;

typedef struct
{
   char *base;
   char *top;
   int stackSize;
}Date;

//初始化栈
void Init(Date &s){
    s.base=new char[SIZE];
    if(!s.base){
        cout<<"内存分配失败"<<endl;
        exit(0);
    }
    s.top=s.base;
    s.stackSize=SIZE;
}
//将括号压入栈
void Push(Date &s,char a){
    if(s.top-s.base==s.stackSize){
        cout<<"栈已满"<<endl;
        exit(0);
    }
    *s.top=a;
    s.top=s.top+1;
}
//将括号推出栈
void Pop(Date &s){
    if(s.top==s.base){
        cout<<"空栈"<<endl;
        exit(0);
    }
    s.top=s.top-1;
    //测试栈顶元素
   // cout<<*s.top<<endl;
}
//判断栈是否为空
int stackEmpty(Date &s){
    if(s.top==s.base) return 1;
    else return 0;
}
//获取栈顶，可通过修改栈顶指针的指向即可
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
    cout<<"请输入一串字符"<<endl;
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
            cout<<"没有这个匹配项"<<endl;
            exit(0);
        }
        cin>>ch;
    }
    if(stackEmpty(s)&&flag) cout<<"匹配成功";
    else cout<<"匹配失败"<<endl;
}
