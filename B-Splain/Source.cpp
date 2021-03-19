#include <math.h>
#include <iostream>

using namespace std;

const int n = 5;//колличество разбиений
const double a = 0;//начало
const double b = 1;//конец
const double h = (b-a)/n; //h = (b-a)/n   шаг
const double h1 = 0.00001;
const double param = 0.3;//просто параметр для погрешности, зануляя его, мы уменьшаем погрешность

double A[n]; double B[n]; double C[n]; double D[n]; double F[n];//double cMatrix[n];
double C1[n-1][n];
double Splain_[n];

double f(double x) {

	return 0.0 - 0.3 * sin(4 * x / 10 + 0.7) + 0.7 * sin(0.5 * x - 0.9) * sin(-1.0 * x);
}
//C[0] = 0; C[n] = 0




void Gauss(int k, double Matrix[n - 1][n]) {
	if (Matrix[k][k] != 1) {
		double T = Matrix[k][k];
		for (int j = k; j < n; j++) {//нормирование строки
			Matrix[k][j] = Matrix[k][j] / T;
		}
	}
	for (int i = 0; i < n - 1; i++) {		//проходим по столбцу
		if ((Matrix[i][k] != 0) && (i != k)) {
			double T = Matrix[i][k];
			Matrix[i][k] = 0;
			for (int j = k + 1; j < n; j++) {	//проходим по двум строкам и вычитаем их
				Matrix[i][j] -= Matrix[k][j] * T;
			}
		}
	}
	if (k < n - 2) {
		Gauss(k + 1, Matrix);
	}
}



int NeobhodimayaFunksia4tobiVMainNeLezt() {
	for (int i = 0; i < n; i++)
	{
		F[i] = f(a + i * h);
		cout << F[i] << endl;
	}

	for (int i = 1; i <= n - 1; i++)  // delaem matrix C
		{
			for (int j = 0; j < n; j++) {
				if ((i == j) && (i == 0)) {
					C1[i][j] = 4;
					C1[i][j + 1] = 1;
				}
				if ((i == j) && (i != 0)) {
					C1[i][j - 1] = 1;
					C1[i][j] = 4;
					C1[i][j + 1] = 1;
				}
				if (j == n - 1) {
					C1[i][j] = 3.0 * (F[i] - 2.0 * F[i + 1] + F[i + 2]) / pow(h, 2);
				}
			}
		
			Gauss(0, C1);

			//Заполнение коэфф С
			C[0] = 0;
			C[n] = 0;
			for (int i = 1; i < n; i++) {
				C[i] = C1[i - 1][n - 1];
			}

			//заполнение А, B, D
			for (int i = 0; i < n; i++) {
				A[i] = F[i];
				B[i] = (F[i + 1] - F[i]) / h - h / 3.0 * (2.0 * C[i] + C[i + 1]);
				D[i] = (C[i + 1] - C[i]) / 3.0 / h;
			}

		}
	for (int i = 0; i < n-1; i++)
	{

	

		
	// C1[i][5] = cMatrix[i];
	// cout << MatrixC[i][5] << endl;
	}
	
	//rtrtrdrtyrur

	//trhrthrhr
	return 1;
}
void Splain()
{
	for (int i = 0; i < n; i++) 
	{
		for (int x = a; x <= b; x += h1) 
		{
		//	if ((x >= a + i * h) && (x <= a + (i + 1) * h))
			//{
				Splain_[i] = A[i] + B[i] * (x - (a + i * h)) + C[i] * pow((x - (a + i * h)), 2) + D[i] * pow((x - (a + i * h)), 3);
				//file << x << "	" << Y << endl;
		//	}
		}
		cout << Splain_[i] << endl;
	}

}

int main (){

	//cout << B_Splain(0.5) << endl;
	NeobhodimayaFunksia4tobiVMainNeLezt();
	Splain();
	return 1;
}