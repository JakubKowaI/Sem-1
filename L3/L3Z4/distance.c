#include "agents.h"
#include <math.h>

double distance(struct agent a1, struct agent a){
    double d=0;
    d=sqrt(pow((a1.x-a.x),2)+pow((a1.y-a.y),2));
    return d;
}