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
    float reviews;
    float overall_satisfaction;
    char accommodates[50];
    int bedrooms;
    float price;
    char property_type[50];
};
void openFile(){
    FILE *arq;

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

    dado *airbnb = (dado*)calloc(1, sizeof(dado));
    if(airbnb == NULL){
        cout << "não há memoria suficiente";
    } else {
        arq = fopen("dados_airbnb.txt", "r");
        char nome[25], texto[25];
        int num;
        int i = 0;

        for(int a = 0; a < 3; a++){
            if(a != 0 ){
                printf("%i %s", a, ") " );
                fscanf
                    ( arq,
                        "%i\t%i\t%20[^\t]\t%20[^\t]\t%20[^\t]\t%20[^\t]\t%f\t%f\t%20[^\t]\t%i\t%f\t%s[^\n]\n",
                        &airbnb[i].room_id, &airbnb[i].host_id, &airbnb[i].room_type,
                        &airbnb[i].country, &airbnb[i].city, &airbnb[i].neighborhood,
                        &airbnb[i].reviews, &airbnb[i].overall_satisfaction, &airbnb[i].accommodates,
                        &airbnb[i].bedrooms, &airbnb[i].price, &airbnb[i].property_type
                    );
                    printf("%i\t%i\t%s\t%s\t%s\t%s\t%f\t%f\t%s\t%i\t%f\t%s\n",
                        airbnb[i].room_id, airbnb[i].host_id, airbnb[i].room_type,
                        airbnb[i].country, airbnb[i].city, airbnb[i].neighborhood,
                        airbnb[i].reviews, airbnb[i].overall_satisfaction, airbnb[i].accommodates,
                        airbnb[i].bedrooms, airbnb[i].price, airbnb[i].property_type
                    );
                    i++;
            }
            if(a == 0){
                //printf("%i", a);
                fscanf
                    ( arq,
                        "%99[^\t]\t %99[^\t]\t %99[^\t]\t %99[^\t]\t %99[^\t]\t %99[^\t]\t %99[^\t]\t %99[^\t]\t %99[^\t]\t %99[^\t]\t %99[^\t]\t %s[^\t]\n",
                        &cabecalho1, &cabecalho2, &cabecalho3,
                        &cabecalho4, &cabecalho5, &cabecalho6,
                        &cabecalho7, &cabecalho8, &cabecalho9,
                        &cabecalho10,&cabecalho11, &cabecalho12
                    );
            }
        }
        fclose(arq);
        /*cout << "" << cabecalho1
             << "\t" << cabecalho2
             << "\t" << cabecalho3
             << "\t" << cabecalho4
             << "\t" << cabecalho5
             << "\t" << cabecalho6
             << "\t" << cabecalho7
             << "\t" << cabecalho8
             << "\t" << cabecalho9
             << "\t" << cabecalho10
             << "\t" << cabecalho11
             << "\t" << cabecalho12 << "\n" ;

             /* printf("%i\t %i\t %s\t %s %s\t %s\t %f\t %f\t %s\t %i\t %f\t %s\n",
                        airbnb[1].room_id, airbnb[1].host_id,
                        airbnb[1].room_type, airbnb[0].country, airbnb[0].city, airbnb[0].neighborhood,
                        airbnb[0].reviews, airbnb[0].overall_satisfaction, airbnb[0].accommodates,
                        airbnb[0].bedrooms, airbnb[0].price, airbnb[0].property_type
                    );*/
        }



}
int main()
{
    openFile();

    return 0;
}

