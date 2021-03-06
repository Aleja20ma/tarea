#include<iostream>
#include<stdio.h>


using namespace std;
struct Estudiante{
	int *codigo;
	string *nombre;
	int **pm_notas;
};

int main(){
int fila_estudiante=0,columna_notas=0;
float promedio=0,sumatoria_notas=0;
Estudiante estudiante;
cout<<"Cuantos Estudiantes Desea Ingresar: ";
cin>>fila_estudiante;	
cout<<"Cuantas Notas Desea Ingresar: ";
cin>>columna_notas;	
estudiante.pm_notas = new  int *[fila_estudiante];
estudiante.codigo = new int[fila_estudiante];
estudiante.nombre = new string[fila_estudiante];
//este for es para ingresar los estudiantes
for (int i=0;i<fila_estudiante;i++){
estudiante.pm_notas[i] = new int[columna_notas]; 	
}
cout<<"--------------Ingrese Notas--------------"<<endl;
string nombre;
//
for (int i=0;i<fila_estudiante;i++){
	cout<<"Codigo: ";
	cin>>estudiante.codigo[i];
	cin.ignore();
	cout<<"Nombre:";
	getline(cin,estudiante.nombre[i]);
	//ingresando las notas 
	for (int ii=0;ii<columna_notas;ii++){
		cout<<"Ingrese Nota "<<ii + 1<<": ";
		cin>>*(*(estudiante.pm_notas+i)+ii);
	}
	cout<<"------------------------------------"<<endl;
}
	cout<<"--------------Mostrar Notas--------------"<<endl;
	//este for despliega los nombres y el codigo de los estudiantes
	for (int i=0;i<fila_estudiante;i++){
		cout<<"Codigo: "<<estudiante.codigo[i]<<" Estudiante:"<<estudiante.nombre[i]<<"."<<endl;
		//for que  despliegua las notas
		sumatoria_notas=0;
		promedio=0;
		for (int ii=0;ii<columna_notas;ii++){
			cout<<"Nota yo ["<<ii + 1 <<"]: "<<((estudiante.pm_notas+i)+ii);
			//sumatoria de notas
			sumatoria_notas=sumatoria_notas+*(*(estudiante.pm_notas+i)+ii);
			
			cout<<endl;
			
		}
		promedio=sumatoria_notas/columna_notas;
		cout<<"promedio:"<<promedio<<endl;
		
		cout<<"------------------------------------"<<endl;
	}
// Liberar el espacio reservado en memoria
for (int i=0;i<fila_estudiante;i++){
	delete [] estudiante.pm_notas[i];
}

delete [] estudiante.pm_notas;
delete[] estudiante.codigo;
delete[] estudiante.nombre;

	system("PAUSE");
	return 0;
	
}
