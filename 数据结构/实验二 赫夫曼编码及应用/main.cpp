#include <bits/stdc++.h>
using namespace std;
/*
思路：1.使用map构建出现字符的权值
	  2.使用vector组成线性结构构建成二叉树的存储 
	  3.使用priority_queue构建弹出权值最小的字符并且删除 
流程：1.使用文件流读取文件，然后使用map进行存储并计算出最大权值
	  2.使用迭代器将map中的所有元素以结构体形式存入priority_queue里面，并且结构体中重载<运算符
	  3.先将权值较小的元素弹出并构成哈夫曼树，以vector进行承载，当然，此时的vector里面还是同一种结构体类型
	  4.哈夫曼树的左右孩子用数组下标标明地址
	  5.再使用第二种map对其进行编码字符相应替换功能
	  
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
//优先队列
priority_queue<huffman> que;
//出现次数 
map<char, int> times;
map<char, int> :: iterator timeIterator;
//每个字符的对应编码 
map<char, string> code;
map<char, string> :: iterator codeIterator;
//文件指针
ifstream infile;//读模式 
ofstream outfile;//写模式 
//动态数组
vector<huffman> vec; 

void welcome(){
	cout<<"实验二 哈夫曼编码及其应用"<<endl;
	cout<<"1.编码(构造哈夫曼树)"<<endl;
	cout<<"2.对比文件"<<endl;
	cout<<"3.清空内存"<<endl;
	cout<<"0.退出"<<endl;
}
void creatTree(){
	vec.push_back(huffman(0,0,0,0,'n'));
	huffman huf1 = que.top();
	
}
void creatHuffman(){
	cout<<"请输入你想要读取的文件路径(txt后缀)"<<endl;
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
	cout<<"已读取到文件"<<endl;
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
