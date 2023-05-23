#include <iostream>
#include <stdio.h>
//librería para aceptar caracteres en español
#include <clocale>
#include <conio.h>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

//variables globales
char menu;
int cantidadArticulos;
int articulosGuardados;
int guardado = 0;
bool statusEliminado[100];
char rayita = 22;

//arreglos de los filtros
string clasificacionArray[100];
string consolaArray[100];
string generoArray[100];

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

//funciones
void alta();
void lista();
void eliminar();
void modificar();
void archivo();
void salir();
void menuPrincipal();
void regresoMenu();
void gotoxy(int x, int y);

int main()
{
	setlocale(LC_CTYPE, "Spanish");

	while (true)
	{
		menuPrincipal();
	}
}


void menuPrincipal()
{
	for (int i = 49; i < 77; i++)
	{
		gotoxy(i, 4); printf("%c", rayita);
	}
	for (int i = 49; i < 77; i++)
	{
		gotoxy(i, 15); printf("%c", rayita);
	}
	gotoxy(49, 5); printf("**     PLANETA JUEGOS     **");
	gotoxy(49, 6); printf("*      MENÚ PRINCIPAL     *");

		//Imprimir menu
		/*printf("Ingrese el número de la opción deseada\n\n");*/

	gotoxy(52, 9); printf("1. AGREGAR ARTICULO\n");
	gotoxy(52, 10); printf("2. MODIFICAR ARTICULO\n");
	gotoxy(52, 11); printf("3. ELIMINAR ARTICULO\n");
	gotoxy(52, 12); printf("4. LISTA DE ARTICULOS\n");
	gotoxy(52, 13); printf("5. LIMPIAR PANTALLA\n");
	gotoxy(52, 14); printf("6. SALIR\n\n");

		//leer opcion a operar
	gotoxy(63, 16); menu = _getch();
		system("cls");
		switch (menu)
		{
			//Alta
		case '1':
			alta();
			break;

			//Modificar
		case '2':
			modificar();
			break;

			//Eliminar
		case '3':
			eliminar();
			break;

			//Lista
		case '4':
			lista();
			break;

			//Limpiar pantalla
		case '5':
			system("cls");
			break;

			//Salir
		case '6':
			salir();
			break;
		default:
			break;
		}
}


//Crear puntero nulo
Alta* articulo = nullptr;
int countClasificacion = 0;
int countGenero = 0;
int countConsola = 0;

