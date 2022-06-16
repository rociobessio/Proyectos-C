#include "Alumno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include  "utn.h"

//							STATIC LIBRARIES
static int esNombre(char* cadena,int longitud);


//							CONSTRUCTORS
eAlumno* Alumno_new()
{
	eAlumno* auxAlumno;

	auxAlumno = (eAlumno*) malloc(sizeof(eAlumno));

	if(auxAlumno!=NULL)//INICIALIZO LOS CAMPOS DE LA STRUCT
	{
		auxAlumno->legajo = 0;
		strcpy(auxAlumno->nombre,"NN"); //[NO NAME]
		strcpy(auxAlumno->apellido,"NLN"); //[NO LAST NAME]
		auxAlumno->promedio = 0.0;
		auxAlumno->materia=0;
		auxAlumno->sexo='I';
	}
	return auxAlumno;
}

eAlumno* Alumno_newParametros(char* legajoStr,char* nombreStr,char* apellidoStr,char* materiaStr,char* promedioStr)
{
	eAlumno *this;

	this = Alumno_new();//GUARDO LO QUE DEVUELVE LA FUNCION

	int auxlegajo;
	int auxMateria;
	float auxPromedio;

	auxlegajo = atoi(legajoStr);
	auxMateria = atoi(materiaStr);
	auxPromedio = atof(promedioStr);

	if(this!=NULL && legajoStr!=NULL && nombreStr!=NULL && materiaStr!=NULL && apellidoStr!=NULL && promedioStr!=NULL)//VALIDO TODO
	{
		if(!(Alumno_setLegajo(this, auxlegajo) &&
			Alumno_setNombre(this, nombreStr) &&
			Alumno_setApellido(this, apellidoStr) &&
			Alumno_setPromedio(this, auxPromedio) &&
			Alumno_setMateria(this, auxMateria)))//[VALIDACION DE CADA CAMPO]
		{
			Alumno_delete(this);
			this=NULL;
		}
	}
	return this;
}

//   					DESTRUCTOR
void Alumno_delete(eAlumno* this)//LE AGREGUE (Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

//						SEARCH/PRINT
int Alumno_searchForLegajo(LinkedList* pArrayAlumnos, int legajo)
{
	int todoOk=-1;

	int auxId;

	eAlumno* pAuxAlumno;
	int sizeAlumnos;
	if(pArrayAlumnos !=NULL)
	{
		sizeAlumnos = ll_len(pArrayAlumnos);
		for(int indice=0;indice<sizeAlumnos;indice++)
		{
			pAuxAlumno = ll_get(pArrayAlumnos, indice);//BUSCAMOS
			if(pAuxAlumno!=NULL)
			{
				if(Alumno_getLegajo(pAuxAlumno, &auxId)==1 && auxId==legajo)
				{
					todoOk=indice;//SI ENCUENTRA DEVUELE INDICE
				}
			}
		}
	}

	return todoOk;
}
int Alumno_getDescripcionMateria(int materia,char* desc)
{
	int todoOk=-1;

	if(desc!=NULL && materia>0)
	{
		if(materia==1)
		{
			strcpy(desc,"INGLES I");
		}
		else if(materia==2)
		{
			strcpy(desc,"LABORATORIO I");
		}
		else if(materia==3)
		{
			strcpy(desc,"PROGRAMACION I");
		}
		else
		{
			strcpy(desc,"SPD");
		}
		todoOk=1;
	}
	return todoOk;
}
int Alumno_ShowOnlyOne(eAlumno *alumno)
{
	int todoOk=0;

	int legajo;
	int materia;
	char name[50];
	char lastName[50];
	float promedio;
	char descripcionMateria[50];

	if(alumno!=NULL)
	{
		Alumno_getLegajo(alumno, &legajo);
		Alumno_getNombre(alumno, name);
		Alumno_getApellido(alumno, lastName);
		Alumno_getPromedio(alumno, &promedio);
		Alumno_getMateria(alumno, &materia);
		Alumno_getDescripcionMateria(materia, descripcionMateria);

		printf("|%4d | %-13s  |    %-13s	  |    %15s       |   %11.2f    |\n",legajo,name,lastName,descripcionMateria,promedio);

		printf("|-----|----------------|--------------------------|--------------------------|------------------|\n");

		todoOk=1;
	}

	return todoOk;
}


