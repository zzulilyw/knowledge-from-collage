#include <bits/stdc++.h>
#include "solve.h"
using namespace std;
const int max_n = 1000;
string dtext;
string ctext;
string textdecode;
string path,savePath;
map<char,int> ttime;
map<char,int> :: iterator timeIterator;
map<char,string> tcode;
map<char,string> :: iterator codeIterator;
char key[max_n];
int w[max_n];
HuffmanTree HT;
HuffmanCode HC;
int num = 0;
void CountStringChar(string s);
void Printttime();
void TempToArray();
void PrintCode();
string getCode(string data);
string getDecode(string data);
void init();

void contrastFile(string code,string decode);
int main()
{
    bool flag = true;
    int choose = -1;
    while(1){
        welcome();
        cout<<"������������";
        cin>>choose;
        switch(choose){
        case 1:
            init();
            cout<<"�������ļ�·��������������·���������ļ���׺����";
            cin>>path;
            dtext = readFile(path);
            cout<<"����Ϊ�ļ����ݣ�"<<"\n"
                <<"----------------------------\n"
                <<dtext<<"\n"
                <<"----------------------------\n";
            CountStringChar(dtext);
            TempToArray();
            HuffmanToCode(HT,HC,w,num);
            ctext = getCode(dtext);
            cout<<"���ܺ������:"<<endl;
            cout<<ctext<<endl;
            cout<<"�������ļ�����·���Ա��ڱ�������:";
            cin>>savePath;
            saveFile(savePath,ctext);
            cout<<"����ɹ�"<<endl;
            break;
        case 2:
            cout<<"�������ļ�·��������������·���������ļ���׺����";
            cin>>path;
            dtext = readFile(path);
            textdecode = getDecode(dtext);
            cout<<"����:"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<textdecode<<endl;
            cout<<"-----------------------------"<<endl;
            break;
        case 3:
            cout<<"�ļ��ԱȻ�������й���"<<endl;
            contrastFile(path,savePath);
            break;
        case 4:
            cout<<"�������"<<endl;
            Printttime();
            cout<<"��������"<<endl;
            PrintCode();
            break;
        case 5:
            init();
            cout<<"��ճɹ���"<<endl;
            break;
        case 6:
            flag = false;
            cout<<"�˳�..."<<endl;
            break;
        default:
            cout<<"�����쳣"<<endl;
            break;
        }
        if(!flag) break;
    }
    return 0;
}
void contrastFile(string code,string decode){
    init();
    string data = readFile(code);
    CountStringChar(data);
    TempToArray();
    HuffmanToCode(HT,HC,w,num);
    string temp1 = getCode(data);

    string temp2 = readFile(decode);

    if(temp1 == temp2){
        cout<<"�����ļ��������ļ�һ��"<<endl;
    }else{
        cout<<"�����ļ��������ļ���һ��"<<endl;
    }
}

void init(){
    dtext="";
    ctext="";
    textdecode="";
    path="";
    savePath="";
    num = 0;
    ttime.clear();
    tcode.clear();

}
string getDecode(string data)
{
    string ans = "",temp;
    int L=0,R=1,length = data.size();
    while(L<length&&R<=length){
        temp = data.substr(L,R-L);
        char c;
        bool flag = false;
        for( codeIterator = tcode.begin(); codeIterator!=tcode.end(); codeIterator++){
            if(codeIterator->second == temp){
                c = codeIterator->first;
                flag = true;
                break;
            }
        }
        if(flag){
            L = R;
            R = L+1;
            ans += c;
        }
        else{
            R++;
        }
    }
    return ans;
}
string getCode(string data){
    string s="",temp;
    int length = data.size();
    tcode.clear();
    for (int i = 1; i <=num; i++){
        temp = "";
        for(int j=0;HC[i][j]!='\0';j++){
            temp += HC[i][j];
        }
        tcode[key[i]] = temp;
    }
    for(int i = 0;i<length;i++){
        s += tcode[data[i]];
    }
    return s;
}
void PrintCode(){
    for (int i = 1; i <=num; i++){
        if(key[i] == '\n'){
            cout<<"\\n"<<":"<<HC[i]<<" ";
        }else
            cout<<key[i]<<":"<<HC[i]<<" ";

        if(++i<=num){
            if(key[i] == '\n'){
                cout<<"\\n"<<":"<<HC[i]<<endl;
            }else
                cout<<key[i]<<":"<<HC[i]<<endl;
        }else{
            cout<<endl;
        }
    }
}
void TempToArray(){
    int i = 1;
    num = ttime.size();
    for(timeIterator = ttime.begin();timeIterator!=ttime.end();timeIterator++){
        key[i] = timeIterator->first;
        w[i] = timeIterator->second;
        i++;
    }
}
void Printttime(){

    for(timeIterator = ttime.begin();timeIterator!=ttime.end();timeIterator++){
        if(timeIterator->first == '\n'){
            cout<<"\\n"<<":"<<timeIterator->second<<endl;
        }
        else cout<<timeIterator->first<<":"<<timeIterator->second<<endl;
    }
}
void CountStringChar(string s){
    ttime.clear();
    if(s.size() == 0) return ;
    int length = s.size();
    for(int i=0;  i<length; i++){
        ttime[s[i]]++;
    }
}
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
    cout<<"ʵ��� ���������뼰��Ӧ��"<<endl;
    cout<<"1.����\n2.����"<<endl;
    cout<<"3.�Ա�\n4.�鿴����"<<endl;
    cout<<"5.����ڴ�\n6.�˳�����"<<endl;
}
