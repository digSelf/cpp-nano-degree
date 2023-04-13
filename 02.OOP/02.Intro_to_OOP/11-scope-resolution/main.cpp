#include <iostream>
#include <cassert>

/* encapsulation is a kind of operation which bundles related data in a single class and protects them from 
 * unauthorized or accidental modificaitons.
 *
 * abstraction is a kind of operation which provides the esstiential information and operations to the public 
 * and hide the details. 
 */
class Date {
public:
    // invariants
    Date(int d, int m, int y) {
        year(y);
        month(m);
        day(d);
    }

    int day() const { return day_; }
    void day(int d);

    int month() const { return month_; }
    void month(int m);

    int year() const { return year_; }
    void year(int y);

private:
    int day_ = 1;
    int month_ = 1;
    int year_ = 0;
};

void Date::year(int y) { year_ = y; }

void Date::month(int m) { 
    if (m >= 1 && m <= 12)
        month_ = m; 
}
void Date::day(int d) { 
    if (d >= 1 && d <= 31)
        day_ = d; 
}
 int main()
{
    Date date(29, 8, 1981);

    assert(date.day() == 29);
    assert(date.month() == 8);
    assert(date.year() == 1981);

    return 0;
}