void alta()
{
	char op;
	//impresion de titulo de menu
	for (int i = 49; i < 77; i++)
	{
		gotoxy(i, 0); printf("%c", rayita);
	}
	gotoxy(54,1); printf("ALTA DE ARTÍCULOS\n\n");
	printf("¿Está seguro de querer añadir artículos nuevos?\n\n1. Continuar\n2. Volver al menú principal\n");
	op = _getch();
	if (op == '1')
	{
		printf("\n¿Cuántos artículos ingresará?\n");
		scanf_s("%d", &cantidadArticulos);
		//validacion
		while (cantidadArticulos < 1 || cantidadArticulos % 1 != 0)
		{
			system("cls");
			for (int i = 49; i < 77; i++)
			{
				gotoxy(i, 0); printf("%c", rayita);
			}
			gotoxy(54, 1); printf("ALTA DE ARTÍCULOS\n");

			printf("\nERROR Número ingresado es inválido. Intente de nuevo\n\n");
			printf("¿Cuántos artículos ingresará?\n");
			scanf_s("%d", &cantidadArticulos);
		}
		system("cls");
		for (int i = 49; i < 77; i++)
		{
			gotoxy(i, 0); printf("%c", rayita);
		}
		gotoxy(54, 1); printf("ALTA DE ARTÍCULOS\n\n");
		//Si el arreglo está vacío
		if (articulo == nullptr)
		{
			//Se crea un arreglo de tipo Alta con la cantidad ingresada
			articulosGuardados = cantidadArticulos;

			articulo = new Alta[cantidadArticulos];

			for (int i = 0; i < cantidadArticulos; i++)
			{
				//Impresion de titulo de menu
				for (int j = 49; j < 77; j++)
				{
					gotoxy(j, 0); printf("%c", rayita);
				}
				gotoxy(54, 1); printf("ALTA DE ARTÍCULOS\n\n\n\n");

				//Solicitar datos
				articulo[i].numero = i + 1;
				printf("\nARTÍCULO %d\n", articulo[i].numero);
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

				//Guardar clasificacion en arreglo de filtro
				bool yaexiste = false;
				for (int j = 0; j < countClasificacion; j++)
				{
					if (articulo[i].clasificacion == clasificacionArray[j])
					{
						yaexiste = true;
					}
				}
				if (yaexiste == false)
				{
					clasificacionArray[countClasificacion] = articulo[i].clasificacion;
					countClasificacion++;
				}
				//Guardar genero en arreglo de filtro
				yaexiste = false;
				for (int j = 0; j < countGenero; j++)
				{
					if (articulo[i].genero == generoArray[j])
					{
						yaexiste = true;
					}
				}
				if (yaexiste == false)
				{
					generoArray[countGenero] = articulo[i].genero;
					countGenero++;
				}
				//Guardar consola en arreglo de filtro
				yaexiste = false;
				for (int j = 0; j < countConsola; j++)
				{
					if (articulo[i].consola == consolaArray[j])
					{
						yaexiste = true;
					}
				}
				if (yaexiste == false)
				{
					consolaArray[countConsola] = articulo[i].consola;
					countConsola++;
				}
				//Opcion para pasar a la alta del siguiente artículo
				if (i != cantidadArticulos - 1)
				{
					printf("\n----Presione una tecla para ingresar el siguiente artículo----\n");
					guardado = _getch();
					if (guardado == 1)
					{
						system("cls");
					}
					else
					{
						system("cls");
					}
				}

			}
			regresoMenu();
		}
		//Si ya hay articulos dados de alta entonces
		else
		{
			//Crear un nuevo arreglo temporal con tamaño de artículos anteriores más los nuevos
			Alta* articuloTemp = new Alta[cantidadArticulos + articulosGuardados];

			//Copiar los articulos anteriores
			for (int i = 0; i < articulosGuardados; i++)
			{
				articuloTemp[i] = articulo[i];
			}

			//Añadir los nuevos datos
			for (int i = articulosGuardados; i < cantidadArticulos + articulosGuardados; i++)
			{
				//Impresion de titulo de menu
				for (int j = 49; j < 77; j++)
				{
					gotoxy(j, 0); printf("%c", rayita);
				}
				gotoxy(54, 1); printf("ALTA DE ARTÍCULOS\n\n\n\n");

				articuloTemp[i].numero = i + 1;
				printf("\nARTÍCULO %d\n", articuloTemp[i].numero);

				//Nombre de videojuego
				printf("Nombre del videojuego: \n");
				cin.ignore();
				getline(cin, articuloTemp[i].nombre);

				//Año de lanzamiento
				printf("Año de lanzamiento:\n");
				scanf_s("%d", &articuloTemp[i].año);

				//Genero
				printf("Género: \n");
				cin.ignore();
				getline(cin, articuloTemp[i].genero);

				//Clasificacion
				printf("Clasificación \n");
				getline(cin, articuloTemp[i].clasificacion);

				//Consola
				printf("Consola:\n");
				getline(cin, articuloTemp[i].consola);

				//Características
				printf("Características:\n");
				getline(cin, articuloTemp[i].caracteristicas);

				//Descripcion
				printf("Descripción:\n");
				getline(cin, articuloTemp[i].descripcion);

				//Precio unitario
				printf("Precio unitario:\n $ ");
				scanf_s("%f", &articuloTemp[i].precio);

				//Impuesto y total
				articuloTemp[i].impuesto = articuloTemp[i].precio * 0.16;
				printf("El impuesto es de $%.6g\n", articuloTemp[i].impuesto);
				articuloTemp[i].total = articuloTemp[i].precio + articuloTemp[i].impuesto;
				printf("El total es de $%.6g\n\n", articuloTemp[i].total);

				//Guardar clasificacion en arreglo de filtro
				bool yaexiste = false;
				for (int j = 0; j < countClasificacion; j++)
				{
					if (articuloTemp[i].clasificacion == clasificacionArray[j])
					{
						yaexiste = true;
					}
				}
				if (yaexiste == false)
				{
					clasificacionArray[countClasificacion] = articuloTemp[i].clasificacion;
					countClasificacion++;
				}
				//Guardar genero en arreglo de filtro
				yaexiste = false;
				for (int j = 0; j < countGenero; j++)
				{
					if (articuloTemp[i].genero == generoArray[j])
					{
						yaexiste = true;
					}
				}
				if (yaexiste == false)
				{
					generoArray[countGenero] = articuloTemp[i].genero;
					countGenero++;
				}

				//Guardar consola en arreglo de filtro
				yaexiste = false;
				for (int j = 0; j < countConsola; j++)
				{
					if (articuloTemp[i].consola == consolaArray[j])
					{
						yaexiste = true;
					}
				}
				if (yaexiste == false)
				{
					consolaArray[countConsola] = articuloTemp[i].consola;
					countConsola++;
				}
				if (i != cantidadArticulos + articulosGuardados - 1)
				{
					printf("\n----Presione una tecla para ingresar el siguiente artículo----\n");
					guardado = _getch();
					if (guardado == 1)
					{
						system("cls");
					}
					else
					{
						system("cls");
					}
				}
			}

			//Cambiuar la variable al total de articulos actuales
			articulosGuardados = articulosGuardados + cantidadArticulos;
			//Eliminar arreglo anterior y pasar datos
			delete[] articulo;
			articulo = articuloTemp;
			regresoMenu();
		}
	}
	else
	{
		regresoMenu();
	}
}


