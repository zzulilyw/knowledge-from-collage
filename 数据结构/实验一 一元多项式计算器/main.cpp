#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;
bool flag = 0;//�����ı�־
typedef struct ElemType{
	int a, b;
	ElemType(int aa, int bb){
		this->a = aa;
		this->b = bb;
	}
};
vector<ElemType> vec1; 
vector<ElemType> vec2;
set<int> s1;
set<int> s2;
bool cmp1(ElemType e1, ElemType e2){//��С�������� 
	if(e1.b!=e2.b){
		return e1.b<e2.b;
	}
	return e1.a<e2.a;
}
bool cmp2(ElemType e2, ElemType e1){//�Ӵ�С���� 
	if(e1.b!=e2.b){
		return e1.b<e2.b;
	}
	return e1.a<e2.a;
}
void menu(){
	cout<<"-----һԪ����ʽ������-----"<<endl;
	cout<<"1.�ֶ���������һԪ����ʽ"<<endl;
	cout<<"2.�Զ���������һԪ����ʽ"<<endl;
	cout<<"3.���һ��Ԫ��/����һ��Ԫ��"<<endl;
	cout<<"4.ɾ��Ԫ��"<<endl;
	cout<<"5.ʹ����������"<<endl;
	cout<<"6.ֱ�����������(����)"<<endl;
	cout<<"7.������������������"<<endl;
	cout<<"0.�˳���ϵͳ"<<endl;
}
void creat_by_hand(){
	cout<<"�������һ�����Ԫ�أ���0����"<<endl;
	while(1) {
		int a, b;
		cin >> a >> b;
		if(a==0){
			break;
		}
		if(s1.count(b)){
			for(vector<ElemType>::iterator it = vec1.begin(); it != vec1.end(); it++){
				if(it->b==b){
					it->a+=a;
					break;
				}
			}
		}else{
			s1.insert(b);
			ElemType elem = ElemType(a, b);
			vec1.push_back(elem);
		}
		
	}
	cout<<"������ڶ������Ԫ�أ���0����"<<endl;
	while(1){
		int a, b;
		cin >> a >> b;
		if(a==0){
			break;
		}
		if(s2.count(b)){
			for(vector<ElemType>::iterator it = vec2.begin(); it != vec2.end(); it++){
				if(it->b==b){
					it->a+=a;
					break;
				}
			}
		}else{
			s2.insert(b);
			ElemType elem = ElemType(a, b);
			vec2.push_back(elem);
		}
	}
	flag = 1;
}
void creat_by_auto(){
	cout<<"��������Ҫ�����ı�һ����"<<endl;
	int length1 = 0;
	cin >> length1;
	srand((int)time(0)); 
	for(int i = 0; i < length1; i++) {
		int a = rand()%100;
		int b = rand()%100;
		if(s1.count(b)){
			for(vector<ElemType>::iterator it = vec1.begin(); it != vec1.end(); it++){
				if(it->b==b){
					it->a+=a;
					break;
				}
			}
		}else{
			s1.insert(b);
			ElemType elem = ElemType(a, b);
			vec1.push_back(elem);
		}
	}
	cout<<"��������Ҫ�����ı������"<<endl;
	int length2 = 0;
	cin >> length2;
	for(int i = 0; i < length2; i++) {
		int a = rand()%100;
		int b = rand()%100;
		if(s2.count(b)){
			for(vector<ElemType>::iterator it = vec2.begin(); it != vec2.end(); it++){
				if(it->b==b){
					it->a+=a;
					break;
				}
			}
		}else{
			s2.insert(b);
			ElemType elem = ElemType(a, b);
			vec2.push_back(elem);
		}
	}
	flag = 1;
}
void creat_elem(){
	cout<<"���������봴����Ԫ������"<<endl;
	int length = 0;
	cin >> length;
	for(int i = 0; i < length; i++) {
		cout<<"������a, b"<<endl; 
		int a, b;
		cin >> a >> b;
		cout<<"����Ҫ�����һ���Ǳ����"<<endl;
		int c;
		cin >> c;
		ElemType elem = ElemType(a, b);
		if(c==1){
			vec1.push_back(elem);
		}else if(c==2){
			vec2.push_back(elem);
		}
		cout<<"����ɹ�"<<endl;
	}
}
void delete_elem(){
	cout<<"����������ɾ��Ԫ�صķ�ʽ"<<endl;
	cout<<"1.ɾ����ĩβԪ��"<<endl;
	cout<<"2.ɾ������������Ԫ��"<<endl;
	cout<<"3.ɾ��һ����Χ�ڵ�Ԫ��"<<endl;
	cout<<"4.��ȷɾ��ĳ��Ԫ��"<<endl;
	cout<<"5.�������Ԫ��"<<endl;
	cout<<"6.ȡ��ɾ��"<<endl;
	int ans;
	vector<ElemType>::iterator it;
	cin >> ans;
	switch(ans){
		case 1:
			cout<<"����ɾ���ĸ������ĩβԪ�أ�"<<endl;
			int ans2;
			cin >> ans2;
			if(ans2==1){
				vec1.pop_back();
			}else if(ans2==2){
				vec2.pop_back();
			}
			break;
		case 2:	
			cout<<"����������Ҫɾ��ϵ��Ϊ����Ԫ��"<<endl;
			int an2;
			cin >> an2;
			cout<<"����ɾ����һ(����1)�����(����2)�����Ƕ�ɾ(����3)��"<<endl;
			int ans3;
			cin >> ans3;
			if(ans3==1){
				for(it == vec1.begin(); it != vec1.end(); it++) {
					if(it->b==an2){
						vec1.erase(it);
						it--;
					}
				}
			}else if(ans3==2){
				for(it == vec2.begin(); it != vec2.end(); it++) {
					if(it->b==an2){
						vec2.erase(it);
						it--;
					}
				}
			}else if(ans3==3){
				for(it == vec1.begin(); it != vec1.end(); it++) {
					if(it->b==an2){
						vec1.erase(it);
						it--;
					}
				}
				for(it == vec2.begin(); it != vec2.end(); it++) {
					if(it->b==an2){
						vec2.erase(it);
						it--;
					}
				}
			}
			break;
		case 3:
			cout<<"����������Ҫɾ���ı��䷶Χ"<<endl;
			cout<<"����ɾ������Ԫ�أ�"<<endl;
			int as2;
			cin >> as2;
			if(as2==1){
				cout<<"��һ����ɾ���ķ�ΧΪ0��"<<vec1.size()<<endl;
				cout<<"����ɾ���ķ�Χ��" <<endl;
				int l, r;
				cin >> l >> r;
				for(it = l + vec1.begin(); it != r + vec1.begin(); it++){
					vec1.erase(it);
					it--;
				}
			}else if(as2==2){
				cout<<"�������ɾ���ķ�ΧΪ0��"<<vec2.size()<<endl;
				cout<<"����ɾ���ķ�Χ��" <<endl;
				int l, r;
				cin >> l >> r;
				for(it = l + vec2.begin(); it != r + vec2.begin(); it++){
					vec2.erase(it);
					it--;
				}
			}
			break;
		case 4:
			cout<<"����ɾ���ĸ����е�Ԫ�أ�"<<endl;
			int ns2;
			cin >> ns2;
			if(ns2==1){
				cout<<"��һ����ɾ���ķ�ΧΪ0��"<<vec1.size()<<endl;
				cout<<"����������Ҫɾ����Ԫ�ص��±�"<<endl;
				int ans3;
				cin >>ans3;
				it = vec1.begin() + ans3;
				vec1.erase(it);
			}else if(ns2==2){
				cout<<"�������ɾ���ķ�ΧΪ0��"<<vec2.size()<<endl;
				cout<<"����������Ҫɾ����Ԫ�ص��±�"<<endl;
				int ns3;
				cin >>ns3;
				it = vec2.begin() + ns3;
				vec1.erase(it);
			}
			break;
		case 5:
			vec1.clear();
			vec2.clear();
			flag = 0;
		case 6:
			return;
	}
}
void sort_elem(){
	cout<<"����Ӵ�С���Ǵ�С����"<<endl;
	cout<<"1.��С����"<<endl;
	cout<<"2.�Ӵ�С"<<endl;
	int ans;
	cin >> ans;
	if(ans==1){
		sort(vec1.begin(), vec1.end(), cmp1);
		sort(vec2.begin(), vec2.end(), cmp1);
	}else if(ans==2){
		sort(vec1.begin(), vec1.end(), cmp2);
		sort(vec2.begin(), vec2.end(), cmp2);
	}
	cout<<"�������"<<endl;
} 
void syso(){
	cout<<"��һ��Am(X)="<<endl;
	for(vector<ElemType>::iterator it = vec1.begin(); it != vec1.end(); it++) {
		if(it==vec1.begin()){
			cout<<it->a<<"X^"<<it->b;
		}else{
			cout<<"+"<<it->a<<"X^"<<it->b;
		}
	}
	cout<<endl;
	cout<<"�����Bn(X)="<<endl;
	for(vector<ElemType>::iterator it = vec2.begin(); it != vec2.end(); it++) {
		if(it==vec2.begin()){
			cout<<it->a<<"X^"<<it->b;
		}else{
			cout<<"+"<<it->a<<"X^"<<it->b;
		}
	}
	cout<<endl;
}
int main(){
	while(1){
		menu();
		int ans;
		cin >> ans;
		switch(ans){
			case 1:
				creat_by_hand();
				break;
			case 2:
				creat_by_auto();
				break;
			case 3:
				if(flag){
					creat_elem(); 
				}else{
					cout<<"�㻹û���������ȴ�����"<<endl;
				}
				break;
			case 4:
				if(flag){
					delete_elem();
				}else{
					cout<<"�㻹û���������ȴ�����"<<endl;
				}
			case 5:
				if(flag){
					sort_elem();
				}else{
					cout<<"�㻹û���������ȴ�����"<<endl;
				}
				break;
			case 6:
				syso();
				break;
			case 7:
				vec1.clear();
				vec2.clear();
				flag = 0;
				break;
			case 0:
				return 0;
		}
	}
}
