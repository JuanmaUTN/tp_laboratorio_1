typedef struct
{
    char nombre[50];
    char dni[15];
    int edad;
    int estado;
}ePersona;

ePersona agregarPersona(ePersona[], int);
/** \brief Agrega una persona al array.
 *
 * \param Un array del tipo ePersona.
 * \param Entero que representa el tamaño del array.
 * \return Devuelve la persona ingresada.
 *
 */


int pedirDatoEnteroValidado(int, char[], int);
/** \brief Pide y valida un valor entero entre 2 limites.
 *
 * \param limite 1.
 * \param Qué se va a validar, por ejemplo, "edad".
 * \param limite 2.
 * \return Devuelve el numero entero validado.
 *
 */


const char* pedirCadenaNumerosValidada(char[], int);
/** \brief Pide una cadena de sólo números.
 *
 * \param Qué se va a ingresar, por ejemplo, "DNI".
 * \param El largo deseado de la cadena.
 * \return Devuelve la cadena validada, y se asigna usando strcmp.
 *
 */


const char* pedirDatoCadenaValidado(char[], int);
/** \brief Pide una cadena de sólo números.
 *
 * \param Qué se va a ingresar, por ejemplo, "Nombre".
 * \param El largo deseado de la cadena.
 * \return Devuelve la cadena validada, y se asigna usando strcmp.
 *
 */


ePersona borrarPersona(ePersona[], int);
/** \brief Borra un elemento del array ePersona.
 *
 * \param Array de ePersona.
 * \param Tamaño del array.
 * \return El elemento dado de baja.
 *
 */


void ordenarYMostrarPorNombre(ePersona[], int);
/** \brief Ordena por nombre los elementos del array y muestra solo aquellos que estan cargados.
 *
 * \param Array de ePersona.
 * \param Tamaño de dicho array.
 * \return No devuelve nada.
 *
 */


void grafico(ePersona[], int);
/** \brief Grafico vertical que muestra las edades de los elementos cargados dl array de ePersona.
 *
 * \param Array de ePersona.
 * \param Tamaño de dicho array.
 * \return No devuelve nada.
 *
 */


int buscarxDNI(ePersona[], int);
/** \brief Busca en el array una coincidencia con el dni ingresado.
 *
 * \param Array de ePersona.
 * \param Tamaño de dicho array.
 * \return Devuelve la posicion del array en la que se encontró dicha coincidencia.
 *
 */


int buscarLugar(ePersona[], int);
/** \brief Busca un lugar disponible para la carga de datos del array.
 *
 * \param Array de ePersona
 * \param Tamaño de dicho array.
 * \return Devuelve la primera posicion disponible para cargar.
 *
 */

