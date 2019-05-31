#include <iostream>
#include <cstring>

using namespace std;

typedef struct student
{
    char name[20];
    int id;
    int grade;
}Student;
typedef struct sqlist
{
    Student stu;
    struct sqlist *next;
}Sqlist,*Psqlist;

void InitList(Psqlist &l){
    l=new Sqlist;
    strcpy(l->stu.name,"头节点");
    l->stu.id=0;
    l->stu.grade=0;
    l->next=NULL;
    cout<<"*****初始化成功*****"<<endl;
    cout<<l->stu.name<<" "<<l->stu.id<<" "<<l->stu.grade<<endl;
}
void InputIf(Psqlist l,int n){
    for(int i=0;i<n;i++){
        Psqlist tem=new Sqlist;
        if(!tem) cout<<"输入阶段申请失败"<<endl;
        cout<<"请依次输入学生的名字、学号、总成绩:"<<endl;
        cin>>tem->stu.name>>tem->stu.id>>tem->stu.grade;
        cout<<"*******输入的消息如下:*******"<<endl;
        cout<<tem->stu.name<<" "<<tem->stu.id<<" "<<tem->stu.grade<<endl;
        tem->next=NULL;
        l->next=tem;
        l=l->next;
    }
    cout<<"*****输入函数结束*****"<<endl;
}
int Search(Psqlist l){
    int a,b=1;
    Student *s=new Student;
    cout<<"     请按照以下提示输入消息："<<endl;
    cout<<"1.按名字查找     2.按学号查找"<<endl;
    cin>>a;
    switch(a){
    case 1:
        cout<<"请输入名字"<<endl;
        cin>>s->name;
        cout<<endl<<s->name<<endl;
        l=l->next;
        while(l&&strcmp(l->stu.name,s->name)){
            l=l->next;
            b=b+1;
        }
        if(strcmp(l->stu.name,s->name)){ cout<<"没有查找到"<<endl;return 0;}
        else return b;
        break;
    case 2:
        cout<<"请输入学号"<<endl;
        cin>>s->id;
        l=l->next;
        while(l&&l->stu.id!=s->id){
            l=l->next;
            b=b+1;
        }
        if(l->stu.id!=s->id){ cout<<"没有查找到"<<endl;return 0;}
        else return b;
        break;
    }
}
void Isert(Psqlist l,Student *st,int n){
    int j=0;
    while(l&&(j<n-1)){
        l=l->next;
        j=j+1;
    }
    Psqlist p=new Sqlist;
    p->stu=*st;
    p->next=l->next;
    l->next=p;
}
void Del(Psqlist l,int n){
    int j=0;
    while((l->next)&&(j<n-1)){
        l=l->next;
        j=j+1;
    }
   // Psqlist tem=new Sqlist;
   // tem=l;
    l->next=l->next->next;
   // delete tem;
}
void OutIf(Psqlist l){
    l=l->next;
    while(l){
        cout<<l->stu.name<<" "<<l->stu.id<<" "<<l->stu.grade<<endl;
        l=l->next;
    }
    cout<<"输出函数结束"<<endl<<endl;
}
int main()
{
    int n;
    Psqlist head;
    InitList(head);
    cout<<"请输入需要录入学生的个数:"<<endl;
    cin>>n;
    InputIf(head,n);
    OutIf(head);
    for(int a=0;a<1;a++)
    {
        int b;
        Student *s=new Student;
        cout<<"请依次输入需要插入学生的信息（姓名、学号、成绩）、位置"<<endl;
        cin>>s->name>>s->id>>s->grade>>b;
        Isert(head,s,b);
        cout<<endl<<endl<<endl;
        OutIf(head);
    }
    cout<<"请输入需要删除的序号"<<endl;
    int e;
    cin>>e;
    Del(head,e);
    OutIf(head);
    for(int j=0;j<10;j++){
        int d=Search(head);
        if(d!=0) cout<<"您查找的学生在第"<<d<<"个位置"<<endl;
    }
    cout<<"程序结束"<<endl;
    return 0;
}
