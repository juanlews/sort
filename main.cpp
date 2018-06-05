#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
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

dado *openFile(int n, int op){


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
        FILE *arq;
        switch(op){
            case 1:
                arq = fopen("dados_airbnb_crescente.txt", "r");
            break;

            case 2:
                arq = fopen("dados_airbnb.txt", "r");
            break;
        }
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

//----------------------------------------------------------- FUNCOES DE PESQUISA

void Imprimir_pesquisa(dado airbnb){
printf("Dados da pesquisa:\nRoom_id: %i\nHost_id: %i\nRoom_type: %s\nCountry: %s\nCity: %s\nNeighborhood: %s\nReviews: %s\nOverall_satisfaction: %s\nAccommodates: %s\nBedrooms: %s\nPrice: %s\nProperty_type: %s\t\n",
                    airbnb.room_id, airbnb.host_id, airbnb.room_type,
                    airbnb.country, airbnb.city, airbnb.neighborhood,
                    airbnb.reviews, airbnb.overall_satisfaction, airbnb.accommodates,
                    airbnb.bedrooms, airbnb.price, airbnb.property_type);

    }


dado Pesquisa_sequencial(dado *v, int chave){
dado falso ={0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<128001; i++){
        if(v[i].room_id==chave){
            cout<<"Registro encontrado!\n";
            return v[i];
        }
    }
cout<<"Registro nao encontrado";
return falso;
}


dado Pesquisa_binaria(dado *v,int n, int chave){
dado falso ={0,0,0,0,0,0,0,0,0,0,0,0};
    int inicio = 0, fim = n-1, meio;


    while(inicio <= fim){

        meio=(inicio+fim)/2;

        if(chave == v[meio].room_id){
        cout<<"Registro encontrado!\n";
            return v[meio];
        }

        if(chave < v[meio].room_id){
            fim = meio-1;
        }
        else{
            inicio = meio+1;
        }
    }

    return falso;
}





int main(){

/*      Modelo funcoes Tempo
StartCounter();
insercao(v, n);
tempoEmMilissegundo = GetCounter();
*/

    setlocale(LC_ALL,"");
    int  op=0, chave;
    dado *v, aux;
    double tempoEmMilissegundo = 0.0000000;
    //dado *v = openFile(128001);

    do{
        cout<<"\t---------> Opcoes disponiveis:\n";
        cout<<"[1] -> Pesquisar as informações de um quarto, usando uma pesquisa sequencial.\n";
        cout<<"[2] -> Pesquisar as informações de um quarto, usando uma pesquisa binária.\n";
        cout<<"[3] -> Pesquisar as informações de um quarto, usando uma árvore binária.\n";
        cout<<"[4] -> Pesquisar as informações de um quarto, usando uma tabela Hash.\n";
        cout<<"[5] -> Contabilizar a quantidade de quartos disponíveis para cada uma das cidades. \n";
        cout<<"[6] -> Pesquisar o quarto mais caro e mais barato de uma determinada cidade.\n";
        cout<<"[7] -> Sair.\n";
        cout<<"Entrada:  ";
        cin>>op;

            if(op==7){
                break;
            }

        switch(op){
            case 1:
                cout<<"\n\tPESQUISA SEQUENCIAL:\n";
                cout<<"Room_id? ";
                cin>>chave;
                v = openFile(128001, 2);
                StartCounter();
                aux=Pesquisa_sequencial(v, chave);
                tempoEmMilissegundo = GetCounter();
                    if(aux.room_id!=0){
                        Imprimir_pesquisa(aux);
                    }
                cout<<"\nTempo para realizar a pesquisa (MS): "<<tempoEmMilissegundo;
                break;

            case 2:
                cout<<"\n\tPESQUISA BINARIA:\n";
                cout<<"Room_id? ";
                cin>>chave;
                v = openFile(128001, 1);
                StartCounter();
                aux=Pesquisa_binaria(v, 128001, chave);
                tempoEmMilissegundo = GetCounter();
                    if(aux.room_id!=0){
                        Imprimir_pesquisa(aux);
                    }
                cout<<"\nTempo para realizar a pesquisa (MS): "<<tempoEmMilissegundo;
                break;

            case 3:
                cout<<"\n\tPESQUISA EM ARVORE BINARIA\n";

                break;

            case 4:
                cout<<"\n\tPESQUISA EM TABELA HASH\n";

                break;

            case 5:
                cout<<"\n\tQUANTIDADE CARROS DISPONIVEIS EM UMA CIDADE\n";

                break;

            case 6:
                cout<<"\n\tQUARTO MAIS CARO E MAIS BARATO DE DETERMINADA CIDADE\n";

                break;

        }
    }while((op<1)||(op>7));

    //cout<<endl<<endl;
    //printDados(v, n); // se quiser verificar se ficou organizado
    free(v);
    return 0;
}
