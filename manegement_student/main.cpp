#include <iostream>
#include <cstring>

using namespace std;

typedef struct student//ѧ���Ļ�����Ϣ
{
    char name[20];
    int id;
    int grade;
}Student;
typedef struct sqlist//����Ļ�����λ
{
    Student stu;
    struct sqlist *next;
}Sqlist,*Psqlist;
//��ʼ������ʹͷ�ڵ�ĸ������ݾ���ʼ��Ϊ0��NULL��ͷ�ڵ�
void InitList(Psqlist &l){
    l=new Sqlist;
    strcpy(l->stu.name,"ͷ�ڵ�");
    l->stu.id=0;
    l->stu.grade=0;
    l->next=NULL;
    cout<<"*****��ʼ���ɹ�*****"<<endl;
    cout<<l->stu.name<<" "<<l->stu.id<<" "<<l->stu.grade<<endl;
}
//���øú�����������nѧ������Ϣ�����ҽ�����Ϣ���ӵ���ʼ�����ͷ�ڵ�
void InputIf(Psqlist l,int n){
    for(int i=0;i<n;i++){
        Psqlist tem=new Sqlist;
        if(!tem) cout<<"����׶�����ʧ��"<<endl;
        cout<<"����������ѧ�������֡�ѧ�š��ܳɼ�:"<<endl;
        cin>>tem->stu.name>>tem->stu.id>>tem->stu.grade;
        //���ڲ��������Ƿ���ȷ
        //cout<<"*******�������Ϣ����:*******"<<endl;
        //cout<<tem->stu.name<<" "<<tem->stu.id<<" "<<tem->stu.grade<<endl;
        tem->next=NULL;
        l->next=tem;
        l=l->next;
    }
    cout<<"*****���뺯������*****"<<endl;
}
//�ú���ʵ�ֲ�ѯ�����Ը������ֻ���ѧ�Ų�ѯ
int Search(Psqlist l){
    int a,b=1;
    Student *s=new Student;
    cout<<"     �밴��������ʾ������Ϣ��"<<endl;
    cout<<"1.�����ֲ���     2.��ѧ�Ų���"<<endl;
    cin>>a;
    switch(a){
    case 1:
        cout<<"����������"<<endl;
        cin>>s->name;
        cout<<endl<<s->name<<endl;
        l=l->next;
        while(l&&strcmp(l->stu.name,s->name)){
            l=l->next;
            b=b+1;
        }
        if(strcmp(l->stu.name,s->name)){ cout<<"û�в��ҵ�"<<endl;return 0;}
        else return b;
        break;
    case 2:
        cout<<"������ѧ��"<<endl;
        cin>>s->id;
        l=l->next;
        while(l&&l->stu.id!=s->id){
            l=l->next;
            b=b+1;
        }
        if(l->stu.id!=s->id){ cout<<"û�в��ҵ�"<<endl;return 0;}
        else return b;
        break;
    }
}
//�ú���ʵ�ֲ���
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
//�ú���ʵ��ɾ��
void Del(Psqlist l,int n){
    int j=0;
    while((l->next)&&(j<n-1)){
        l=l->next;
        j=j+1;
    }
    l->next=l->next->next;
}
//�ú���ʵ�����
void OutIf(Psqlist l){
    l=l->next;
    while(l){
        cout<<l->stu.name<<" "<<l->stu.id<<" "<<l->stu.grade<<endl;
        l=l->next;
    }
    cout<<"�����������"<<endl;
}
int main()
{
    int n;
    Psqlist head;
    InitList(head);
    cout<<"��������Ҫ¼��ѧ���ĸ���:"<<endl;
    cin>>n;
    InputIf(head,n);
    OutIf(head);
    //��β���
    for(int a=0;a<2;a++)
    {
        int b;
        Student *s=new Student;
        cout<<"������������Ҫ����ѧ������Ϣ��������ѧ�š��ɼ�����λ��"<<endl;
        cin>>s->name>>s->id>>s->grade>>b;
        Isert(head,s,b);
        cout<<endl<<endl<<endl;
        OutIf(head);
    }
    cout<<"��������Ҫɾ�������"<<endl;
    int e;
    cin>>e;
    Del(head,e);
    OutIf(head);
    for(int j=0;j<10;j++){
        int d=Search(head);
        if(d!=0) cout<<"�����ҵ�ѧ���ڵ�"<<d<<"��λ��"<<endl;
    }
    cout<<"�������"<<endl;
    return 0;
}
