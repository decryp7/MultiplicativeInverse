//============================================================================
// Name        : inverse.cpp
// Author      : Teo Kok Yong 3562967
// Version     :
// Copyright   : Your copyright notice
// Description : Euclidean Algoritium
//============================================================================

#include <iostream>
using namespace std;

void CalculateInverse(int number, int mod);
void PrintPretty(int n1, int n2, int r, int q, int a1, int a2, int b1, int b2);

int main(int argc, char *argv[]) {
	int number = atoi(argv[1]);
	int mod = atoi(argv[2]);
	
	CalculateInverse(number, mod);
	
	return 0;
}

void PrintPretty(int n1, int n2, int r, int q, int a1, int a2, int b1, int b2){
	cout << n1;
	cout.width(10);
	cout << n2;
	cout.width(10);
	cout << r;
	cout.width(10);
	cout << q;
	cout.width(10);
	cout << a1;
	cout.width(10);
	cout << a2;
	cout.width(10);
	cout << b1;
	cout.width(10);
	cout << b2 << endl;
}

void CalculateInverse(int number, int mod){
	int n1 = number;
	int n2 = mod;
	int r = number % mod;
	int q = number / mod;
	int a1 = 1;
	int a2 = 0;
	int b1 = 0;
	int b2 = 1;
	
	PrintPretty(n1, n2, r, q, a1, a2, b1, b2);
	
	while(r != 0){
		n1 = n2;
		n2 = r;
		
		r = n1 % n2;
		int tempQ = q;
		q = n1 / n2;
		
		int tempA1 = a1;
		a1 = a2;
		a2 = tempA1 - (a2 * tempQ);
		
		int tempB1 = b1;
		b1 = b2;
		b2 = tempB1 - (b2 * tempQ);
		PrintPretty(n1, n2, r, q, a1, a2, b1, b2);
	}
	
	if(n2 != 1){
		cout << "gcd(" << number << "," << mod << ") is not 1" << endl;
		cout << "So there is no inverse." << endl;
	}else{
		cout << "Inverse of " << number << " is " << a2 <<".";
	}
}
