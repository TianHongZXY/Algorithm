//实现堆的基本操作
#include<iostream>
#include<vector>
using namespace std;
int N,ans=0;
vector<int>val;
void DownHeap(){//堆纠正  
	int k=1;
	while(2*k<=ans){//如果有左孩子 k的左孩子为2k 右孩子为2k+1 
		int j=2*k;//指向左孩子
		if(j<ans&&val[j]>val[j+1])//k的左右孩子进行相比较 
			j=j+1;//若右孩子小于左孩子 j指向右孩子 
		if(val[k]<=val[j])//比较小的孩子小 
			break; 
		else//说明父亲节点k要比孩子j大 需要交换 
			swap(val[k],val[j]);//交换位置 
		k=j;//k交换到新的位置，继续向下比较，一直沉到底部 
	}
}
void CreateHeap(int n){//建堆 
	val[++ans]=n;
	int i=ans;
	while(1){
		if(i<=1)
			break;
		if(val[i/2]>val[i])
			swap(val[i/2],val[i]);//进行互换 
		i=i/2;
	}
}
int main(){
	cin>>N;
	val.resize(N+2);
	int type,num;
	for(int i=0;i<N;i++){
		cin>>type;
		if(type==1){
			cin>>num;
			CreateHeap(num); 
		}else{
			cout<<val[1]<<endl;//最小值 小顶堆 最小值在第一个
			swap(val[1],val[ans]);
			--ans;//交换之后 长度减一 相当于删除这个最小的元素 在赋值的话会把原来ans位置的元素覆盖掉 不影响后面程序执行 
			DownHeap();//进行堆调整
		}
	}
	return 0;
} 

