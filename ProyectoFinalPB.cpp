#include <iostream>
#include <stdio.h>
//librer�a para aceptar caracteres en espa�ol
#include <clocale>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int menu = 0;
int cantidadArticulos=0;
int articulosGuardados=0;
int guardado = 0;

struct Alta
{
	int numero;
	int a�o;

	string nombre;
	string genero; 
	string clasificacion; 
	string consola; 
	string caracteristicas; 
	string descripcion;

	float precio = 0; 
	float impuesto = 0; 
	float total = 0;
};

//Alta *articulo;


void alta2();
void lista();

int main()
{


	setlocale(LC_CTYPE, "Spanish");

	do
	{
		printf("\t** TIENDA DE VIDEOJUEGOS **\n");
		printf("\t*      MEN� PRINCIPAL     *\n\n\n");

		//Imprimir menu
		printf("Ingrese el n�mero de la opci�n deseada\n\n");

		printf("1. AGREGAR ARTICULO\n");
		printf("2. MODIFICAR ARTICULO\n");
		printf("3. ELIMINAR ARTICULO\n");
		printf("4. LISTA DE ARTICULOS\n");
		printf("5. LIMPIAR PANTALLA\n");
		printf("6. SALIR\n\n");

		//leer opcion a operar
		scanf_s("%d", &menu);

		switch (menu)
		{
			//Alta
		case 1:
			alta2();
			break;

			//Modificar
		case 2:

			break;

			//Eliminar
		case 3:

			break;

			//Lista
		case 4:
			lista();
			break;

			//Limpiar pantalla
		case 5:
			system("cls");
			break;

			//Salir
		case 6:
			exit(1);
			break;
		}
	}while (menu != 6);
}

/*void alta()
{
	//articulo = new Alta[100];

	if (cantidadArticulos > 0)
	{
		articulosGuardados = cantidadArticulos;
		printf("Registre el n�mero de art�culos que dar� de alta \n");
		scanf_s("%d", &cantidadArticulos);
		int i = articulosGuardados;
		cantidadArticulos = cantidadArticulos + articulosGuardados;

		for (int i = articulosGuardados; i < cantidadArticulos; i++)
		{
			//Numero del art�culo
			articulo[i].numero = i + 1;

			//Nombre de videojuego
			printf("Nombre del videojuego: \n");
			cin.ignore();
			getline(cin, articulo[i].nombre);

			//A�o de lanzamiento
			printf("A�o de lanzamiento:\n");
			scanf_s("%d", &articulo[i].a�o);

			//Genero
			printf("G�nero: \n");
			cin.ignore();
			getline(cin, articulo[i].genero);

			//Clasificacion
			printf("Clasificaci�n \n");
			getline(cin, articulo[i].clasificacion);

			//Consola
			printf("Consola:\n");
			getline(cin, articulo[i].consola);

			//Caracter�sticas
			printf("Caracter�sticas:\n");
			getline(cin, articulo[i].caracteristicas);

			//Descripcion
			printf("Descripci�n:\n");
			getline(cin, articulo[i].descripcion);

			//Precio unitario
			printf("Precio unitario:\n $ ");
			scanf_s("%f", &articulo[i].precio);

			//Impuesto y total
			articulo[i].impuesto = articulo[i].precio * 0.16;
			printf("El impuesto es de $%.6g\n", articulo[i].impuesto);
			articulo[i].total = articulo[i].precio + articulo[i].impuesto;
			printf("El total es de $%.6g\n\n", articulo[i].total);

		}
	}
	else
	{
		printf("Registre el n�mero de art�culos que dar� de alta \n");
		scanf_s("%d", &cantidadArticulos);
		for (int i = 0; i < cantidadArticulos; i++)
		{
			//Numero del art�culo
			articulo[i].numero = i + 1;

			//Nombre de videojuego
			printf("Nombre del videojuego: \n");
			cin.ignore();
			getline(cin, articulo[i].nombre);

			//A�o de lanzamiento
			printf("A�o de lanzamiento:\n");
			scanf_s("%d", &articulo[i].a�o);

			//Genero
			printf("G�nero: \n");
			cin.ignore();
			getline(cin, articulo[i].genero);

			//Clasificacion
			printf("Clasificaci�n \n");
			getline(cin, articulo[i].clasificacion);

			//Consola
			printf("Consola:\n");
			getline(cin, articulo[i].consola);

			//Caracter�sticas
			printf("Caracter�sticas:\n");
			getline(cin, articulo[i].caracteristicas);

			//Descripcion
			printf("Descripci�n:\n");
			getline(cin, articulo[i].descripcion);

			//Precio unitario
			printf("Precio unitario:\n $ ");
			scanf_s("%f", &articulo[i].precio);

			//Impuesto y total
			articulo[i].impuesto = articulo[i].precio * 0.16;
			printf("El impuesto es de $%.6g\n", articulo[i].impuesto);
			articulo[i].total = articulo[i].precio + articulo[i].impuesto;
			printf("El total es de $%.6g\n\n", articulo[i].total);

		}
	}

	
}*/

