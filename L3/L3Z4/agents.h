#include <stdio.h>

struct agent{
    int x;
    int y;
};

struct agent newagent(int x,int y);

void North(struct agent *a);

void South(struct agent *a);

void East(struct agent *a);

void West(struct agent *a);

double distance(struct agent a1, struct agent a);