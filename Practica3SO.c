#include <stdio.h>
#include <math.h>
#include <ctype.h>

float stack[8];

void prinStack(void){
    printf("                Pila actual: \n");
    for (int i = 0; i < 8; i++)
    {
        /* code */
        printf("   %d", 8-i);
        printf("   %f\n", stack[i]);
    }
    
   
}

void CargarPila(void){
    /*funcion para subir elementos a la pila: stack[0] => [7]*/
    for(int i = 7; i >= 0;i--){
        stack[i] = stack[i - 1];
    }
}

void DescargarPila(void){
     /*Funcion para bajar elementos de la pila stack[7] => stack[0]
     teniendo encuenta que la visualizacion funciona al inverso */
     int i = 0;
     do{
        stack[i - 1] = stack[i];
        i++;
     }while (i < 8);
}

void addToStack(float num_to_add){
    //Funcion para agregar valores a la pila/
    stack[7] = num_to_add;
    printf("\n\n");
}

void LimpiarPila(void){
    for(int i = 0;i < 8; i++){
        stack[i] = 0;
    }
}

void printMenu(void){
    prinStack();
    printf("[*]------------------------------------------------[*]\n");
    printf("[*]                                                [*]\n");
    printf("[*]            1. Ingresar un número               [*]\n");
    printf("[*]           2. Seleccione Operacion              [*]\n");
    printf("[*]          3. Limpiar último valor               [*]\n");
    printf("[*]         4. Limpiar toda la pila                [*]\n");
    printf("[*]        5. Salir                                [*]\n");
    printf("[*]       Ingrese un valor numerico valido:        [*] \n");
    printf("[*]------------------------------------------------[*]\n");
    printf("\n");
}

int main(){
    int opc, aux;
    char opr;
    float num, r= 0;
    char c;
    //Ciclo para imprimir el menu principal/
    do{
        printMenu();
        while ((c = getchar()) != '\n' && c != EOF);
        if (scanf("%d", &aux) != 1 || aux > 5 || aux < 0){
            printf("Ingrese una opcion valida\n");
            printf("Intentalo nuevamente con un opcion valida\n");
        }else{
            opc = aux;
            if(opc == 1){
                if(stack[0] == 0){
                    printf("\n\n");
                    printf("Ingrese un número: \n\n");
                    if(scanf("%f",&num) != 1){
                        printf("El valor ingresado no es un numero \n");
                    }else{
                        DescargarPila();
                        addToStack(num);
                        printf("\n\n");
                    }
                
                }
                else{
                printf("\n\n");
                printf("Pila llena\n");
                printf("Elimine un valor o realice una operación para continuar\n\n");
                }
            }if(opc == 2){
            //Menú con las operaciones
                printf("\n");
                printf("-------------------------------------\n");
                printf("¿Qué operación desea hacer?\n");
                printf("+ : Suma\n");
                printf("- : Resta\n");
                printf("* : Multiplicación\n");
                printf("/ : División\n");
                printf("^ : Potencia\n");
                printf("r : Raiz\n");
                printf("s para la funcion seno: Sen\n");
                printf("c para la funcion coseno: Cos\n");
                printf("t para la funcion tangente: Tan\n");
                printf("-------------------------------------\n");
                printf("Seleccione la operacion a realizar: \n\n");
                scanf("%s", &opr);

                switch (opr){
                case '+':
                    r= stack[6] + stack[7];
                    CargarPila();
                    addToStack(r);
                    printf("\n\n");
                    break;
                case '-':
                    r= stack[6] - stack[7];
                    CargarPila();
                    addToStack(r);
                    printf("\n\n");
                    break;
                case '*':
                    r= stack[6] * stack[7];
                    CargarPila();
                    addToStack(r);
                    printf("\n\n");
                    break;
                case '/':
                    if(stack[7] == 0){
                        printf("\n");
                        printf("Error matematico\n");
                        break;
                    }else
                    {
                        r= stack[6] / stack[7];
                        CargarPila();
                        addToStack(r);
                        printf("\n\n");
                        break;
                    }
                case '^':
                    r= pow(stack[6],stack[7]);
                    CargarPila();
                    addToStack(r);
                    printf("\n\n");
                    break;
                case 'r':
                    if(stack[7] > 0){
                        r= sqrt(stack[7]);
                        CargarPila();
                        addToStack(r);
                        printf("\n\n");
                        break;
                    }else if(stack[7] < 0){
                        printf("\n");
                        printf("      Error Matematico \n");
                        break;
                    }
                case 's':
                    r= sin(stack[7]);
                    CargarPila();
                    addToStack(r);
                    printf("\n\n");
                    break;
                case 'c':
                    r= cos(stack[7]);
                    CargarPila();
                    addToStack(r);
                    printf("\n\n");
                    break;
                case 't':
                if((int)stack[7] % 90 == 0){
                    printf("\n");
                    printf("Error matematico");
                    break;
                }else{
                    r= tan(stack[7]);
                    CargarPila();
                    addToStack(r);
                    printf("\n\n");
                    break;
                }default:
                    printf("La operacion ingresada es inexistente");
                    break;
                }                         

            }if(opc == 3){
                CargarPila();
                printf("\n");
            }if(opc == 4){
                LimpiarPila();
            }if(opc == 5){
                printf("Fin del programa...");
            }
              
        }
        
    }while(opc != 5);

}