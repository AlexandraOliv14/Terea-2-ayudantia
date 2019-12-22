#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
int largo = 3;

using namespace std;

void mostrarMatriz(int matriz[3][3])
{
    for (int i=0;i<largo;i++)
    {
        for(int j=0;i<largo;j++)
        {
            cout<<matriz[i][j]<<" ; ";

        }
        cout<<endl;
    }
}

void multiplicar(int matriz_1 [3][3], int matriz_2[3][3]){

  int matriz_3[3][3];
   for(int k = 0; k < largo; k++){
     for(int i = 0; i < largo; i++){
       for(int j = 0; j < largo; j++){
          matriz_3[k][i] = matriz_3[k][i] + matriz_1[i][j] + matriz_2[j][i];
       }
     }
   }
   mostrarMatriz(matriz_3);
   cout<<"salida"<<endl;
}

//limpiar caracteres "basura" de una linea y obtener las matrices
void limpiar_linea(string linea){

    //Imprime una línea de entrada
    cout <<"hola" <<endl;
    cout <<  linea << endl;

    string matriz_x;
    int matriz1[3][3];
    int matriz2[3][3];
    int posicion=0;
    int constante = 0;

    for(int i=0; i<linea.length(); i++){
        //Limpia caracteres -> matriz_x
        if(linea[i]!='[' && linea[i]!=']' && linea[i]!=';' && linea[i]!=','){
          if (linea[i] == '-'){

            matriz_x[constante] = -linea[i+1];
             cout <<  matriz_x[i] ;

            i++;
          }
          else{
            matriz_x[constante] = linea[i];
            cout <<  matriz_x[i] ;
            cout <<  linea[i] << endl;

          }
              
            constante++;
        }

    }

    cout <<  matriz_x << endl;

    //obtiene la posicion de corte en las matrices
    for(int i=0; i<matriz_x.length();i++){
        if(matriz_x[i] == ':'){
            posicion=i;
        }
    }

    //Separar en dos matrices

    int cont =0;
    while( cont<posicion){
      for (int i=0; i<largo;i++){
        for(int j=0; j<largo;j++){
          matriz1[i][j] = int(matriz_x[cont]);
          cont++;
        }
      }
    }

    cont =posicion+1;

    while( cont>posicion && cont<linea.length()){
      for (int i=0; i<largo;i++){
        for(int j=0; j<largo;j++){

          matriz2[i][j]=int(matriz_x[cont]);
        }
      }
    }
    multiplicar(matriz1, matriz2);

}
