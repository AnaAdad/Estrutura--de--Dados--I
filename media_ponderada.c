#include <stdio.h>
#include <stdlib.h>


float media_ponderada(float *notas, int qtd_testes, int *pesos){
    float soma = 0; 
    int soma_pesos = 0;
    for(int i=0; i<qtd_testes; i++){
        soma += notas[i] * pesos[i];
        soma_pesos += pesos[i];
    }
    return soma / soma_pesos;
}

int main(){
    int n;
    printf("Digite o numero de participantes: ");
    scanf("%d", &n);
    
    // Alocando memória para as inscricoes e as notas
    float *notas = (float *)malloc(n * 5 * sizeof(float));
    int *pesos =  (int *) malloc(n * 5 * sizeof(int));
    int *inscr = (int *)malloc(n * sizeof(int));

    printf("Digite as inscrições dos participantes:\n");
    for(int i=0; i < n; i++) {
        printf("Participantes %d: ", i + 1);
        scanf("%d", &inscr[i]);
    }

    printf("Digite as notas e pesos dos participantes:\n");
    for(int i = 0; i < n;  i++){
        printf("Participante %d:\n",  i + 1);
        for (int j = 0; j < 5 ; j++ ) {
            printf("Nota do teste %d: ",j + 1);
            scanf("%f", &notas[i * 5 + j]);
            printf("Peso %d:", j + 1);
            scanf("%d", &pesos[i * 5 + j] );
        }
    }

    printf("Media ponderada de todos os participantes:\n");
    for (int i = 0;  i < n; i++) {
        float media = media_ponderada(&notas[i * 5], 5, &pesos[i * 5]);
        printf("%d - %2f\n", inscr[i], media);
        }

        free(notas);
        free(pesos);
        free(inscr);
        
	return 0;
}


    
        
   