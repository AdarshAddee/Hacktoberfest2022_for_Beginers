// Github username: CodeBreaker518
// Aim: https://github.com/CodeBreaker518
// Date: 09/09/2022

// start coding

//DISCLAIMER: this program was developed on spanish, see a traduction if needed
#include <stdio.h>
#include <windows.h> //SLEEP (milisegundos)

int main (){
    //digitar tipo: hora, minuto, segundo
    int type, quantity, hora, minuto, segundo;
    printf ("1. Horas\n2. Minutos \n3. Segundos\n Eleccion?: ");
    scanf("%i", &type);
    
    //DIGITAR LA CANTIDAD DE HORAS MINUTOS O SEGUNDOS
    
    printf("Digite la cantidad: ");
    scanf("%i",&quantity);
    

	
	//3 BUCLES ANIDADOS DE TIPO FOR 3 para = horas, minutos, segundos
	for(int i=0;i<10323019203; i++){
		for (int hora = 0; hora <= 24; hora++){
				for (int minuto = 0; minuto < 60; minuto++ ){
					for(int segundo = 0; segundo<60; segundo++){
					
					//AGREGAR INTERVALO DE 1000MS == 1 SEGUNDO
					Sleep(1000);
	
					//IMPRIMIR NUESTRO CRONOMETRO
					printf("\r %.2i : %.2i : %i ",hora,minuto,segundo);
					
					//CONDICIONAL PARA LAS HORAS
					if (type == 1 && quantity <= hora){
						printf("\nCronometro Finalizado.");
						return 0;
						
					} //CONDICIONAL PARA LOS MINUTOS
					else if (type == 2 && quantity <= minuto){
						printf("\nCronometro Finalizado.");
						
						
					} //CONDICIONAL PARA LOS SEGUNDOS
					else if (type == 3 && quantity <= segundo){
						printf("\nCronometro Finalizado.");
						return 0;
					}
				}
			}
		}
	}
	

    return 0;
}