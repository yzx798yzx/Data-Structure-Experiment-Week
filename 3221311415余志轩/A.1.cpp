 #include<iostream>
 #include<string.h>
 #include<stdlib.h>
 using namespace std;
 void Printf(int a[],int n){
 	for(int i=0;i<n;i++){
 		cout<<a[i]<<" ";
	 }
	 cout<<endl;
 } 
 void ShellSort(int a[],int n){
 	int i,j,d,t;
 	d=n/2; 
 	while(d>0){
 		for(i=d;i<n;i++){
 			t=a[i];
 			j=i-d;
 			while(j>=0&&t<a[j]){
 				a[j+d]=a[j];
 				j=j-d;
			 }
			 a[j+d]=t;
		 }
		d=d/2;//分组减小 
	
	 }
	 Printf(a,n);
 }
 void QuickSort(int a[],int l,int h,int n){
 	int i=l;
 	int j=h;
 	int t1=a[i],t2;
 	if(i>=j){
 		return ;
	 }
 	while(i!=j){
 		while(a[j]>=t1&&j>i){
 			j--;
		 }
		 while(a[i]<=t1&&j>i){
		 	i++;
		 }
		 if(i<j){
		 	t2=a[i];
		 	a[i]=a[j];
		 	a[j]=t2;
		 }
	}
	t2=a[l];
	a[l]=a[i];
	a[i]=t2;	
	QuickSort(a,l,i-1,n);
	QuickSort(a,i+1,h,n);
 }
 void Headpify(int a[],int n,int i){
 	int l1=i;
 	int l2=i*2+1;
 	int l3=i*2+2;
 	int t;
 	//维护堆的性质 
 	if(l2<n&&a[l1]<a[l2]){
 		l1=l2;
	 }
	if(l3<n&&a[l1]<a[l3]){
		l1=l3;
	}
	if(l1!=i){
		t=a[l1];
		a[l1]=a[i];
		a[i]=t;
		Headpify(a,n,l1);
	}
 }
 void Headpify2(int a[],int n,int i){
 	int l1=i;
 	int l2=i*2+1;
 	int l3=i*2+2;
 	int t;
 	if(l2<n&&a[l1]>a[l2]){
 		l1=l2;
	 }
	if(l3<n&&a[l1]>a[l3]){
		l1=l3;
	}
	if(l1!=i){
		t=a[l1];
		a[l1]=a[i];
		a[i]=t;
		Headpify(a,n,l1);
	}
 }
 void HeapSort(int a[],int n){
 	int i,t;
 	for(i=n/2-1;i>0;i--){
 		Headpify(a,n,i);
	 }
	 for(i=n-1;i>0;i--){
	 	//将堆顶元素放在数组最后； 
	 	t=a[i];
	 	a[i]=a[0];
	 	a[0]=t;
	 	Headpify(a,i,0);
	 }
	 Printf(a,n);
 }
 void HeapSort2(int a[],int n){
 	int i,t;
 	for(i=n/2-1;i>0;i--){
 		Headpify2(a,n,i);
	 }
	 for(i=n-1;i>0;i--){
	 	t=a[i];
	 	a[i]=a[0];
	 	a[0]=t;
	 	Headpify2(a,i,0);
	 }
	 Printf(a,n);
 }
 void merge(int a[],int t[],int left,int mid,int right){
 	int l1=left;
 	int l2=mid+1;
 	int l3=left;
 	while(l1<=mid&&l2<=right){
 		if(a[l1]<a[l2]){
 			t[l3++]=a[l1++];
		 }
		 else{
		 	t[l3++]=a[l2++];
		 }
	 }
	 while(l1<=mid){
	 	t[l3++]=a[l1++];
	 }
	 while(l2<=right){
	 	t[l3++]=a[l2++];
	 }
	 while(left<=right){
	 	a[left]=t[left];
	 	left++;
	 }
 }
 void msort(int a[],int t[],int left,int right){
 	if(left<right){
 		int mid=(left+right)/2;
 		//递归划分左半区 
 		msort(a,t,left,mid);
 		//递归划分右半区 
 		msort(a,t,mid+1,right);
 		//合并 
 		merge(a,t,left,mid,right); 
	 }
 }
 void MergeSort(int a[],int n){
 	int *t=(int*)malloc(n*sizeof(int));
 	if(t){
 		msort(a,t,0,n-1);
 		free(t);
 		Printf(a,n);
	 }
	 else{
	 	cout<<"error";
	 }
 }
 void CoutSort(int a[],int n){
 	int i,j,Max=a[0];
 	for(i=1;i<n;i++){
 		if(Max<a[i]){
 			Max=a[i];
		 }
	 }
	int *b = (int *)malloc((Max + 1) * sizeof(int));
	memset(b,0,sizeof(int)*(Max+1));
	//计数数组 
	 for(i=0;i<n;i++){
	 	b[a[i]]++;
	 }
	 //累加数组 
	 for(i=1;i<Max+1;i++){
	 	b[i]=b[i]+b[i-1];
	 }
	 int c[n];
	 for(i=0;i<n;i++){
	 	c[b[a[i]]-1]=a[i];
	 	b[a[i]]--;
	 }
	 for(i=0;i<n;i++){
	 	a[i]=c[i];
	 }
	 Printf(a,n);
	 free(b);
 }
 void RadixSort(int a[],int n){
 	int b[10],d=0,max=a[0],c[n];
 	int i,j,k;
 	for(i=1;i<n;i++){
 		if(a[i]>max){
 			max=a[i];
		 }
	 }
	 for(k=1;max/k>0;k*=10){
	 	for(i=0;i<10;i++){
	 		b[i]=0;
		 }
		 for(i=0;i<n;i++){
		 	b[(a[i]/k)%10]++;
		 }
		 for(i=1;i<10;i++){
		 	b[i]=b[i]+b[i-1];
		 }
		 for(i=n-1;i>=0;i--){
		 	c[b[(a[i]/k)%10]-1]=a[i];
		 	b[(a[i]/k)%10]--;
		 }
		 for(i=0;i<n;i++){
		 	a[i]=c[i];
		 }
	 }
	 Printf(a,n);
 } 
 int main(){
 	int a[100];
 	int n,i;
 	cin>>n;
 	for(i=0;i<n;i++){
 		cin>>a[i];
	 }
	cout<<"希尔排序："<<endl; 
	ShellSort(a,n);
	for(i=0;i<n;i++){
 		cin>>a[i];
	 }
	cout<<"快速排序："<<endl; 
	QuickSort(a,0, n-1,n);
	Printf(a,n);
	for(i=0;i<n;i++){
 		cin>>a[i];
	 }
	cout<<"堆排序(大)："<<endl; 
	HeapSort( a, n);
	for(i=0;i<n;i++){
 		cin>>a[i];
	 }
	cout<<"堆排序(小)："<<endl; 
	HeapSort2( a, n);
	for(i=0;i<n;i++){
 		cin>>a[i];
	 }
	cout<<"归并排序："<<endl; 
	MergeSort(a,n); 
	for(i=0;i<n;i++){
 		cin>>a[i];
	 }
	cout<<"计数排序："<<endl; 
	CoutSort(a,n); 
	for(i=0;i<n;i++){
 		cin>>a[i];
	 }
	//cout<<"基数排序："<<endl; 
	RadixSort(a,n); 
	 
 } 
