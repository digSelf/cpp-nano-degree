#include <iostream>
#include <cassert>

struct Date {
public:
    // define public accessors and mutators for the private member vairables
    void day(int d) { this->day_ = d; }
    int day() const { return this->day_; }

    void month(int m) { this->month_ = m; }
    int month() const { return this->month_; }

    void year(int y) { this->year_ = y; }
    int year() const { return this->year_; }

private:
    int day_ = 1;
    int month_ = 1;
    int year_ = 0;
};


int main()
{
    Date date;

    date.day(29);
    date.month(8);
    date.year(1981);

    assert(date.day() == 29);
    assert(date.month() == 8);
    assert(date.year() == 1981);

    std::cout << date.day() << "/" << date.month() << "/" << date.year() << "\n";
}
