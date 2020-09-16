#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len = data.size();
        if(len<2)
            return;
		sort(data.begin(), data.end());
        int num[2];
        int j=0;
        int count = 0, preNum = data[0] ;
        for(int i=0; i<len; i++){
            if(preNum == data[i]){
                count++;
            }
            else{
                if(count == 1){
					cout<<"preNum"<<preNum<<endl;
                    num[j++] = (preNum);
                }
                count = 1;
            }
            preNum = data[i];
        }
		if(count == 1){
            num[j] = preNum;
			cout<<"preNum"<<preNum<<endl;
        }
        *num1 = num[0];
        *num2 = num[1];
}

int main(){
	vector<int> data = {2,4,3,6,3,2,5,5};
	int num1=0, num2=0;
	FindNumsAppearOnce(data, &num1, &num2);
	return 0;
}