#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
int lon_p, p_bits, lon_h; //Variables pertenecientes a la logica del proceso
int i,j,k; //Variables de contador
int fil, col; // Variables de la tabla

//Obtener el tamaño de la palabra digital

printf("¿Cual es la extension de su palabra en bits\n");
scanf("%d/n", &lon_p);

//Crear y llenar un arreglo dinamico con los bits de la palabra digital
int *mensaje = (int *)malloc(lon_p * sizeof(int));

printf("\n Ingrese la palabra digital:\n");
    for (i = 0; i < lon_p; i++) {
        printf("Ingrese el bit %d\n", i);
        scanf("%d", &mensaje[i]);
        }

//Obtener la cantidad de bits de paridad, longitud del codigo de Hamming
p_bits = 1;
while ((p_bits + lon_p + 1) > pow(2, p_bits)){
        p_bits++;
        }
lon_h = p_bits + lon_p;
printf("Hay %d bits de paridad\nLa longitud del codigo de Hamming es de %d bits\n",p_bits, lon_h);

//Llenar el arreglo que contiene las posiciones de los bits de paridad y los bits del mensaje
int * posiciones = (int *)malloc(lon_h * sizeof(int));
j = 0;
k = 0;
for (i = 0; i < lon_h; i++){
    if (i + 1 == pow(2,j)){
        posiciones[i] = 2;
        j++;}
    else{
       posiciones[i] = mensaje[k];
       k++;}
        }

//Imprimir el arreglo posiciones
/*j = 1;
for(i = 0; i < lon_h; i++){
    if(posiciones[i] == 2){
        printf("|P%d|",j);
        j++;}
    else{
    printf("|%d|", posiciones[i]);}
}*/


//Generar el arreglo que contiene los coeficientes de 2^p_bits
int * coefiecientes = (int *)malloc(p_bits * sizeof(int));
for(i = 0; i<p_bits; i++){
    coefiecientes[i] = pow(2,i);}


//Imprimir el arreglo coeficientes
for(i = 0; i < p_bits; i++){
    printf("|%d|\n", coefiecientes[i]);
}




return 0;
}
