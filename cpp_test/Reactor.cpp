//
// Created by Balint on 2016.02.21..
//

#include "Reactor.h"

double Reactor::volume() const{
    return this->width * this->depth * this->length;
}

bool Reactor::addable(const Reactor &r1, const Reactor &r2) {
    return (!r1.has_carrier && !r2.has_carrier) && (r1.anoxic && r2.anoxic)
           && (r1.width == r2.width) && (r1.depth == r2.depth);;
}

Reactor Reactor::operator+(const Reactor & r ) {
    Reactor r2 = Reactor(depth, width, length + r.length, anoxic + r.anoxic, has_carrier + r.has_carrier);
    return r2;
}


Reactor::Reactor(double d, double w, double l, bool ax, bool hc): depth(d), width(w), length(l),
anoxic(ax), has_carrier(hc) {

}
