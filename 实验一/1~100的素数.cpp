#include<iostream>
#include<cmath> 
using namespace std;

int su_shu(int num) {
	if(num == 2) return 1;
	for(int i = 2; i <= sqrt(num); i++) {
		if(num % i == 0) return 0;
	}
	return 1;
} 

int main() {
	for(int i = 2; i < 100; i++) {
		if(su_shu(i)) cout<<i<<" ";
	}
	return 0;
}
