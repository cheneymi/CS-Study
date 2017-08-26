#include <iostream>

using namespace std;

void sortByMerge(int data[],int head,int tail){
    if (head==tail) { // 递归边界
        return;
    }
    int mid=(head+tail)/2;
    // cerr<<"head="<<head<<" mid="<<mid<<" tail="<<tail<<"\n";
    sortByMerge(data,head,mid);   // 排序左子列
    sortByMerge(data,mid+1,tail); // 排序右子列
    
    int left=head, right=mid+1, i=0;    // 左右两个游标
    int tmp[tail-head+1];   // 存放临时结果
    while (left<=mid || right<=tail) {  // 归并过程
        // 把左右游标中较小的一个放入tmp的当前位置
        if (right>tail|| (left<=mid && data[left]<data[right])){
            tmp[i++]=data[left++];
        } else{
            tmp[i++]=data[right++];
        }
    }
    // 将tmp（排好序的）回填到原数组的head到tail位置
    for (int j=head;j<=tail;j++){
        data[j]=tmp[j-head];
    }
}

// zhf
void printDupNumber(){
    int n;
    cin>>n; // 输入
    int num1[n];
    int num2[n];
    for (int i=0;i<=n-1;i++) {
        cin>>num1[i];
    }
    for (int i=0;i<=n-1;i++) {
        cin>>num2[i];
    }
    
    sortByMerge(num1,0,n-1);
    sortByMerge(num2,0,n-1);
    
    int pos1=0,pos2=0;    // 两个游标和最终结果
    while (pos1<n && pos2<n) {  // 判断相同的元素
        if (num1[pos1]==num2[pos2]){
            cout<<num1[pos1]<<" ";
            pos1++;
            pos2++;
        } else if (num1[pos1]<num2[pos2]){
            pos1++;
        } else {
            pos2++;
        }
    }
    cout<<endl;
}

// glx
void printDupNumber2(){
    int book[1001],t,n; // 初始化
    for(int i=0;i<=1000;i++){
        book[i]=0;
    }
    
    scanf("%d",&n); // 输入第一组数据，记录出现过的数字
    for(int i=1;i<=n;i++) {
        scanf("%d",&t);
        book[t]++;
    }
    
    for(int i=1;i<=n;i++) { // 输入第二组数据，判断重复数据
        scanf("%d",&t);
        if (book[t]>0){
            printf("%d ",t);
        }
    }
    printf("\n");
}

// syz
void printDupNumber3(){
    int n=0;
    cin>>n; // 输入
    int a[n],b[n];
    for(int i=0;i<n;i++){
        a[i]=b[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    for(int i=0;i<n;i++){   // 比较
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                cout<<a[i]<<" ";
            }
        }
    }
    cout<<endl;
}
#include <algorithm>

// wyj
void printDupNumber4() {
    int num;
    cin>>num;
    int num1[1000];
    int num2[1000];
    for (int i=1;i<=num;i++) cin>>num1[i];
    for (int i=1;i<=num;i++) cin>>num2[i];
    sort (num1+1,num1+num+1);
    sort (num2+1,num2+num+1);   // ^^
    for (int i=1;i<=num;i++) {
        int l=1,r=num;
        while (r-l>2) { // 二分查找
            int mid=(l+r)/2;
            if (num2[mid]>num1[i]){
                r=mid;
            } else {
                l=mid;

            }
        }
        for (int j=l;j<=r;j++) 	{
            if (num2[j]==num1[i]) {
                cout<<num1[i]<<" ";
            }
        }
    }
    cout<<endl;
}

int main() {
    /* 3
       3 2 1
       2 4 1 */
//    printDupNumber();
//    printDupNumber2();
//    printDupNumber3();
//    printDupNumber4();
    return 0;
}

