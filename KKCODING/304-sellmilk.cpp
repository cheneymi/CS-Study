#include<iostream>
using namespace std;

int main(){
	int q[10001];
	int n,a,b,sold=0,expired=0,allin=0;
	int day=0,front_day;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;//a-input,b-sell
		day++;//the day
		q[day]=a;//input
		allin+=a;
		if(day>4){//expired day
		//	expired+=q[day-4];//expired amount add
			front_day=day-3;//valid days
		}else{
			front_day=1;//valid days
		}
		while(b>0){
			if(q[front_day]>=b){//if enough sell b in this day
				q[front_day]-=b;  
				sold+=b;
				b=0;
			}else{//if not enough sell all in this day,feont day move to next day
				b-=q[front_day];
				sold+=q[front_day];
				q[front_day]=0;
				front_day++;
			}
			if(front_day>day) break;
	    }
	}
	expired=allin-sold; 
	cout<<sold<<" "<<expired<<endl;
	return 0;
}