//					SETTERS
int Alumno_setNombre(eAlumno* this,char* nombre)
{
	int todoOk = -1;
	if(this!=NULL && nombre!=NULL && strlen(nombre)<48  && strlen(nombre)>=2)
	{
		if(esNombre(nombre, 49))
		{
			strlwr(nombre);
			nombre[0] = toupper(nombre[0]);
			strncpy(this->nombre,nombre,48);
			todoOk=1;
		}
	}
	return todoOk;
}

int Alumno_setApellido(eAlumno* this,char* apellido)
{
	int todoOk = -1;
	if(this!=NULL && apellido!=NULL && strlen(apellido)<=48 && strlen(apellido)>=3)
	{
		if(esNombre(apellido, 48))
		{
			strlwr(apellido);
			apellido[0] = toupper(apellido[0]);
			strncpy(this->apellido,apellido,48);
			todoOk=1;
		}
	}
	return todoOk;
}

int Alumno_setLegajo(eAlumno* this,int legajo)
{
	int todoOk=-1;

	if(this!=NULL && legajo>=0)
	{
		this->legajo = legajo;
		todoOk=1;
	}

	return todoOk;
}

int Alumno_setMateria(eAlumno* this,int materia)
{
	int todoOk=-1;

	if(this!=NULL && materia>0)
	{
		this->materia = materia;
		todoOk=1;
	}

	return todoOk;
}
/*
int Alumno_setSexo(eAlumno* this,char* sexo)
{
	int todoOk=-1;

	sexo = toupper(sexo);
	if(this!=NULL && (sexo == 'F' || sexo == 'M'))
	{
		this->sexo = sexo;
		todoOk=1;
	}

	return todoOk;
}*/


int Alumno_setPromedio(eAlumno* this,float promedio)
{
	int todoOk = 0;

	if (this != NULL && promedio>0)
	{
		this->promedio = promedio;
		todoOk = 1;
	}
	return todoOk;
}

//   				GETTERS
int Alumno_getNombre(eAlumno* this,char* nombre)
{
	int todoOk=-1;
	if(this!=NULL && nombre!=NULL)
	{
		todoOk=1;
		strcpy(nombre,this->nombre);
	}
	return todoOk;
}

int Alumno_getApellido(eAlumno* this,char* apellido)
{
	int todoOk=-1;
	if(this!=NULL && apellido!=NULL)
	{
		todoOk=1;
		strcpy(apellido,this->apellido);
	}
	return todoOk;
}

int Alumno_getLegajo(eAlumno* this,int* legajo)
{
	int todoOk=-1;

	if(this!=NULL && legajo!=NULL)
	{
		*legajo = this->legajo;
		todoOk = 1;
	}
	return todoOk;
}

int Alumno_getHigherLegajo(eAlumno* this,int* legajo)
{
    int todoOk = -1;

    if(this != NULL)
    {
       Alumno_getLegajo(this,legajo);
        todoOk = 0;
    }
    return todoOk;
}

int Alumno_getPromedio(eAlumno* this,float* promedio)
{
	int todoOk = 0;

	if (this != NULL && promedio != NULL)
	{
		*promedio = this->promedio;
		todoOk = 1;
	}
	return todoOk;
}

int Alumno_getMateria(eAlumno* this,int* materia)
{
	int todoOk=-1;

	if(this!=NULL && materia>=0)
	{
		 *materia = this->materia;
		todoOk=1;
	}
	return todoOk;
}



