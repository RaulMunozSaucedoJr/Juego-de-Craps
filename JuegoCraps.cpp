//Materia: Estructura de Datos.
//Programa: Juego Craps.

//enum: Conjunto de constantes enteras. A enum se le puede asignar un nombre/numero que se comportara como un nuevo tipo de dato que solo podra contener valores especificados en la enumeracion.
//void: Se utiliza como un tipo de valor devuelto.

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Archivo de cabecera que muestra la fecha del sistema.

//Se ponen las constantes de enumeracion que representan el estado del juego.

enum Estatus {CONTINUA, GANA, PIERDE}; //Estados actual del juego.

int tiraDados(void); //Funcion de tirarDados

//Inicio del programa
int main()
	{ //Inicia el main.
	int suma=0; //Se declara la suma del tiro de dados
	int miPunto; //Puntos Ganados
	int RM=0;
	do{
	puts("Bienvenidos al juego de craps \n Por favor seleccione la opcion deseada \n [1] Jugar \n [2] Leer intrucciones \n [3] Salir \n");
	scanf("%d",&RM);
	system("cls");
	switch(RM){
               case 1:
	enum Estatus estatusJuego; //Estado que puede contener tanto GANAR, PERDER O CONTINUAR.
	
	//Se generan los numeros RANDOM o ALEATORIOS mediante el uso de la funcion srand
	srand(time(NULL)); //
	
	suma = tiraDados(); //Aqui se ejecuta el primer tiro/lanzamiento de los dados.
	
	//Aqui se determina el estatus del juego basado en la suma de los dos valores obtenidos de ambos dados.
	switch(suma)	//Suma de dados (cases).
	{ //Inicia el switch
		
		//Caso en el que se gana al primer tiro de ambos dados
		case 7:
		case 11:
			estatusJuego = GANA;
			break;
			
		//Caso en el que se pierde en el primer tiro de ambos dados
		case 2: 
		case 3:
		case 12:
			estatusJuego = PIERDE; //Estatus Pierde.
			break; //
				
		//Aqui recordamos los puntos obtenidos mediante el tiro de ambos dados.
		default:
			estatusJuego = CONTINUA; //Se muestra si el juego CONTINUA.
			miPunto = suma;
			printf(" \n"); //Salto de Linea.
			printf("		**Sus puntos son %d/n		**", miPunto); //Se imprimen en pantalla los puntos obtenidos.
			printf(" \n"); //Salto de Linea.
			break; //Frena este proceso.	
	} //Termina el switch
	
	//Mientras el juego no se complete, continuamos con lo siguiente.
	while (estatusJuego == CONTINUA) //Se muestra si el jugador CONTINUA.
	{ //Inicia el while
		suma = tiraDados(); //Aqui se tiran de nuevo los dados. Esto solo en caso de que no se haya ganado con el primer tiro de ambos dados.
		suma = tiraDados(); //Aqui se tiran de nuevo los dados. Esto solo en caso de que no se haya ganado con el primer tiro de ambos dados.
		
	//Determina el estatus del juego.
	if (suma == miPunto)
	{ //Inicia el if.
		estatusJuego = GANA; //Se muestra si el jugador GANA.		
	} //Termina el if.
		else 
	{ //Inicia el else.
		if(suma == 7) //Se determina que el juegador pierde por tirar 7.
	{ //Inicia el if.
		estatusJuego = PIERDE; //Se muestra que el jugar PIERDE. Por lo tanto el juego termina.
		break; 	
	} //Termina el if.
	} //Termina el else.
	} //Termina el while
	
	//Aqui se despliega un mensaje que avisa al jugador si resulto GANADOR O PERDEDOR.
	if (estatusJuego == GANA) //Estatus GANADOR del jugador.
	{ //Inicia el if
		printf(" \n"); //Salto de Linea.
		printf("		**		Gana el jugador		**"); //Se muestra mensaje de que el jugador resulto GANADOR.
		printf(" \n");	//Salto de Linea.
	} //Termina el if.
		else
	{ //Inicia else.
		printf(" \n");	//Salto de Linea.
		printf("		**		Pierde el jugador/n		**"); //Se muestra mensaje de que el jugador resulto PERDEDOR.
		printf(" \n"); //Salto de Linea
	} //Termina else.
	break;
	case 2:
         puts("Hay 2 formas de ganar \n    1: Obtener una puntuacion de 7 u 11 en el primer lanzamiento\n\n\n 2: obtener 4,5,6,8,9,o 10 en la primera tirada \nlo que da la oportunidad de una segunda tirada donde debe obtener \n la misma puntuacion antes de tener un 7"); 
         break;
         }
         }
         while(RM !=3 );
	system("pause");
		return 0; //Inidica que el juego fue exitoso.
	} //Termina del main.
	
	//Tiro de dados. Ademas se calcula la suma de ambos y se despliegan los resultados.
	int tiraDados(void)
	{ //Inicia la funcion Tirar Dados.
		int dado1; //Primer dado.
		int dado2; //Segundo dado.
		int sumaTemp; //Suma de los dados.
		
		dado1 = 1 + (rand() % 6); //Toma el aleatorio para el dado 1.
		dado2 = 1 + (rand() % 6); //Toma el aleatorio para el dado 2.
		sumaTemp = dado1 + dado2; //Suma el dado1 y el dado2.
		
		//Despliega los resultados de este tiro.
		printf(" \n"); //Salto de Linea.
		printf("		**		El jugador tiro %d + %d = %d		**", dado1, dado2, sumaTemp); //Se imprime en pantalla el numero que resulto de los dos lados.
		printf(" \n"); //Salto de linea
		return (sumaTemp); //Devuelve la suma de ambos dados.
	} //Termina funcion Tirar Dados.

