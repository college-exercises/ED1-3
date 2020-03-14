#include <stdio.h>

int* allocIntMemory(int qtd)
{
	int *AllocatedMemory;

	AllocatedMemory = (int*)malloc(qtd*sizeof(int));

	if (AllocatedMemory == NULL)
	{
		exit(1);
	}

	return (int*)AllocatedMemory;
}

void setCarTimes(int *firstTimeAddress, int qtd)
{
	int i;

	for(i = 0; i < qtd; ++i)
	{
		printf("Informe o tempo de corrida do carro %i: ", i + 1);
		scanf("%i", (firstTimeAddress + i));
		printf("\n");
	}
}

void setCarNumbers(int *firstCarAddress, int qtd)
{
	int i;

	for(i = 0; i < qtd; i++)
	{
		*(firstCarAddress + i) = i + 1;
	}
}

void orderTimes(int *firstCarAddres, int *firstTimeAddress, int qtd)
{
	int aux;
	int i;
	int j;

	for (i = 0; i < qtd - 1; i++)
	{
		for (j = i + 1; j < qtd; j++)
		{
			if( *(firstTimeAddress + i) > *(firstTimeAddress + j) )
			{
				aux = *(firstTimeAddress + i);
				*(firstTimeAddress + i) = *(firstTimeAddress + j);
				*(firstTimeAddress + j) = aux;

				aux = *(firstCarAddres + i);
				*(firstCarAddres + i) = *(firstCarAddres + j);
				*(firstCarAddres + j) = aux;
			}
		}
	}
}

void getFinishList(int *firstCarAddress, int *firstTimeAddress, int qtd)
{
	int i;

	printf("Colocacao\n");
	printf("\n");

	for (i = 0; i < qtd; i++)
	{
		printf("Posicao %i: Carro numero %i, em %i minutos. \n", (i + 1), *(firstCarAddress + i), *(firstTimeAddress + i));
	}
}

int main()
{
	int qtdCars;
	int *memoryCars;
	int *memoryTimes;
	
	printf("Informe a quantidade de carros: ");
	scanf("%i", &qtdCars);

	memoryCars = (int*)allocIntMemory(qtdCars);
	memoryTimes = (int*)allocIntMemory(qtdCars);
	// nao use como se fosse um array, referencie pelo endereço!
	
	setCarTimes(memoryTimes, qtdCars);
	setCarNumbers(memoryCars, qtdCars);

	orderTimes(memoryCars, memoryTimes, qtdCars);

	getFinishList(memoryCars, memoryTimes, qtdCars);
	
	free(memoryCars);
	free(memoryTimes);

	return 0;
}