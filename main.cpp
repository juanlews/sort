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
#include <windows.h>
double PCFreq = 0.0;
__int64 CounterStart = 0;


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

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        printf("QueryPerformanceFrequency Failed.\n");
    PCFreq = (double)(li.QuadPart) / 1000.0;
    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return (double)(li.QuadPart - CounterStart) / PCFreq;
}

void printDados(dado *airbnb, int n){
    for(int i = 0; i < n; i++){
        printf("\n%i\t %i\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",
                    airbnb[i].room_id, airbnb[i].host_id, airbnb[i].room_type,
                    airbnb[i].country, airbnb[i].city, airbnb[i].neighborhood,
                    airbnb[i].reviews, airbnb[i].overall_satisfaction, airbnb[i].accommodates,
                    airbnb[i].bedrooms, airbnb[i].price, airbnb[i].property_type);

    }
}

void insercao(dado *airbnb, int n){
 int i, j;
 dado tmp;

 for(i = 1; i < n; i++)
 {
  tmp = airbnb[i];
  for(j = i-1; ((j >= 0) && (tmp.room_id < airbnb[j].room_id)); j--)
  {
   airbnb[j+1] = airbnb[j];
  }
  airbnb[j+1] = tmp;
 }
}

void bolha(dado *airbnb, int n){
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
}

void selecao(dado *airbnb, int n){

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
void mergeSort(dado *airbnb, int l, int r){

    if (l < r){
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(airbnb, l, m);
        mergeSort(airbnb, m+1, r);

        merges(airbnb, l, m, r);
    }
}

void quick_sort(dado *airbnb, int left, int right) {
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
}

dado *openFile(int n){


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
                   /* printf(
                        "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                        cabecalho1, cabecalho2, cabecalho3,
                        cabecalho4, cabecalho5, cabecalho6,
                        cabecalho7, cabecalho8, cabecalho9,
                        cabecalho10,cabecalho11, cabecalho12

                    );*/
            }
            //depois da primeira repetição lê os valores e quarda na Struct
            if(a != 0 ){
                //printf("\n %i %s", a, ")\n " );
                fscanf
                    ( arq, "%i\t%i\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",
                        //"%d\t%d\t%20[^\t]\t%20[^\t]\t%20[^\t]\t%20[^\t]\t%20[^\t]\t%i%20[^\t]\t%20[^\t]\t%f\t%20[^\n]\n",//%f\t%f\t%f\t%f\t%f\t%20[^\n]\n",
                        &airbnb[i].room_id, &airbnb[i].host_id, &airbnb[i].room_type,
                        &airbnb[i].country, &airbnb[i].city, &airbnb[i].neighborhood,
                        &airbnb[i].reviews, &airbnb[i].overall_satisfaction, &airbnb[i].accommodates,
                        &airbnb[i].bedrooms, &airbnb[i].price, &airbnb[i].property_type
                    );
              /*  printf("%i\t %i\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",
                    airbnb[i].room_id, airbnb[i].host_id, airbnb[i].room_type,
                    airbnb[i].country, airbnb[i].city, airbnb[i].neighborhood,
                    airbnb[i].reviews, airbnb[i].overall_satisfaction, airbnb[i].accommodates,
                    airbnb[i].bedrooms, airbnb[i].price, airbnb[i].property_type);
            */
                i++;
            }
        }
        fclose(arq);

    }
    return airbnb;
}

int main(){

    setlocale(LC_ALL,"");
    int n, op;
    double tempoEmMilissegundo = 0.0000000;
    do{
        cout<<"Tamanho do Vetor? ";
        cin>>n;
    } while ((n<0) || (n>128001));

    cout<<endl;
    dado *v = openFile(n);

    do{
        cout<<"Metodo de ordenacao: 1)Insercao 2) Selecao 3)Bolha 4)MergeSort 5)QuickSort\n";
        cin>>op;
    }while((op<1)||(op>5));

        switch(op){
            case 1:
                cout<<"\n       INSERCAO\n";
                StartCounter();
                insercao(v, n);
                tempoEmMilissegundo = GetCounter();
                cout<<"\nTempo para ordenacao ="<<tempoEmMilissegundo<<" ms";
                cout<<endl;
                break;

            case 2:
                cout<<"\n       SELECAO\n";
                StartCounter();
                selecao(v, n);
                tempoEmMilissegundo = GetCounter();
                cout<<"\nTempo para ordenacao ="<<tempoEmMilissegundo<<" ms";
                cout<<endl;
                break;

            case 3:
                cout<<"\n       BOLHA\n";
                StartCounter();
                bolha(v, n);
                tempoEmMilissegundo = GetCounter();
                cout<<"\nTempo para ordenacao ="<<tempoEmMilissegundo<<" ms";
                cout<<endl;
                break;

            case 4:
                cout<<"\n       MERGESORT\n";
                StartCounter();
                mergeSort(v, 0, n-1);
                tempoEmMilissegundo = GetCounter();
                cout<<"\nTempo para ordenacao ="<<tempoEmMilissegundo<<" ms";
                cout<<endl;
                break;

            case 5:
                cout<<"\n       QUICKSORT\n";
                StartCounter();
                quick_sort(v, 0, n-1);
                tempoEmMilissegundo = GetCounter();
                cout<<"\nTempo para ordenacao ="<<tempoEmMilissegundo<<" ms";
                cout<<endl;
                break;

            case 6:
                cout<<"\n       DEUS ME ACUDE\n";
                StartCounter();
                //funcao
                tempoEmMilissegundo = GetCounter();
                cout<<"\nTempo para ordenacao ="<<tempoEmMilissegundo<<" ms";
                break;


        }

    cout<<endl<<endl;
    //printDados(v, n); // se quiser verificar se ficou organizado
    return 0;
}

