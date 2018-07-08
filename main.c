#include <stdio.h>
#include<math.h>

double  factorial (int n);
double  factorial2 (int n);
double bin_coefficiend (int n, int r);
double bin_theorem(int a, int b, int n);
void pascal_traingle(int n);

int main(int argc, char **argv){
	int n =5;
    printf("Το %d  παραγοντικό είναι %g\n",n,factorial2(n));
    printf("binomial coefficient of (9, 4) is %g \n", bin_coefficiend(9,4));
    printf(" (7 + 8)**5  is %g \n", bin_theorem(7,8,5));
    pascal_traingle(20);
	return 0;
}


double  factorial (int n){
    if (n==0)
        return 1;
    else 
        return n*factorial(n-1);
}

double  factorial2 (int n){
    double result =1;
    int i = 1;
    while (i<=n){
        result*=i ;
        i++;
    }
    return result;
}

double bin_coefficiend (int n, int r){
   // if (n<=r)
      //  return -1;
    return  factorial(n)/(factorial(r)*factorial(n-r));
}

double bin_theorem(int a, int b, int n){
    int r = 0;
    double result = 0;
    int n2=n;
    while (r<=n){
        result+=bin_coefficiend(n,r)*pow((double)a,n2)*pow((double)b,r);
        r++;
        n2--;
    }
    return result;
}

void pascal_traingle(int n){
    int spaces =82;
    int lines=n;
    int diff=4;
    int line=0;
    int spaces2=spaces;
    for (int i=0;i<lines;i++){
        spaces2=spaces;
        for (int j=0;j<=line;j++){
            
            printf("% *.0lf", spaces2,bin_coefficiend(line,j));
            spaces2=2*diff; 
        }
        line++;
        spaces-=diff;
        printf("\n");
        printf("\n");

    }
   //printf("% *.0lf\n", i,bin_coefficiend(1,0));
}
