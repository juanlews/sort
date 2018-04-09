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
        printf("\n%i\t\n",
                airbnb[i].room_id);
    }
}

int selecao (dado *v, int n){
    // menor vai indicar a posiçao que esta o menor elemento, não valor
    int i, menor, cont=0, j;
    dado aux;
    // tam-1. não precisa de ir ate o final do vetor, pois a última posição é o maior
    for (i = 0; i <n-1; i++){
        // supondo que o elemento menor esta na primeira posiçao e etc
        menor=i;
        // para comparar com a proxima posicao
        for (j=i+1; j<n; j++){
             cont++;
             // recebe em qual posicao o menor esta, não troca
             if(v[menor].room_id > v[j].room_id){
                menor = j;
             }
             // não compara se é igual, pois  a grande maioria dos dados não é igual.
             aux = v[i];
             // passa o elemento menor para primeira posicao
             v[i] = v[menor];
             v[menor] = aux;
        }
    }
    printDados(v, n);
    return cont;
}

dado *openFile(int n){
    //Inicia a contagem do tempo
    clock_t Ticks[2];
    Ticks[0] = clock();
    //O código a ter seu tempo de execução medido ficaria neste ponto.

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

    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto ao ler o arquivo e atribuir os valores as variáveis: %g ms.", Tempo);
    getchar();
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
    printf("\n%d", selecao(v, n));

    return 0;
}

