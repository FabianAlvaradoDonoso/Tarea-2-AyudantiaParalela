#include <iostream>  //cout, cin
#include <time.h>    //time(null)
#include <vector>    //vector<int>
#include <math.h>    //pow()
#include <cstdlib>   //rand()

using namespace std;

void limpiar_terminal(){
	#ifdef WINDOWS
		std::system("cls");
	#else
	    // Assume POSIX
	    std::system("clear");
	#endif
}
void pausar_terminal(){
	#ifdef WINDOWS
	    std::system("pause");
	#else
	    // Assume POSIX
	    system("read -p 'Press Enter to continue...' var");
	#endif
}

vector<int> crearArreglo() {
	limpiar_terminal();
	int tamanio = 0;
	vector<int> v;

	cout << "Ingrese cantidad de datos en el vector: "; cin >> tamanio;

	for (int i = 0; i < tamanio; i++) {
		int num = 1 + rand() % (11 - 1);
		v.push_back(num);
	}
	return v;
}

void imprimir(const vector<int> v) {
	limpiar_terminal();
	if (!v.empty()) {
		int i = 0;
		for (int element : v) {
			printf("Vector[%i]: %i\n", i, element);
			i++;
		}
	}
	else {
		printf("Vector vacio!\n\n");
	}
	pausar_terminal();
}

float promedio(vector<int> v) {
	limpiar_terminal();
	if (!v.empty()){
		int suma = 0;
		for (int elemento : v) {
			suma += elemento;
		}
		float prom = (float)suma / v.size();
		printf("Sumatoria: %i\n\n", suma);
		printf("Promedio: %.2lf\n\n", prom);
		pausar_terminal();
		return prom;
	}else{
		printf("Vector vacio!\n\n");
		pausar_terminal();
		return 0;
	}
}

float varianza(vector<int> v, int prom) {
	limpiar_terminal();
	if (!v.empty()){
		float sumaCuadrados = 0;
		for (int elemento : v) {
			sumaCuadrados += (float) pow(elemento - prom, 2);
		}
		float varia = (float)sumaCuadrados / v.size();
		//printf("Diferencia 2: %.2lf\n\n", sumaCuadrados);
		printf("Varianza: %.2lf\n\n", varia);
		pausar_terminal();
		return varia;
	}else{
		printf("Vector vacio!\n\n");
		pausar_terminal();
		return 0;
	}
}

float desviacionTipica(float varianza) {
	limpiar_terminal();
	if (varianza > 0){
		float desvTipica = (float) sqrt(varianza);
		printf("Desviacion Estandar: %.2lf\n\n", desvTipica);
		pausar_terminal();
		return desvTipica;
	}else{
		printf("Vector vacio!\n\n");
		pausar_terminal();
		return 0;
	}
}

void opciones() {
	vector<int> v;
	int opcionPrincipal = 0;
	srand(time(NULL));
	float prom, varia, desvTipica;

	while (opcionPrincipal != 6) {
		limpiar_terminal();
		cout << "1.- Crear vector" << endl;
		cout << "2.- Imprimir vector" << endl;
		cout << "3.- Promedio" << endl;
		cout << "4.- Varianza" << endl;
		cout << "5.- Desviacion tipica" << endl;
		cout << "6.- Salir" << endl;
		cout << "Opcion elegida: "; cin >> opcionPrincipal;

		switch (opcionPrincipal) {
		case 1:
			v = crearArreglo();
			break;
		case 2:
			imprimir(v);
			break;
		case 3:
			prom = promedio(v);
			break;
		case 4:
			varia = varianza(v, prom);
			break;
		case 5:
			desvTipica = desviacionTipica(varia);
			break;
		case 6:
			limpiar_terminal();
			cout << "\nHasta pronto!!!\n\n" << endl;
			break;
		}
	}

}

int main() {
	opciones();
}
