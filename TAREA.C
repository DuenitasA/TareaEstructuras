#include <stdio.h>
#include <string.h>

struct Alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};
int ingresarDatos(struct Alumno *alumno);
int mostrarDatos(struct Alumno *alumno);

int main(int argc, char const *argv[])
{
    int n;
    printf("Ingrese la cantidad de alumnos:\n ");
    fflush(stdout);
    scanf("%d", &n);
    struct Alumno alumnos[n];
    int opcion;
    do
    {
        printf("1. Ingresar datos de los alumnos\n");
        printf("2. Mostrar datos de los alumnos\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion:\n ");
        fflush(stdout);
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                printf("Ingrese los datos del alumno %d:\n", i + 1);
                ingresarDatos(&alumnos[i]);
            }
            break;
        case 2:
            printf("Datos de los alumnos:\n");
            for (int i = 0; i < n; i++)
            {
                mostrarDatos(&alumnos[i]);
            }
            break;
        case 3:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Ingrese una opcion del 1 al 3 por favor.\n");
            break;
        }
    } while (opcion != 3);
    return 0;
}
int ingresarDatos(struct Alumno *alumno)
{
    char buffer[100];
    printf("Matricula:\n");
    fflush(stdout);
    scanf("%d", &(alumno->matricula));
    printf("Nombre:\n");
    fflush(stdout);
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(alumno->nombre, buffer, sizeof(alumno->nombre));
    printf("Direccion:\n");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(alumno->direccion, buffer, sizeof(alumno->direccion));
    printf("Carrera:\n");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer,"\n")] = '\0';
    strncpy(alumno->carrera, buffer, sizeof(alumno->carrera));
    printf("Promedio:\n");
    fflush(stdout);
    scanf("%f", &(alumno->promedio));
    return 0;
}
int mostrarDatos(struct Alumno *alumno)
{
    printf("Matricula: %d\n", alumno->matricula);
    printf("Nombre: %s\n", alumno->nombre);
    printf("Direccion: %s\n", alumno->direccion);
    printf("Carrera: %s\n", alumno->carrera);
    printf("Promedio: %.2f\n", alumno->promedio);
    printf("\n");
    return 0;
}
