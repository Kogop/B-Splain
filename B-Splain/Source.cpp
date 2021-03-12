#include <math.h>
#include <iostream>

using namespace std;

const int n = 5;//колличество разбиений
const double a = 0;//начало
const double b = 1;//конец
const double h = (b-a)/n; //h = (b-a)/n   шаг
const double param = 0.3;//просто параметр для погрешности, зануляя его, мы уменьшаем погрешность

double A[n]; double B[n]; double C[n]; double D[n]; double F[n]; double cMatri4noe[n];
long double MatrixC[n-1][n];

//need this change to push to repository
double f(double x) {

	return 0.0 - 0.3 * sin(4 * x / 10 + 0.7) + 0.7 * sin(0.5 * x - 0.9) * sin(-1.0 * x);
}
//C[0] = 0; C[n] = 0

int NeobhodimayaFunksia4tobiVMainNeLezt() {
	for (int i = 0; i < n; i++)
	{
		F[i] = f(a + i * h);
		cout << F[i] << endl;
	}

	for (int i = 1; i <= n - 1; i++)
	{

		cMatri4noe[i - 1] = 3 * (F[i - 1] - 2 * F[i] + F[i + 1]) / pow(h, 2);
	}
	for (int i = 0; i < n-1; i++)
	{

	

		
	 MatrixC[i][5] = cMatri4noe[i];
	 cout << MatrixC[i][5] << endl;
	}
	
	//rtrtrdrtyrur


	return 1;
}


int main (){

	//cout << B_Splain(0.5) << endl;
	NeobhodimayaFunksia4tobiVMainNeLezt();
	return 1;
}