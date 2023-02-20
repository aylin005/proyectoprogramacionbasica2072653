
#include <iostream>
//librería para aceptar caracteres en español
#include <clocale>

using namespace std;

int main()
{
	int menu=0;
	int numero=0;
	char nombre[100];
	int año=0;
	char genero[50];
	char clasificacion[30];
	char consola[50];
	char caracteristicas[200];
	char descripcion[300];
	float precio=0, impuesto = 0.16, total=0;
	int guardado=0;

  //Para aceptar caracteres en español
	setlocale(LC_CTYPE, "Spanish");


	cout << "\t** TIENDA DE VIDEOJUEGOS **" << endl;
	cout << "\t*      MENÚ PRINCIPAL     *" << endl << endl << endl;


	//Imprimir menu
	cout << "Ingrese el número de la opción deseada" << endl << endl;

	cout << "1. AGREGAR ARTICULO" << endl;
	cout << "2. MODIFICAR ARTICULO" << endl;
	cout << "3. ELIMINAR ARTICULO" << endl;
	cout << "4. LISTA DE ARTICULOS" << endl;
	cout << "5. LIMPIAR PANTALLA" << endl;
	cout << "6. SALIR" << endl<<endl;
	//leer opcion a operar
	cin >> menu;

	switch (menu)
	{
	case 1:
		//Numero del artículo
		cout << "Número del artículo:" << endl;
		cin >> numero;
		//Nombre de videojuego
		cout <<"Nombre del videojuego:"<<endl;
		cin.ignore();
		cin.getline (nombre,100);
		
		//Año de lanzamiento
		cout << "Año de lanzamiento:" << endl;
		cin >> año;

		//Genero
		cout << "Género:" << endl;
		cin.ignore();
		cin.getline(genero, 50);

		//Clasificacion
		cout << "Clasificación:" << endl;
		cin.getline(clasificacion, 30);
		
		//Consola
		cout << "Consola:" << endl;
		cin.getline(consola, 50);

		//Características
		cout << "Características:" << endl;
		cin.getline(caracteristicas, 200);

		//Descripcion
		cout << "Descripción:" << endl;
		cin.getline(descripcion, 300);

		//Precio unitario
		cout << "Precio unitario:" << endl<<"$";
		cin >> precio;

		//Impuesto y total
		impuesto = precio * impuesto;
		cout << "El impuesto es de $" << impuesto << endl;
		total = precio + impuesto;
		cout << "El total es de $" << total << endl;

		//Ver informacion guardada
		cout << "¿Desea ver la información guardada?   Si(1) No(2)" << endl;
		cin >> guardado;
		if (guardado==1)
		{
			cout <<endl<<endl<< "Número del artículo: " << numero << endl;
			cout << "Nombre del videojuego: " << nombre << endl;
			cout << "Año de lanzamiento: " << año << endl;
			cout << "Género: " << genero << endl;
			cout << "Clasificación: " << clasificacion << endl;
			cout << "Consola: " << consola << endl;
			cout << "Características: " << caracteristicas << endl;
			cout << "Descripción: " << descripcion << endl;
			cout << "Precio unitario: " << precio << endl;
			cout << "El impuesto es de $" << impuesto << endl;
			cout << "El total es de $" << total << endl<<endl;

			cout << "Presione 1 para volver al menu principal" << endl;
			cin >> guardado;
			if (guardado==1)
			{
				return main();
				break;
			}
			else
			{
				exit(1);
			}
		}
		return main();
		break;

	//Modificar Artículo
	case 2:
		break;
	//Eliminar Artículo
	case 3:
		break;
	//Lista de Artículos
	case 4:
		break;
	//Limpiar pantalla
	case 5:
		system("cls");
		return main();
		break;
	//Salir
	case 6:
		exit(1);
		break;
	default:
		cout << "El valor ingresado es inválido intente de nuevo" << endl;
		return main();
		break;
	}
	return 0;
}
