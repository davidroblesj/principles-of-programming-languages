#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{

int real;

int img;



}complex;
typedef struct{

double uno;

double dos;

complex sol1;

complex sol2;

}raices;


complex suma(complex x,complex y){

  complex resultado;
  resultado.real=x.real+y.real;
  resultado.img=x.img+y.img;
  return resultado;

}
complex resta(complex x,complex y){

  complex resultado;
  resultado.real=x.real-y.real;
  resultado.img=x.img-y.img;
  return resultado;

}
complex multiply(complex x,complex y){

  complex resultado;
  resultado.real=x.real*y.real-x.img*y.img;
  resultado.img=x.real*y.img+x.img*y.real;
  return resultado;

}
complex division(complex x,complex y){

  complex resultado;
  resultado.real=(x.real*y.real+x.img*y.img)/(y.real*y.real+y.img*y.img);
  resultado.img=(x.img*y.real-x.real*y.img)/(y.real*y.real+y.img*y.img);
  return resultado;

}
complex escalar(int x,complex y){
    complex resultado;
    resultado.real=x*y.real;
    resultado.img=x*y.img;
    return resultado;


}
float modulo(int a, int b){

    return sqrt(pow(a,2)+pow(b,2));

}

raices raiz(complex x){
    raices real,imaginaria,resultado;
    float a,b,c,d,discrc,discrd;
    float z=modulo(x.real,x.img);
    a=(x.real+z)/2;
    c=(-x.real+z)/2;

    if(x.img>0){
        resultado.sol1.real=sqrt(a);
        resultado.sol1.img=sqrt(c);
        resultado.sol2.real=-sqrt(a);
        resultado.sol2.img=-sqrt(c);

    }
    else if(x.img<0)
    {
        resultado.sol1.real=sqrt(a);
        resultado.sol1.img=-sqrt(c);
        resultado.sol2.real=-sqrt(a);
        resultado.sol2.img=sqrt(c);
    }

   return resultado; 

}
raices ecuacion(complex a,complex b, complex c){
  raices square, x;
  complex b2=multiply(b,b);
  complex ac=multiply(a,c);
  complex fourac=escalar(4,ac);
  complex dis=resta(b2,fourac);
  square=raiz(dis);
  x.sol1=division(suma(escalar(-1,b),square.sol1),escalar(2,a));

  x.sol2=division(suma(escalar(-1,b),square.sol2),escalar(2,a)); 
  return x;

}

int main(void) {
  complex minum1,minum2;
  raices solucion,solucion2;
  complex a,b,c;
  int op1,out;
  char cadena[50],cadena2[50];
    while(out!=2){
      printf("Escribir ecuacion: 1\nSalir del programa: 2\n");
      scanf("%d",&out);
      if(out==2)
        break;
      printf("Introduce el coeficiente a:\n real:1 \n imaginario:2 \n");
      scanf("%d",&op1);
      printf("introduce parte real \n");
      scanf("%d",&a.real);
      if(op1==1){

          a.img=0;
      }
      else {
        printf("introduce parte imaginaria\n");
        scanf("%d",&a.img);
      }
      printf("Introduce el coeficiente b:\n real:1 \n imaginario:2 \n");
      scanf("%d",&op1);
      printf("introduce parte real \n");
      scanf("%d",&b.real);
      if(op1==1){

          b.img=0;
      }
      else {
        printf("introduce parte imaginaria\n");
        scanf("%d",&b.img);
      }
      printf("Introduce el coeficiente c:\n real:1 \n imaginario:2 \n");
      scanf("%d",&op1);
      printf("introduce parte real \n");
      scanf("%d",&c.real);
      if(op1==1){

          c.img=0;
      }
      else {
        printf("introduce parte imaginaria\n");
        scanf("%d",&c.img);
      }
      
      solucion=ecuacion(a,b,c);
    
      printf("Raiz 1: \nReal: %d,Imaginaria: %d\n",solucion.sol1.real,solucion.sol1.img);
      printf("Raiz 2: \nReal: %d,Imaginaria: %d\n",solucion.sol2.real,solucion.sol2.img);

    }

  return 0;
}