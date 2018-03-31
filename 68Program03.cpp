/* 16115068 Sadanand Vishwas */
#include <iostream>

using namespace std;
class Complex {
private : float real;
float imag;
public :
Complex(float a=0,float b=0){
real=a;
real=b;
}
Complex add(Complex B){
Complex C;
C.real=real + B.real;
C.imag=imag+B.imag;
return C;
}
Complex sub(Complex B){
Complex C;
C.real=real - B.real;
C.imag=imag-B.imag;
return C;
}
Complex mul(Complex B){
Complex C;
C.real=real*B.real - imag*B.imag;
C.imag=real*B.imag + imag*B.real;
return C;
}
Complex div(Complex B){
Complex C;
float X;
X=B.real*B.real-B.imag*B.imag;
C.real=(real*B.real + imag*B.imag)/X;
C.imag=(-real*B.imag + imag*B.real)/X;

return C;
}
void display(){
cout<<"Result :"<<real<<"+i("<<imag<<")\n";
}
void inp(){
cout<<"Enter real and imagenary part (a b) :";
cin>>real>>imag;
}

static Complex add(Complex A,Complex B);
};
Complex Complex::add(Complex A,Complex B){
Complex C;
C.real=A.real + B.real;
C.imag=A.imag+B.imag;
return C;
}
int main()
{ Complex A,B,C;
int choice;
cout<<"Enter 1st Complex number \n";
A.inp();
cout<<"Enter 2nd Complex number \n";
B.inp();
while(1){
cout<<"1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Static Add\n6.Exit\nEnter your choice :";
cin>>choice;
switch(choice){
case 1:C=A.add(B);
C.display();break;
case 2:C=A.sub(B);
C.display();break;
case 3:C=A.mul(B);
C.display();break;
case 4:C=A.div(B);
C.display();break;
case 5:C=Complex::add(A,B);
C.display();break;
case 6:return 1;
default :cout<<"Wrong choice choose correctly\n";
}
}
    return 0;
}
