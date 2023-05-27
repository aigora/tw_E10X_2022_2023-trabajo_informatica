#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int creaTabla(char *filas[])
{
printf("Crear Tabla\n");
return(0);
}

void calculomedia(float matriz[500][500], float media[25]);

int main()
{

FILE *datos;
char matrizdatos[25][30][256];
int elegir, n = 0, i = 0,j, k, numcomas = 0, maxcomas = 0;
char c;
float matriz[500][500];
float media[25];



    printf("*************************************\n\n");
    printf("*    DATOS DE GENERACIÓN ELÉCTRICA  *\n");
    printf("*************************************\n\n");
    printf("En el menú se muestran diferenciados por números las distintas estadísticas energéticas\n\n");

            datos = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");


if (datos == NULL)
{
printf("Fichero no abierto\n");

}
else
{
printf("Abierto correctamente\n\n");
}


for ( i = 0; i < 25; i++)
            {
for ( j = 0; j < 30; j++)
                {
                    for ( k = 0; k < 256; k++)
                    {
                        matrizdatos[i][j][k] = 0;
                    }
                }
            }

while (!feof(datos))
{
c = fgetc(datos);
//printf("->%c<-\n", c);

if (c == ',')
{
matrizdatos[n][numcomas][i] = 0;
//printf("-->%d<-->%d<-->%s<--\n", n, numcomas, matrizdatos[n][numcomas]);
numcomas++;
if (numcomas > maxcomas) maxcomas = numcomas;
i = 0;
continue;
}
else if (c == '\n')
{
//printf("----------------------------->%d<-------------------------------------------------\n", n);
matrizdatos[n][numcomas][i] = 0;
//printf("-->%d<-->%d<-->%s<--\n", n, numcomas, matrizdatos[n][numcomas]);
numcomas++;
if (numcomas > maxcomas) maxcomas = numcomas;
n++;
numcomas = 0;
i = 0;
//if (n > 4) break;
}
else
{
matrizdatos[n][numcomas][i++] = c;
}

}
fclose(datos);



   for (int i = 5; i < n; i++)
            {
                for (int j = 0; j < maxcomas; j++)
                {
                    matriz[i-5][j-1] = atof(matrizdatos[i][j]);
                }
            }

do
{
//imprimimos menu para que elija el usuario

   printf("1.-Cargar y mostrar datos del archivo:\n");
printf("2.-Estadistica de la energia que mayor consumo presenta\n");
printf("3.-Seleccionar energia y mostrar su consumo por meses\n");
printf("4.-Calcular la media de consumo de una energía por meses\n");
printf("5.-Seleccionar una energia y mandarla a otro fichero\n");
printf("6.-¿En qué mes se produce mas energía entre todos los tipos de generación?\n");
printf("7.-Ordenar consumo de mayor a menor de cada energía\n");
printf("8.-FIN\n\n\n");

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

printf("\n\n");
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
printf("Calcular la media de consumo de una energía total\n");

calculomedia(matriz,media);

for (i = 5, j= 0; i < 18; i++, j++)
            {
                printf("%s ==>", matrizdatos[i]);
                printf("%f\n", media[j]);
            }
            printf("\n\n");
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

void calculomedia(float matriz[500][500], float media[25])
{
    int i,j;
    float suma[25];

    for (i = 0; i<13; i++)
    {
        for(j = 0; j < 24; j++)
        {
            suma[i] += matriz[i][j];
            //printf("Haciendo sumas %f\n", suma[i]);(COMPROBAMOS QUE SE REALIZAN LAS SUMAS DE FORMA CORRECTA)
        }

        media[i] = suma[i] / 24;
        printf("");
    }

}


