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


void openFile(int n){
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
        FILE *arq = fopen("dados_airbnb.txt", "r");

        int i = 0;

        for(int a = 0; a <= n; a++){

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


}
int main()
{int n;
do{
    cout<<"Tamanho do Vetor? ";
    cin>>n;
}while((n<0) || (n>128001));

    cout<<endl<<endl;

    openFile(n);

    return 0;
}

