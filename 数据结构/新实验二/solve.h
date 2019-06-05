#include <bits/stdc++.h>
using namespace std;
#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED
//哈夫曼树相关 

const int INF = 0x3f3f3f3f;

typedef struct huffNode
{
    int weight;   
    int Lchild,Rchild,parent;  
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

void select(const HuffmanTree &HT,int n,int &s1,int &s2);
void HuffmanToCode(HuffmanTree &HT,HuffmanCode &HC,int *w,int n);

//文件处理相关 

string readFile(string path);
void saveFile(string savepath,string data);
//页面交互相关 
void welcome();

#endif
