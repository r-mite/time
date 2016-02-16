#include <stdio.h>
#include <time.h>
#include <sys/time.h>

typedef struct TimeWatcher
{
        double start;
        double end;
} TimeWatcher;

void start(TimeWatcher* tw);
void end(TimeWatcher* tw);
void print_time_sec(TimeWatcher* tw);

// =================
// measure time(sec)
// =================

double gettimeofday_sec()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

void start(TimeWatcher* tw)
{
      tw->start = gettimeofday_sec();
}

void end(TimeWatcher* tw)
{
     tw->end = gettimeofday_sec();
}

void print_time_sec(TimeWatcher* tw)
{
     printf("%10.10f(sec)\n", tw->end - tw->start);
}

int main(){
	TimeWatcher tw;
	start(tw);
	int i;
	for(i=0; i<100; i++){
		printf("t\n");
	}
	end(tw);
	print_time_sec(tw);
	return 0;
}