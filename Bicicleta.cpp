//clase bicicleta

#include <iostream>

using namespace std;

class Bicicleta{
	private:
		int pinon;
		int plato;

	public:
		Bicicleta(){
			pinon=0;
			plato=0;
		}

		void AvanzarPlato(){
			plato++;
		}

		void BajarPlato(){
			plato--;
		}

		void AvanzarPinon(int posiciones){
			pinon-=posiciones;
		}

		void BajarPinon(int posiciones){
			pinon+=posiciones;
		}

		void TipoMovimiento(char engranaje, char movimiento){
			
			if(plato == 1 && pinon > 5 || plato == 2 && pinon == 7 || plato == 2 && pinon == 1 || plato == 3 && pinon <=3)
				cout << "el cambio de marcha " << engranaje << " " << movimiento << " no se ha podido hacer. " << endl;
			else{
				if(engranaje == 'E'){
					if(movimiento == 'S' && plato < 3)
						AvanzarPlato();
					if(movimiento == 'B' && plato > 1)
						BajarPlato();
				}
				else{

					if(movimiento == 'S' && pinon > 2)
						AvanzarPinon(1);
					if(movimiento == 'B' && pinon < 6)
						BajarPinon(1);
					if(movimiento == 'T' && pinon > 3)
						AvanzarPinon(2);
					if(movimiento == 'C' && pinon < 5)
						BajarPinon(2);
				}
			}
		}

		int GetPlato () {
			return plato;
		}

		int GetPinon(){
			return pinon;
		}
};	

int main(){
	Bicicleta objeto;

	char pinon, movimiento;
	cout << "introduce una serie de movimientos: ";
	cin >> pinon;
	cin >> movimiento;

	while(pinon != 'X'){
		objeto.TipoMovimiento(pinon, movimiento);
		cin >> pinon;
		cin >> movimiento;
	}

	cout << "el resultado final del pinon es: " << objeto.GetPinon() << endl;
	cout  << "el resultado final de plato es: " << objeto.GetPlato() << endl;
}
