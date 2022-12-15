#include <stdio.h>
#include "generalList2.h"
#include "HW4_2017114657.h"
#include <stdlib.h>

int sort_rule(Element point1, Element point2)
{
	// (1) fill this part
    if (point1->x > point2->x){
        return 1; //if point1->x is greater than point2.x, return 1 it is just inserting data
    }
    else if (point1->x == point2->x){//if point1->x and point2.x are the same, compare with point1->y and point2->y
        if (point1->y > point2 ->y){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int main()
{
	Lhead* plist = createList();
    setSortRule(plist,(sort_rule));
    for(int i =0; i<10; i++){//create 10 pointers to the structure
        Point* data = (Point*)malloc(sizeof(Point));
        data->x = (float)(rand()%100)/10;//use rand method. its range is 0 to 10.0
        data->y = (float)(rand()%100)/10;//use rand method. its range is 0 to 10.0
        insertionbyRule(plist,data);//insert data into list by using insertionbyRule
    }
    for(int i =0; i<10; i++) {
        printf("%f, %f \n", plist->front->link->data->x, plist->front->link->data->y);//print list's front data
        deletion(plist, plist->front);//and delete front data
    }
}
