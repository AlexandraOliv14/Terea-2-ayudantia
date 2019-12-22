#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>

#include "func.cpp"

using namespace std;

int main(int argc, char* argv[]){

    ifstream archivo_entrada;
    string matrices;
    int i=0;
    //paso de parámetros y validación de argumentos
    string args_auxiliar;
    string argumentos;
    int contador_archivos = 0;
    for(int i=1; i<argc; i++){
        args_auxiliar = argv[i];
        if(args_auxiliar == "-m" && i!=argc-1)
        {
            argumentos = argv[i+1];
            contador_archivos++;
        }
    }

    if(contador_archivos != 1){
        cout << "FALTAN O SOBRAN ARGUMENTOS" << endl;
        return 0;
    }

    //Abrir archivo en modo lectura
    archivo_entrada.open("Matrices.txt",ios::in);
    if(archivo_entrada.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    //Mientras no este en el final del archivo, obtengo cada línea y la guardo en matrices[i]
    while(!archivo_entrada.eof()){
//        cout << "aqui toy 10"<< endl;
        getline(archivo_entrada,matrices);
        limpiar_linea(matrices);
        matrices.clear();
    }
    archivo_entrada.close();
    return 0;
}
