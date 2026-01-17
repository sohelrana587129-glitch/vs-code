#include <stdio.h>
 
int main() {
 
    float a,b,c, area, perimetro;
    scanf("%f %f %f", &a, &b, &c);
    //perimetro = a + b + c;
    //area = (a+b)*c / 2;
    //printf("Area = %0.1f\n", area);
    //printf("Perimetro = %0.1f\n", perimetro);
    if (a < b + c && b < a + c && c < a + b) {
        perimetro = a + b + c;
        printf("Perimetro = %.1f\n", perimetro);
    } else {
        area = (a + b) * c / 2;
        printf("Area = %.1f\n", area);
    }
    return 0;
}
