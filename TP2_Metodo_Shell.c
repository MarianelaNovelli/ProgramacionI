#include <stdio.h>
void shell(int[], int);            
void imprimir(int[], int);

int main()
{
    int longitud_vector = 0;
    
    printf("Ingrese la cantidad de numeros que desea ordenar: ");
    scanf("%d", &longitud_vector);    
    
    int vector[longitud_vector];
    for (int i = 0; i < longitud_vector; i++)
    {
        printf("Ingrese el numero de la posicion %i del vector: ", i + 1);
        fflush(stdin);
        scanf("%d", &vector[i]);
    }

    printf("Vector ingresado: ");
    for (int i = 0; i < longitud_vector; i++)  
    {
        printf("%d \t", vector[i]);
    }

    shell(vector, longitud_vector); 
    imprimir(vector, longitud_vector);

    return 0;
}

void shell(int array[], int posiciones_array)
{
    int i = 0, j = 0, auxiliar = 0;
    int incremento = 0; 

    for (incremento = posiciones_array / 2; incremento > 0; incremento = incremento / 2)
    {
        for (i = incremento; i < posiciones_array; i++)
        {
            for(j = i - incremento; j >= 0; j = j - incremento)
            {
                if (array[j + incremento] >= array[j])
                    {
                        j = j - 1; 
                        break; 
                    }
                else
                {
                    auxiliar = array[j];
                    array[j] = array[j + incremento];
                    array[j + incremento] = auxiliar;
                }
            }
        }
    }
}

void imprimir(int array[], int posiciones_array)
{
    printf("\nVector ordenado: ");
    for (int i = 0; i < posiciones_array; i++)
    {
        printf("%d \t", array[i]);
    }
}