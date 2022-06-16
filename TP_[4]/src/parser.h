
/** \brief Parsea los datos los datos de los pasajeros desde el archivo alumnos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_AlumnoFromText(FILE* pFile , LinkedList* pArrayListAlumnos);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo alumnos.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_AlumnoFromBinary(FILE* pFile , LinkedList* pArrayListAlumnos);
