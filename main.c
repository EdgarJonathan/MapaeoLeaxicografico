#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mapeoFilas(void);
void mapeoCol(void);
void generarGraficaCol(int fila, int columna, int filas, int columnas);
void generarGraficaFil(int fila, int columna, int filas, int columnas);
void graficaCol(int fila, int columna, int filas, int columnas);
void graficaFil(int fila, int columna, int filas, int columnas);


int main (void )
{
    int opc=0;

    do{
        system("clear");
        printf("******Mapeo Lexicografico*******\n");
        printf("1. Filas \n");
        printf("2. Columnas \n");
        printf("Opcion a escoge\n");
        scanf("%d",&opc);

        switch (opc) {
            case 1:
                mapeoFilas();
                break;
            case 2:
                  mapeoCol();
                break;

            default:
                    break;
        }

    }while(opc!=2);

    return 0;
}


void mapeoFilas(void)
{
    int filas=0,columnas=0;
    system("clear");
    printf("******Dimensiones de la matriz*******\n");
    printf("Numero de filas ");
    scanf("%d",&filas);
    printf("Numero de columnas");
    scanf("%d",&columnas);

    int fila=0,columna=0;
    system("clear");
    printf("******Posicion  mapear *******\n");
    printf("Numero de fila ");
    scanf("%d",&fila);
    printf("Numero de columna");
    scanf("%d",&columna);

    int lineal =(fila*filas)+columna;

    generarGraficaFil(fila, columna, filas, columnas);
    graficaFil(fila, columna, filas, columnas);

     printf("Resultado= %d\n\n",lineal );

}

void mapeoCol(void)
{
    int filas=0,columnas=0;
    system("clear");
    printf("******Dimensiones de la matriz*******\n");
    printf("Numero de filas ");
    scanf("%d",&filas);
    printf("Numero de columnas");
    scanf("%d",&columnas);


    int fila=0,columna=0;
    system("clear");
    printf("******Posicion  mapear *******\n");
    printf("Numero de fila ");
    scanf("%d",&fila);
    printf("Numero de columna");
    scanf("%d",&columna);
    int lineal =(columna*filas)+fila;

    generarGraficaCol(fila, columna,filas,columnas);
    graficaCol(fila, columna,filas,columnas);

    printf("Resultado = %d \n\n",lineal);
}


void generarGraficaFil(int fila, int columna, int filas, int columnas){

    FILE *archivo;
    char direccion[] = "mapeolexicografico.dot";
    archivo = fopen(direccion,"w"); //escribir w=write -- escribir -- crear
    fprintf(archivo," ");
    archivo = fopen(direccion,"a");
    fprintf(archivo,"digraph structs {\nnode [shape=plaintext]\nstruct1 "
                    "[label=<\n<TABLE bgcolor=\"gray\">\n ");

    int i;
    for (i=0;i<filas;i++) {

      fprintf(archivo,"<tr>\n");

        int j;
        for (j=0;j<columnas;j++) {

           int thisLineal = i*columnas+j;
            if( (fila*columnas+columna) == thisLineal)
            {
                fprintf(archivo,"       <td bgcolor=\"red\">(%d,%d):%d</td>\n",i,j,thisLineal);
            }else
            {
                fprintf(archivo,"       <td>(%d,%d):%d</td>\n",i,j,thisLineal);
            }

        }
       fprintf(archivo,"</tr>\n");
    }


    fprintf(archivo,"</TABLE>\n>];\n}");
    fclose(archivo);

    char *dot = "dot mapeolexicografico.dot -Tpng -o mapeo.png";
    char *opendot = "xdg-open mapeo.png";

    //system("nano mapeolexicografico.dot");
    system(dot);
    system(opendot);

}






