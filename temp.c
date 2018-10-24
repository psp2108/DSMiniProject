#include<stdio.h>
#include<conio.h>
#include<time.h>
struct timespec {
    time_t   tv_sec;        /* seconds */
    long     tv_nsec;       /* nanoseconds */
}ts;

long randnum(long bound)
{
    long r = 0;
    int i;

//    for(i = 0; i < 10; i++){
        clock_gettime(1, &ts);
        srand((time_t)ts.tv_nsec);
        r += rand();
 //   }

    return r % bound;
}

void main(){
    long long int a = 181023230300001;
	time_t now;
    int hours, minutes, seconds, day, month, year;

    long x = 99998;

    int i;
 /*   printf("%lld\n\n", a);

    a = a + 1;
    printf("%lld\n\n", a);

    a = a * 2;
    printf("%lld\n\n", a);


	time(&now);
	struct tm *local = localtime(&now);

    hours = local->tm_hour;      	// get hours since midnight (0-23)
    minutes = local->tm_min;     	// get minutes passed after the hour (0-59)
    seconds = local->tm_sec;     	// get seconds passed after minute (0-59)

    day = local->tm_mday;        	// get day of month (1 to 31)
    month = local->tm_mon + 1;   	// get month of year (0 to 11)
    year = local->tm_year + 1900;	// get year since 1900


	// print local time
    printf("Time is : %02d:%02d:%02d am\n", hours, minutes, seconds);

	// print current date
	printf("Date is : %02d/%02d/%d\n\n\n", day, month, year);

	a = year % 100;
	a *=100;
	a += month;
	a = a*100;
	a = a + day;
	a = a*100;
	a = a + hours;
	a = a*100;
	a = a + minutes;
	a = a*100000;

    printf("%lld\n\n", a++);
    printf("%lld\n\n", a++);
    printf("%lld\n\n", a++);
    printf("%lld\n\n", a++);
    printf("%lld\n\n", a++);

    printf("0\t:a\n");
    printf("00000\t:a\n\n\n");


    printf("%li\n", x);
    x++;
    printf("%li\n", x);
    x++;
    printf("%li\n", x);
    x++;
*/
    for(int i=0; i<40; i++){

        //while(t < 25000){
            printf("%d\n",randnum(123));
       //}
    }
    getch();
}
