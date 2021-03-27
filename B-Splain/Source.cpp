#include <math.h>
#include <iostream>

using namespace std;

//int n;
const int n = 5;//колличество разбиений
const double a = 0;//начало
const double b = 1;//конец
const double h = (b-a)/n; //h = (b-a)/n   шаг
const double h1 = 0.00001;

double A[n]; double B[n]; double C[n]; double D[n]; double F[n+1];//double cMatrix[n];
double C1[n-1][n];
double Splain_[n];

double f(double x) {

	return 0.0 - 0.3 * sin(4 * x / 10 + 0.7) + 0.7 * sin(0.5 * x - 0.9) * sin(-1.0 * x);
}
//C[0] = 0; C[n] = 0

int m = n;


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
	/*while ((fabs(F[1] - Splain_[1]) > 0.001))
	{*/

	/*while (fabs(Splain_[1] - f(a + h / 2)) > 0.001) {*/

		for (int i = 0; i < m + 2; i++)
		{
			F[i] = f(a + i * h);
			if (i < n)
			{
				cout << F[i] << endl;
			}

		}

		for (int i = 0; i < m - 1; i++)  // delaem matrix C
		{
			for (int j = 0; j < m; j++)
			{
				if ((i == j) && (i == 0))
				{
					C1[i][j] = 4;
					C1[i][j + 1] = 1;
				}
				if ((i == j) && (i != 0))
				{
					C1[i][j - 1] = 1;
					//cout << C1[i][j - 1] << endl;
					C1[i][j] = 4;
					C1[i][j + 1] = 1;
				}
				if (j == n - 1)
				{
					C1[i][j] = 3.0 * (F[i] - 2.0 * F[i + 1] + F[i + 2]) / pow(h, 2);

				}


			}





		}
		//for (int i = 0; i < n-1; i++)
		//{

		// vivod matrix C
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << C1[i][j] << " ";
			}
			cout << endl;
		}
		Gauss(0, C1);



		//Заполнение коэфф С
		for (int i = 1; i < m; i++)
		{
			C[i] = C1[i - 1][m - 1];
			//	cout << C1[i-1][n-1] << endl;
		}
		C[m] = 0; C[0] = 0;
		//заполнение А, B, D
		for (int i = 0; i < m; i++)
		{
			A[i] = F[i];
			B[i] = (F[i + 1] - F[i]) / h - h / 3.0 * (2.0 * C[i] + C[i + 1]);
			D[i] = (C[i + 1] - C[i]) / 3.0 / h;
		}
		/*m = n*5;
		if (m > 126) {
			cout << "Выход за предел ограничения итераций\n";
			return 0;
		}*/
	
	return 1;
}
//do and vivod Splaina
void Splain()
{
	for (double x = a; x <= b; x += h)
	{
		for (int i = 0; i < m; i++)
		{
			if ((x >= a + i * h) && (x < a + (i + 1) * h))
			{
				Splain_[i] = A[i] + B[i] * (x - (a + i * h)) + C[i] * pow((x - (a + i * h)), 2) + D[i] * pow((x - (a + i * h)), 3);
				//file << x << "	" << Y << endl;
				cout << Splain_[i] << endl;
			}
			
		}
		
	}

}

int main (){
	//n = 5;
	//cout << "f=" << f(1) << endl;
	NeobhodimayaFunksia4tobiVMainNeLezt();
	Splain();
	
	for (int i = 0; i < 2; i++)
	{
		if (fabs(F[1] - Splain_[1]) > 0.001)
		{
			m = m * 5;
			NeobhodimayaFunksia4tobiVMainNeLezt();
			Splain();
		}
	}
	/*while((fabs(F[1]-Splain_[1])>0.001)
	{
		n = n * 5;
		NeobhodimayaFunksia4tobiVMainNeLezt(n);
		Splain(n);

	}*/
	return 1;
}