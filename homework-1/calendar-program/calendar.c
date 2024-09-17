#include <stdio.h>

// formula to determine whether a year is a leap year
// https://learn.microsoft.com/en-us/office/troubleshoot/excel/determine-a-leap-year
int leapYearCheck(int year) {
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

// algorithm for determining the number of days in a month
// http://www.dispersiondesign.com/articles/time/number_of_days_in_a_month
int getMonthDays(int month, int isLeapYear) {
  int daysInMonth;

  if (month == 2) {
    daysInMonth = 28 + isLeapYear;
  } else {
    daysInMonth = 31 - (month - 1) % 7 % 2;
  }

  return daysInMonth;
}

// algorithm to calculate the day of the week
// https://en.wikipedia.org/wiki/Zeller%27s_congruence
int getDayOfWeek(int month, int year) {
  if (month < 3) { // January and February are counted as months 13 and 14 of the previous year
    month += 12;
    year -= 1;
  }

  int q = 1;          // day of the month
  int j = year / 100; // century
  int k = year % 100; // year

  int h = (q + 13 * (month + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7; // Zeller's congruence for the Gregorian calendar

  int day = ((h + 5) % 7) + 1; // ISO week date (1 = Monday to 7 = Sunday)

  return day;
}

void drawCalendar(int month, int year) {
  char *months[] = {"January",   "February", "March",    "April",
                    "May",       "June",     "July",     "August",
                    "September", "October",  "November", "December"};

  int monthDays = getMonthDays(month, year);
  int monthStartDayOfWeek = getDayOfWeek(month, year);

  printf("%s %d\n", months[month - 1], year);
  printf("Mo Tu We Th Fr Sa Su\n");

  for (int offset = 1; offset < monthStartDayOfWeek; offset++) {
    printf("   ");
  }

  int daysOffset = monthStartDayOfWeek - 1;

  for (int monthDay = 1; monthDay <= monthDays; monthDay++) {
    printf("%2d ", monthDay);

    if ((daysOffset + monthDay) % 7 == 0) {
      printf("\n");
    }
  }
  printf("\n");
}

int main(void) {
  int month;
  int year;

  printf("Hi! Please enter number of year to start:\n");

  while (scanf(" %d", &year) != 1) {
      fflush(stdin);
      printf("Error: Invalid input. Please, try again:\n");
  }

  printf("Awesome! Now choose a month from 1 to 12:\n");

  while (scanf(" %d", &month) != 1 || month < 1 || month > 12) {
      fflush(stdin);
      printf("Error: Invalid input. Please enter correct month date:\n");
  }

  printf("Nice! Loading your calendar...\n\n");
  drawCalendar(month, year);

  return 0;
}
