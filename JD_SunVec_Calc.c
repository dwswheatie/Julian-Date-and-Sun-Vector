#include <stdio.h>
#include <math.h>

int main()
{
	double year = 1;
	double month = 1;
	double day = 1;
	double hour = 0;
	double minute = 0;
	double second = 0;
	printf("Julian Date and ECI Frame Sun Vector Calculator\n");
	printf("By Eric M. Wietstruk\n\n");
	while (year > 0 && month > 0 && day > 0 && day > 0 && hour >= 0 && minute >= 0 && second >= 0)
	{
		printf("Enter the 4 digit year: ");
		scanf("%lf", &year);
		printf("Enter the month using 1-12: ");
		scanf("%lf", &month);
		printf("Enter the day: ");
		scanf("%lf", &day);
		printf("Enter the hour using 0-24: ");
		scanf("%lf", &hour);
		printf("Enter the minute: ");
		scanf("%lf", &minute);
		printf("Enter the second: ");
		scanf("%lf", &second);
		
		if (year > 0 && month > 0 && day > 0 && day > 0 && hour >= 0 && minute >= 0 && second >= 0)
		{
			double JD = 367*year-floor(7*(year+floor((month+9)/12))/4)+floor(275*month/9)+day+1721013.5+hour/24+minute/1440+second/86400;
			double pi = 3.14159265359;
			double UT1 = (JD-2451545)/36525;
			double longMSUN = 280.4606184+36000.77005361*UT1;
			double mSUN = 357.5277233+35999.05034*UT1;
			double ecliptic = longMSUN+1.914666471*sin(mSUN)+0.918994643*sin(2*mSUN);
			double eccen = 23.439291-0.0130042*UT1;
	
			double x = cos(ecliptic*pi/180);
			double y = cos(eccen*pi/180)*sin(ecliptic*pi/180);
			double z = sin(eccen*pi/180)*sin(ecliptic*pi/180);
		
			printf("Julian Date: %lf\n", JD);
			printf("X: %lf\n", x);
			printf("Y: %lf\n", y);
			printf("Z: %lf\n\n", z);
		}
		else
		{
			printf("One or more incorrect values!\n");
			exit(0);
		}
	}
	return 0;
}
