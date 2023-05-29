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
void calculomediaresiduos(float matriz[500][500], float mediared[25]);
void mayorconsumototal(float matriz [500][500]);
void ordenar(float matriz[500][500], float orden[25]);

int main()
{
    setlocale(LC_CTYPE, "spanish");
    FILE *datos;
    char matrizdatos[25][30][256];
    int elegir1, elegir2, elegir3, n = 0, i = 0,j, k, numcomas = 0, maxcomas = 0;
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
        printf("2.-�Cu�l es el porcentaje de generaci�n seg�n el mes de cada energ�a?\n");
        printf("3.-Seleccionar energia y mostrar generaci�n por meses\n");
        printf("4.-Calcular la media de consumo de una energ�a por meses\n");
        printf("5.-�En qu� mes se produce mas energ�a entre todos los tipos de generaci�n?\n");
        printf("6.-Ordenar consumo de mayor a menor de cada energ�a\n");
        printf("7.-Calcular la media de cada residuos\n");
        printf("0.-FIN\n\n\n");

        printf("Introduzca un valor\n");
        scanf("%d", &elegir1);


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
                    printf("�Cu�l es el porcentaje de generaci�n seg�n el mes de cada energ�a?\n");
                    printf("Elige el mes que desee entre los a�os 2021 y 2022\n");

                        printf("1.- 1/2021\n");
                        printf("2.- 2/2021\n");
                        printf("3.- 3/2021\n");
                        printf("4.- 4/2021\n");
                        printf("5.- 5/2021\n");
                        printf("6.- 6/2021\n");
                        printf("7.- 7/2021\n");
                        printf("8.- 8/2021\n");
                        printf("9.- 9/2021\n");
                        printf("10.- 10/2021\n");
                        printf("11.- 11/2021\n");
                        printf("12.- 12/2021\n\n");

                        printf("13.- 1/2022\n");
                        printf("14.- 2/2022\n");
                        printf("15.- 3/2022\n");
                        printf("16.- 4/2022\n");
                        printf("17.- 5/2022\n");
                        printf("18.- 6/2022\n");
                        printf("19.- 7/2022\n");
                        printf("20.- 8/2022\n");
                        printf("21.- 9/2022\n");
                        printf("22.- 10/2022\n");
                        printf("23.- 11/2022\n");
                        printf("24.- 12/2022\n\n");

                        printf("**PULSE 0 PARA SALIR AL MEN�**\n");

                    do
                    {

                        scanf("%d", &elegir3);

                        switch(elegir3)
                        {
                        case 1:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f\n", matrizdatos[i][0] ,matriz[j][0]/24305.47495*100);
                                }
                            break;
                            }
                        case 2:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][1]/21134.389784*100);
                                }
                            break;
                            }
                        case 3:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][2]/22097.189386*100);
                                }
                            break;
                            }
                        case 4:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][3]/19900.364428999*100);
                                }
                            break;
                            }
                        case 5:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][4]/20471.481075*100);
                                }
                            break;
                            }
                        case 6:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][5]/19863.791971*100);
                                }
                            break;
                            }
                        case 7:
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][6]/22436.768607*100);
                                }
                            break;
                        case 8:
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][7]/21585.235814*100);
                                }
                            break;
                        case 9:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][8]/20688.86822*100);
                                }
                            break;
                            }
                        case 10:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][9]/20634.64191*100);
                                }
                            break;
                            }
                        case 11:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][10]/23017.698421*100);
                                }
                            break;
                            }
                        case 12:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][11]/23875.280879*100);
                                }
                            break;
                            }
                        case 13:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][12]/24302.335181*100);
                                }
                            break;
                            }
                        case 14:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][13]/21120.725026*100);
                                }
                            break;
                            }
                        case 15:
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][14]/22758.010234*100);
                                }
                            break;
                        case 16:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][15]/21751.098819*100);
                                }
                            break;
                            }
                        case 17:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][16]/22084.406638*100);
                                }
                            break;
                            }
                        case 18:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][17]/23242.456504*100);
                                }
                            break;
                            }
                        case 19:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][18]/26409.488103*100);
                                }
                            break;
                            }
                        case 20:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][19]/25284.7418*100);
                                }
                            break;
                            }
                        case 21:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][20]/23658.54689899*100);
                                }
                            break;
                            }
                        case 22:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][21]/21941.569779*100);
                                }
                            break;
                            }
                        case 23:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][22]/21564.342557*100);
                                }
                            break;
                            }
                        case 24:
                            {
                                for(i = 5, j = 0; i < 22, j <16 ; i++, j++)
                                {
                                    printf("%s ==> %f \n", matrizdatos[i][0], matriz[j][23]/22197.557015*100);
                                }
                            break;
                            }


                        }

                    }while (elegir3 != 0);

                    break;
                }
            case 3:
                {
                    printf("Seleccionar energia y mostrar generaci�n por meses\n\n");
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
                                printf("\n");
                                break;
                            case 2:
                                {
                                    printf(" TURBINA BOMBEO\n");
                                    printf("****************\n");
                                    for (j = 1, k = 0; j < 24, k < 24; j++, k++)
                                    {
                                        printf("%s ==> %f(GWh)\n", matrizdatos[4][j], matriz[1][k]);
                                    }
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
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
                                    printf("\n");
                                    break;
                                }
                            default:
                                {
                                    //printf("No posible\n");
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
            case 6:
                {
                    printf("Ordenar generaci�n de mayor a menor de cada energ�a\n");
                    float orden[25];
                    ordenar(matriz,orden);
                    //for(i=0;i<13;i++){
                    //	printf("%f\n",orden[i]);
					//}
                    break;
                }
            case 7:
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

    for (i = 0; i<13; i++)
    {
        for(j = 0; j < 24; j++)
        {
            suma[i] += matriz[i][j];
            //printf("Haciendo sumas %f\n", suma[i]);//(COMPROBAMOS QUE SE REALIZAN LAS SUMAS DE FORMA CORRECTA)
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

    void ordenar(float matriz[500][500], float orden[25])
{
    int i,j,k=12;
    float suma[25];
    float mayor;


    for (i = 0; i<13; i++)
    {
        for(j = 0; j < 24; j++)
        {
            suma[i] += matriz[i][j];
            //printf("Haciendo sumas %f\n", suma[i]);//(COMPROBAMOS QUE SE REALIZAN LAS SUMAS DE FORMA CORRECTA)
        }


    }


    for(i=0;i<13;i++){

    	orden[i]=suma[i];
	}




    	for( j=0; j<12; j++)
	{
		for (i=0; i < k; i++)
		{
			if (orden[i]< orden[i+1])
				{
				mayor = orden[i];
				orden[i] =orden[i+1];
				orden[i+1]=mayor;
				}
		}
		k--;
   	}

   	for(i=0;i<13;i++){
   		if(orden[i]==suma[0]){
   			printf("HIDR�ULICA=>");
		   }
		   else if (orden[i]==suma[1]){
		   	printf("TURBINA BOMBEO=>");
		   }
		    else if (orden[i]==suma[2]){
		   	printf("NUCLEAR=>");
		   }
		    else if (orden[i]==suma[3]){
		   	printf("CARBON=>");
		   }
		    else if (orden[i]==suma[4]){
		   	printf("MOTOR DIESEL=>");
		   }
		    else if (orden[i]==suma[5]){
		   	printf("TURBINA DE GAS=>");
		   }
		    else if (orden[i]==suma[6]){
		   	printf("TURBINA DE VAPOR=>");
		   }
		    else if (orden[i]==suma[7]){
		   	printf("CICLO CONBINADO=>");
		   }
		    else if (orden[i]==suma[8]){
		   	printf("HIDROEOLICA=>");
		   }
		    else if (orden[i]==suma[9]){
		   	printf("EOLICA=>");
		   }
		    else if (orden[i]==suma[10]){
		   	printf("SOLAR FOTOVOLTAICA=>");
		   }
		    else if (orden[i]==suma[11]){
		   	printf("SOLAR TERMICA");
		   }
		    else if (orden[i]==suma[12]){
		   	printf("OTRAS RENOVABLES=>");
		   }

       	printf("%f\n",orden[i]);
					}
        printf("\n\n");


}


