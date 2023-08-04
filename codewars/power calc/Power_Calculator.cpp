#include <iostream>
#include <cstdlib>
using namespace std;

int power(int a, int b) {
	int result = a;
	for (int i = 1; i < b; i++)
		result *= a;
		
	return result;
}
int circuitPower(int voltage, int current) {
	int result = voltage;
	for(int i = 1 ; i < current ; i++)
		result *= voltage;
	return result;
}
