#include <stdio.h>
#include <stdlib.h>

int* zlacz(int* tab1, int* tab2, int len1, int len2, int* nw){
    int* temp_pt, k = 0;
    int* pt, *i, *j;
    if((temp_pt = malloc(sizeof(int) * (len1 + len2))) == NULL) 
        return NULL;
    pt = temp_pt;
    i = tab1;
    j = tab2;
    while(1){
        if((i == tab1 + len1) || (j == tab2 + len2))
            break;
        if(*i == *j){
            *pt++ = *i++;
            ++j;
            ++k;
            continue;
        }
        *pt++ = *i++;
        *pt++ = *j++;
        k += 2;
    }
    while(i != tab1 + len1){
        *pt++ = *i++;
        ++k;
    }  
    while(j != tab2 + len2){
        *pt++ = *j++;
        ++k;
    }
    *nw = k;
    if((pt = (int*) realloc(temp_pt, sizeof(int)*k)) == NULL){
        return NULL;
    }

    return pt;
}

int main(void){
    int n[2], *tab1, *tab2, *result_tab, final_n;

    for(int i = 0; i < 2; ++i){
        printf("Podaj wielkosc %d tablicy(>=1): ", i + 1);
        while(scanf("%d", &n[i]) && n[i] < 1){
            printf("Podaj prawidlowa wielkosc %d tablicy: ", i + 1);
        }
    }
    tab1 = (int*) malloc(sizeof(int) * n[0]);
    tab2 = (int*) malloc(sizeof(int) * n[1]);
    if(tab1 == NULL || tab2 == NULL){
        printf("Nie udalo sie zaalokowac miejsca podczas tworzenia tablic.\n");
        exit(EXIT_FAILURE);
    }
    else{

        printf("Wprowadz dane do tablic.\n");
        printf("Tablica 1:\n");
        for(int i = 0; i < n[0]; ++i){
            printf("Podaj %d liczbe: ", i+1);
            scanf("%d", (tab1+i));
        }
        printf("Tablica 2:\n");
        for(int i = 0; i < n[1]; ++i){
            printf("Podaj %d liczbe: ", i+1);
            scanf("%d", (tab2+i));
        }

        if((result_tab = zlacz(tab1, tab2, n[0], n[1], &final_n)) == NULL){
            printf("Nie udalo sie zaalokowac miejsca podczas scalania tablic.\n");
            free(tab1);
            free(tab2);
            exit(EXIT_FAILURE);
        }
        else{
            printf("Zawartosc tablicy po scaleniu:\n");
            for(int* i = result_tab; i < result_tab + final_n; ++i){
                printf("%d ", *i);
            }
            printf("\n");
        }
    }


    free(tab1);
    free(tab2);
    free(result_tab);
    return 0;
}