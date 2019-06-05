#include <bits/stdc++.h>
using namespace std;
/*
˼·��1.ʹ��map���������ַ���Ȩֵ
	  2.ʹ��vector������Խṹ�����ɶ������Ĵ洢 
	  3.ʹ��priority_queue��������Ȩֵ��С���ַ�����ɾ�� 
���̣�1.ʹ���ļ�����ȡ�ļ���Ȼ��ʹ��map���д洢����������Ȩֵ
	  2.ʹ�õ�������map�е�����Ԫ���Խṹ����ʽ����priority_queue���棬���ҽṹ��������<�����
	  3.�Ƚ�Ȩֵ��С��Ԫ�ص��������ɹ�����������vector���г��أ���Ȼ����ʱ��vector���滹��ͬһ�ֽṹ������
	  4.�������������Һ����������±������ַ
	  5.��ʹ�õڶ���map������б����ַ���Ӧ�滻����
	  
*/
 
typedef struct huffman{
	int ttime, Lchild, Rchild, parent;
	char ch;
	bool friend operator < (const huffman &a, const huffman &b){
		return a.ttime > b.ttime;
	}
	huffman(int ttime, int Lchild, int Rchild, int parent, char ch){
		this->ch = ch;
		this->Lchild = Lchild;
		this->Rchild = Rchild;
		this->ttime = ttime;
		this->parent = parent;
	} 
}; 
//���ȶ���
priority_queue<huffman> que;
//���ִ��� 
map<char, int> times;
map<char, int> :: iterator timeIterator;
//ÿ���ַ��Ķ�Ӧ���� 
map<char, string> code;
map<char, string> :: iterator codeIterator;
//�ļ�ָ��
ifstream infile;//��ģʽ 
ofstream outfile;//дģʽ 
//��̬����
vector<huffman> vec; 

void welcome(){
	cout<<"ʵ��� ���������뼰��Ӧ��"<<endl;
	cout<<"1.����(�����������)"<<endl;
	cout<<"2.�Ա��ļ�"<<endl;
	cout<<"3.����ڴ�"<<endl;
	cout<<"0.�˳�"<<endl;
}
void creatTree(){
	vec.push_back(huffman(0,0,0,0,'n'));
	huffman huf1 = que.top();
	
}
void creatHuffman(){
	cout<<"����������Ҫ��ȡ���ļ�·��(txt��׺)"<<endl;
	string destination;
	cin >> destination;
	char ch[destination.length()];
	for(int i = 0; i < destination.length(); i++) {
		ch[i] = destination[i];
	}
	infile.open(ch); 
	string data;
	infile >> data;
	times.clear();
	for(int i = 0; i < data.length(); i++) {
		times[data[i]]++;
	}
	cout<<"�Ѷ�ȡ���ļ�"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<data<<endl;
	cout<<"-------------------------"<<endl;
	for(timeIterator = times.begin(); timeIterator != times.end(); timeIterator++) {
		que.push(huffman(timeIterator->second, 0, 0, 0, timeIterator->first));
	}
	times.clear();
	 
}

int main(){
	while(1){
		int ans;
		cin >> ans;
		/*switch(ans){
			case 1:
				
		}*/
	}
	return 0;
}
