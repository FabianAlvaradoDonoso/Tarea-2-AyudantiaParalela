#include <iostream>  //cout, cin
#include <stdlib.h>  //rand()
#include <time.h>    //time(null)
#include <vector>    //vector<int>
#include <math.h>    //pow()

using namespace std;

vector<int> crearArreglo(int tamanio) {
	vector<int> v;
	for (int i = 0; i < tamanio; i++) {
		int num = 1 + rand() % (11 - 1);
		v.push_back(num);
	}
	return v;
}

void imprimir(const vector<int> v) {
	if (!v.empty()) {
		int i = 0;
		system("cls");
		for (int element : v) {
			printf("Vector[%i]: %i\n", i, element);
			i++;
		}
	}
	else {
		printf("Vector vacio!\n\n");
	}
}

float promedio(vector<int> v) {
	int suma = 0;
	for (int elemento : v) {
		suma += elemento;
	}
	float prom = (float)suma / v.size();
	system("cls");
	printf("Sumatoria: %i\n\n", suma);
	printf("Promedio: %.2lf\n\n", prom);
	return prom;
}

float varianza(vector<int> v, int prom) {
	float sumaCuadrados = 0;
	for (int elemento : v) {
		sumaCuadrados += (float) pow(elemento - prom, 2);
	}
	float varia = (float)sumaCuadrados / v.size();
	system("cls");
	printf("Diferencia 2: %.2lf\n\n", sumaCuadrados);
	printf("Varianza: %.2lf\n\n", varia);
	return varia;
}

float desviacionTipica(float varianza) {
	float desvTipica = (float) sqrt(varianza);
	system("cls");
	printf("Desviacion Estandar: %.2lf\n\n", desvTipica);
	return desvTipica;
}

void opciones() {
	vector<int> v;
	int tamanio, opcionPrincipal = 0;
	srand(time(NULL));
	float prom, varia, desvTipica;

	while (opcionPrincipal != 6) {
		system("cls");
		cout << "1.- Crear vector" << endl;
		cout << "2.- Imprimir vector" << endl;
		cout << "3.- Promedio" << endl;
		cout << "4.- Varianza" << endl;
		cout << "5.- Desviacion tipica" << endl;
		cout << "6.- Salir" << endl;
		cout << "Opcion elegida: "; cin >> opcionPrincipal;

		switch (opcionPrincipal) {
		case 1:
			system("cls");
			cout << "Ingrese largo del arreglo: "; cin >> tamanio;
			v = crearArreglo(tamanio);
			break;
		case 2:
			system("cls");
			imprimir(v);
			system("pause");
			break;
		case 3:
			system("cls");
			prom = promedio(v);
			system("pause");
			break;
		case 4:
			system("cls");
			varia = varianza(v, prom);
			system("pause");
			break;
		case 5:
			system("cls");
			desvTipica = desviacionTipica(varia);
			system("pause");
			break;
		case 6:
			system("cls");
			cout << "\nHasta pronto!!!\n\n" << endl;
			system("pause");
			break;
		}
	}

}

int main() {
	opciones();
}


