#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "principalMenu.h"

/****************************************************
 * 		STUDENT'S INFORMATION:
 *
 * NAME			: ROCIO
 * LAST NAME    : BESSIO
 * D.N.I        : 45.013.997
 * DIV.			: 1-A
 * EMAIL        : ROCIBESSIO@GMAIL.COM
 *
 * -------------------------------------------------------
 * 		ASSIGNAMENT INFORMATION:
 * DEAD LINE   							 : 11/06/2022
 * SUBJECT      						 : LABORATORIO I
 *
 * REQUIREMENTS TO MAKE THE ASSIGNAMENT  :
 * 											• Manejo de punteros.
 *  										• Manejo de linkedList.
 *  										• Manejo de estructuras.
 *  										• Manejo de memoria dinámica.
 *
 *		LINKEDLIST TO USE:
 *	LinkedList* ll_newLinkedList(void)
 *	void ll_deleteLinkedList(LinkedList* self)
 *	void ll_add(LinkedList* self , void* element)
 *	void ll_remove(LinkedList* self , int index)
 *	void* ll_get(LinkedList* self , int index)
 *	int ll_len(LinkedList* self )

*****************************************************/

int main()
{
	setbuf(stdout,NULL);

	goingToMainMenu();//EVERYTHING GOES FROM THERE!

    return 0;
}

