#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
int lon_p, p_bits, lon_h, e; //Variables pertenecientes a la logica del proceso
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

//Generar el arreglo que contiene los coeficientes de 2^p_bits
int * coefiecientes = (int *)malloc(p_bits * sizeof(int));
for(i = 0; i<p_bits; i++){
    coefiecientes[i] = pow(2,i);}



//Crear una matriz que almacena las posiciones permitidas para cada bit -1 significa que la posicion no puede ser ocupada, 1 siginifica que la poisicion puede ser ocupada
fil = p_bits;
col = lon_h;
int **matriz = (int **)malloc(fil * sizeof(int *));
for (int i = 0; i < fil; i++) {
    matriz[i] = (int *)malloc(col * sizeof(int));}


e = -1;
for (i = 0; i < fil; i++){
    int cont = 0;
        for(j = 0; j < col; j++){
            if (cont == pow(2,i)){
                cont = 0;
                e = (-1)*e;}
            matriz[i][j]=e;
            cont++;}
            e = -1;}

//Inicio contenido//
for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matriz[i][j]);}
            printf("\n");}
//Fin contenido//


/*Se copia la matriz de posiciones permitidas en una matriz de comparacion*/
int **matriz_comp = (int **)malloc(fil * sizeof(int *));
for (int i = 0; i < fil; i++)
    matriz_comp[i] = (int *)malloc(col * sizeof(int));
matriz_comp=matriz;



/*Se sustituyen las posiciones de los bits de paridad en la matriz de compracion*/
for (i = 0; i < fil; i++){
    for (j = 0; j < col; j++){
        if(posiciones[j]==2){
            matriz_comp[i][j]=2;}
    }
}
//Inicio contenido//
for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matriz_comp[i][j]);}
            printf("\n");}
//Fin contenido//


/*Se sustiyen las posiciones permitidas en la matriz de comp por el mensaje en el arreglo posiciones*/
for (i = 0; i < fil; i++){
    for (j = 0; j < col; j++){
        if(matriz[i][j]==1){
            matriz_comp[i][j]=posiciones[j];}
    }
}

/*Se crea un arreglo en donde se almacenan p_bits que funcionaran como bits de verificacion*/
int *bit_ver = (int *)malloc(p_bits * sizeof(int));

/*Se cuenta la cantidad de 1's en cada fila de la matriz de comp, si son pares se guarda un 0 en bit_ver, si son impares, se guarda un 1.*/
for (i = 0; i < fil; i++){
    k = 0;
    for (j = 0; j < col; j++){
        if (matriz_comp[i][j]==1){
            k++;}
    }
    bit_ver[i]=k;
}


/*Imprimir la tabla*/
//Encabezado Inicio//
j = 1;
printf("\t");
for (i = 0; i < col; i++){
    printf("|%d\t",i+1);}
printf("|Verificar\n\t");
for(i = 0; i < col; i++){
    if(posiciones[i] == 2){
        printf("|P%d\t",j+1);
        j++;}
    else{
    printf("|%d \t", posiciones[i]);}
}
printf("|\n");
//Fin Encabezado//

//Inicio contenido//
for (i = 0; i < fil; i++) {
        printf("P%d\t",i+1);
        for (j = 0; j < col; j++) {
            printf("|%d\t ", matriz[i][j]);}
        printf("|%d\t\n",bit_ver[i]);}
//Fin contenido//
return 0;
}
