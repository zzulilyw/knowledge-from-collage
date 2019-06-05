#include <bits/stdc++.h>
#include "solve.h"
using namespace std;
const int max_n = 1000;
string textdata;
string textcode;
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
    int order = -1;
    while(1){
        welcome();
        cout<<"请输入操作命令：";
        cin>>order;
        switch(order){
        case 1:
            init();
            cout<<"请输入文件路径，必须是完整路径，加上文件后缀名：";
            cin>>path;
            textdata = readFile(path);
            cout<<"以下为文件内容："<<"\n"
                <<"----------------------------\n"
                <<textdata<<"\n"
                <<"----------------------------\n";
            CountStringChar(textdata);
            TempToArray();
            HuffmanToCode(HT,HC,w,num);
            textcode = getCode(textdata);
            cout<<"加密后的密文:"<<endl;
            cout<<textcode<<endl;
            cout<<"请输入文件完整路径以便于保存密文:";
            cin>>savePath;
            saveFile(savePath,textcode);
            cout<<"保存成功"<<endl;
            break;
        case 2:
            cout<<"请输入文件路径，必须是完整路径，加上文件后缀名：";
            cin>>path;
            textdata = readFile(path);
            textdecode = getDecode(textdata);
            cout<<"明文:"<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<textdecode<<endl;
            cout<<"-----------------------------"<<endl;
            break;
        case 3:
            cout<<"文件对比会清空已有规则"<<endl;
            contrastFile(path,savePath);
            break;
        case 4:
            cout<<"编码规则："<<endl;
            Printttime();
            cout<<"编码结果："<<endl;
            PrintCode();
            break;
        case 5:
            init();
            cout<<"清空成功！"<<endl;
            break;
        case 6:
            flag = false;
            cout<<"退出..."<<endl;
            break;
        default:
            cout<<"命令异常"<<endl;
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
        cout<<"密文文件 == 明文文件"<<endl;
    }else{
        cout<<"密文文件 != 明文文件"<<endl;
    }
}

void init(){
    textdata="";
    textcode="";
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
