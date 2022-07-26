#include<stdio.h>
#include<time.h>
#include<math.h>

double f1(int n, double a[], double x) {
  double p = a[0];
  for(int i = 1; i <= n; i++)
    p += (a[i]*pow(x,i));
  return p; 
}

double f2(int n, double a[], double x) {
  double p = a[n];
  for(int i = n; i > 0; i--) 
    p = a[i-1] + p*x;
  return p;
}

int main() {
  double a[10];
  double duration;
  for(int i = 0; i < 10; i++) a[i] = (double)i;
  clock_t start, stop;
  start = clock();
  f1(9, a, 2);
  stop = clock();
  duration = (double)(stop-start)/CLK_TCK;
  printf("ticks = %lf\nduration = %lfs\n", (double)(stop-start), duration);
  start = clock();
  f2(9, a, 2);
  stop = clock();
  duration = (double)(stop-start)/CLK_TCK;
  printf("ticks = %lf\nduration = %lfs\n", (double)(stop-start), duration);
  return 0;
}
