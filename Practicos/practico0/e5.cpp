#include <stdio.h>

void OrdenarArreglo(int arr[],int largo) 
{
	int aux;
	for (int i = 0; i < (largo-1); i++)
		for (int j = i; j < largo; j++)
			if(arr[j] < arr[i])
            {
				aux = arr[j];
				arr[j] = arr[i];
				arr[i] = aux;
			}
}
int main()
{
	int arr[6] = {2,4,1,6,8,5};
	for (int l=0; l<6; l++)
	{
		printf("%d",arr[l]);
	}
	
	printf("\n");

	OrdenarArreglo(arr,6);	
	for (int k =0; k<6; k++)
	{
		printf("%d",arr[k]);
	}
	return 0;
}
