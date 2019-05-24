#include <bits/stdc++.h>
using namespace std;
//���ֽṹ���������ͣ�һ���Ƕ��㣬��һ���ǻ�
//����map��ӳ��ģʽ����������ĵ�һά 
//�����ͨ״̬����vector���л��Ĵ洢
//ʹ�����ȶ��ж������bfs�滮������nodeֻ�����ȶ����еĽ�� 
//nodeֻ�������ȶ��еĴ洢������άӳ�������д洢��ֻ��arc��vec[0]�洢����arc���ͣ��������������һ����� 
typedef struct arc;
typedef struct node;
map<string, vector<arc> > mp;
map<string, bool> vis;

typedef struct arc{//�� 
	int speed, length;
	double time;
	string destination;//��A��㵽B��� 
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
typedef struct tnode{//Ҫ�������ȶ��еĽ�� 
	double time;//��ʱ�����������ȶ����бȽϵ���ʱ�� 
	int length;//�ó������������ȶ����бȽϵĳ��� 
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
typedef struct lnode{//Ҫ�������ȶ��еĽ�� 
	double time;//��ʱ�����������ȶ����бȽϵ���ʱ�� 
	int length;//�ó������������ȶ����бȽϵĳ��� 
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
void bfs_time(){//����bfs�����������·���������ʱ�� 
	cout<<"�������������\n";
	string begin;
	cin >> begin;
	if(!mp.count(begin)){
		cout<<"û�������㣬�����˳�\n";
		system("pause");
		system("cls");			
		return;
	}
	cout<<"�������յ�����\n";
	string end;
	cin >> end;
	if(!mp.count(end)){
		cout<<"û�������㣬�����˳�\n";
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
			cout<<"�����ʱ�����������\n";
			cout<<"��С��ʱ"<<now.time<<"�룬\n·���滮Ϊ:\n"<<now.procedure<<"\n";
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
	cout<<"û���ҵ����ʵ�·��\n";
	return;
}
void bfs_length(){
	cout<<"�������������\n";
	string begin;
	cin >> begin;
	if(!mp.count(begin)){
		cout<<"û�������㣬�����˳�\n";
		system("pause");
		system("cls");			
		return;
	}
	cout<<"�������յ�����\n";
	string end;
	cin >> end;
	if(!mp.count(end)){
		cout<<"û�������㣬�����˳�\n";
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
			cout<<"�����ʱ�����������\n";
			cout<<"��С��ʱ"<<now.time<<"�룬·���滮Ϊ"<<now.procedure<<"\n";
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
	cout<<"û���ҵ����ʵ�·��\n";
	return;
}
void menu(){
	cout<<"ʵ���� ͼ����Ӧ��\n";
	cout<<"1.�������ͻ�\n";
	cout<<"2.���������յ����������ʱ��滮\n";
	cout<<"3.���������յ����������·���滮\n";
	cout<<"4.ɾ����(��·������¼�)\n";
	cout<<"5.ɾ�����\n";
	cout<<"6.֣�ݵ����˳�·�߹滮����\n";
	cout<<"0.�˳���ϵͳ\n";
}
void creat_node_and_arc(){
	cout<<"���������봴����������\n";
	int num = 0;
	cin >> num;
	for(int i = 0; i < num; i++) {
		if(i==0){
			cout<<"����������Ҫ�����Ľ������\n";
		}
		string str;
		cin >> str;
		vector<arc> vec;
		arc a = arc(0, 0);
		vec.push_back(a);
		mp[str] = vec;
	}
	cout<<"���������봴���Ļ�������\n";
	num = 0;
	cin >> num;
	for(int i = 0; i < num; i++) {
		cout<<"�������"<<i+1<<"������\n";
		cout<<"�������������˭��������һ���ַ�����\n";
		string str1;
		cin >> str1;
		if(!mp.count(str1)){
			cout<<"û�������㣬����������\n";
			system("pause");
			system("cls");
			i--;
			continue;
		}
		cout<<"���������յ���˭��������һ���ַ�����\n";
		string str2;
		cin >> str2;
		if(!mp.count(str2)){
			cout<<"û�������㣬����������\n";
			system("pause");
			system("cls");
			i--;
			continue;
		}
		cout<<"�������ĳ��Ⱥ�ͨ���ٶȣ��밴�� ����-ͨ���ٶ� ��ʽ���룩\n";
		int length, speed;
		cin >> length >> speed;
		cout<<"�������ǵ���Ļ���˫��ģ�����������1��˫������2��\n";
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
	cout<<"�����ɹ�\n";
}
void delete_node(){
	cout<<"��������ɾ���Ľ�����ƣ�\n";
	string ans;
	cin >> ans;
	if(mp.count(ans)){
		mp[ans].clear();
		mp.erase(ans);
		cout<<"ɾ���ɹ�\n"; 
	}else{
		cout<<"û��������\n";
	}

}
void delete_arc(){
	cout<<"��������ɾ���Ļ�\n";
	cout<<"������������˭��\n";
	string begin;
	cin >> begin;
	cout<<"��������յ���˭��\n";
	string end;
	cin >> end;
	cout<<"����ɾ��������ĵ�����˫�򣿵�������1��˫������2\n";
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
		cout<<"�����ɹ�\n";
	}else{
		cout<<"����ʧ��\n";
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
				cout<<"������������������"<<endl;
				system("pause");
				system("cls");
		}
	}
} 
