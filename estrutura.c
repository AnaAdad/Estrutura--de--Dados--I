#include  <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct ponto{
    int x;
    int y;
}Ponto;

typedef struct circulo{
    Ponto p;
    int raio;
}Circulo;

void mostrar_circulo(Circulo *c);
void atribuir_aleatorio(Circulo *c);
void mostrar_circulo_vetor(Circulo *c, int n);
void atribuir_aleatorio_vetor(Circulo *c, int n);

int main(){
    srand(time(NULL));

    Ponto p1;
    printf("Digite os valores de x e y para p1: \n");
    scanf("%d %d", &p1.x, &p1.y);

    Circulo c1;
    printf("Digite os valores de x e y e o raio para o circulo c1: ");
    scanf("%d %d %d", &c1.p.x, &c1.p.y, &c1.raio);

    Circulo *c2 = (Circulo *)malloc(sizeof(Circulo));
    printf("Digite os valores de x e y e o raio para o circulo c2: ");
    scanf("%d %d %d", &c2->p.x, &c2->p.y, &c2->raio);

    mostrar_circulo(&c1);

    atribuir_aleatorio(&c1);
    mostrar_circulo(&c1);

    atribuir_aleatorio(c2);
    mostrar_circulo(c2);

    Circulo *c3 = &c1;
    c3->p.x = 10;
    c3->p.y = 20;
    c3->raio = 30;
    printf("\nValores de c1  após alteração:\n");
    mostrar_circulo(&c1);
    printf("\n\nValores de c3: \n");
    mostrar_circulo(c3);

    Circulo vet[10];
    atribuir_aleatorio_vetor(vet, 10);
    mostrar_circulo_vetor(vet, 10);

    free(c2);

    return 0;

    }

void mostrar_circulo(Circulo *c){
    printf("\nCirculo:\n");
    printf("Coordenadas do centro: (%d, %d)\n", c->p.x, c->p.y);
    printf("Raio: %d\n", c->raio);
}

void atribuir_aleatorio(Circulo *c){
    c->p.x = rand() % 100;
    c->p.y = rand() % 100;
    c->raio = rand() % 100;
}


void mostrar_circulo_vetor(Circulo *c, int n) {
    printf("\nVetor de circulos:\n");
    for (int i = 0; i < n; i++){
        printf("Circulo %d:\n", i+1);
        mostrar_circulo(&c[i]);
    }
}

void atribuir_aleatorio_vetor(Circulo *c, int n){
    for (int i = 0; i < n;  i++) {
        c[i].p.x = rand() % 100;
        c[i].p.y = rand() % 100;
        c[i].raio = rand() % 100;
    }
}










    