int Alumno_getSexo(eAlumno* this,char* sexo)
{
	int todoOk=-1;

	if(this!=NULL && sexo!=NULL)
	{
		 *sexo = this->sexo ;
		todoOk=1;
	}
	return todoOk;
}

int Alumno_getAll(eAlumno* this,char* name,char* lastname,float* promedio,int* materia,char* sexo,int* legajo)//[HECHA] - [MY ADDITION]
{
	int todoOk = 1;

	if(this!=NULL)
	{
		Alumno_getLegajo(this, legajo);
		Alumno_getNombre(this, name);
		Alumno_getApellido(this, lastname);
		Alumno_getPromedio(this, promedio);
		Alumno_getMateria(this, materia);
		todoOk=0;
	}
	return todoOk;
}

//STATIC LIBRARYS
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


//						SORT PASSENGERS
int Alumnos_sortByName(void* name1,void* name2)
{
	int todoOk = 0;


	eAlumno* auxPas1;
	eAlumno* auxPas2;

	if(name1!=NULL && name2!=NULL)
	{
		auxPas1 = (eAlumno*) name1;
		auxPas2 = (eAlumno*) name2;

		todoOk = strcmp(auxPas1->nombre,auxPas2->nombre);
	}

	return todoOk;
}

int Alumnos_sortByLastName(void* lastName1,void* lastName2)
{
	int todoOk = 0;

	eAlumno* auxPas1;
	eAlumno* auxPas2;

	if(lastName1!=NULL && lastName2!=NULL)
	{
		auxPas1 = (eAlumno*) lastName1;
		auxPas2 = (eAlumno*) lastName2;

		todoOk = strcmp(auxPas1->apellido,auxPas2->apellido);
	}

	return todoOk;
}

int Alumno_sortByPromedio(void* promedio1,void* promedio2)
{
	int todoOk = 0;

	eAlumno* auxPas1;
	eAlumno* auxPas2;

	if(promedio1!=NULL && promedio2!=NULL)
	{
		auxPas1 = (eAlumno*) promedio1;
		auxPas2 = (eAlumno*) promedio2;

		if(auxPas1->promedio>auxPas2->promedio)
		{
			todoOk=1;
		}
		else if(auxPas1->promedio<auxPas2->promedio)
		{
			todoOk=-1;
		}
	}

	return todoOk;
}

int Alumno_sortByMateria(void* materia1,void* materia2)
{
	int todoOk = 0;

	eAlumno* auxPas1;
	eAlumno* auxPas2;

	if(materia1!=NULL && materia2!=NULL)
	{
		auxPas1 = (eAlumno*) materia1;
		auxPas2 = (eAlumno*) materia2;

		if(auxPas1->materia>auxPas2->materia)
		{
			todoOk=1;
		}
		else if(auxPas1->materia<auxPas2->materia)
		{
			todoOk=-1;
		}
	}

	return todoOk;
}

int Alumno_sortBySexo(void* sexo1,void* sexo2)
{
	int todoOk = 0;

	eAlumno* auxPas1;
	eAlumno* auxPas2;

	if(sexo1!=NULL && sexo2!=NULL)
	{
		auxPas1 = (eAlumno*) sexo1;
		auxPas2 = (eAlumno*) sexo2;

		if(auxPas1->sexo>auxPas2->sexo)
		{
			todoOk=1;
		}
		else if(auxPas1->sexo<auxPas2->sexo)
		{
			todoOk=-1;
		}
	}

	return todoOk;
}

//				FILTROS
int filterByLaboratorio(void* pElement)
{
	return ((eAlumno*) pElement)->materia == 2; //casteo el elemento
}

int filterBySPD(void* pElement)
{
	return ((eAlumno*) pElement)->materia == 4; //casteo el elemento
}

int filterByPromedio(void* pElement)
{
	return ((eAlumno*) pElement)->promedio >= 6; //casteo el elemento
}
