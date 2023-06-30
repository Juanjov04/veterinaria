#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MASCOTAS 100
#define MAX_SERVICIOS 10

void mostrarMenu() {
    printf("----- Menu -----\n");
    printf("1. Ingresar mascota\n");
    printf("2. Ingresar servicio\n");
    printf("3. Facturar\n");
    printf("4. Salir\n");
    printf("Ingrese una opcion: ");
}

void ingresarMascota(int* contadorMascotas, int* ids, char nombres[][50], char tipos[][50], int* edades, char nombresDueño[][50]) {
    if (*contadorMascotas < MAX_MASCOTAS) {
        printf("Ingrese el ID de la mascota: ");
        scanf("%d", &ids[*contadorMascotas]);

        printf("Ingrese el nombre de la mascota: ");
        scanf("%s", nombres[*contadorMascotas]);

        printf("Ingrese el tipo de mascota: ");
        scanf("%s", tipos[*contadorMascotas]);

        printf("Ingrese la edad de la mascota: ");
        scanf("%d", &edades[*contadorMascotas]);

        printf("Ingrese el nombre del dueño: ");
        scanf("%s", nombresDueño[*contadorMascotas]);

        (*contadorMascotas)++;

        printf("Mascota ingresada correctamente.\n");
    } else {
        printf("No se pueden ingresar mas mascotas. Limite alcanzado.\n");
    }
}

void ingresarServicio(int* contadorServicios, char nombres[][50], float* precios, char descripciones[][100], int* idsMascota) {
    if (*contadorServicios < MAX_SERVICIOS) {
        printf("Ingrese el nombre del servicio: ");
        getchar();
        fgets(nombres[*contadorServicios], 50, stdin);
        nombres[*contadorServicios][strcspn(nombres[*contadorServicios], "\n")] = '\0';

        printf("Ingrese el precio del servicio: ");
        scanf("%f", &precios[*contadorServicios]);

        printf("Ingrese la descripcion del servicio: ");
        getchar();
        fgets(descripciones[*contadorServicios], 100, stdin);
        descripciones[*contadorServicios][strcspn(descripciones[*contadorServicios], "\n")] = '\0';

        printf("Ingrese el ID de la mascota a la que se asignara el servicio: ");
        scanf("%d", &idsMascota[*contadorServicios]);

        (*contadorServicios)++;

        printf("Servicio ingresado correctamente.\n");
    } else {
        printf("No se pueden ingresar mas servicios. Limite alcanzado.\n");
    }
}

void facturar(int contadorMascotas, int contadorServicios, int* ids, char nombres[][50], char nombresDueño[][50], char nombresServicio[][50], float* precios, char descripciones[][100], int* idsMascota) {
    int idMascota;
    float precioTotal = 0.0;

    printf("Ingrese el ID de la mascota: ");
    scanf("%d", &idMascota);

    int mascotaEncontrada = 0;
    for (int i = 0; i < contadorMascotas; i++) {
        if (ids[i] == idMascota) {
            mascotaEncontrada = 1;
            printf("Factura:\n");
            printf("Mascota: %s\nDueno: %s\n", nombres[i], nombresDueño[i]);

            printf("Servicios asignados:\n");
            for (int j = 0; j < contadorServicios; j++) {
                if (idsMascota[j] == idMascota) {
                    printf("Servicio: %s\nPrecio: %.2f\n", nombresServicio[j], precios[j]);
                    printf("Descripcion: %s\n", descripciones[j]);
                    precioTotal += precios[j];
                }
            }

            printf("Precio Total: %.2f\n", precioTotal);
            break;
        }
    }

    if (!mascotaEncontrada) {
        printf("No se encontro la mascota.\n");
    }
}

int main() {
    int opcion;
    int contadorMascotas = 0;
    int contadorServicios = 0;

    int ids[MAX_MASCOTAS];
    char nombres[MAX_MASCOTAS][50];
    char tipos[MAX_MASCOTAS][50];
    int edades[MAX_MASCOTAS];
    char nombresDueño[MAX_MASCOTAS][50];

    char nombresServicio[MAX_SERVICIOS][50];
    float precios[MAX_SERVICIOS];
    char descripciones[MAX_SERVICIOS][100];
    int idsMascota[MAX_SERVICIOS];

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarMascota(&contadorMascotas, ids, nombres, tipos, edades, nombresDueño);
                break;
            case 2:
                ingresarServicio(&contadorServicios, nombresServicio, precios, descripciones, idsMascota);
                break;
            case 3:
                facturar(contadorMascotas, contadorServicios, ids, nombres, nombresDueño, nombresServicio, precios, descripciones, idsMascota);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
