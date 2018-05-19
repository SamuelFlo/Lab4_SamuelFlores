#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int*** crear(int n){
	int*** tablero = new int **[n];

	for(int i =0;i<n;i++){
		tablero[i]=new int*[3];

	}
	for(int i = 0; i<n;i++){
		for(int j=0;j<3;j++){	
			tablero[i][j]=new int[n];

		}
	}
	return tablero;

}

void ejercicio1(){


}
void ejercicio2(){
	int grado,a,n,poli,valores=0;
	cout << "Ingrese el grado del polinomio: "<<endl;
	cin >> grado;
	cout<< "Ingrese la a: "<<endl;
	cin>>a;
	n=grado+1;
	int cont=0;
	int *** matriz=crear(n);
	for(int i =0; i<n;i++){
		cout<<"Ingrese el valor: "<<endl;
		cin>>valores;
		matriz[0][0][i]=valores;
		valores=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matriz[i][0][j]=matriz[0][0][j];
			matriz[i][2][0]=matriz[0][0][0];
			//primer
			//matriz[i][1][1]=matriz[i][2][0]*a;
			//matriz[i][2][1]=matriz[i][0][1]+matriz[i][1][1];
			//segundo
			//matriz[i][1][2]=matriz[i][2][1]*a;
			//matriz[i][2][2]=matriz[i][0][2]+matriz[i][1][2];
		}
	}
	for(int i =0;i<n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<n;k++){
				matriz[i][1][k+1]=matriz[i][2][k]*a;
				matriz[i][2][k+1]=matriz[i][0][k+1]+matriz[i][1][k+1];
			}
		}

	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<n;k++){
				cout<<" "<<matriz[i][j][k]<<" ";
				
			}
			cout<<"|"<<a<<endl;

		}
		cout<<endl;
	}
	
}

void ejercicio3(){
	string clave;
//	char [][] matriz = new char[5][5];
	cout<<"Ingrese la palabra clave: "<<endl;
	cin>>clave;
	//matriz[0][0]='a';
}

int menu(){
	int opcion = 0;
	do{
		cout<<"MENU"<<endl
		<<"1. Ejercicio 1"<<endl
		<<"2. Ejercicio 2"<<endl
		<<"3. Ejercicio 3"<<endl
		<<"4. Salir"<<endl;
		cin>>opcion;
		if(opcion<1||opcion>4){
			cout<<"Opcion Invalida"<<endl;
			opcion=0;
			

		}else{

			return opcion;
		}


	}while(opcion==0);


}



int main(){
	bool seguir = true;
	while(seguir){
		switch(menu()){
			case 1:
				ejercicio1();
				break;
			case 2:
				ejercicio2();
				break;
			case 3:
				ejercicio3();
				break;
			case 4:
				seguir = false;
				break;



		}

	}
	return 0;

}
