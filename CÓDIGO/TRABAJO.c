#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


int creaTabla(char *filas[])
{
printf("Crear Tabla\n");
return(0);
}

void calculomedia(float matriz[500][500], float media[25]);

int main()
{
    setlocale(LC_CTYPE, "spanish");
    FILE *datos;
    char matrizdatos[25][30][256];
    int elegir1, elegir2, n = 0, i = 0,j, k, numcomas = 0, maxcomas = 0;
    char c;
    float matriz[500][500];
    float media[25], mediared[25];



    printf("*************************************\n");
    printf("*    DATOS DE GENERACI�N EL�CTRICA  *\n");
    printf("*************************************\n\n");


    datos = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");


    if (datos == NULL)
        {
            printf("Fichero no abierto\n");
        }else{

            printf("Fichero abierto correctamente\n\n");
        }

    printf("En el men� se muestran diferenciados por n�meros las distintas estad�sticas energ�ticas\n\n");


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

            if (c == ',')
            {
                matrizdatos[n][numcomas][i] = 0;
                numcomas++;
                if (numcomas > maxcomas) maxcomas = numcomas;
                i = 0;
                continue;
            }
            else if (c == '\n')
            {
                matrizdatos[n][numcomas][i] = 0;
                numcomas++;
                if (numcomas > maxcomas) maxcomas = numcomas;
                n++;
                numcomas = 0;
                i = 0;
            }
            else
            {
                matrizdatos[n][numcomas][i++] = c;
            }
    }
    fclose(datos);



   for ( i = 5; i < n; i++)
            {
                for ( j = 0; j < maxcomas; j++)
                {
                    matriz[i-5][j-1] = atof(matrizdatos[i][j]);
                }
            }

    do
    {
        //imprimimos menu para que elija el usuario
        printf("1.-Mostrar datos ordenados del archivo:\n");
        printf("2.-Estad�stica de la energia que mayor consumo presenta\n");
        printf("3.-Seleccionar energia y mostrar su consumo por meses\n");
        printf("4.-Calcular la media de consumo de una energ�a por meses\n");
        printf("5.-Seleccionar una energia y mandarla a otro fichero\n");
        printf("6.-�En qu� mes se produce mas energ�a entre todos los tipos de generaci�n?\n");
        printf("7.-Ordenar consumo de mayor a menor de cada energ�a\n");
        printf("8.-Calcular la media de cada residuos\n");
        printf("0.-FIN\n\n\n");

        printf("Introduzca un valor\n");
        scanf_s("%d", &elegir1);


        switch (elegir1)
        {
            case 1:

                printf("Mostrar datos ordenados del archivo:\n");

                //printf("Numero de lineas: %d\n", n);
                //printf("Numero de columnas: %d\n", maxcomas);

                for ( i = 0; i < n; i++)
                {
                        printf("LINEA[%d]:\n", i);
                        for (j = 0; j < maxcomas; j++)
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
                    printf("Seleccionar energia y mostrar su consumo por meses\n\n");
                    printf("1.- HIDR�ULICA  \n");
                    printf("2.- TURBINACI�N BOMBEO  \n");
                    printf("3.- NUCLEAR  \n");
                    printf("4.- CARB�N  \n");
                    printf("5.- MOTORES DI�SEL  \n");
                    printf("6.- TURBINA DE GAS  \n");
                    printf("7.- TURBINA DE VAPOR  \n");
                    printf("8.- CICLO COMBINADO  \n");
                    printf("9.- HIDROE�LICA  \n");
                    printf("10.- E�LICA  \n");
                    printf("11.- SOLAR FOTOVOLTAICA  \n");
                    printf("12.- SOLAR T�RMICA  \n");
                    printf("13.- OTRAS RENOVABLES  \n");

                    do
                    {
                        scanf("%d", &elegir2);
                        printf("*** PULSE 0 PARA SALIR AL MEN�***\n\n");

                        switch(elegir2)
                        {

                            case 1:
                                printf(" HIDR�ULICA\n");
                                printf("************\n");
                                for(j = 1, k = 0; j<24, k <24; j++,k++)
                                {
                                    printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[0][k]);
                                }
                                printf("\n\n");
                                break;
                            case 2:
                                {
                                    printf(" TURBINA BOMBEO\n");
                                    printf("****************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[1][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 3:
                                {
                                    printf(" NUCLEAR\n");
                                    printf("*********\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[2][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 4:
                                {
                                    printf(" CARB�N\n");
                                    printf("********\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[3][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 5:
                                {
                                    printf(" MOTORES DIESEL\n");
                                    printf("****************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[4][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 6:
                                {
                                    printf(" TURBINA DE GAS\n");
                                    printf("****************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[5][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 7:
                                {
                                    printf(" TURBINA DE VAPOR\n");
                                    printf("******************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[6][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 8:
                                {
                                    printf(" CICLO COMBINADO\n");
                                    printf("*****************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[7][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 9:
                                {
                                    printf(" HIDROE�LICA\n");
                                    printf("*************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[8][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 10:
                                {
                                    printf(" E�LICA\n");
                                    printf("********\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[9][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 11:
                                {
                                    printf(" SOLAR FOTOVOLTAICA\n");
                                    printf("********************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[10][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 12:
                                {
                                    printf(" SOLAR T�RMICA\n");
                                    printf("***************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[11][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            case 13:
                                {
                                    printf(" OTRAS RENOVABLES\n");
                                    printf("******************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[12][k]);
                                    }
                                    printf("\n\n");
                                    break;
                                }
                            default:
                                {
                                    printf("No posible\n");
                                }

                        }
                    }while (elegir2 != 0);

                    break;
                }
            case 4:
                {
                    printf("Calcular la media de consumo de una energ�a total\n\n");
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
                    printf("�En qu� mes se produce mas energ�a entre todos los tipos de generaci�n?\n\n");

                    printf("A continuaci�n se mostrar� la energia total producida por meses\n");

                    for(j = 1, k = 0; j<24, k <24; j++,k++)
                    {
                        printf(" %s ==> %f(GWh)\n", matrizdatos[4][j], matriz[16][k]);
                    }

                    printf("\nORDENANDO LOS DATOS DE MAYOR A MENOR QUEDAR�A: \n\n");
                    mayorconsumototal(matriz);


                    break;
                }
            case 7:
                {
                    printf("Ordenar consumo de mayor a menor de cada energ�a\n");
                    break;
                }
            case 8:
                {
                    printf("C�lculo de la media de residuos\n");
                    calculomediaresiduos(matriz,mediared);

                    for (i = 19, j= 14; i < 21; i++, j++)
                        {
                            printf("%s ==>", matrizdatos[i]);
                            printf("%f\n", mediared[j]);
                        }
                    printf("\n\n");
                    break;
                }
            case 0:
                {
                    printf("FIN\n\n");
                    return 0;
                }
            default:
                {
                    printf("ERROR\n");
                }
        }

    } while (elegir1 != 0);

    return 0;
}

void calculomedia(float matriz[500][500], float media[25])
{
    int i,j;
    float suma[25];

    printf("DENTRO\n");

    for (i = 0; i<13; i++)
    {
        for(j = 0; j < 24; j++)
        {
            suma[i] += matriz[i][j];
            printf("Haciendo sumas %f\n", suma[i]);//(COMPROBAMOS QUE SE REALIZAN LAS SUMAS DE FORMA CORRECTA)
        }

        media[i] = suma[i] / 24;
    }

}

void mayorconsumototal(float matriz [500][500])
{
    int i, j, mayor, a, c = 24;

    for (i = 0; i < c - 1; i++)
    {
        mayor = i;

        for (j = i + 1; j < c; j++)
        {
            if (matriz[16][j] > matriz[16][mayor])
            {
                mayor = j;
            }
        }

        if (mayor != i)
        {
            a = matriz[16][i];
            matriz[16][i] = matriz[16][mayor];
            matriz[16][mayor] = a;
        }

    }

    for (i = 0; i<24; i++)
    {
         printf(" %d >> %f(GWh)\n",i+1, matriz[16][i]);
    }
}

void calculomediaresiduos(float matriz[500][500], float mediared[25])
{
    int i,j;
    float suma[25];

    for (i = 14; i<16; i++)
    {
        for(j = 0; j < 24; j++)
        {
            suma[i] += matriz[i][j];
           //printf("Haciendo sumas %f\n", suma[i]);//(COMPROBAMOS QUE SE REALIZAN LAS SUMAS DE FORMA CORRECTA)
        }


        mediared[i] = suma[i] / 24;

        printf("");
    }

}


