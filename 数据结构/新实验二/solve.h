#include <bits/stdc++.h>
using namespace std;
#ifndef SOLVE_H_INCLUDED
#define SOLVE_H_INCLUDED
//����������� 

const int INF = 0x3f3f3f3f;

typedef struct huffNode
{
    int weight;   
    int Lchild,Rchild,parent;  
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

void select(const HuffmanTree &HT,int n,int &s1,int &s2);
void HuffmanToCode(HuffmanTree &HT,HuffmanCode &HC,int *w,int n);

//�ļ�������� 

string readFile(string path);
void saveFile(string savepath,string data);
//ҳ�潻����� 
void welcome();

#endif
