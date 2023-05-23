#include <iostream>
#include <stdio.h>
//librería para aceptar caracteres en español
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
	int año;

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
		printf("\t*      MENÚ PRINCIPAL     *\n\n\n");

		//Imprimir menu
		printf("Ingrese el número de la opción deseada\n\n");

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
		printf("Registre el número de artículos que dará de alta \n");
		scanf_s("%d", &cantidadArticulos);
		int i = articulosGuardados;
		cantidadArticulos = cantidadArticulos + articulosGuardados;

		for (int i = articulosGuardados; i < cantidadArticulos; i++)
		{
			//Numero del artículo
			articulo[i].numero = i + 1;

			//Nombre de videojuego
			printf("Nombre del videojuego: \n");
			cin.ignore();
			getline(cin, articulo[i].nombre);

			//Año de lanzamiento
			printf("Año de lanzamiento:\n");
			scanf_s("%d", &articulo[i].año);

			//Genero
			printf("Género: \n");
			cin.ignore();
			getline(cin, articulo[i].genero);

			//Clasificacion
			printf("Clasificación \n");
			getline(cin, articulo[i].clasificacion);

			//Consola
			printf("Consola:\n");
			getline(cin, articulo[i].consola);

			//Características
			printf("Características:\n");
			getline(cin, articulo[i].caracteristicas);

			//Descripcion
			printf("Descripción:\n");
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
		printf("Registre el número de artículos que dará de alta \n");
		scanf_s("%d", &cantidadArticulos);
		for (int i = 0; i < cantidadArticulos; i++)
		{
			//Numero del artículo
			articulo[i].numero = i + 1;

			//Nombre de videojuego
			printf("Nombre del videojuego: \n");
			cin.ignore();
			getline(cin, articulo[i].nombre);

			//Año de lanzamiento
			printf("Año de lanzamiento:\n");
			scanf_s("%d", &articulo[i].año);

			//Genero
			printf("Género: \n");
			cin.ignore();
			getline(cin, articulo[i].genero);

			//Clasificacion
			printf("Clasificación \n");
			getline(cin, articulo[i].clasificacion);

			//Consola
			printf("Consola:\n");
			getline(cin, articulo[i].consola);

			//Características
			printf("Características:\n");
			getline(cin, articulo[i].caracteristicas);

			//Descripcion
			printf("Descripción:\n");
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
	printf("¿Cuántos artículos ingresará?\n");
	scanf_s("%d", &cantidadArticulos);

	//Si el arreglo está vacío
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

			//Año de lanzamiento
			printf("Año de lanzamiento:\n");
			scanf_s("%d", &articulo[i].año);

			//Genero
			printf("Género: \n");
			cin.ignore();
			getline(cin, articulo[i].genero);

			//Clasificacion
			printf("Clasificación \n");
			getline(cin, articulo[i].clasificacion);

			//Consola
			printf("Consola:\n");
			getline(cin, articulo[i].consola);

			//Características
			printf("Características:\n");
			getline(cin, articulo[i].caracteristicas);

			//Descripcion
			printf("Descripción:\n");
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

		//Crear un nuevo arreglo temporal con tamaño de artículos anteriores más los nuevos
		Alta *articuloTemp =new Alta [cantidadArticulos+articulosGuardados];

		//Copiar los articulos anteriores
		for (int i = 0; i < articulosGuardados; i++)
		{
			articuloTemp[i] = articulo[i];
		}

		//Añadir los nuevos datos
		for (int i = articulosGuardados; i < cantidadArticulos+articulosGuardados; i++)
		{
			//Nombre de videojuego
			printf("Nombre del videojuego: \n");
			cin.ignore();
			getline(cin, articulo[i].nombre);

			//Año de lanzamiento
			printf("Año de lanzamiento:\n");
			scanf_s("%d", &articulo[i].año);

			//Genero
			printf("Género: \n");
			cin.ignore();
			getline(cin, articulo[i].genero);

			//Clasificacion
			printf("Clasificación \n");
			getline(cin, articulo[i].clasificacion);

			//Consola
			printf("Consola:\n");
			getline(cin, articulo[i].consola);

			//Características
			printf("Características:\n");
			getline(cin, articulo[i].caracteristicas);

			//Descripcion
			printf("Descripción:\n");
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
		printf("\n\nArtículo %d\n", i+1);
		printf("Nombre del videojuego: %s\n", articulo[i].nombre.c_str());
		printf("Año de lanzamiento: %d\n", articulo[i].año);
		printf("Género: %s\n", articulo[i].genero.c_str());
		printf("Clasificación: %s\n", articulo[i].clasificacion.c_str());
		printf("Consola: %s\n", articulo[i].consola.c_str());
		printf("Características: %s\n", articulo[i].caracteristicas.c_str());
		printf("Descripción: %s\n", articulo[i].descripcion.c_str());
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