void graficaFil(int fila, int columna, int filas, int columnas)
{
    FILE *archivo;
    char direccion[] = "mapeo.dot";
    archivo = fopen(direccion,"w"); //escribir w=write -- escribir -- crear
    fprintf(archivo," ");
    archivo = fopen(direccion,"a");
    fprintf(archivo,"digraph structs {\nnode [shape=plaintext]\nstruct1 "
                    "[label=<\n<TABLE bgcolor=\"gray\">\n ");

    int i;
    fprintf(archivo,"<tr>\n");
    for (i=0;i<filas;i++) {



        int j;
        for (j=0;j<columnas;j++) {

           int thisLineal = i*columnas+j;
            if( (fila*columnas+columna) == thisLineal)
            {
                fprintf(archivo,"       <td bgcolor=\"red\">(%d,%d):%d</td>\n",i,j,thisLineal);
            }else
            {
                fprintf(archivo,"       <td>(%d,%d):%d</td>\n",i,j,thisLineal);
            }

        }

    }
    fprintf(archivo,"</tr>\n");


    fprintf(archivo,"</TABLE>\n>];\n}");
    fclose(archivo);

    char *dot = "dot mapeo.dot -Tpng -o mapeo1.png";
    char *opendot = "xdg-open mapeo1.png";

    //system("nano mapeolexicografico.dot");
    system(dot);
    system(opendot);
}





void generarGraficaCol(int fila, int columna, int filas, int columnas){

    FILE *archivo;
    char direccion[] = "mapeolexicografico.dot";
    archivo = fopen(direccion,"w"); //escribir w=write -- escribir -- crear
    fprintf(archivo," ");
    archivo = fopen(direccion,"a");
    fprintf(archivo,"digraph structs {\nnode [shape=plaintext]\nstruct1 "
                    "[label=<\n<TABLE bgcolor=\"gray\" >\n ");

    int i;
    for (i=0;i<filas;i++) {

      fprintf(archivo,"<tr>\n");

        int j;
        for (j=0;j<columnas;j++) {

            int thisLineal = j*filas+i;
             if(((columna*filas)+fila) == thisLineal)
             {
                 fprintf(archivo,"       <td bgcolor=\"red\">(%d,%d):%d</td>\n",i,j,thisLineal);
             }else
             {
                 fprintf(archivo,"       <td>(%d,%d):%d</td>\n",i,j,thisLineal);
             }

        }
       fprintf(archivo,"</tr>\n");
    }


    fprintf(archivo,"</TABLE>\n>];\n}");
    fclose(archivo);

    char *dot = "dot mapeolexicografico.dot -Tpng -o mapeo.png";
    char *opendot = "xdg-open mapeo.png";

    //system("nano mapeolexicografico.dot");
    system(dot);
    system(opendot);

}


void graficaCol(int fila, int columna, int filas, int columnas)
{


    FILE *archivo;
    char direccion[] = "mapeo.dot";
    archivo = fopen(direccion,"w"); //escribir w=write -- escribir -- crear
    fprintf(archivo," ");
    archivo = fopen(direccion,"a");
    fprintf(archivo,"digraph structs {\nnode [shape=plaintext]\nstruct1 "
                    "[label=<\n<TABLE bgcolor=\"gray\">\n ");

    int i;
    fprintf(archivo,"<tr>\n");
    for (i=0;i<columnas;i++) {



        int j;
        for (j=0;j<filas;j++) {

           int thisLineal = i*columnas+j;
            if( (fila*columnas+columna) == thisLineal)
            {
                fprintf(archivo,"       <td bgcolor=\"red\">(%d,%d):%d</td>\n",i,j,thisLineal);
            }else
            {
                fprintf(archivo,"       <td>(%d,%d):%d</td>\n",i,j,thisLineal);
            }

        }

    }
    fprintf(archivo,"</tr>\n");


    fprintf(archivo,"</TABLE>\n>];\n}");
    fclose(archivo);

    char *dot = "dot mapeo.dot -Tpng -o mapeo1.png";
    char *opendot = "xdg-open mapeo1.png";

    //system("nano mapeolexicografico.dot");
    system(dot);
    system(opendot);
}

