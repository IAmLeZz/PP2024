#include <stdio.h>
//
// Created by Álvaro on 10/27/2024.
//
int cargar(double v[], int tam) {
   int rta, stop = 1, i = 0;
   do {
      printf("[%d]: ", i);
      scanf("%lf", &v[i]);
      if(v[i]==0) {
         stop = 0;
      }
      i++;
   } while ((i<tam)&&stop);
   if (stop) {
      rta = tam;
   } else {
      rta = i-1;
   }
   return rta;
}

double *menorVector(double *v, int n) {
  double *min = v;

   for(int i = 1; i < n; i++) {
      if (*(v+i) < *min) {
         min = v+i;
      }
   }
   return min;
}

int main() {
   double v[1000];
   int cant = 0;

   printf("Ingrese numeros en el vector\n");
   printf("Para finalizar ingrese 0\n");

   cant=cargar(v,1000);

   printf("La cantidad actual de elementos del vector es de %d elementos\n",cant);

   printf("\n**************************************************");

   double *res = menorVector(v, cant);
   printf("\nEl elemento menor es: %.2f\n",*res);
   printf("\nLa direccion del elemento menor es: %p",(void*)res);

   printf("\n**************************************************\n");
}