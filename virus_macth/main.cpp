#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

typedef struct{
   char ch[100];
   int len;
}HString;

//BF�㷨
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
//���麯��
void Virus_detection()
{
    //numΪ��Ҫ����Ĵ�����mΪ�����ĳ��ȣ�flagΪ�����־
    //i,jʵ��ѭ��
   int num,m,flag,i,j; char Vir[100];
   HString Virus,Person,temp;
   ifstream inFile("������Ⱦ�����������.txt");
   ofstream outFile("������Ⱦ���������.txt");
   inFile>>num;
   while(num--)
   {
      inFile>>Virus.ch+1;
      inFile>>Person.ch+1;
      //����Virus.ch��1��Ϊ�˲���VirΪ�գ����Ҳ��Virus.ch��Person.ch����ʵ����
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
      //����Ļ��������������д�뵽�ļ���
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
