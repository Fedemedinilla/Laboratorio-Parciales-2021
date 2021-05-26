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
#include "trabajo.h"
#include "cliente.h"

#define TIPOSTAM 5
#define COLORESTAM 5
#define MASCOTASTAM 5
#define SERVICIOSTAM 3
#define TRABAJOSTAM 10
#define CLIENTESTAM 5

int main()
{
    eMascota mascotasLista[MASCOTASTAM];
    eTipoMascota tiposMascotasLista[TIPOSTAM];
    eColorMascota coloresMascotasLista[COLORESTAM];
    eServicio serviciosMascotasLista[SERVICIOSTAM];
    eTrabajo trabajosLista[TRABAJOSTAM] = {{1,100,20000,{10,5,2021}}};
    eCliente clientesLista[CLIENTESTAM];

    int menuOpcion;
    char menuSalida;
    int idMascotaActual=100;
    int idTrabajoActual=1;


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
    if(!initTrabajos(trabajosLista,TRABAJOSTAM))
    {
        printf("\nTrabajos inicializados correctamente.");
    }
    else
    {
        printf("\nERROR - Trabajos no inicializados.");
    }

    if(!initClientes(clientesLista,CLIENTESTAM))
    {
        printf("\nClientes inicializados correctamente.");
    }
    else
    {
        printf("\nERROR - Clientes no inicializados.");
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
                "\n10) Mostrar mascotas por COLOR"
                "\n11) Mostrar mascotas por TIPO"
                "\n12) Mostrar mascota de menor edad"
                "\n13) Salir\n\n"
                "Ingrese una opcion: ",
                "\nERROR - Opcion invalida",1,13))
        {
            switch(menuOpcion)
            {
            case 1:
                if(!agregarMascota(mascotasLista,MASCOTASTAM,&idMascotaActual,tiposMascotasLista,TIPOSTAM,coloresMascotasLista,COLORESTAM,clientesLista,CLIENTESTAM))
                {
                    printf("\nMascotas cargadas con exito.");
                }
                else
                {
                    printf("\nERROR - Las mascotas no han sido cargadas.");
                }
                break;
            case 2:
                if(!modificarMascota(mascotasLista,MASCOTASTAM,&idMascotaActual,tiposMascotasLista,TIPOSTAM,coloresMascotasLista,COLORESTAM,clientesLista,CLIENTESTAM))
                {
                    printf("\nMascotas modificadas con exito.");
                }
                else
                {
                    printf("\nERROR - Las mascotas no fueron modificadas.");
                }
                break;
            case 3:
                if(!bajaMascota(mascotasLista,MASCOTASTAM,tiposMascotasLista,TIPOSTAM,coloresMascotasLista,COLORESTAM,clientesLista,CLIENTESTAM))
                {
                    printf("\nLas bajas han sido realizadas con exito.");
                }
                else
                {
                    printf("\nERROR - Bajas no realizadas.");
                }
                break;
            case 4:
                if(!mostrarMascotas(mascotasLista,MASCOTASTAM,tiposMascotasLista,TIPOSTAM,coloresMascotasLista,COLORESTAM,clientesLista,CLIENTESTAM))
                {
                    printf("\nListado de Mascotas cargado con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas para mostrar.\n");
                }
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
                if(!agregarTrabajo(trabajosLista,TRABAJOSTAM,&idTrabajoActual,mascotasLista,MASCOTASTAM,serviciosMascotasLista,SERVICIOSTAM,tiposMascotasLista,TIPOSTAM,coloresMascotasLista,COLORESTAM,clientesLista,CLIENTESTAM))
                {
                    printf("\nTrabajo agregado con exito.");
                }
                else
                {
                    printf("\nERROR - Carga del trabajo no realizada.");
                }
                break;
            case 9:
                if(!mostrarTrabajos(trabajosLista,TRABAJOSTAM,mascotasLista,MASCOTASTAM,serviciosMascotasLista,SERVICIOSTAM))
                {
                    printf("\nTrabajos mostrados con exito.");
                }
                else
                {
                    printf("\nERROR - No se pudo mostrar los trabajos.");
                }
                break;
            case 10:
                if(!mostrarMascotasPorColor(mascotasLista,MASCOTASTAM,tiposMascotasLista,TIPOSTAM,coloresMascotasLista,COLORESTAM,clientesLista,CLIENTESTAM))
                {
                    printf("\nMascotas por color mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - Falla al mostrar las mascotas por color.");
                }
                break;
           case 11:
                if(!mostrarMascotasPorTipo(mascotasLista,MASCOTASTAM,tiposMascotasLista,TIPOSTAM,coloresMascotasLista,COLORESTAM,clientesLista,CLIENTESTAM))
                {
                    printf("\nMascotas por tipo mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - Falla al mostrar las mascotas por tipo.");
                }
               break;
           case 12:
                if(!mostrarMascotaDeMenorEdad(mascotasLista,MASCOTASTAM))
                {
                   printf("\nInforme realizado.");
                }
                else
                {
                    printf("\nERROR - Informe no realizado.");
                }
            case 13:
                if(!getDosChar("\nDesea salir del programa?(S para afirmar, N para negar)","\nERROR - Re-ingrese una opcion",'n','s'))
                {
                    menuSalida='n';
                }
                else
                {
                    menuSalida='s';
                }
                break;
            }
        }
    }while(menuSalida!='s');
}
