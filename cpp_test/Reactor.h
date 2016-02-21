//
// Created by Balint on 2016.02.21..
//

#ifndef CPP_TEST_REACTOR_H
#define CPP_TEST_REACTOR_H


class Reactor{
private:
    double depth;
    double length;
    double width;
public:
    bool anoxic;
    bool has_carrier;
    Reactor(double, double, double, bool, bool);
    double volume() const;
    static bool addable(const Reactor&, const Reactor&);
    Reactor operator+(const Reactor&);
};

#endif //CPP_TEST_REACTOR_H
