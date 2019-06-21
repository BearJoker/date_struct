#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

typedef struct{
    char date;
    int weight;
    int parent,lchild,rchild;
}HTNnode,*HuffmanTree;
typedef char **HuffmanCode;
void Select(HuffmanTree HT,int k,int &l,int &r){
    int min1=1000,min2=1000;
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
    for(int i=1;i<=m;++i){
        outfile<<HT[i].date<<" "<<HT[i].weight<<" "<<HT[i].parent
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
void Init_file(HuffmanTree HT){
    int n;
    ifstream in("D:\\Qt\\Project\\Course_Design\\hfmTree.txt");
    in>>n;
    if(n<=1) return;
    int m=2*n-1;
    HT=new HTNnode[m+1];
    for(int i=0;++i;i<=m){
        cin>>HT[i].date>>HT[i].weight>>HT[i].parent>>HT[i].lchild>>HT[i].rchild;
    }
}
void find(HuffmanTree HT,HuffmanCode &HC,int n){
    char c;
    ifstream in("D:\\Qt\\Project\\Course_Design\\ToBeTran.txt");
    if(!in) {cout<<"打开输入文件失败"<<endl; exit(0);}
    ofstream out("D:\\Qt\\Project\\Course_Design\\CodeFile.txt");
    if(!out) {cout<<"打开输出文件失败"<<endl; exit(0);}
    for(int i=1;i<=n;++i){
        in>>c;
        for(int j=0;j<=n;++j){
            if(c==HT[j].date){
                out<<HT[j].date<<HC[j]<<endl;
            }
        }
    }
}
