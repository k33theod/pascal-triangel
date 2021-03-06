#include <stdio.h>
#include<math.h>
#include <windows.h>

double  factorial (int n);
double  factorial2 (int n);
double bin_coefficiend (int n, int r);
void pascal_traingle(int n);
int get_screen_width();

int main(int argc, char **argv){
    pascal_traingle(20);
	return 0;
}

double  factorial (int n){
    if (n==0)
        return 1;
    else 
        return n*factorial(n-1);
}

//not in use
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
    return  factorial(n)/(factorial(r)*factorial(n-r));
}

void pascal_traingle(int n){
    int spaces = get_screen_width()/2;
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
}

int get_screen_width(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}
