#include <iostream>
#include <fstream>
#include<cstring>

using namespace std;
typedef struct{
    char date;
    int weight;
    int parent,lchild,rchild;
}HTNnode,*HuffmanTree;
typedef char **HuffmanCode;

void Select(HuffmanTree HT,int k,int &l,int &r){
    int min1=0x3f3f3f3f,min2=0x3f3f3f3f;
        for(int i=1;i<=k;++i)
        {
            if((HT[i].parent==0) && (HT[i].weight<min1))
            {
                min1=HT[i].weight;
                l=i;
            }
        }
        for(int i=1;i<=k;++i)
        {
            if((HT[i].parent==0) && (HT[i].weight<min2) && (i!=l))
            {
                min2=HT[i].weight;
                r=i;
            }
        }
}
void Init(HuffmanTree &HT,int n){
    if(n<=1) return;
    int m=2*n-1;
    HT=new HTNnode[m+1];
    for(int i=1;i<=m;++i){
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    cout<<"请依次输入字符，权值"<<endl;
    for(int i=1;i<=n;++i){
        cin>>HT[i].date>>HT[i].weight;
    }
    for(int i=n+1;i<=m;++i){
        int l=0,r=0;
        Select(HT,i-1,l,r);
        HT[l].parent=i;HT[r].parent=i;
        HT[i].lchild=l;HT[i].rchild=r;
        HT[i].weight=HT[l].weight+HT[r].weight;
    }
    ofstream outfile("D:\\Qt\\Project\\Course_Design\\hfmTree.txt");
    if(!outfile) {cout<<"打开输出文件失败"<<endl; exit(0);}
    outfile<<n<<endl;
    for(int i=1;i<=n;++i){
        outfile<<HT[i].date<<" "<<HT[i].weight<<" "<<HT[i].parent
              <<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;
    }
    for(int i=n+1;i<=m;++i){
        outfile<<"   "<<HT[i].weight<<" "<<HT[i].parent
              <<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;
    }
    outfile.close();
}
void Encoding(HuffmanTree HT,HuffmanCode &HC,int n){
    int start,c,f;
    HC=new char*[n+1];
    char *cd=new char[n];
    cd[n-1]='\0';
    for(int i=1;i<=n;++i)
    {
        start=n-1;
        c=i;
        f=HT[i].parent;
        while(f!=0)
        {
            --start;
            if(HT[f].lchild==c)
                cd[start]='0';
            else
                cd[start]='1';
            c=f;
            f=HT[f].parent;
        }
        HC[i]=new char[n-start];
        strcpy(HC[i],&cd[start]);
    }
    delete cd;
}
void Init_file(HuffmanTree &HT){
    int a;
    ifstream in("D:\\Qt\\Project\\Course_Design\\hfmTree.txt");
    in>>a;
    if(a<=1) return;
    int m=2*a-1;
    HT=new HTNnode[m+1];
    for(int i=1;i<=a;++i){
        in>>HT[i].date>>HT[i].weight>>HT[i].parent>>HT[i].lchild>>HT[i].rchild;
    }
    for(int i=a+1;i<=m;++i){
        in>>HT[i].weight>>HT[i].parent>>HT[i].lchild>>HT[i].rchild;
    }
}
void find(HuffmanTree HT,HuffmanCode &HC,int n){
    char c;
    ifstream in("D:\\Qt\\Project\\Course_Design\\ToBeTran.txt");
    if(!in) {cout<<"打开输入文件失败"<<endl; exit(0);}
    ofstream out("D:\\Qt\\Project\\Course_Design\\CodeFile.txt",ios::trunc);
    if(!out) {cout<<"打开输出文件失败"<<endl; exit(0);}
    while(in.get(c))
    {
        for(int j=1;j<=n;++j){
            if(c==HT[j].date){
                out<<HC[j];
            }
        }
    };
}
void Decoding(HuffmanTree S,ifstream &in,ofstream &out,int m,HuffmanTree &HT,int head){
    char c;
    if(S->lchild==0&&S->rchild==0){
        out<<S->date;
        S=&HT[head];
        Decoding(S,in,out,m,HT,head);
    }
    if(in.get(c)){
        if(c=='0'){
            m=S->lchild;
            S=&HT[m];
            Decoding(S,in,out,m,HT,head);
        }
        if(c=='1'){
            m=S->rchild;
            S=&HT[m];
            Decoding(S,in,out,m,HT,head);
        }
    }
}

int main()
{
    cout<<"******************************************"<<endl;
    cout<<"********************选择功能***************"<<endl;
    cout<<"*       I:初始化           E:编码         *"<<endl;
    cout<<"*       D:编译             P:输出         *"<<endl;
    cout<<"*               Q:退出                    *"<<endl;
    cout<<"******************************************"<<endl;
    HuffmanTree HT;
    HT=NULL;
    char op;
    int n;
    cout<<"按照提示选择功能"<<endl;
    cin>>op;
    while(op!='Q'){
        switch(op){
        case 'I':
            cout<<"请输入符个数:"<<endl;
            cin>>n;
            Init(HT,n);
            break;
        case 'E':
        {
            HuffmanCode HC;
            if(HT==NULL){
                ifstream infile("D:\\Qt\\Project\\Course_Design\\hfmTree.txt");
                if(!infile) {cout<<"E处打开文件失败"<<endl;exit(1);}
                infile>>n;
                Init_file(HT);
            }
            Encoding(HT,HC,n);
            find(HT,HC,n);
            break;
        }
        case 'D':
        {
            ifstream readfile("D:\\Qt\\Project\\Course_Design\\CodeFile.txt");
            if(!readfile){cout<<"D处打开输入文件失败"<<endl;exit(0);}
            ofstream outfile("D:\\Qt\\Project\\Course_Design\\TextFile.txt");
            if(!readfile){cout<<"D处打开输出文件失败"<<endl;exit(0);}
            HuffmanTree tem;
            int m=2*n-1;
            tem=&HT[m];
            int head=m;
            Decoding(tem,readfile,outfile,m,HT,head);
            break;
        }
        case 'P':
            break;
        default:
            cout<<"没有这个选项，请重新选择"<<endl;
        }
        cout<<"按照提示选择功能"<<endl;
        cin>>op;
    }

}
