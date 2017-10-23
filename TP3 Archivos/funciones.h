typedef struct{
    char titulo[20];
    char genero[20];
    float duracion;
    char descripcion[50];
    float puntaje;
    char linkImagen[50];
    int estadoAltaBaja;
}EMovie;

EMovie agregarPelicula(EMovie movie[]);


EMovie borrarPelicula(EMovie movie[]);


void generarPagina(EMovie lista[], char nombre[]);



