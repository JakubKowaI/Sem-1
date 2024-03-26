#include <stdio.h>
#include "agents.h"

int main(void)
{
struct agent Bob = newagent(0, 0);
struct agent Alice = newagent(3, 3);
North (&Bob);
South (&Alice);
West(&Alice);
North (&Bob);
East(&Bob);
South (& Alice);
printf("odleglosc = %f\n", distance(Bob , Alice));
return 0;
}