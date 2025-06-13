#include<iostream>
using namespace std;

int arrSum(int num[], int size){
  int sum = 0;
  for(int i = 0;i < size; i++){
    sum += num[i];
  }

  return sum;

}

int main(){
  int size;
  cin >> size;

  int num[100];
  for(int i = 0; i< size; i++){
    cin >> num[i];
  }

  cout << arrSum(num,size) << endl;
}