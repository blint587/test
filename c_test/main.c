#include <stdio.h>
#include <stdbool.h>

typedef struct Reactor Reactor;

struct Reactor{
    double depth;
    double length;
    double width;
    bool anoxic;
    bool has_carrier;
};

double reactorVolume(Reactor *);
void readInReactors(int, Reactor []);
void writeOutReactors(int, Reactor []);
bool addable(struct Reactor *, Reactor *);
void add(struct Reactor *, Reactor *);
int aggregateReactors(Reactor [], int);

int main() {

    int n;

    scanf("%d", &n);

    Reactor reactors[n];

    readInReactors(n, reactors);

    n = aggregateReactors(reactors, n);

    writeOutReactors(n, reactors);

    return 0;
}


double reactorVolume(struct Reactor *r){
    return r->width * r->depth * r->length;
}

void readInReactors(int n, Reactor *reactors) {

    for(int i = 0; i < n; i++){
        int anoxic;
        int has_carrier;
        Reactor r;
        scanf("%lf", &r.length);
        scanf("%lf", &r.width);
        scanf("%lf", &r.depth );
        scanf("%d", &anoxic);
        scanf("%d", &has_carrier);

        r.anoxic = anoxic != 0;
        r.has_carrier = has_carrier != 0;

        reactors[i] = r;
    }

}

void writeOutReactors(int n, Reactor *reactors) {
    for(int index = 0; index < n; index++){
        Reactor * r = &reactors[index];
        printf("%d. Volume: %f, has carrier: %d, anoxic: %d \n", index+1, reactorVolume(r), r->has_carrier, r->anoxic);
    }

}

bool addable(struct Reactor *r1, struct Reactor *r2) {
    return (!r1->has_carrier && !r2->has_carrier) && (r1->anoxic && r2->anoxic)
           && (r1->width == r2->width) && (r1->depth == r2->depth);

}

void add(struct Reactor * r1, struct Reactor * r2) {
    r1->length += r2->length;
}

int aggregateReactors(Reactor *reactors, int n) {
    for (int i = 0; i < n - 1; i++){
        if (addable(&reactors[i], &reactors[i+1])){
            add(&reactors[i], &reactors[i+1]);
            for(int j = i+1; j < n-1; j++){
                reactors[j] = reactors[j+1];
            }
            n = n - 1;
            n = aggregateReactors(reactors, n);

        }
    }
    return n;
}
