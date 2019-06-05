#include <bits/stdc++.h>
#define left(x) 2*x+1
#define right(x) 2*(x+1)
using namespace std;
vector<int> arr;
int length;
void menu(){
	cout<<"ʵ���� ���õ��ڲ������㷨\n";
	cout<<"1.����һ������\n";
	cout<<"2.ֱ�Ӳ�������\n";
	cout<<"3.��ѡ������\n";
	cout<<"4.ð������\n";
	cout<<"5.�۰��������\n";
	cout<<"6.ϣ������\n";
	cout<<"7.��������\n";
	cout<<"8.������\n";
	cout<<"9.�������\n";
	cout<<"10.��ʾ������\n";
	cout<<"0.�˳���ϵͳ\n";
}
void print(int *a, int len){
	for(int i = 0; i < len; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void creat_array(){
	cout<<"�����봴������ĳ���\n";
	cin >> length;
	cout<<"�����봴��������Ԫ�أ��м��ÿո����\n";
	for(int i = 0; i < length; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	cout<<"�����ɹ���\n";
}
void InsertSort(int* a,int len)//�������� 
{
    int begin = 1;
    int i = 0;
    while(begin < len)
    {
        int key = a[begin];
        for(i = begin-1;i>=0;i--)
        {
            if(a[i]<=key)    
            {
                a[i+1] = key;
                break;
            }
            a[i+1] = a[i];
        }
        if(i<0)
            a[0] = key;//˵���������������������ж�û�ҵ�
        begin++;
    }
    print(a, len);
}
void SelectionSort (int *array, int size){
    int startScan, minIndex, minValue;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
    print(array, size);
}
void BubbleSort(int *array, int len){
	int t;
	for(int i = 0; i < len - 1; i++) {
		for(int j = i + 1; j < len; j++) {
			if(array[i]>array[j]){
				t = array[j];
				array[j] = array[i];
				array[i] = t;
			}
		}
	}
	print(array, len);
}
void InsertBinarySort(int* a, int n){
    for(int i=1;i<n;++i)
    {
        if(a[i]<a[i-1])
        {
           int low = 0;
           int high = i-1;
           int j;
           int temp = a[i];
           while(low<=high)
           {
               int mid=(low+high)/2;
               if(a[mid]==a[i])
               {//��a[i]����a[mid]�ұ�
                   for( j=i-1;j>mid;--j)
                   {
                       a[j+1]=a[j];
                   }
                 a[mid+1] = temp;
               }
               else if(a[mid]<a[i])
               {
                   low=mid+1;
               }
               else
               {
                   high=mid-1;
               }
           }
           if(low>high)/*˵����ǰ�����Ԫ�ز������ź����������,��ʱӦ�ý�Ԫ�ط���index����low��������index����high+1����*/
           {
               for( j=i-1;j>=low;--j)
                   {
                       a[j+1]=a[j];
                   }
                   a[low] = temp;
           }
        }
    }
	print(a, n);
}

void ShellSort(int array[], int n){//ϣ������ 
	int i, j;
	int increment = n;
	do{
		increment = increment / 3 + 1;//��������
		for (i = increment + 1; i <= n; i++)
		{
			if (array[i] < array[i - increment])
			{
				array[0] = array[i];
				for (j = i - increment; j>0 && array[0] < array[j]; j -= increment)
					array[j + increment] = array[j];
				array[j + increment] = array[0];
			}
		}
	} 
	while (increment>1);
	print(array, n); 
}
void quicksort(int data[], int first, int last){
    int lower = first + 1;
    int upper = last;
    swap(data[first], data[(first + last) / 2]);
    int bound = data[first];
    while (lower <= upper)
    {
        while (data[lower] < bound)
            lower++;
        while (data[upper] > bound)
            upper--;
        if (lower < upper)
            swap(data[lower++], data[upper--]);
        else lower++;
    }
    swap(data[upper], data[first]);
    if (first < upper - 1)
        quicksort(data, first, upper - 1);
    if (upper + 1 < last)
        quicksort(data, upper + 1, last);
    
}
//�ٶ���ĳһ���ڵ�i�������������Ƕ������ѣ����Ƕ��ڽڵ�i�����������ӽڵ�������ƻ����ѵ����ʣ�������дһ����������
//����µĶ�������ά��ʹ����Ķ�������������
void MaxHeapify(int* a,int i,int low,int high){/*����ΪҪ�����������͸��ڵ㣬����a���б�ά������һ���ֵ��±�low��high*/
    int l = left(i);//�����±�Ϊi�Ľڵ�����ӽڵ�
    int r = right(i);//�����±�Ϊi�Ľڵ�����ӽڵ�
    int largest;//����i,l,r(��i�����������ӽڵ�)֮�����������±�
    int temp;//���������е�����ʹ�õ���ʱ����
    //�ҵ����������������Ǹ������������Ǹ�����i���л���
    if (l<=high && a[l]>a[i]){
        largest = l;
    }else{
        largest = i;
    }

    if (r<=high && a[r]>a[largest]){
        largest = r;
    }
    if (largest != i){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        MaxHeapify(a, largest,low,high);//�����п����ƻ��������������ʣ����Զ����������Ǹ��ӽڵ����һ��ά������δ�������Ǹ��ӽڵ㣬�������ǵļ��裬�Ǳ������������ʵġ�
    }
}
//�����齨��Ϊһ������
//�������鵱������λ�ý��䴦��Ϊһ������
void BuildMaxHeap(int* a,int length){
    for (int i = length / 2-1; i >= 0; i--){
        MaxHeapify(a, i, 0, length - 1);
    }
}
//��������
void HeapSort(int* a,int length){
    int temp;
    BuildMaxHeap(a,length);
    for (int i = length - 1; i >= 1; i--){
        //�������ڵ����������һ���ڵ�
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        MaxHeapify(a, 0, 0, i-1);//ά�����±�Ϊi-1��0��������
    }
}
int main(){
	while(1){
		menu();
		int ans;
		cin >> ans;
		switch(ans){
			case 1:
				creat_array();
				break;
			case 2:
				InsertSort(&arr[0], arr.size());
				break;
			case 3:
				SelectionSort(&arr[0], arr.size());
				break;
			case 4:
				BubbleSort(&arr[0], arr.size());
				break;
			case 5:
				InsertBinarySort(&arr[0], arr.size());
				break;
			case 6:
				ShellSort(&arr[0], arr.size());
				break;
			case 7:
				sort(arr.begin(), arr.end());
				print(&arr[0], arr.size());
				break;
			case 8:
				HeapSort(&arr[0], arr.size());
				print(&arr[0], arr.size());
				break;
			case 9:
				arr.clear();
				break;
			case 10:
				print(&arr[0], arr.size());
				break;
			case 0:
				return 0;
		}
	}
} 
