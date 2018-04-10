#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <time.h>
#include <locale.h>


using namespace std;

struct dado{
    int room_id;
    int host_id;
    char room_type[50];
    char country[50];
    char city[50];
    char neighborhood[50];
    char reviews[50];
    char overall_satisfaction[50];
    char accommodates[50];
    char bedrooms[50];
    char price[50];
    char property_type[50];
};
void printDados(dado *airbnb, int n){
    for(int i = 0; i < n; i++){
        printf("\n%i\t %i\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",
                    airbnb[i].room_id, airbnb[i].host_id, airbnb[i].room_type,
                    airbnb[i].country, airbnb[i].city, airbnb[i].neighborhood,
                    airbnb[i].reviews, airbnb[i].overall_satisfaction, airbnb[i].accommodates,
                    airbnb[i].bedrooms, airbnb[i].price, airbnb[i].property_type);

    }
}
void bolha(dado *airbnb, int n){
    /*/Inicia a contagem do tempo
    clock_t Ticks[2];
    Ticks[0] = clock();
    //O código a ter seu tempo de execução medido ficaria neste ponto.*/
    dado temp;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){

            if (airbnb[j].room_id > airbnb[j+1].room_id){
                temp = airbnb[j];
                airbnb[j] = airbnb[j+1];
                airbnb[j+1] = temp;
            }
        }
    }
    /*Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto ao ordenar por BubbleSort: %g ms.", Tempo);
    getchar();*/
}
void selecao(dado *airbnb, int n){//SELECAO
    /*/Inicia a contagem do tempo
    clock_t Ticks[2];
    Ticks[0] = clock();
    //O código a ter seu tempo de execução medido ficaria neste ponto.*/
    int i, j, menor;
    dado temp;
    for (i = 0; i < n-1; i++){
        menor = i;
        for (j = i + 1; j < n; j++){
            if (airbnb[j].room_id < airbnb[menor].room_id){
                menor = j;
            }
        }
        temp = airbnb[menor];
        airbnb[menor] = airbnb[i];
        airbnb[i] = temp;
    }
    /*Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto ao ordenar por SelectionSort: %g ms.", Tempo);
    getchar();*/
}
void merges(dado *airbnb, int l, int m, int r){

    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    dado L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = airbnb[l + i];
    for (j = 0; j < n2; j++)
        R[j] = airbnb[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].room_id <= R[j].room_id)
        {
            airbnb[k] = L[i];
            i++;
        }
        else
        {
            airbnb[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        airbnb[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        airbnb[k] = R[j];
        j++;
        k++;
    }

}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(dado *airbnb, int l, int r, int toTime = 0){

    if (l < r){
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(airbnb, l, m , 1);
        mergeSort(airbnb, m+1, r, 1);

        merges(airbnb, l, m, r);
    }
}

void quick_sort(dado *airbnb, int left, int right) {
    /*/Inicia a contagem do tempo
    clock_t Ticks[2];
    Ticks[0] = clock();
    //O código a ter seu tempo de execução medido ficaria neste ponto.*/
    int i, j;
    dado x, y;

    i = left;
    j = right;
    x = airbnb[(left + right) / 2];

    while(i <= j) {
        while(airbnb[i].room_id < x.room_id && i < right) {
            i++;
        }
        while(airbnb[j].room_id > x.room_id && j > left) {
            j--;
        }
        if(i <= j) {
            y = airbnb[i];
            airbnb[i] = airbnb[j];
            airbnb[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(airbnb, left, j);
    }
    if(i < right) {
        quick_sort(airbnb, i, right);
    }

    /*Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto ao ordenar com QuickSort: %g ms.", Tempo);
    getchar();*/
}
dado *openFile(int n){

    /*/Inicia a contagem do tempo
    clock_t Ticks[2];
    Ticks[0] = clock();
    //O código a ter seu tempo de execução medido ficaria neste ponto.
    */

    char cabecalho1[50];
    char cabecalho2[50];
    char cabecalho3[50];
    char cabecalho4[50];
    char cabecalho5[50];
    char cabecalho6[50];
    char cabecalho7[50];
    char cabecalho8[50];
    char cabecalho9[50];
    char cabecalho10[50];
    char cabecalho11[50];
    char cabecalho12[50];

    dado *airbnb = (dado*)calloc(n, sizeof(dado));

    if(airbnb == NULL){
        cout << "não há memoria suficiente";
    } else {
        //inicia abertura do arquivo em modo leitura
        FILE *arq = fopen("dados_airbnb.txt", "r");

        int i = 0;

        for(int a = 0; a <= n; a++){
            //na primeira repetição atribui os valores de cabeçalho
            if(a == 0){
                fscanf
                    ( arq,
                        "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",
                        &cabecalho1, &cabecalho2, &cabecalho3,
                        &cabecalho4, &cabecalho5, &cabecalho6,
                        &cabecalho7, &cabecalho8, &cabecalho9,
                        &cabecalho10,&cabecalho11, &cabecalho12
                    );
                    printf(
                        "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                        cabecalho1, cabecalho2, cabecalho3,
                        cabecalho4, cabecalho5, cabecalho6,
                        cabecalho7, cabecalho8, cabecalho9,
                        cabecalho10,cabecalho11, cabecalho12
                    );
            }
            //depois da primeira repetição lê os valores e quarda na Struct
            if(a != 0 ){
                printf("\n %i %s", a, ")\n " );
                fscanf
                    ( arq, "%i\t%i\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",
                        //"%d\t%d\t%20[^\t]\t%20[^\t]\t%20[^\t]\t%20[^\t]\t%20[^\t]\t%i%20[^\t]\t%20[^\t]\t%f\t%20[^\n]\n",//%f\t%f\t%f\t%f\t%f\t%20[^\n]\n",
                        &airbnb[i].room_id, &airbnb[i].host_id, &airbnb[i].room_type,
                        &airbnb[i].country, &airbnb[i].city, &airbnb[i].neighborhood,
                        &airbnb[i].reviews, &airbnb[i].overall_satisfaction, &airbnb[i].accommodates,
                        &airbnb[i].bedrooms, &airbnb[i].price, &airbnb[i].property_type
                    );
                printf("%i\t %i\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",
                    airbnb[i].room_id, airbnb[i].host_id, airbnb[i].room_type,
                    airbnb[i].country, airbnb[i].city, airbnb[i].neighborhood,
                    airbnb[i].reviews, airbnb[i].overall_satisfaction, airbnb[i].accommodates,
                    airbnb[i].bedrooms, airbnb[i].price, airbnb[i].property_type);

                i++;
            }
        }
        fclose(arq);

    }

    /*Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto ao ler o arquivo e atribuir os valores as variáveis: %g ms.", Tempo);
    getchar();*/
    return airbnb;
}

int main(){

    setlocale(LC_ALL,"");
    int n;

    do{
        cout<<"Tamanho do Vetor? ";
        cin>>n;
    } while ((n<0) || (n>128001));

    cout<<endl<<endl;

    dado *v = openFile(n);
    bolha(v, n);
    printDados(v, n);
    return 0;
}

