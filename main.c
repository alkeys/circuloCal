#include <stdio.h>
#include "math.h"


int main() {
    int a = 0, b = 0;
    int c = 10, d = 10;
    double r = (pow((a - c), 2) + pow((b - d), 2)) / 2;
    printf("radio %f\n", r);
    double auxpro, temp;
    int v=30;
    double datosCirculo1[(int) r * v][2];
    double datosCirculo2[(int) r * v][2];
    /**
     * (x-h)2+(y-k)2=r2
     * y=raiz(r2-(x-h)2)+k
     */
    float rRaiz = sqrt(r) * -1;
    int cont = 0;
    for (float i = rRaiz + a; i < sqrt(r) + a; i += 0.01) {
        auxpro = r - pow((i - a), 2);
        temp = sqrt(auxpro) + b;
        datosCirculo1[cont][0] = floor(i*1000)/1000;
        datosCirculo1[cont][1] =floor(temp*1000)/1000;
        cont++;
    }
    cont = 0;
    for (float i = rRaiz + c; i < sqrt(r) + c; i += 0.01) {
        auxpro = r - pow((i - c), 2);
        temp = -sqrt(auxpro) + d;
        datosCirculo2[cont][0] = floor(i*1000)/1000;
        datosCirculo2[cont][1] = floor(temp*1000)/1000;
        cont++;
    }
    for (int i = 0; i < r*3; ++i) {
   //printf("%f %f ||  %f %f\n",datosCirculo1[i][0],datosCirculo1[i][1],datosCirculo2[i][0],datosCirculo2[i][1]);
    }


    float q, w, e, t,error;
    for (int i = 0; i < r * v; ++i) {
        q = datosCirculo1[i][0];
        w = datosCirculo1[i][1];
        for (int j = 0; j < r * v; j++) {
            e = datosCirculo2[j][0];
            t = datosCirculo2[j][1];

            if(q==e) {
                error = fabs((t - w) / t);
                if (error > 0 && error<0.0024) {
                printf("xd %f   %f\n", q, w);
            }
            }
          //  printf("%f \n",e);
        }
    }



    return 0;
}