//Crear puntero nulo
Alta *articulo = nullptr;

void alta2()
{
	printf("�Cu�ntos art�culos ingresar�?\n");
	scanf_s("%d", &cantidadArticulos);

	//Si el arreglo est� vac�o
	if (articulo == nullptr)
	{
		//Se crea un arreglo de tipo Alta con la cantidad ingresada
		articulo = new Alta[cantidadArticulos];
		
		//Solicitar datos
		for (int i = 0; i < cantidadArticulos; i++)
		{
			//Nombre de videojuego
			printf("Nombre del videojuego: \n");
			cin.ignore();
			getline(cin, articulo[i].nombre);

			//A�o de lanzamiento
			printf("A�o de lanzamiento:\n");
			scanf_s("%d", &articulo[i].a�o);

			//Genero
			printf("G�nero: \n");
			cin.ignore();
			getline(cin, articulo[i].genero);

			//Clasificacion
			printf("Clasificaci�n \n");
			getline(cin, articulo[i].clasificacion);

			//Consola
			printf("Consola:\n");
			getline(cin, articulo[i].consola);

			//Caracter�sticas
			printf("Caracter�sticas:\n");
			getline(cin, articulo[i].caracteristicas);

			//Descripcion
			printf("Descripci�n:\n");
			getline(cin, articulo[i].descripcion);

			//Precio unitario
			printf("Precio unitario:\n $ ");
			scanf_s("%f", &articulo[i].precio);

			//Impuesto y total
			articulo[i].impuesto = articulo[i].precio * 0.16;
			printf("El impuesto es de $%.6g\n", articulo[i].impuesto);
			articulo[i].total = articulo[i].precio + articulo[i].impuesto;
			printf("El total es de $%.6g\n\n", articulo[i].total);

		}
	}
	//Si ya hay articulos dados de alta entonces
	else
	{
		//calcular cuantos articulos ya hay guardados
		articulosGuardados = sizeof(articulo) / sizeof(articulo[0]);

		//Crear un nuevo arreglo temporal con tama�o de art�culos anteriores m�s los nuevos
		Alta *articuloTemp =new Alta [cantidadArticulos+articulosGuardados];

		//Copiar los articulos anteriores
		for (int i = 0; i < articulosGuardados; i++)
		{
			articuloTemp[i] = articulo[i];
		}

		//A�adir los nuevos datos
		for (int i = articulosGuardados; i < cantidadArticulos+articulosGuardados; i++)
		{
			//Nombre de videojuego
			printf("Nombre del videojuego: \n");
			cin.ignore();
			getline(cin, articulo[i].nombre);

			//A�o de lanzamiento
			printf("A�o de lanzamiento:\n");
			scanf_s("%d", &articulo[i].a�o);

			//Genero
			printf("G�nero: \n");
			cin.ignore();
			getline(cin, articulo[i].genero);

			//Clasificacion
			printf("Clasificaci�n \n");
			getline(cin, articulo[i].clasificacion);

			//Consola
			printf("Consola:\n");
			getline(cin, articulo[i].consola);

			//Caracter�sticas
			printf("Caracter�sticas:\n");
			getline(cin, articulo[i].caracteristicas);

			//Descripcion
			printf("Descripci�n:\n");
			getline(cin, articulo[i].descripcion);

			//Precio unitario
			printf("Precio unitario:\n $ ");
			scanf_s("%f", &articulo[i].precio);

			//Impuesto y total
			articulo[i].impuesto = articulo[i].precio * 0.16;
			printf("El impuesto es de $%.6g\n", articulo[i].impuesto);
			articulo[i].total = articulo[i].precio + articulo[i].impuesto;
			printf("El total es de $%.6g\n\n", articulo[i].total);
		}

		//Eliminar arreglo anterior y pasar datos
		delete[] articulo;
		articulo = articuloTemp;
	}
}

void lista()
{
	for (int i = 0; i < cantidadArticulos+articulosGuardados; i++)
	{
		printf("\n\nArt�culo %d\n", i+1);
		printf("Nombre del videojuego: %s\n", articulo[i].nombre.c_str());
		printf("A�o de lanzamiento: %d\n", articulo[i].a�o);
		printf("G�nero: %s\n", articulo[i].genero.c_str());
		printf("Clasificaci�n: %s\n", articulo[i].clasificacion.c_str());
		printf("Consola: %s\n", articulo[i].consola.c_str());
		printf("Caracter�sticas: %s\n", articulo[i].caracteristicas.c_str());
		printf("Descripci�n: %s\n", articulo[i].descripcion.c_str());
		printf("Precio unitario: $%.6g\n", articulo[i].precio);
		printf("El impuesto es de $%.6g\n", articulo[i].impuesto);
		printf("El total es de $%.6g\n\n", articulo[i].total);
	}
	//printf("\nPresione una tecla para volver al menu principal\n\n");
	//guardado = _getch();
	//if (guardado == 1)
	//{
	//	return (main());
	//}
	//else
	//{
	//	break;
	//}
}