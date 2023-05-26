#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int creaTabla(char *filas[])
{
	printf("Crear Tabla\n");
	return(0);
}

float media (float matriz[][24], int n);

int main()
{

	FILE *datos;
	char matrizdatos[25][30][256];
	int elegir, n = 0, i = 0,j, numcomas = 0, maxcomas = 0;
	char c;
	float matriz[500][500];
	float valormedia;

				//datos = fopen("genera.txt", "r");
    fopen_s(& datos, "generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");

    if (datos == NULL)
    {
        printf("Fichero no abierto\n");

    }else
    {
        printf("Abierto correctamente\n\n");
    }

    i = 0;
    n = 0;
    numcomas = 0;
    maxcomas = 0;
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            for (int k = 0; k < 256; k++)
            {
                matrizdatos[i][j][k] = 0;
            }
        }
    }

    while (!feof(datos))
    {
        c = fgetc(datos);

        if (c == ',')
        {
            matrizdatos[n][numcomas][i] = 0;
            numcomas++;
            if (numcomas > maxcomas) maxcomas = numcomas;
                i = 0;
                continue;
        }else if (c == '\n')
        {
            matrizdatos[n][numcomas][i] = 0;
            numcomas++;
            if (numcomas > maxcomas) maxcomas = numcomas;
					n++;
					numcomas = 0;
					i = 0;
					//if (n > 4) break;
        }else
        {
            matrizdatos[n][numcomas][i++] = c;
        }

    }
fclose(datos);



	    for (int i = 5; i < n; i++) {
        for (int j = 0; j < maxcomas; j++) {

                matriz[i-5][j-1] = atof(matrizdatos[i][j]);
        }
    }

	do
	{
		//imprimimos menu para que elija el usuario
		printf("*************************************\n\n");
		printf("*    DATOS DE GENERACIÓN ELÉCTRICA  *\n");
		printf("*************************************\n\n");
		printf("En el menú se muestran diferenciados por números las distintas estadísticas energéticas\n\n");
	    printf("1.-Cargar y mostrar datos del archivo:\n");
		printf("2.-Estadistica de la energia que mayor consumo presenta\n");
		printf("3.-Seleccionar energia y mostrar su consumo por meses\n");
		printf("4.-Calcular la media de consumo de una energía por meses\n");
		printf("5.-Seleccionar una energia y mandarla a otro fichero\n");
		printf("6.-¿En qué mes se produce mas energía entre todos los tipos de generación?\n");
		printf("7.-Ordenar consumo de mayor a menor de cada energía\n");
		printf("8.-FIN\n");

		printf("Introduzca un valor\n");
		//scanf("%d", &elegir);
		scanf_s("%d", &elegir);


		switch (elegir)
		{
		case 1:
			printf("Cargar y mostrar datos del archivo:\n");
			//datos = fopen("genera.txt", "r");

			printf("Numero de lineas: %d\n", n);
			printf("Numero de columnas: %d\n", maxcomas);

			for (int i = 0; i < n; i++)
			{
				printf("LINEA[%d]:\n", i);
				for (int j = 0; j < maxcomas; j++)
				{
					printf("-->%s<--\n",matrizdatos[i][j]);
				}
				printf("-------------- FIN LINEA(%d) ----------------------\n", i);
			}
			break;
		case 2:
		{
			printf("Estadistica de la energia que mayor consumo presenta\n");

			break;
		}
		case 3:
		{
			printf("Seleccionar energia y mostrar su consumo por meses\n");
			break;
		}
		case 4:
		{
			printf("Calcular la media de consumo de una energía por meses\n");

			break;
		}
		case 5:
		{
			printf("Seleccionar una energia y mandarla a otro fichero\n");
			break;
		}
		case 6:
		{
			printf("¿En qué mes se produce mas energía entre todos los tipos de generación?\n");
			break;
		}
		case 7:
		{
			printf("Ordenar consumo de mayor a menor de cada energía\n");
			break;
		}
		case 8:
		{
			printf("FIN\n");
			return 0;
		}
		default:
		{
			printf("ERROR\n");
		}
		}
	} while (elegir != 8);

	return 0;
}
