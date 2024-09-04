#include<iostream>
using namespace std;

int main(){
	
	int total_cr = 18;
	double cs301 = 3.53 * 3;
	double cs301P = 4.00 * 1;
	double cs401 = 1.20 * 3;
	double cs401P = 2.93 * 1;
	double cs504 = 3.87 * 3;
	double cs610 = 2.67 * 3;
    double cs610p = 4.00 * 1;
	double cs602 = 3.87 * 3;
	double total_sum = cs301 + cs301P +cs401+cs401P	+cs504 +cs610 +cs610p +cs602;
	double ans = total_sum / total_cr;
	cout<<"answer:"<<ans;
}
