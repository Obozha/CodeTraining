int daysofmonth [] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
days = year * 365 + year / 4 - year /100 + year / 400;
days += daysofmonth [ month ] + day;
days += isleap ( year ) && (month &gt; 2) ? 1 : 0;
