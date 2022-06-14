#include<stdio.h>
#include<math.h>
#define SIZE 3

struct stComplex{
    int re, im;
};

typedef struct  stComplex Complex;
//math.h kütüphanesinden dolayý sorun çýktý bu sebeple absc fonksiyonu kullandým
double absc(Complex c){

    return ((c.re*c.re) + (c.im*c.im));
}



int main(){

    Complex complex[SIZE];
    int i, count = 0;
    int real, imag;

    for(i=0; i<SIZE; i++){

        printf("Enter real and imaginary separated by space (enter 0 0 to exit): ");
        scanf("%d %d", &real, &imag);
        if(real==0 && imag ==0)
            break;
        complex[count].re = real;
        complex[count].im = imag;
        count+=1;
    }

    Complex largest = complex[0];

    for(i=0; i<count; i++){
        if(absc(largest) < absc(complex[i]))
            largest = complex[i];
    }

    printf("Largest absolute value complex number is %d + %dy\n",
        largest.re, largest.im
    );
    int absolute_variable = sqrt(largest.re*largest.re+largest.im*largest.im);

    printf("The absolute value of a complex number : %d",absolute_variable);

    return 0;

}
