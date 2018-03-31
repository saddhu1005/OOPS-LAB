/*16115068 Sadanand Vishwas */
#include<bits/stdc++.h>
using namespace std;
#define mx 1000
void subsequence( char *X, char *Y, int m, int n )
{
   int LCS[m+1][n+1],length,i,j;
   for ( i=0; i<=m; i++)
   {
     for ( j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         LCS[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         LCS[i][j] = LCS[i-1][j-1] + 1;
       else
         LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
     }
   }
   int index = LCS[m][n];
   char lcs[index+1];
   lcs[index] = '\0';
   i = m;
    j = n;
   while (i > 0 && j > 0)
   {
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1];
          i--; j--; index--;
      }
      else if (LCS[i-1][j] > LCS[i][j-1])
         i--;
      else
         j--;
   }
   length=strlen(lcs);
   cout << "LCS of '" << X << "' and '" << Y << "' is '" << lcs<<"' of length "<<length<<"\n";
}
int main(){

int m,n;
char A[mx],B[mx];
cout<<"Enter first String :";
cin>>A;
cout<<"Enter second String :";
cin>>B;
m=strlen(A);
n=strlen(B);
subsequence(A,B,m,n);
return 0;
}

