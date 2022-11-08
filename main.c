#include <stdio.h>
#include "HW3_2017114657.h"

 customer* findFirstinCust(qHead* q1, qHead* q2, qHead* q3)
 {
 	// (4) fill this part
	if (queueFront(q1)->custom_id == 1)
	{
		return queueFront(q1);
	}
	else if (queueFront(q2)->custom_id == 1)
	{
		return queueFront(q2);
	}
	else if (queueFront(q3)->custom_id == 1)
	{
		return queueFront(q3);
	}
	return 0;
	//find first customer use a queueFront function, if find first customer then return the pointer to structure
 }

int main()
{
	qHead* CafeteriaDesk = CreateQueue();
	for (int i = 0; i < 100; i++)
	{
		customer* pcus = enterCustomer(i+1);
		enQueue(CafeteriaDesk, pcus);
	}
	int temp;

	
	
	// (2) fill this part
	qHead* q1 = CreateQueue();//create queue
	qHead* q2 = CreateQueue();
	qHead* q3 = CreateQueue();
	for(int i = 0; i < 100; i++)
	{
		switch(queueFront(CafeteriaDesk)->menu)		//Add the menu of the first queue customer to the case.
		{
			case 'A':
				enQueue(q1,CafeteriaDesk->front->cus);	//insert customer's impormation
				deQueue(CafeteriaDesk);					//and delete it. 
				break;
			case 'B':
				enQueue(q2,CafeteriaDesk->front->cus);
				deQueue(CafeteriaDesk);
				break;
			case 'C':
				enQueue(q3,CafeteriaDesk->front->cus);
				deQueue(CafeteriaDesk);
				break;	
		}
	}
	

	printf("%d customers choosen menu A \n", q1->count);	//print the count of queue
	printf("%d customers choosen menu B \n", q2->count);
	printf("%d customers choosen menu C \n", q3->count);
	


	printf("The first customer selects menu %c\n", findFirstinCust(q1,q2,q3)->menu);//use findFirstinCust function, and print it
}