#include <iostream>
#include <vector>

#include "Reactor.h"



void readInReactors(int, std::vector<Reactor>&);
void writeOutReactors(const std::vector<Reactor>&);

void aggregateReactors(std::vector<Reactor>&);

int main() {

    int n;

    std::cin >> n;

    std::vector<Reactor> reactors;

    readInReactors(n, reactors);

    aggregateReactors(reactors);

    writeOutReactors(reactors);

    return 0;
}


void readInReactors(int n, std::vector<Reactor> &reactors) {

    for(int i = 0; i < n; i++){
        bool anoxic;
        bool has_carrier;
        double  length;
        double width;
        double depth;

        std::cin >> length;
        std::cin >>  width;
        std::cin >>  depth;
        std::cin >>  anoxic;
        std::cin >>  has_carrier;
        Reactor r(depth, width, length, anoxic, has_carrier);

        reactors.push_back(r);
    }

}

void writeOutReactors(const std::vector<Reactor> &reactors) {
    for(int index = 0; index < reactors.size(); index++){

        std::cout << index+1 << ". Volume: " << reactors[index].volume() << " has carrier: " <<  reactors[index].has_carrier <<" anoxic: "<<  reactors[index].anoxic << std::endl;
    }

}


void aggregateReactors(std::vector<Reactor> &reactors ) {
    for (int i = 0; i < reactors.size() - 1; i++){
        if (Reactor::addable(reactors[i], reactors[i+1]))
        {
            reactors[i] = reactors[i] + reactors[i+1];
            reactors.erase(reactors.begin()+i+1);
            aggregateReactors(reactors);

        }
    }
}

