#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prefixo(char palavra[50], int tam) {
	char prefixo[50];
	int tam_prefixo = 0, i = 0;

	printf("Digite o prefixo para comparar:");
	scanf("%s", &prefixo);

	while (prefixo[i] != '\0') {
		tam_prefixo++;
		i++;
	}
	for (i = 0; i < tam_prefixo; i++) {
		if (palavra[i] != prefixo[i]) {
			printf("Nao e o prefixo!\n");
			return 0;
		}
	}
	printf("E um prefixo!!\n");
}

int sufixo(char palavra[50], int tam_palavra) {
	char sufixo[50];
	int tam_sufixo = 0, i = 0;
	printf("Digite o sufixo para comparar:");
	scanf("%s", &sufixo);

	while (sufixo[i] != '\0') {
		tam_sufixo++;
		i++;
	}
	for (i = tam_sufixo; i > 0; i--) {
		if (sufixo[i - 1] != palavra[tam_palavra - 1]) {
			printf("Nao e o sufixo!\n");
			return 0;
		}
		tam_palavra--;
	}
	printf("E um sufixo!!\n");
}

int subpalavra(char palavra[50], int tam_palavra) {
	char sub[50];
	int i = 0, j, aux, tam_sub = 0, cont = 0;
	printf("Digite a subpalavra:");
	scanf("%s", &sub);

for(tam_sub = 0; sub[tam_sub] != '\0'; ++tam_sub);

	for (i = 0; i < tam_palavra; i++) {
		if (palavra[i] == sub[0]) {
			aux = i;
			for (j = 0; j < tam_sub; j++) {
				if (sub[j] == palavra[aux]) {
					cont++;
          if(cont==1){
            printf("E uma subpalavra\n");
            return 0;
          }
          aux++;
				}
				break;
			}
		}
	}
  if(cont==tam_sub){
    printf("E uma subpalavra\n");
  }
}

int main(void) {
	char palavra[50];
	int escolha, i = 0, tam_palavra = 0;

	printf("Digite a palavra:");
	fgets(palavra, 50, stdin);

	while (palavra[i] != '\0') {
		tam_palavra++;
		i++;
	}
	tam_palavra--;
	
		printf("Digite a operação que deseja realizar:\n");
		printf("[1]Deseja comparar o sufixo\n");
		printf("[2]Deseja comparar o prefixo\n");
		printf("[3]Deseja comparar a subpalavra\n");
		scanf("%d", &escolha);

		switch (escolha) {
		case 1:
			sufixo(palavra, tam_palavra);
			break;
		case 2:
			prefixo(palavra, tam_palavra);
			break;
		case 3:
			subpalavra(palavra, tam_palavra);
			break;
		default:
			printf("Escolha invalida\n");
		}

	return 0;
}
