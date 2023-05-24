#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <string.h>

struct cadenas{
	char filasdedatos[1000];
};

int main()
{
    setlocale(LC_CTYPE,"spanish");

    FILE *datos;
    struct cadenas *filas;
    char c;

    int elegir, n, i;

    printf("    DATOS DE GENERACIÓN ELÉCTRICA    \n");
    printf("*************************************\n\n");
    printf("En el menú se muestran diferenciados por números las distintas estadísticas energéticas\n\n");

    //imprimimos menu para que elija el usuario
    printf("1.-Cargar y mostrar datos del archivo:\n");
    printf("2.-Estadistica de la energia que mayor consumo presenta\n");
    printf("3.-Seleccionar energia y mostrar su consumo por meses\n");
    printf("4.-Calcular la media de consumo de una energía por meses\n");
    printf("5.-Seleccionar una energia y mandarla a otro fichero\n");
    printf("6.-¿En qué mes se produce mas energía entre todos los tipos de generación?\n");
    printf("7.-Ordenar consumo de mayor a menor de cada energía\n");
    printf("8.-FIN\n");

    do
    {
    printf("Introduzca un valor\n");
    scanf("%d", &elegir);
    switch (elegir)
    {
    case 1:
        {
            printf("Cargar y mostrar datos del archivo:\n");

            datos = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv","r");

            if (datos == NULL)
            {
                printf("Fichero no abierto\n");
            }else{
                printf("Abierto correctamente\n\n");
            }

            while(!feof(datos))
            {
	                c=fgetc(datos);
	                if (c=='\n') n++;
            }
            rewind(datos);

            filas = (struct cadenas*)malloc(n*sizeof(struct cadenas));

            for(i=0;i<n;i++)
            {
	            fgets(filas[i].filasdedatos,sizeof(filas[i].filasdedatos),datos);
	            filas[i].filasdedatos[strlen(filas[i].filasdedatos)-1]='\0';
            }


            for(i=0;i<n;i++)//IMPRIMIMOS DATOS DEL FICHERO
            {
                printf ("%s\n",filas[i].filasdedatos);

            }


            fclose(datos);

            break;
        }
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
    }while (elegir != 8);

return 0;
}
