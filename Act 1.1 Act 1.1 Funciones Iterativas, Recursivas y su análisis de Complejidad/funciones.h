/*Datos del Alumno
Nombre: Kevin Joan Delgado Pérez
Matrícula: A01706328*/
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <string>
#include <iostream>

using namespace std;

class Funciones{

  public:

    Funciones(){

    };
  
  int sumaIterativa(int n);
  int sumaRecursiva(int n);
  int sumaDirecta(int n);

};

int Funciones::sumaIterativa(int n){
  int suma = 0;
  for(int i=0;i<=n;i++){
    suma+=i;
  }
  return suma;
}

int Funciones::sumaRecursiva(int n){
  if(n<=1){
    return n;
  }
  else{
    return n+sumaRecursiva(n-1);
  }
}

int Funciones::sumaDirecta(int n){
int suma;
suma=((n+1)*n)/2;
  return suma;
}

#endif 