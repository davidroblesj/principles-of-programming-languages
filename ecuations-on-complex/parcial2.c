#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{

  int real;

  int img;

} complex;
typedef struct
{

  double uno;

  double dos;

  complex sol1;

  complex sol2;

} raices;

complex suma(complex x, complex y)
{

  complex resultado;
  resultado.real = x.real + y.real;
  resultado.img = x.img + y.img;
  return resultado;
}
complex resta(complex x, complex y)
{

  complex resultado;
  resultado.real = x.real - y.real;
  resultado.img = x.img - y.img;
  return resultado;
}
complex multiply(complex x, complex y)
{

  complex resultado;
  resultado.real = x.real * y.real - x.img * y.img;
  resultado.img = x.real * y.img + x.img * y.real;
  return resultado;
}
complex division(complex x, complex y)
{

  complex resultado;
  resultado.real = (x.real * y.real + x.img * y.img) / (y.real * y.real + y.img * y.img);
  resultado.img = (x.img * y.real - x.real * y.img) / (y.real * y.real + y.img * y.img);
  return resultado;
}
complex escalar(int x, complex y)
{
  complex resultado;
  resultado.real = x * y.real;
  resultado.img = x * y.img;
  return resultado;
}
float modulo(int a, int b)
{

  return sqrt(pow(a, 2) + pow(b, 2));
}

raices raiz(complex x)
{
  raices real, imaginaria, resultado;
  float a, b, c, d, discrc, discrd;
  float z = modulo(x.real, x.img);
  a = (x.real + z) / 2;
  c = (-x.real + z) / 2;

  if (x.img > 0)
  {
    resultado.sol1.real = sqrt(a);
    resultado.sol1.img = sqrt(c);
    resultado.sol2.real = -sqrt(a);
    resultado.sol2.img = -sqrt(c);
  }
  else if (x.img < 0)
  {
    resultado.sol1.real = sqrt(a);
    resultado.sol1.img = -sqrt(c);
    resultado.sol2.real = -sqrt(a);
    resultado.sol2.img = sqrt(c);
  }

  return resultado;
}
raices ecuacion(complex a, complex b, complex c)
{
  raices square, x;
  complex b2 = multiply(b, b);
  complex ac = multiply(a, c);
  complex fourac = escalar(4, ac);
  complex dis = resta(b2, fourac);
  square = raiz(dis);
  x.sol1 = division(suma(escalar(-1, b), square.sol1), escalar(2, a));

  x.sol2 = division(suma(escalar(-1, b), square.sol2), escalar(2, a));
  return x;
}

int main(void)
{
  complex minum1, minum2;
  raices solucion, solucion2;
  complex resultado;
  complex a, b, c;
  int opcion;
  printf("Introduzca la parte real del primer numero: ");
  scanf("%d", &minum1.real);
  printf("Introduzca la parte imaginaria del primer numero: ");
  scanf("%d", &minum1.img);
  printf("Introduzca la parte real del segundo numero: ");
  scanf("%d", &minum2.real);
  printf("Introduzca la parte imaginaria del segundo numero: ");
  scanf("%d", &minum2.img);
  printf("Introduce:\n1: para suma\n2: para resta\n3: para multiplicacion\n4: para division\n5: para multiplicacion por escalar\n6: para raiz\n7: para ecuacion cuadratica\n\n");
  scanf("%d", &opcion);
  switch (opcion)
  {
  case 1:;
    resultado = suma(minum1, minum2);
    printf("real %d ", resultado.real);
    printf("img %d\n ", resultado.img);

    break;

  case 2:;
    resultado = resta(minum1, minum2);
    printf("real %d ", resultado.real);
    printf("img %d\n ", resultado.img);

    break;
  case 3:;
    resultado = multiply(minum1, minum2);
    printf("real %d ", resultado.real);
    printf("img %d\n ", resultado.img);

    break;

  case 4:;
    resultado = division(minum1, minum2);
    printf("real %d ", resultado.real);
    printf("img %d\n ", resultado.img);

    break;
  case 5:;
    int numEscalar;
    printf("Introduce el escalar: ");
    scanf("%d", &numEscalar);
    resultado = escalar(numEscalar, minum2);
    printf("real %d ", resultado.real);
    printf("img %d\n ", resultado.img);

    break;

  case 6:;
    complex num;
    printf("Introduzca la parte real del numero: ");
    scanf("%d", &num.real);
    printf("Introduzca la parte imaginaria del numero: ");
    scanf("%d", &num.img);
    raices solucion2 = raiz(num);
    printf("raiz 1 real %d,img %d \n", solucion2.sol1.real, solucion2.sol1.img);
    printf("raiz 2 real %d,img %d ", solucion2.sol2.real, solucion2.sol2.img);

    break;
  case 7:;
    complex a, b, c;
    raices solucion;
    printf("Introduzca la parte real de a: ");
    scanf("%d", &a.real);
    printf("Introduzca la parte imaginaria de a: ");
    scanf("%d", &a.img);
    printf("Introduzca la parte real de b: ");
    scanf("%d", &b.real);
    printf("Introduzca la parte imaginaria de b: ");
    scanf("%d", &b.img);
    printf("Introduzca la parte real de c: ");
    scanf("%d", &c.real);
    printf("Introduzca la parte imaginaria de c: ");
    scanf("%d", &c.img);
    solucion = ecuacion(a, b, c);
    printf("raiz 1 real %d,img %d \n", solucion.sol1.real, solucion.sol1.img);
    printf("raiz 2 real %d,img %d \n", solucion.sol2.real, solucion.sol2.img);

    break;
  }
  return 0;
}