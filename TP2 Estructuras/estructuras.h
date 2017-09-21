typedef struct
{
    char nombre[50];
    char dni[15];
    int edad;
    int estado;
}ePersona;

ePersona agregarPersona(ePersona[], int);

int pedirDatoEnteroValidado(int, char[], int);

const char* pedirCadenaNumerosValidada(char[], int);

const char* pedirDatoCadenaValidado(char[], int);

ePersona borrarPersona(ePersona[], int);

void ordenarYMostrarPorNombre(ePersona[], int);

void grafico(ePersona[], int);

int buscarxDNI(ePersona[], int);
