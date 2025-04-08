#include <stdio.h>
#include <stdlib.h>
#define N 5
struct compu
{ 
    int velocidad;      // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio;           // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;     // Tipo de procesador (apuntador a cadena de caracteres) 
};

void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main(int argc, char const *argv[])
{
    struct compu listado[N];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    for (int i = 0; i < N; i++)
    {
        struct compu n;
        n.velocidad = 1 + rand()%3;
        n.anio = 2015 + rand()%10;
        n.cantidad_nucleos = 1 + rand()%8;
        n.tipo_cpu = tipos[rand()%6];
        listado[i] = n;
    }
    listarPCs(listado, N);
    mostrarMasVieja(listado, N);
    mostrarMasVeloz(listado, N);
    
    return 0;
}

void listarPCs(struct compu pcs[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("PC %d\n", i+1);
        printf("Velocidad: %d\n", pcs[i].velocidad);
        printf("Año: %d\n", pcs[i].anio);
        printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("Tipo CPU: %s\n\n", pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad)
{
    int vieja = 0;
    for (int i = 1; i < cantidad; i++)
    {
        if (pcs[i].anio < pcs[vieja].anio)
        {
            vieja = i;
        }
    }
    printf("PC MAS VIEJA\n");
    printf("Velocidad: %d\n", pcs[vieja].velocidad);
    printf("Año: %d\n", pcs[vieja].anio);
    printf("Cantidad de nucleos: %d\n", pcs[vieja].cantidad_nucleos);
    printf("Tipo CPU: %s\n\n", pcs[vieja].tipo_cpu);
}

void mostrarMasVeloz(struct compu pcs[], int cantidad)
{
    int veloz = 0;
    for (int i = 1; i < cantidad; i++)
    {
        if (pcs[veloz].velocidad < pcs[i].velocidad)
        {
            veloz = i;
        }
    }
    printf("PC MAS VELOZ\n");
    printf("Velocidad: %d\n", pcs[veloz].velocidad);
    printf("Año: %d\n", pcs[veloz].anio);
    printf("Cantidad de nucleos: %d\n", pcs[veloz].cantidad_nucleos);
    printf("Tipo CPU: %s\n\n", pcs[veloz].tipo_cpu);
}