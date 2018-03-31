/*16115068 Sadanand Vishwas  */
#include<bits/stdc++.h>
using namespace std;
 int **A,n;
 float **B,**I ;

int det(int **C,int r);
int cofactor(int **C,int r,int row,int col);
int minar(int **C,int r,int row,int col);
void adjoint(int **C,int r);
bool inv(int **C,int r);

int main(){

 int i,j,flag=0,k;
   cout<<"Enter rows of square matrix (n) :";
 cin>>n;
 A=new int *[n];
 B=new float *[n];
 I=new float *[n];

 for(i=0;i<n;i++){
     A[i]=new int[n];
     B[i]=new float[n];
     I[i]=new float[n];
 }
 cout<<"Enter a matrix of "<<n<<"x"<<n<<":\n";
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 cin>>A[i][j];

flag=inv(A,n);
if(flag){
cout<<"Inverse of Matrix is :\n";
  for(i=0;i<n;i++){
 for(j=0;j<n;j++)
 printf("%.2f\t",B[i][j]);
 cout<<endl;
  }
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
            I[i][j]=0;
        for(k=0;k<n;k++){
            I[i][j]+=A[i][k]*B[k][j];
        }
    }
}
cout<<"Matrix A*B is :\n";
  for(i=0;i<n;i++){
 for(j=0;j<n;j++){
    printf("%.1f\t",I[i][j]);

 }
 cout<<endl;
  }

}
  return 0;
}
int minar(int **C,int r,int row,int col){

    if(r==1)
    return 1;


  int **D,k=0,l=0,i,j;
  D=new int *[r-1];
  for(i=0;i<r-1;i++){
      D[i]=new int[r-1];
  }

  for(i=0;i<r;i++){
      if(i==row)
      continue;
      for(j=0;j<r;j++){
          if(col==j)
          continue ;
        D[k][l]=C[i][j]  ;
          l++;

      }
      k++;
      l=0;
  }

  return det(D,r-1) ;

}
int cofactor(int **C,int r,int row,int col){

    return (pow(-1,row+col) * minar(C,r,row,col));

}
int det(int **C,int r){

    int detm=0,i;
    if(r==1)
    return C[0][0];
   for(i=0;i<r;i++){
       detm+=C[0][i]*cofactor(C,r,0,i);

   }
   return detm;
}
void adjoint(int **C,int r){
    int **D,i,j;
     D=new int *[r-1];
  for(i=0;i<r;i++){
      D[i]=new int[r];
  }
  for(i=0;i<r;i++){
      for(j=0;j<r;j++){
          D[i][j]=cofactor(C,r,i,j);
      }
  }
  for(i=0;i<r;i++){
      for(j=0;j<r;j++){
          B[j][i]=D[i][j];
      }
  }

}
bool inv(int **C,int r){
  int detm=0,i,j;
  detm=det(C,r);
  if(detm==0){
      cout<<"Singular Matrix  Inverse not possible ! "<<endl;
      return 0;
  }
  adjoint(A,n);
  for(i=0;i<r;i++){
      for(j=0;j<r;j++){
          B[i][j]/=(float)detm;
      }
  }
  return 1;
}

