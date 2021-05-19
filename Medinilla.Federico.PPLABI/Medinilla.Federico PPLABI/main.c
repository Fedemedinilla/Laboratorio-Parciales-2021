#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"
#include "mascota.h"
#include "fecha.h"
#include "tipoMascota.h"
#include "colorMascota.h"
#include "servicio.h"

#define TIPOSTAM 5
#define COLORESTAM 5
#define MASCOTASTAM 10
#define SERVICIOSTAM 3

int main()
{
    eMascota mascotasLista[MASCOTASTAM];
    eTipoMascota tiposMascotasLista[TIPOSTAM];
    eColorMascota coloresMascotasLista[COLORESTAM];
    eServicio serviciosMascotasLista[SERVICIOSTAM];

    int menuOpcion;
    int idMascotaActual=100;


    if(!initTipos(tiposMascotasLista,TIPOSTAM))
    {
        printf("\nTipos inicializados correctamente.");
    }
    else
    {
        printf("\nERROR - Tipos no inicializados.");
    }

    if(!initColores(coloresMascotasLista,COLORESTAM))
    {
        printf("\nColores inicializados correctamente.");
    }
    else
    {
        printf("\nERROR - Colores no inicializados.");
    }

    if(!initServicios(serviciosMascotasLista,SERVICIOSTAM))
    {
        printf("\nServicios inicializados correctamente.");
    }
    else
    {
        printf("\nERROR - Servicios no inicializados.");
    }

    if(!initMascotas(mascotasLista,MASCOTASTAM))
    {
        printf("\nMascotas inicializadas correctamente.");
    }
    else
    {
        printf("\nERROR - Mascotas no inicializadas.");
    }

    do
    {
        if(!getNumero(&menuOpcion,
                "\n\n1) Cargar una mascota"
                "\n2) Modificar una mascota"
                "\n3) Eliminar una mascota"
                "\n4) Listar mascotas"
                "\n5) Listar tipos"
                "\n6) Listar colores"
                "\n7) Listar servicios"
                "\n8) Cargar trabajo"
                "\n9) Listar trabajos"
                "\n10) Salir",
                "\nERROR - Opcion invalida",1,10))
        {
            switch(menuOpcion)
            {
            case 1:
                agregarMascota(mascotasLista,MASCOTASTAM,&idMascotaActual);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                mostrarTipos(tiposMascotasLista,TIPOSTAM);
                break;
            case 6:
                mostrarColores(coloresMascotasLista,COLORESTAM);
                break;
            case 7:
                mostrarServicios(serviciosMascotasLista,SERVICIOSTAM);
                break;
            case 8:
                break;
            case 9:
                break;
            }
        }
    }while(menuOpcion!=10);

}
