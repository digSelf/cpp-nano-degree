#include <iostream>
#include <cassert>

struct Date {
    int day;
    int month;
    int year;
};

int main() {
    Date date;

    date.day = 1;
    date.month = 10;
    date.year = 2019;

    assert(date.day == 29);
    assert(date.month == 9);
    assert(date.year == 1981);

    return 0;
}
