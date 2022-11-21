#include <stdio.h>
//#include "generalList2.h"
#include "HW4.h"
#include <stdlib.h>

int sort_rule(Element point1, Element point2)
{
	// (1) fill this part
}

int main()
{
	Lhead* plist = createList();
    struct _point p;
    float p1[10];
    float p2[10];
    float test[2];
    for(int i =0; i<10; i++){
        p1[i] = (float)(rand()%100)/10;
        p2[i] = (float)(rand()%100)/10;
        p.x = p1[i];
        p.y = p2[i];
        printf("%f, %f \n", p1[i],p2[i]);
        insertionbyRule(plist,&p);
    }
    printf("%f,%f\n", plist[0]);
	// (2), (3), (4) fill this part
}
