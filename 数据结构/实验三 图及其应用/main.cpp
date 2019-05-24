#include <bits/stdc++.h>
using namespace std;
//两种结构体数据类型，一种是顶点，另一种是弧
//采用map的映射模式来创建数组的第一维 
//结点连通状态采用vector进行弧的存储
//使用优先队列对其进行bfs规划，其中node只是优先队列中的结点 
//node只用于优先队列的存储，而二维映射数组中存储的只是arc，vec[0]存储的是arc类型，但是它代表的是一个结点 
typedef struct arc;
typedef struct node;
map<string, vector<arc> > mp;
map<string, bool> vis;

typedef struct arc{//弧 
	int speed, length;
	double time;
	string destination;//从A结点到B结点 
	arc(int speed, int length){
		this->length = length;
		if(length==0){
			this->speed = 0;
		}else{
			this->speed = speed;
		} 
		this->time = 1.0*length/speed;
		this->destination = "";
	}
};
typedef struct tnode{//要存入优先队列的结点 
	double time;//该时间是用作优先队列中比较的总时间 
	int length;//该长度是用作优先队列中比较的长度 
	string procedure;
	string name; 
	tnode(double time, int length, string name, string procedure){
		this->length = length;
		this->time = time;
		this->name = name;
		this->procedure = procedure;
	}
	bool operator < (const tnode &n) const {
		return this->time < n.time;
	}
}; 
typedef struct lnode{//要存入优先队列的结点 
	double time;//该时间是用作优先队列中比较的总时间 
	int length;//该长度是用作优先队列中比较的长度 
	string procedure;
	string name; 
	lnode(double time, int length, string name, string procedure){
		this->length = length;
		this->time = time;
		this->name = name;
		this->procedure = procedure;
	}
	bool operator < (const lnode &n) const {
		return this->time < n.time;
	}
}; 
void bfs_time(){//采用bfs进行搜索最短路径或者最短时间 
	cout<<"请输入起点名称\n";
	string begin;
	cin >> begin;
	if(!mp.count(begin)){
		cout<<"没有这个结点，即将退出\n";
		system("pause");
		system("cls");			
		return;
	}
	cout<<"请输入终点名称\n";
	string end;
	cin >> end;
	if(!mp.count(end)){
		cout<<"没有这个结点，即将退出\n";
		system("pause");
		system("cls");
		return;
	}
	priority_queue<tnode> que;
	que.push(tnode(0, mp[begin][0].length, begin, begin));
	while(!que.empty()){
		tnode now = que.top();
		que.pop();
		if(now.name == end){
			cout<<"最短用时方案结果如下\n";
			cout<<"最小用时"<<now.time<<"秒，\n路径规划为:\n"<<now.procedure<<"\n";
			vis.clear();
			return; 
		}
		vis[now.name] = true;
		for(vector<arc>::iterator it = mp[now.name].begin(); it != mp[now.name].end(); it++) {
			if(!vis[it->destination]){ 
				que.push(tnode(it->time+now.time, it->length+now.length, it->destination, now.name+" -> "+it->destination));
			}
		}
	}
	cout<<"没有找到合适的路径\n";
	return;
}
void bfs_length(){
	cout<<"请输入起点名称\n";
	string begin;
	cin >> begin;
	if(!mp.count(begin)){
		cout<<"没有这个结点，即将退出\n";
		system("pause");
		system("cls");			
		return;
	}
	cout<<"请输入终点名称\n";
	string end;
	cin >> end;
	if(!mp.count(end)){
		cout<<"没有这个结点，即将退出\n";
		system("pause");
		system("cls");
		return;
	}
	priority_queue<lnode> que;
	que.push(lnode(0, mp[begin][0].length, begin, begin));
	while(!que.empty()){
		lnode now = que.top();
		que.pop();
		if(now.name == end){
			cout<<"最短用时方案结果如下\n";
			cout<<"最小用时"<<now.time<<"秒，路径规划为"<<now.procedure<<"\n";
			vis.clear();
			return; 
		}
		vis[now.name] = true;
		for(vector<arc>::iterator it = mp[now.name].begin(); it != mp[now.name].end(); it++) {
			if(!vis[it->destination]){ 
				que.push(lnode(it->time+now.time, it->length+now.length, it->destination, now.name+" -> "+it->destination));
			}
		}
	}
	cout<<"没有找到合适的路径\n";
	return;
}
void menu(){
	cout<<"实验三 图及其应用\n";
	cout<<"1.创建结点和弧\n";
	cout<<"2.输入起点和终点帮你进行最短时间规划\n";
	cout<<"3.输入起点和终点帮你进行最短路径规划\n";
	cout<<"4.删除弧(修路等添加事件)\n";
	cout<<"5.删除结点\n";
	cout<<"6.郑州地铁乘车路线规划样例\n";
	cout<<"0.退出本系统\n";
}
void creat_node_and_arc(){
	cout<<"请输入你想创建结点的数量\n";
	int num = 0;
	cin >> num;
	for(int i = 0; i < num; i++) {
		if(i==0){
			cout<<"请输入你想要创建的结点名称\n";
		}
		string str;
		cin >> str;
		vector<arc> vec;
		arc a = arc(0, 0);
		vec.push_back(a);
		mp[str] = vec;
	}
	cout<<"请输入你想创建的弧的数量\n";
	num = 0;
	cin >> num;
	for(int i = 0; i < num; i++) {
		cout<<"请输入第"<<i+1<<"组数据\n";
		cout<<"这条弧的起点是谁？（输入一个字符串）\n";
		string str1;
		cin >> str1;
		if(!mp.count(str1)){
			cout<<"没有这个结点，请重新输入\n";
			system("pause");
			system("cls");
			i--;
			continue;
		}
		cout<<"这条弧的终点是谁？（输入一个字符串）\n";
		string str2;
		cin >> str2;
		if(!mp.count(str2)){
			cout<<"没有这个结点，请重新输入\n";
			system("pause");
			system("cls");
			i--;
			continue;
		}
		cout<<"这条弧的长度和通行速度（请按照 长度-通行速度 方式输入）\n";
		int length, speed;
		cin >> length >> speed;
		cout<<"这条弧是单向的还是双向的？（单向输入1，双向输入2）\n";
		int type;
		cin >> type;
		arc a = arc(speed, length);
		a.destination = str2;
		mp[str1].push_back(a);
		if(type==2){
			a.destination = str1;
			mp[str2].push_back(a);
		}
	}
	cout<<"创建成功\n";
}
void delete_node(){
	cout<<"输入你想删除的结点名称：\n";
	string ans;
	cin >> ans;
	if(mp.count(ans)){
		mp[ans].clear();
		mp.erase(ans);
		cout<<"删除成功\n"; 
	}else{
		cout<<"没有这个结点\n";
	}

}
void delete_arc(){
	cout<<"输入你想删除的弧\n";
	cout<<"这个弧的起点是谁？\n";
	string begin;
	cin >> begin;
	cout<<"这个弧的终点是谁？\n";
	string end;
	cin >> end;
	cout<<"你想删除这个弧的单向还是双向？单向输入1，双向输入2\n";
	int type;
	cin >> type;
	bool flag = 0;
	for(vector<arc>::iterator it = mp[begin].begin(); it != mp[begin].end(); it++) {
		if(it->destination == end){
			mp[begin].erase(it);
			flag = 1;
			break;
		}
	}
	if(type==2){
		for(vector<arc>::iterator it = mp[end].begin(); it != mp[end].end(); it++) {
			if(it->destination == begin){
				mp[end].erase(it);
				flag = 1;
				break;
			}
		}
	}
	if(flag){
		cout<<"操作成功\n";
	}else{
		cout<<"操作失败\n";
	}
}

int main(){
	while(1){
		menu();
		int choose;
		cin >> choose;
		switch(choose){
			case 1:
				creat_node_and_arc();
				break;
			case 2:
				bfs_time();
				break;
			case 3:
				bfs_time();
				break;
			case 4:
				delete_arc();
				break;
			case 5:
				delete_node();
				break;
			case 0:
				return 0;
			default:
				system("cls");
				cout<<"输入有误请重新输入"<<endl;
				system("pause");
				system("cls");
		}
	}
} 
