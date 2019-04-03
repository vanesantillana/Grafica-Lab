#include <iostream>
#include <math.h>

using namespace std;

void circulos_angulo(int cant,float porcent,float angulo){
	float x = 0;
	float y = 0;
	float r = 10;
	float newr=r;
	for(int i = 0; i < cant; i++){
		cout<< "creo circulo"<<endl;
        cout<< "radio "<<r<<endl;
		newr= r-( r * porcent/100);
        cout<< "nuevo radio "<<newr<<endl;
        cout<< "sin "<<round(cos(angulo)*10)/10 <<endl;
		x += round(cos(angulo))*(r+newr);
		y += round(sin(angulo))*(r+newr);
        cout<< "(x,y) ="<<x<<" , "<<y<<endl;
		r = newr;
	}
}

int main()
{
    circulos_angulo(3,50,20);

    return 0;
}