#include <stdio.h>
#include <time.h>
#include <sys/time.h>

double get_dtime(void){
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 0.001 * 0.001);
}

int main(){
	double d0, d1;
	d0 = get_dtime();
	int i;
	for(i=0; i<100; i++){
		printf("t\n");
	}
	d1 = get_dtime();
	printf("elapsed: %f", d1 - d0);
	printf("hello\n");	
return 0;
}
