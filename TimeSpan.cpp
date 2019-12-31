//
// Created by Kemba Konteh on 10/10/19.
//
// This project is designed to help understand operator overloading. It implements ​TimeSpan​ class which represents a
// duration in hours, minutes and seconds. The seconds and minutes are between 0 and 59. The hours can be 0 to any number.
// When ​TimeSpan​ is printed, the minutes and ​seconds​ will always have 2 digits. The constructor for ​TimeSpan​ can
// take 0, 1, 2, or 3 parameters. In addition to integer value, the constructor is also able to handle double values and
// convert them as accurately as possible.
//
//

#include "TimeSpan.h"
#include <iostream>
#include <cmath>

using namespace std;

/* Constructor */
TimeSpan::TimeSpan()
{
    simplify(Hour,Minutes,Seconds);

    setTime(0,0,0);

}
/* Constructor */
TimeSpan::TimeSpan(double Hour)
{
    simplify(Hour,Minutes,Seconds);
    setTime(Hour,0,0);

}
/* Constructor  */
TimeSpan::TimeSpan(double Minutes, double Seconds)
{
    simplify(Hour,Minutes,Seconds);
   setTime(Hour, Minutes,0);


}
/* Full constructor */
TimeSpan::TimeSpan(double Hour, double Minutes, double Seconds)
{

    simplify(Hour,Minutes,Seconds);
    setTime(Hour, Minutes, Seconds);


}
/* Destructor */
TimeSpan::~TimeSpan()
{


}


// Gets the hours
// Returns true if successful and false otherwise
int TimeSpan::getHour() const
{
    return Hour;

}
// Gets the minutes
// Returns true if successful and false otherwise
int TimeSpan::getMinutes() const
{
    return Minutes;
}
// Gets the second
// Returns true if successful and false otherwise
int TimeSpan::getSeconds() const
{
    return Seconds;

}

// Sets the time; hour, minute and second

bool TimeSpan::setTime(double Hour, double Minutes, double Seconds)
{

    simplify(Hour, Minutes, Seconds);
    this->Hour = Hour;
    this->Minutes = Minutes;
    this->Seconds = Seconds;

}

// Method that simplifies the time. Makes sure that hour, minute and second are within the required domain as
// per the spec.
void TimeSpan::simplify(double &Hour, double &Minutes, double &Seconds)
{

    if(Seconds < 0 && Minutes != 0)
    {
        Seconds += 60;
        Minutes--;
    }
    else if(Seconds <0 && Minutes == 0)
    {
        Seconds = Seconds;

    }

    if (Seconds == 60)
    {
        Seconds -= 60;
        Minutes++;
    }

    if(Minutes < 0 && Hour != 0)
    {
        Minutes += 60;
        Hour --;
    } else if (Minutes < 0 && Hour == 0)
    {
        Minutes = Minutes;
    }

    if (Minutes == 60)
    {
        Minutes -= 60;
        Hour++;
    }


    // converting doubles into integer

    double h;
    double h1;
    h1 = modf(Hour, &h);
    Minutes = Minutes + abs(h1 * 60);
    Hour = h;

    double m;
    double m1;
    m1 = modf(Minutes, &m);
    Seconds = Seconds + abs(m1 * 60);
    Minutes = m;
    Seconds = round(Seconds);

    if(Minutes >= 60){
        Hour ++;
        Minutes -= 60;
    }

    if (Seconds >= 60){
        Minutes ++;
        Seconds -= 60;
    }

}
// overloads the == operator. Returns true if successful and false otherwise
bool TimeSpan::operator==(const TimeSpan &time) const
{
    return (time.Hour == Hour && time.Minutes == Minutes && time.Seconds == Seconds);
}

// overloads the != operator. Returns true if successful, false otherwise
bool TimeSpan::operator!=(const TimeSpan &timeSpan) const {
    return !(*this == timeSpan);
}

// overloads the <= operator, returns true if successful, false otherwise
 bool TimeSpan::operator<=(const TimeSpan &timeSpan) const
{
    return (this->Hour <= timeSpan.Hour && this->Minutes <= timeSpan.Minutes && this->Seconds <= timeSpan.Seconds);

}

// overloads the < operator, returns true if successful, false otherwise
bool TimeSpan:: operator < (const TimeSpan &timeSpan) const
{
    return (this->Hour < timeSpan.Hour && this->Minutes < timeSpan.Minutes && this->Seconds < timeSpan.Seconds);

}

// overloads the >= operator, returns true if successful, false otherwise
bool TimeSpan:: operator >= (const TimeSpan &timeSpan) const
{
    return (this->Hour >= timeSpan.Hour && this-> Minutes >= timeSpan.Minutes && this->Seconds >= timeSpan.Seconds);

}

// overloads the > operator, returns true if successful, false otherwise

bool TimeSpan::operator > (const TimeSpan &timeSpan) const
{
    return (this->Hour > timeSpan.Hour && this->Minutes > timeSpan.Minutes && this->Seconds > timeSpan.Seconds);

}
// overloads the + operator, returns time
TimeSpan TimeSpan::operator + (const TimeSpan &timeSpan) const
{
    TimeSpan time;
    time.Hour = this->Hour + timeSpan.Hour;
    time.Minutes = this->Minutes + timeSpan.Minutes;
    time.Seconds = this->Seconds + timeSpan.Seconds;
    time.simplify(time.Hour,time.Minutes,time.Seconds);

    return time;


}
// overloads the - operator, returns  t

TimeSpan TimeSpan::operator-(const TimeSpan &time) const
{
    TimeSpan t;
    t.Hour = this->Hour - time.Hour;
    t.Minutes = this->Minutes - time.Minutes;
    t.Seconds = this->Seconds - time.Seconds;
    t.simplify(t.Hour, t.Minutes,t.Seconds);
    return t;
}

// overloads the += operator, returns the object this
TimeSpan& TimeSpan::operator+=(const TimeSpan &timeSpan) {

    TimeSpan t = *this;
    *this= t + timeSpan;
    return *this;


}

// overloads the -= operator, returns the object this
TimeSpan& TimeSpan::operator-=(const TimeSpan &time)
{
    TimeSpan t = *this;
    *this = t - time;

    return *this;

}

// overloads the * operator, returns timeSpan1
TimeSpan TimeSpan::operator * (int timeSpan ) const {
    TimeSpan timeSpan1(this->Hour * timeSpan, this->Minutes * timeSpan, this->Seconds * timeSpan);
    timeSpan1.simplify(timeSpan1.Hour,timeSpan1.Minutes,timeSpan1.Seconds);
    return timeSpan1;



}


// overloads the ostream operator <<. This method is responsible for the output. It puts a 0 in front of the
// time if it is less than 10 so it be 09, 08,01 etc. and then puts a colon to to give the required out as per the spec

ostream& operator<<(ostream& outStream, TimeSpan &time) {

    outStream << time.Hour << ":";
    if (time.Minutes >= 0 && time.Minutes <= 9) {
        outStream << "0" << time.Minutes << ":";
    } else {
        outStream << time.Minutes << ":";
    }
    if (time.Seconds >= 0 && time.Seconds <= 9) {
        outStream << "0" << time.Seconds;
    } else {
        outStream << time.Seconds;
    }
    return outStream;

}









