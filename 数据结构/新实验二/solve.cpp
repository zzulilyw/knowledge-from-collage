#include <bits/stdc++.h>
#include "solve.h"
using namespace std;

string readFile(string path)
{
    const char * filepath = path.data();
    ifstream ifile(filepath);
    ostringstream buf;
    char ch;
    while(buf&&ifile.get(ch))
        buf.put(ch);
    ifile.close();
    return buf.str();
}

void saveFile(string savePath,string data){
    ofstream outFile;
    const char * path = savePath.data();
    outFile.open(path);
    outFile << data;
    outFile.close();
}

void select(const HuffmanTree &HT,int n,int &s1,int &s2){
    s1 = s2 = 0;

    int min1 = INF,min2 = INF;

    for (int i=1; i<=n; ++i){
        
        if ( HT[i].parent == 0 ){
            if ( HT[i].weight < min1 ){
                min2 = min1;
                s2 = s1;
                min1 = HT[i].weight;
                s1 = i;
            }
            else if ( (HT[i].weight >= min1) && (HT[i].weight < min2) ){
                min2 = HT[i].weight;
                s2 = i;
            }
        }
    }
}
void HuffmanToCode(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{

    int s1,s2;
    int m = 2*n-1;
    int i,c,f,j;
    HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));

    
    for (int i=1; i<=n; i++)
        HT[i] = {w[i],0,0,0};
    
    for (int i=n+1; i<=m; i++)
        HT[i] = {0,0,0,0};

    
    for (int i=n+1; i<=m; i++){
        
        select(HT,i-1,s1,s2);
        
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].Lchild = s1;
        HT[i].Rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    
    HC = (HuffmanCode)malloc((n)*sizeof(char *));
    
    char * code = (char *)malloc(n*sizeof(char));
    code[n-1] = '\0';

    for (int i = 1; i <= n; i++ ){
        int start = n-1;
        for (int c = i,f = HT[c].parent; f!=0; c=HT[c].parent,f=HT[c].parent){
            
            if ( HT[f].Lchild == c )
                code[--start] = '0';
            else if(HT[f].Rchild == c)
                code[--start] = '1';
        }
        HC[i] = (char *)malloc(strlen(code)*sizeof(char));
        strcpy(HC[i],&code[start]);
    }
}

void welcome(){
    cout<<"实验二 哈夫曼编码及其应用"<<endl;
    cout<<"1.文件编码\n2.文件解码"<<endl;
    cout<<"3.文件对比\n4.查看规则"<<endl;
    cout<<"5.清空内存\n6.退出程序"<<endl;
}
