
#include <iostream>
#include <stdio.h>
//librer�a para aceptar caracteres en espa�ol
#include <clocale>
#include <conio.h>
using namespace std;

int menu = 0;
int guardado = 0;

struct alta
{
	int numero, a�o;
	char nombre[500], genero[100],clasificacion[30],consola[100],caracteristicas[500],descripcion[800];
	float precio = 0,impuesto=0, total = 0;
};

int main()
{
	alta articulo[3];

	//Para aceptar caracteres en espa�ol
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
		case 1:
			for (int i = 0; i < 3; i++)
			{
				//Numero del art�culo
				articulo[i].numero = i + 1;

				//Nombre de videojuego
				printf("Nombre del videojuego: \n");
				cin.ignore();
				cin.getline(articulo[i].nombre, 500);

				//A�o de lanzamiento
				printf("A�o de lanzamiento:\n");
				scanf_s("%d", &articulo[i].a�o);

				//Genero
				printf("G�nero: \n");
				cin.ignore();
				cin.getline(articulo[i].genero, 100);

				//Clasificacion
				printf("Clasificaci�n \n");
				cin.getline(articulo[i].clasificacion, 30);

				//Consola
				printf("Consola:\n");
				cin.getline(articulo[i].consola, 100);

				//Caracter�sticas
				printf("Caracter�sticas:\n");
				cin.getline(articulo[i].caracteristicas, 500);

				//Descripcion
				printf("Descripci�n:\n");
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

			//Modificar Art�culo
		case 2:
			break;
			//Eliminar Art�culo
		case 3:
			break;
			//Lista de Art�culos
		case 4:
			for (int i = 0; i < 3; i++)
			{

				printf("\n\nArt�culo %d\n", articulo[i].numero);
				printf("Nombre del videojuego: %s\n", articulo[i].nombre);
				printf("A�o de lanzamiento: %d\n", articulo[i].a�o);
				printf("G�nero: %s\n", articulo[i].genero);
				printf("Clasificaci�n: %s\n", articulo[i].clasificacion);
				printf("Consola: %s\n", articulo[i].consola);
				printf("Caracter�sticas: %s\n", articulo[i].caracteristicas);
				printf("Descripci�n: %s\n", articulo[i].descripcion);
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
		printf("El valor ingresado es inv�lido intente de nuevo\n");
		break;
	}
	}while (menu != 6);
	return 0;
}
	
