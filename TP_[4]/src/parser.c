#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Alumno.h"


int parser_AlumnoFromText(FILE* pFile , LinkedList* pArrayListAlumnos)
{
	int todoOk = 0;
	int elementoUno=1;

	//AUXILIARIES
	eAlumno *pAuxAlumno;
	char auxLegajo[5000];
	char auxName[5000];
	char auxLastName[5000];
	char auxPromedio[5000];
	char auxMateria[5000];

	if(pFile!=NULL)
	{
		while (!feof(pFile))
		{//WHILE IT ISN'T THE END OF THE FILE CONTINUE
			if(elementoUno)
			{
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxLegajo, auxName,
						auxLastName,auxMateria,auxPromedio);
				/*fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxLegajo, auxName,
						auxLastName,auxSexo,auxMateria,auxPromedio);*/
				elementoUno = 0;
			}
			/*fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxLegajo, auxName,
					auxLastName,auxSexo,auxMateria,auxPromedio);*/
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxLegajo, auxName,
								auxLastName,auxMateria,auxPromedio);

			//pAuxAlumno = Alumno_newParametros(auxLegajo, auxName, auxLastName, auxMateria, auxPromedio, auxSexo);
			pAuxAlumno = Alumno_newParametros(auxLegajo, auxName, auxLastName, auxMateria, auxPromedio);

			if(pAuxAlumno!=NULL)//valido q parametros no devuelva NULL
			{
				ll_add(pArrayListAlumnos, pAuxAlumno);
				todoOk=1;
			}
		}
	}
    return todoOk;
}


int parser_AlumnoFromBinary(FILE* pFile , LinkedList* pArrayListAlumnos)
{
	int todoOk=0;

	eAlumno *pAuxAlumno;

	if(pFile!=NULL)
	{
		while(!feof(pFile))//WHILE IT ISN'T THE END OF THE FILE CONTINUE
		{
			pAuxAlumno = Alumno_new();
			if(fread(pAuxAlumno,sizeof(eAlumno),1,pFile) ==1)//IF RETURNS 1 PUDO LEERLO
			{
				ll_add(pArrayListAlumnos, pAuxAlumno);
			}
		}
		todoOk=1;
	}
    return todoOk;
}
