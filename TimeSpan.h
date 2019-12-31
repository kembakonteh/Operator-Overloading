//
// Created by Kemba Konteh on 10/10/19.
//

#ifndef ASSIGNMENT2_TIMESPAN_H
#define ASSIGNMENT2_TIMESPAN_H

#include <iostream>

using namespace std;


class TimeSpan {

private:
    double Hour;
    double Minutes;
    double Seconds;

    void simplify(double &Hour, double &Minutes, double &Seconds);

public:

    TimeSpan();
    TimeSpan(double Hour);
    TimeSpan(double Minutes, double Seconds);
    TimeSpan(double Hour, double Minutes, double Seconds);

    // Destructor
    ~TimeSpan();

    // Gets the hours
    // Returns true if successful and false otherwise
    int getHour() const;

    // Gets the minutes
    // Returns true if successful and false otherwise
    int getMinutes() const;

    // Gets the second
    // Returns true if successful and false otherwise
    int getSeconds() const;

    // Sets the time; hour, minute and second
    bool setTime(double Hour, double Minutes, double Seconds);


    // Friend functions
    friend ostream& operator <<(ostream & outStream, TimeSpan &time);
    //friend ostream& operator <<(ostream & outStream, TimeSpan &time);

    // overloads the assignment operator
    bool operator == (const TimeSpan &timeSpan) const;

    // Overloads the != operator
    bool operator != (const TimeSpan &timeSpan) const;

    // Overloads the <= operator
    bool operator <= (const TimeSpan &timeSpan) const;

    // Overloads the < operator
    bool operator < (const TimeSpan &timeSpan) const;

    // Overloads the >= operator
    bool operator >= (const TimeSpan &timeSpan) const;

    // Overloads the > operator
    bool operator > (const TimeSpan &timeSpan) const;

    // Overloads the + operator
    TimeSpan operator + (const TimeSpan &timeSpan) const;

    // Overloads the - operator
    TimeSpan operator - (const TimeSpan &timeSpan) const;

    // Overloads the += operator
    TimeSpan& operator += (const TimeSpan &timeSpan) ;

    // Overloads the -= operator
    TimeSpan& operator -= (const TimeSpan &timeSpan) ;

    // overloads the * operator
    TimeSpan  operator * (int timeSpan) const ;

    //
    TimeSpan operator-();


















};


#endif //ASSIGNMENT2_TIMESPAN_H