void lista()
{
	char filtro;
	int filtro2;

	//impresion de titulo de menu
	for (int i = 49; i < 77; i++)
	{
		gotoxy(i, 0); printf("%c", rayita);
	}
	gotoxy(54, 1); printf("LISTA DE ARTÍCULOS\n\n");

	printf("FILTROS: \n");
	printf("1. Todos los artículos\n");
	printf("2. Por clasificación\n");
	printf("3. Por géneros\n");
	printf("4. Por consolas\n\n");

	filtro = _getch();
	switch (filtro)
	{
		//Todos los articulos
	case '1':
		for (int i = 0; i < articulosGuardados; i++)
		{
			if (statusEliminado[i] == true)
			{
				printf("ARTÍCULO %d ELIMINADO\n", i + 1);
			}
			else
			{
				printf("\n\n\tARTÍCULO %d\n", articulo[i].numero);
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
		}
		regresoMenu();
		break;
		
		//Clasificacion
	case '2':
			//Imprime clasificaciones
		for (int i = 0; i < countClasificacion; i++) 
		{
			printf("%d Clasificación: %s\n",i+1, clasificacionArray[i].c_str());
		}
			//Lee clasificacion elegida
		scanf_s("%d", &filtro2);

			//Imprime articulos con clasificacion elegida
		for (int i = 0; i < articulosGuardados; i++)
		{
			if (articulo[i].clasificacion == clasificacionArray[filtro2-1])
			{
				if (statusEliminado[i] == true)
				{
					printf("ARTÍCULO %d ELIMINADO\n", i + 1); 
				}
				else
				{
					printf("\n\n\tARTÍCULO %d\n", articulo[i].numero);
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
			}
		}
		regresoMenu();
		break;
		
		//Generos
	case '3':
		//Imprime generos
		for (int i = 0; i < countGenero; i++) 
		{
			printf("%d Género: %s\n", i + 1, generoArray[i].c_str()); 
		}
		//Lee genero elegido
		scanf_s("%d", &filtro2);

		//Imprime articulos con genero elegido
		for (int i = 0; i < articulosGuardados; i++)
		{
			if (articulo[i].genero == generoArray[filtro2 - 1])
			{
				if (statusEliminado[i] == true)
				{
					printf("ARTÍCULO %d ELIMINADO\n", i + 1);
				}
				else
				{
					printf("\n\n\tARTÍCULO %d\n", articulo[i].numero);
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
			}
		}
		regresoMenu();
		break;
		
		//Consolas
	case '4':
		//Imprime consolas
		for (int i = 0; i < countConsola; i++) 
		{
			printf("%d Consola: %s\n", i + 1, consolaArray[i].c_str());
		}
		//Lee categoria elegida
		scanf_s("%d", &filtro2);

		//Imprime articulos con clasificacion elegida
		for (int i = 0; i < articulosGuardados; i++)
		{
			if (articulo[i].consola == consolaArray[filtro2 - 1])
			{
				if (statusEliminado[i] == true)
				{
					printf("ARTÍCULO %d ELIMINADO\n", i + 1);
				}
				else
				{
					printf("\n\n\tARTÍCULO %d\n", articulo[i].numero);
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
			}
		}
		regresoMenu();
		break;

	default:
		regresoMenu();
		break;
	}
}

void eliminar()
{
	int artEliminado;
	char op;

	//impresion de titulo de menu
	for (int i = 49; i < 77; i++)
	{
		gotoxy(i, 0); printf("%c", rayita);
	}
	gotoxy(54, 1); printf("ELIMINAR ARTÍCULO\n\n");

	printf("¿Está seguro de querer eliminar un artículo?\n1.Sí  2.No\n");
	op = _getch();
	if (op == '1')
	{
		printf("Ingrese el número del artículo a eliminar\n"); 
		scanf_s("%d", &artEliminado);

		while (artEliminado > articulosGuardados || artEliminado < 1 || artEliminado % 1 != 0)
		{
			printf("ERROR Número ingresado es inválido. Seleccione: \n1. Ingresar número de nuevo\n2. Volver al menú principal\n");
			op = _getch();
			if (op == '1')
			{
				printf("\nIngrese el número del artículo que desea modificar\n");
				scanf_s("%d", &artEliminado);
			}
			else
			{
				regresoMenu();
			}
		}
		printf("\t\nINFORMACIÓN GUARDADA: ");

		printf("\n\n\tARTÍCULO %d\n", articulo[artEliminado-1].numero);
		printf("Nombre del videojuego: %s\n", articulo[artEliminado - 1].nombre.c_str());
		printf("Año de lanzamiento: %d\n", articulo[artEliminado - 1].año);
		printf("Género: %s\n", articulo[artEliminado - 1].genero.c_str());
		printf("Clasificación: %s\n", articulo[artEliminado - 1].clasificacion.c_str());
		printf("Consola: %s\n", articulo[artEliminado - 1].consola.c_str());
		printf("Características: %s\n", articulo[artEliminado - 1].caracteristicas.c_str());
		printf("Descripción: %s\n", articulo[artEliminado - 1].descripcion.c_str());
		printf("Precio unitario: $%.6g\n", articulo[artEliminado - 1].precio);
		printf("El impuesto es de $%.6g\n", articulo[artEliminado - 1].impuesto);
		printf("El total es de $%.6g\n\n", articulo[artEliminado - 1].total);
		printf("\n----¿Está seguro de querer eliminar el artículo %d?----\n\n", artEliminado);
		printf("1.Eliminar\n2.Volver al menú principal\n");
		op = _getch();
		switch (op)
		{
		case'1':
			statusEliminado[artEliminado - 1] = true; 
			printf("\nARTÍCULO %d ELIMINADO\n", artEliminado);
			regresoMenu();
			break;
		case '2':
			regresoMenu();
			break;
		default:
			regresoMenu();
			break;
		}
		
	}
	else 
	{
		regresoMenu();
	}
}

void modificar()
{
	int artModificar=0;
	char op;
	char opModificar;
	bool yaexiste = false;

	//impresion de titulo de menu
	for (int i = 49; i < 77; i++)
	{
		gotoxy(i, 0); printf("%c", rayita);
	}
	gotoxy(54, 1); printf("MODIFICAR ARTÍCULO\n\n");

	printf("¿Está seguro de querer modificar un artículo?\n1.Sí  2.No\n");
	op = _getch(); 
	if (op == '1') 
	{
		printf("\nIngrese el número del artículo que desea modificar\n");
		scanf_s("%d", &artModificar);

		//validacion de numero ingresado
		while(artModificar > articulosGuardados||artModificar<1||artModificar%1!=0)
		{
			printf("ERROR Número ingresado es inválido. Seleccione: \n1. Ingresar número de nuevo\n2. Volver al menú principal\n");
			op = _getch();
			if (op == '1')
			{
				printf("\nIngrese el número del artículo que desea modificar\n");
				scanf_s("%d", &artModificar); 
			}
			else
			{
				regresoMenu();
			}
		}
		//Articulo eliminado
		if (statusEliminado[artModificar - 1] == true)
		{
			printf("ERROR artículo eliminado\n");
			regresoMenu();
		}
		//Modificar articulo
		else
		{
			printf("\t\nINFORMACIÓN GUARDADA: ");

			printf("\n\n\tARTÍCULO %d\n", articulo[artModificar - 1].numero);
			printf("Nombre del videojuego: %s\n", articulo[artModificar - 1].nombre.c_str());
			printf("Año de lanzamiento: %d\n", articulo[artModificar - 1].año);
			printf("Género: %s\n", articulo[artModificar - 1].genero.c_str());
			printf("Clasificación: %s\n", articulo[artModificar - 1].clasificacion.c_str());
			printf("Consola: %s\n", articulo[artModificar - 1].consola.c_str());
			printf("Características: %s\n", articulo[artModificar - 1].caracteristicas.c_str());
			printf("Descripción: %s\n", articulo[artModificar - 1].descripcion.c_str());
			printf("Precio unitario: $%.6g\n", articulo[artModificar - 1].precio);
			printf("El impuesto es de $%.6g\n", articulo[artModificar - 1].impuesto);
			printf("El total es de $%.6g\n\n", articulo[artModificar - 1].total);
			printf("\n----¿Está seguro de querer modificar el artículo %d?----\n\n", artModificar);
			printf("1.Continuar\n2.Volver al menú principal\n");
			op = _getch();
			switch (op)
			{
			case'1':
				printf("¿Qué parte del artículo %d desea modificar?\n\n", artModificar);
				printf("//1. Nombre // 2. Año // 3. Género // 4. Clasificación//\n// 5. Consola // 6. Características // 7. Descripción// 8. Precio\n");
				opModificar = _getch();
				switch (opModificar)
				{
				case '1':
					system("cls");
					//impresion de titulo de menu
					for (int i = 49; i < 77; i++)
					{
						gotoxy(i, 0); printf("%c", rayita);
					}
					gotoxy(54, 1); printf("MODIFICAR ARTÍCULO\n\n");
					printf("\tARTÍCULO %d **NOMBRE**\n", artModificar);

					printf("\nEl dato actual es: %s\n\n //Ingrese el nuevo nombre:\n", articulo[artModificar - 1].nombre.c_str());
					cin.ignore();
					getline(cin, articulo[artModificar - 1].nombre);
					printf("\nInformación guardada con éxito!\n");
					regresoMenu();
					break;
				case '2':
					system("cls");
					//impresion de titulo de menu
					for (int i = 49; i < 77; i++)
					{
						gotoxy(i, 0); printf("%c", rayita);
					}
					gotoxy(54, 1); printf("MODIFICAR ARTÍCULO\n\n");
					printf("\tARTÍCULO %d **AÑO**\n", artModificar);

					printf("El dato actual es: %d\n //Ingrese el nuevo año:\n", articulo[artModificar - 1].año);
					scanf_s("%d", &articulo[artModificar - 1].año);
					printf("Información guardada con éxito!\n");
					regresoMenu();
					break;
				case '3':
					system("cls");
					//impresion de titulo de menu
					for (int i = 49; i < 77; i++)
					{
						gotoxy(i, 0); printf("%c", rayita);
					}
					gotoxy(54, 1); printf("MODIFICAR ARTÍCULO\n\n");
					printf("\tARTÍCULO %d **GÉNERO**\n", artModificar);

					printf("El dato actual es: %s\n //Ingrese el nuevo género:\n", articulo[artModificar - 1].genero.c_str());
					cin.ignore();
					getline(cin, articulo[artModificar - 1].genero);
					printf("Información guardada con éxito!\n");

					yaexiste = false;
					for (int j = 0; j < countGenero; j++)
					{
						if (articulo[artModificar - 1].genero == generoArray[j])
						{
							yaexiste = true;
						}
					}
					if (yaexiste == false)
					{
						generoArray[countGenero] = articulo[artModificar - 1].genero;
						countGenero++;
					}
					regresoMenu();
					break;
				case '4':
					system("cls");
					//impresion de titulo de menu
					for (int i = 49; i < 77; i++)
					{
						gotoxy(i, 0); printf("%c", rayita);
					}
					gotoxy(54, 1); printf("MODIFICAR ARTÍCULO\n\n");
					printf("\tARTÍCULO %d **CLASIFICACIÓN**\n", artModificar);

					printf("El dato actual es: %s\n //Ingrese la nueva clasificación:\n", articulo[artModificar - 1].clasificacion.c_str());
					cin.ignore();
					getline(cin, articulo[artModificar - 1].clasificacion);
					printf("Información guardada con éxito!\n");

					yaexiste = false;
					for (int j = 0; j < countClasificacion; j++)
					{
						if (articulo[artModificar - 1].clasificacion == clasificacionArray[j])
						{
							yaexiste = true;
						}
					}
					if (yaexiste == false)
					{
						clasificacionArray[countClasificacion] = articulo[artModificar - 1].clasificacion;
						countClasificacion++;
					}
					regresoMenu();
					break;
				case '5':
					system("cls");
					//impresion de titulo de menu
					for (int i = 49; i < 77; i++)
					{
						gotoxy(i, 0); printf("%c", rayita);
					}
					gotoxy(54, 1); printf("MODIFICAR ARTÍCULO\n\n");
					printf("\tARTÍCULO %d **CONSOLA**\n", artModificar);

					printf("El dato actual es: %s\n //Ingrese la nueva consola:\n", articulo[artModificar - 1].consola.c_str());
					cin.ignore();
					getline(cin, articulo[artModificar - 1].consola);
					printf("Información guardada con éxito!\n");

					yaexiste = false;
					for (int j = 0; j < countConsola; j++)
					{
						if (articulo[artModificar - 1].consola == consolaArray[j])
						{
							yaexiste = true;
						}
					}
					if (yaexiste == false)
					{
						consolaArray[countConsola] = articulo[artModificar - 1].consola;
						countConsola++;
					}
					regresoMenu();
					break;
				case'6':
					system("cls");
					//impresion de titulo de menu
					for (int i = 49; i < 77; i++)
					{
						gotoxy(i, 0); printf("%c", rayita);
					}
					gotoxy(54, 1); printf("MODIFICAR ARTÍCULO\n\n");
					printf("\tARTÍCULO %d **CARACTERÍSTICAS**\n", artModificar);

					printf("El dato actual es: %s\n //Ingrese las nuevas características:\n", articulo[artModificar - 1].caracteristicas.c_str());
					cin.ignore();
					getline(cin, articulo[artModificar - 1].caracteristicas);
					printf("Información guardada con éxito!\n");
					regresoMenu();
					break;
				case '7':
					system("cls");
					//impresion de titulo de menu
					for (int i = 49; i < 77; i++)
					{
						gotoxy(i, 0); printf("%c", rayita);
					}
					gotoxy(54, 1); printf("MODIFICAR ARTÍCULO\n\n");
					printf("\tARTÍCULO %d **DESCRIPCIÓN**\n", artModificar);

					printf("El dato actual es: %s\n //Ingrese la nueva descripción:\n", articulo[artModificar - 1].descripcion.c_str());
					cin.ignore();
					getline(cin, articulo[artModificar - 1].descripcion);
					printf("Información guardada con éxito!\n");
					regresoMenu();
					break;
				case'8':
					system("cls");
					//impresion de titulo de menu
					for (int i = 49; i < 77; i++)
					{
						gotoxy(i, 0); printf("%c", rayita);
					}
					gotoxy(54, 1); printf("MODIFICAR ARTÍCULO\n\n");
					printf("\tARTÍCULO %d **PRECIO**\n", artModificar);

					printf("El dato actual es: $%.6g\n //Ingrese el nuevo precio:\n", articulo[artModificar - 1].precio);
					scanf_s("%f", &articulo[artModificar - 1].precio);
					printf("Información guardada con éxito!\n");

					articulo[artModificar - 1].impuesto = articulo[artModificar - 1].precio * 0.16;
					articulo[artModificar - 1].total = articulo[artModificar - 1].precio + articulo[artModificar - 1].impuesto;
					regresoMenu();
				default:
					break;
				}
				regresoMenu();
				break;
			case '2':
				regresoMenu();
				break;
			default:
				regresoMenu();
				break;
			}
		}
	}
	else
	{
		regresoMenu();
	}
}

void archivo()
{
	ofstream File;
	File.open("Planeta_juegos.txt");
	File<<"**     PLANETA JUEGOS     **"<<endl<<endl;
	for (int i = 0; i < articulosGuardados; i++)
	{
		if (statusEliminado[i] == true)
		{
			File<<"\nARTÍCULO " <<i+1<< " ELIMINADO\n";
		}
		else
		{
			File << "\n\n-----ARTÍCULO " << articulo[i].numero << "-----" << endl;
			File << articulo[i].nombre.c_str() << endl;
			File << "Año de lanzamiento: " << articulo[i].año << endl;
			File << "Género: " << articulo[i].genero.c_str() << endl;
			File << "Clasificación: " << articulo[i].clasificacion.c_str() << endl;
			File << "Consola: " << articulo[i].consola.c_str() << endl;
			File << "Características: " << articulo[i].caracteristicas.c_str() << endl;
			File << "Descripción: " << articulo[i].descripcion.c_str() << endl;
			File << "Precio unitario: " << articulo[i].precio << endl;
			File << "Impuesto: " << articulo[i].impuesto << endl;
			File << "Total: " << articulo[i].total << endl;
		}
	}
	File.close();
}

void salir()
{
	char op;
	printf("\n\n¿Está seguro de querer cerrar el programa? La información no guardada no se incluirá en el archivo\n\n");
	printf("1. Salir\n2. Volver al menú principal\n");
	op = _getch();
	switch (op)
	{
	case'1':
		archivo();
		exit(1);
		break;
	case'2':
		regresoMenu();
	default:
		regresoMenu();
	}
}

void regresoMenu()
{
	printf("\n----Presione una tecla para volver al menu principal----\n");
	guardado = _getch();
	if (guardado == 1)
	{
		system("cls");
		menuPrincipal();
	}
	else
	{
		system("cls");
		menuPrincipal();
	}
}
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
