#include <stdio.h>
#include <stdlib.h>
        /* It's almost the same code like Part 1 but i modified the program to accept leap years*/
int date1( void)
{
	int day = 0, month = 0, year = 0;     /*I make all the variables 0 so they don't carry unecessary bits, and useless numbers*/
	char a, b;
	int ex_days = 0, result_days = 0;
	int leap_years = 0;

	day = 0, month = 0, year = 0;


	while (1)                              /*I use the same loop as the first part But i add some pieces so it can accept leap years*/
	{
		day = 0, month = 0, year = 0;


		scanf("%d%c%d%c%d", &day, &a, &month, &b, &year);
		

		if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1 && year <= 10000)
		{
		    if (year % 4 == 0 && month == 2 && day <= 29)           /*Checks if the year is leap it can accept 29 days in February*/
			{
				break;
			}

			else if (month == 2 && day <= 28)
			{
				break;
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day <= 30)
				{
					break;
				}
			}
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				break;
			}
		}
	}


	if ((month - 1) == 0)            /*I do that because i Multiply every month with 30 and then add the extra days that i missed*/
	{
		ex_days = 0;
	}
	else if ((month - 1) == 1)
	{
		ex_days = 1;
	}
	else if ((month - 1) == 2)
	{
		ex_days = -1;
	}
	else if ((month - 1) == 3)
	{
		ex_days = 0;
	}
	else if ((month - 1) == 4)
	{
		ex_days = 0;
	}
	else if ((month - 1) == 5)
	{
		ex_days = 1;
	}
	else if ((month - 1) == 6)
	{
		ex_days = 1;
	}
	else if ((month - 1) == 7)
	{
		ex_days = 2;
	}
	else if ((month - 1) == 8)
	{
		ex_days = 3;
	}
	else if ((month - 1) == 9)
	{
		ex_days = 3;
	}
	else if ((month - 1) == 10)
	{
		ex_days = 4;
	}
	else if ((month - 1) == 11)
	{
		ex_days = 4;
	}
	else if ((month - 1) == 12)
	{
		ex_days = 5;
	}



	if (year % 4 == 0)
	{
		if (month <= 2)
		{
			leap_years = ((year / 4) - 1);
		}
		else if (month > 2)
		{
			leap_years = ((year - (year % 4)) / 4);
		}
	}
	else
	{
		leap_years = (year / 4);
	}

	result_days = (month - 1) * 30 + ex_days + day + leap_years + ((year - 1) * 365);   /*Multiply the months by 30 and then adds the ex days that are missing and then it adds  the days form all the past leap years*/
	
	return(result_days);

}


int main()
{
	int date1_inDays = 0, date2_inDays = 0;
	int TotalResult_Days;

	date1_inDays = date1();

	date2_inDays = date1();

	if (date1_inDays > date2_inDays)      /*Checks which date is larger so it can print the number negative*/
	{
		TotalResult_Days = date2_inDays - date1_inDays;
	}
	else
	{
		TotalResult_Days = date1_inDays - date2_inDays;
	}
	printf("The result is: %d \n", TotalResult_Days);

	return(0);
}