
#include <iostream>
#include <stdio.h>
//librería para aceptar caracteres en español
#include <clocale>
#include <conio.h>
using namespace std;

int menu = 0;
int guardado = 0;

struct alta
{
	int numero, año;
	char nombre[500], genero[100],clasificacion[30],consola[100],caracteristicas[500],descripcion[800];
	float precio = 0,impuesto=0, total = 0;
};

int main()
{
	alta articulo[3];

	//Para aceptar caracteres en español
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
		case 1:
			for (int i = 0; i < 3; i++)
			{
				//Numero del artículo
				articulo[i].numero = i + 1;

				//Nombre de videojuego
				printf("Nombre del videojuego: \n");
				cin.ignore();
				cin.getline(articulo[i].nombre, 500);

				//Año de lanzamiento
				printf("Año de lanzamiento:\n");
				scanf_s("%d", &articulo[i].año);

				//Genero
				printf("Género: \n");
				cin.ignore();
				cin.getline(articulo[i].genero, 100);

				//Clasificacion
				printf("Clasificación \n");
				cin.getline(articulo[i].clasificacion, 30);

				//Consola
				printf("Consola:\n");
				cin.getline(articulo[i].consola, 100);

				//Características
				printf("Características:\n");
				cin.getline(articulo[i].caracteristicas, 500);

				//Descripcion
				printf("Descripción:\n");
				cin.getline(articulo[i].descripcion, 800);

				//Precio unitario
				printf("Precio unitario:\n $ ");
				scanf_s("%f", &articulo[i].precio);

				//Impuesto y total
				articulo[i].impuesto = articulo[i].precio * 0.16;
				printf("El impuesto es de $%.6g\n", articulo[i].impuesto);
				articulo[i].total = articulo[i].precio + articulo[i].impuesto;
				printf("El total es de $%.6g\n\n", articulo[i].total);
			}
			break;

			//Modificar Artículo
		case 2:
			break;
			//Eliminar Artículo
		case 3:
			break;
			//Lista de Artículos
		case 4:
			for (int i = 0; i < 3; i++)
			{

				printf("\n\nArtículo %d\n", articulo[i].numero);
				printf("Nombre del videojuego: %s\n", articulo[i].nombre);
				printf("Año de lanzamiento: %d\n", articulo[i].año);
				printf("Género: %s\n", articulo[i].genero);
				printf("Clasificación: %s\n", articulo[i].clasificacion);
				printf("Consola: %s\n", articulo[i].consola);
				printf("Características: %s\n", articulo[i].caracteristicas);
				printf("Descripción: %s\n", articulo[i].descripcion);
				printf("Precio unitario: $%.6g\n", articulo[i].precio);
				printf("El impuesto es de $%.6g\n", articulo[i].impuesto);
				printf("El total es de $%.6g", articulo[i].total);
			}
			printf("\nPresione una tecla para volver al menu principal\n\n");
			guardado=_getch();
			if (guardado == 1)
			{
				break;
			}
			else
			{
				break;
			}
		return main();
		break;
		//Limpiar pantalla
	case 5:
		system("cls");
		break;
		//Salir
	case 6:
		exit(1);
		break;
	default:
		printf("El valor ingresado es inválido intente de nuevo\n");
		break;
	}
	}while (menu != 6);
	return 0;
}
	
