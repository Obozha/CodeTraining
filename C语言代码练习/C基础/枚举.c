#include <stdio.h>

enum WeekDay
{
Monday = 10,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
};

int main(void)
{
  //int day;
  enum WeekDay day = Sunday;
  printf("%d\n",day);
  system("pause");
  return 0;
}

