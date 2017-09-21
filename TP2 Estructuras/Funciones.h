typedef struct
{
    int codigo;
    char nombre[50];
    char dni[15];
    int edad;
    int flagEstado;
} eCliente;

            /**< Operaciones matemáticas. */

int pedirNumeroInt();
/** \brief Pide un numero entero a través de consola con printf y scanf.
 *
 * \param No recibe nada.
 * \return Devuelve el numero que el usuario ingresó por consola.
 *
 */


int sumar2Numeros(int, int);
/** \brief Suma 2 números.
 *
 * \param Recibe numero 1.
 * \param Recibe numero 2.
 * \return Devuelve el resultado de la suma.
 *
 */


int restar2Numeros(int, int);
/** \brief Resta 2 números.
 *
 * \param Recibe número 1.
 * \param Recibe número 2.
 * \return Devuelve el resultado de la resta.
 *
 */


int dividir2Numeros(int, int);
/** \brief Divide 2 números. (El programa se rompe si se divide por 0 (arreglado))
 *
 * \param Recibe número 1.
 * \param Recibe número 2.
 * \return Devuelve el resultado de la división.
 *
 */


int multiplicar2Numeros(int, int);
/** \brief Multiplica 2 números.
 *
 * \param Recibe número 1.
 * \param Recibe número 2.
 * \return Devuelve el resultado de la multiplicación.
 *
 */


int factorizar1Numero(int);
/** \brief Factoriza el número ingresado. (Ejemplo: Número ingresado es 5, 5.4.3.2.1)
 *
 * \param Recibe 1 número.
 * \return Devuelve el resultado de la factorización.
 *
 */

            /**< Boludeces. */

int mostrarTablaAscii();
/** \brief Muestra la tabla ASCII.
 *
 * \param No recibe nada.
 * \return No devuelve nada.
 *
 */


int saludoDeApu();
 /** \brief Escribe letra por letra el saludo de Apu con un delay (Sleep en windows.h).
 *
 * \param No recibe nada.
 * \return No devuelve nada.
 *
 */


int pantallaDeCarga();
/** \brief Muestra una pantalla de carga.
 *
 * \param No recibe nada.
 * \return No devuelve nada.
 *
 */

            /**< Funciones con estructura eCliente. */

eCliente cargar1Cliente(eCliente[]);
/** \brief Carga un array de eCliente, contiene una función que busca un lugar disponible en el array.
 *
 * \param Array de eCliente.
 * \return La posición del array que fue cargado.
 *
 */


eCliente borrar1Cliente(eCliente[]);
/** \brief Borra un elemento de un array de eCliente.
 *
 * \param Recibe array de eCliente.
 * \return Devuelve la posición del array borrado.
 *
 */


void mostrarClientes(eCliente[]);
/** \brief Muestra el array de eClientes. (Siempre que el flagEstado esté en 1).
 *
 * \param Recibe el array de eCliente.
 * \return No devuelve nada.
 *
 */


void graficoEdadesHorizontal(eCliente[]);
/** \brief Muestra un grafico con asteriscos de los grupos de edades (0-18, 19-35, 36-100).
 *
 * \param Recibe el array de eCliente.
 * \return No devuelve nada.
 *
 */


void ordenarNombres(eCliente[]);
/** \brief Ordena alfabeticamente los clientes por su nombre.
 *
 * \param Recibe el array de eCliente.
 * \return No devuelve nada.
 *
 */








