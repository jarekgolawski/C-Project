#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dane.h"

int main(int argc, char** argv) {

   dane d;
   wczytaj_dane(argc, argv, &d);

   printf("%f\n",d.wsp );
   printf("%f\n",d.mp );
   printf("%f\n",d.cpow );
}
