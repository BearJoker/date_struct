#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

typedef struct{
   char ch[100];
   int len;
}HString;

//BF算法
int Index_BF(HString S,HString T,int pos)
{
    int i,j;
   i=pos; j=1;
   while(i<=S.len&&j<=T.len)
   {
      if(S.ch[i]==T.ch[j]){++i;++j;}
      else{i=i-j+2;j=1;}
   }
   if(j>T.len) return i-T.len;
   else return 0;
}
//检验函数
void Virus_detection()
{
    //num为需要检验的次数，m为病毒的长度，flag为检验标志
    //i,j实现循环
   int num,m,flag,i,j; char Vir[100];
   HString Virus,Person,temp;
   ifstream inFile("病毒感染检测输入数据.txt");
   ofstream outFile("病毒感染检测输出结果.txt");
   inFile>>num;
   while(num--)
   {
      inFile>>Virus.ch+1;
      inFile>>Person.ch+1;
      //这里Virus.ch加1是为了不让Vir为空，并且测得Virus.ch和Person.ch的真实长度
      strcpy(Vir,Virus.ch+1);
      Virus.len=strlen(Virus.ch+1);
      Person.len=strlen(Person.ch+1);
      flag=0;
      m=Virus.len;
      for(i=m+1,j=1;j<=m;j++) Virus.ch[i++]=Virus.ch[j];
      Virus.ch[2*m+1]='\0';
      for(i=0;i<m;i++)
      {
         for(j=1;j<=m;j++) temp.ch[j]=Virus.ch[i+j];
         temp.ch[m+1]='\0';
         temp.len=strlen(temp.ch+1);
         flag=Index_BF(Person,temp,1);
         if(flag) break;
      }
      //在屏幕上输出结果，并且写入到文件内
      if(flag){
          outFile<<Vir<<"	"<<Person.ch+1<<"      "<<"YES"<<endl;
             cout<<Vir<<"	"<<Person.ch+1<<"      "<<"YES"<<endl;
          }
      else{
         outFile<<Vir<<"	"<<Person.ch+1<<"      "<<"NO"<<endl;
            cout<<Vir<<"	"<<Person.ch+1<<"      "<<"NO"<<endl;
      }
   }
}

int main()
{
    Virus_detection();
    return 0;
}
