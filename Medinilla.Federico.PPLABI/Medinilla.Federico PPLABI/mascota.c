#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"
#include "mascota.h"
#include "tipoMascota.h"
#include "colorMascota.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

#define VACIO 1
#define OCUPADO 0


int initMascotas(eMascota mascotas[],int tam)
{
    int error=1;

	if(mascotas!=NULL&&tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			mascotas[i].isEmpty=VACIO;
		}
		error=0;
	}
	return error;
}
void ordernarMascotasxID(eMascota mascotas[],int tam)
{
    eMascota auxMascota;

    if(mascotas!=NULL && tam>0)
    {
        for (int i=0;i<tam-1;i++)
        {
            for(int x=i+1;x<tam;x++)
            {
                if(mascotas[i].id>mascotas[x].id)
                {
                    auxMascota=mascotas[i];
                    mascotas[i]=mascotas[x];
                    mascotas[x]=auxMascota;
                }
            }
        }
    }
}
void mostrarMascota(eMascota mascota,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam)
{
    if(!cargarDescripcionTipo(mascota.idTipo,tipos,tiposTam,tipos->descripcion)
       && !cargarNombreColor(mascota.idColor,colores,coloresTam,colores->nombreColor)
       && !cargarNombreCliente(mascota.idCliente,clientes,clientesTam,clientes->nombreCliente))
    {
        printf("\n|ID: %d|  %s  %s  %s  %s  %d ",mascota.id,clientes->nombreCliente,mascota.nombreMascota,tipos->descripcion,colores->nombreColor,mascota.edad);
        printf("\n---------------------------------\n");
    }
}
int mostrarMascotas(eMascota mascotas[],int tam, eTipoMascota tipos[],int tiposTam, eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam)
{
    int error=0;
    int flag=1;

    ordernarMascotasxID(mascotas,tam);
    if(mascotas!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(mascotas[i].isEmpty==0)
            {
                mostrarMascota(mascotas[i],tipos,tiposTam,colores,coloresTam,clientes,clientesTam);
                flag=0;
            }
        }
    }
    if(flag==1)
    {
        error=1;
    }
    return error;
}
int mostrarMascotasPorColor(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam)
{
    int error=1;
    int menuOpcion;
    char menuSalida;

    do
    {
        if(!getNumero(&menuOpcion,
                "\n1) Negro(5000)"
                "\n2) Blanco(5001)"
                "\n3) Gris(5002)"
                "\n4) Rojo(5003)"
                "\n5) Azul(5004)"
                "\n6) Salir",
                "\nERROR - Re-ingrese una opcion.",1,6))
        {
            switch(menuOpcion)
            {
            case 1:
                if(!buscarMascotaPorColor(mascotas,tam,tipos,tiposTam,colores,coloresTam,5000,clientes,clientesTam))
                {
                    printf("\nMascotas del color NEGRO mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese color.");
                }
                break;
            case 2:
                if(!buscarMascotaPorColor(mascotas,tam,tipos,tiposTam,colores,coloresTam,5001,clientes,clientesTam))
                {
                    printf("\nMascotas del color BLANCO mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese color.");
                }
                break;
            case 3:
                if(!buscarMascotaPorColor(mascotas,tam,tipos,tiposTam,colores,coloresTam,5002,clientes,clientesTam))
                {
                    printf("\nMascotas del color GRIS mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese color.");
                }
                break;
            case 4:
                if(!buscarMascotaPorColor(mascotas,tam,tipos,tiposTam,colores,coloresTam,5003,clientes,clientesTam))
                {
                    printf("\nMascotas del color ROJO mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese color.");
                }
                break;
            case 5:
                if(!buscarMascotaPorColor(mascotas,tam,tipos,tiposTam,colores,coloresTam,5004,clientes,clientesTam))
                {
                    printf("\nMascotas del color AZUL mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese color.");
                }
                break;
            case 6:
                if(getDosChar("\nDesea volver al menu anterior?(S para confirmar, N para negar): ","\nERROR - Re-ingrese su eleccion.",'n','s')==0)
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

    return error;
}
int buscarMascotaPorColor(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,int id, eCliente clientes[],int clientesTam)
{
    int error=1;

    if(mascotas!=NULL && tam>0 && colores!=NULL && coloresTam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(mascotas[i].idColor==id && mascotas[i].isEmpty==OCUPADO)
            {
                mostrarMascota(mascotas[i],tipos,tiposTam,colores,coloresTam,clientes,clientesTam);
                error=0;
            }
        }
    }
    return error;
}
int mostrarMascotasPorTipo(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam)
{
    int error=1;
    int menuOpcion;
    char menuSalida;

    do
    {
        if(!getNumero(&menuOpcion,
                "\n1) Aves(1000)"
                "\n2) Perros(1001)"
                "\n3) Gatos(1002)"
                "\n4) Roedores(1003)"
                "\n5) Peces(1004)"
                "\n6) Salir",
                "\nERROR - Re-ingrese una opcion.",1,6))
        {
            switch(menuOpcion)
            {
            case 1:
                if(!buscarMascotasPorTipo(mascotas,tam,tipos,tiposTam,colores,coloresTam,1000,clientes,clientesTam))
                {
                    printf("\nMascotas del tipo AVE mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese tipo.");
                }
                break;
            case 2:
                if(!buscarMascotasPorTipo(mascotas,tam,tipos,tiposTam,colores,coloresTam,1001,clientes,clientesTam))
                {
                    printf("\nMascotas del tipo PERRO mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese tipo.");
                }
                break;
            case 3:
                if(!buscarMascotasPorTipo(mascotas,tam,tipos,tiposTam,colores,coloresTam,1002,clientes,clientesTam))
                {
                    printf("\nMascotas del tipoGATO mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese tipo.");
                }
                break;
            case 4:
                if(!buscarMascotasPorTipo(mascotas,tam,tipos,tiposTam,colores,coloresTam,1003,clientes,clientesTam))
                {
                    printf("\nMascotas del tipo ROEDOR mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese tipo.");
                }
                break;
            case 5:
                if(!buscarMascotasPorTipo(mascotas,tam,tipos,tiposTam,colores,coloresTam,1004,clientes,clientesTam))
                {
                    printf("\nMascotas del tipo PEZ mostradas con exito.");
                }
                else
                {
                    printf("\nERROR - No hay mascotas de ese tipo.");
                }
                break;
            case 6:
                if(getDosChar("\nDesea volver al menu anterior?(S para confirmar, N para negar): ","\nERROR - Re-ingrese su eleccion.",'n','s')==0)
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

    return error;
}
int buscarMascotasPorTipo(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,int id, eCliente clientes[],int clientesTam)
{
    int error=1;

    if(mascotas!=NULL && tam>0 && tipos!=NULL && tiposTam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(mascotas[i].idTipo==id && mascotas[i].isEmpty==OCUPADO)
            {
                mostrarMascota(mascotas[i],tipos,tiposTam,colores,coloresTam,clientes,clientesTam);
                error=0;
            }
        }
    }
    return error;
}
int getEmptyIndex(eMascota mascotas[],int tam)
{
	int indiceVacio=-1;

	if(mascotas!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(mascotas[i].isEmpty==VACIO)
			{
				indiceVacio=i;
				break;
			}
		}
	}
	return indiceVacio;
}
int agregarMascota(eMascota mascotas[],int tam, int* idMascota,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam)
{
    int error=1;
    char salida;

    int indiceVacio;
    eMascota auxiliar;

    if(mascotas!=NULL && tam>0 && idMascota>0)
    {
        while(salida!='s')
        {
            indiceVacio=getEmptyIndex(mascotas,tam);
            if(mostrarClientes(clientes,tam)==0
               && getNumero(&auxiliar.idCliente,"\nA que cliente se lo quiere agregar?","ERROR - Re-ingrese el ID del cliente.",300,304)==0
               && getNombre(auxiliar.nombreMascota,"\nIngrese el nombre: ","\nERROR - Re-ingrese el nombre.",51)==0
               && mostrarTipos(tipos,tam)==0
               && getNumero(&auxiliar.idTipo,"\nIngrese el ID del TIPO(1000-1004): ","\nERROR - Re-ingrese el ID del TIPO.",1000,1004)==0
               && mostrarColores(colores,tam)==0
               && getNumero(&auxiliar.idColor,"\nIngrese el ID del COLOR(5000-5004): ","\nERROR - Re-ingrese el ID del COLOR.",5000,5004)==0
               && getNumero(&auxiliar.edad,"\nIngrese la EDAD(1-99): ","\nERROR - Re-ingrese la EDAD.",1,99)==0)
            {
                auxiliar.id=*idMascota;
                printf("\nEsta es la mascota que quiere agregar?\n");
                mostrarMascota(auxiliar,tipos,tiposTam,colores,coloresTam,clientes,clientesTam);
                if(getDosChar("\nIngrese S para confirmar, o N para negar: ","\nERROR - Re-ingrese su eleccion.",'s','n')==0)
                {
                    auxiliar.isEmpty=OCUPADO;
                    mascotas[indiceVacio]=auxiliar;
                    mascotas[indiceVacio].id=*idMascota;
                    (*idMascota)++;

                    error=0;
                    printf("\nCarga realizada con exito.");
                }
                else
                {
                    error=1;
                    printf("\nCarga cancelada.");
                }
            }
            if(getDosChar("\nDesea agregar otro?(S para confirmar, N para negar): ","\nERROR - Re-ingrese su eleccion.",'n','s')==0)
            {
                salida='s';
            }
            else
            {
                salida='n';
            }
        }
    }
    return error;
}
int modificarMascota(eMascota mascotas[],int tam, int* idMascota,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam)
{
    int error=1;
    char salida;
    char salidaMiniMenu;

    int idParaEditar=-1;
    int indiceParaEditar=-1;

    eMascota auxiliar;
    eMascota auxiliares[tam];
    auxiliares[tam]=mascotas[tam];

    if(mascotas!=NULL && tam>0 && idMascota>0)
    {
        while(salida!='s')
        {
            if(!mostrarMascotas(mascotas,tam,tipos,tiposTam,colores,coloresTam,clientes,clientesTam)
                &&!getNumero(&idParaEditar,"\nIngrese el ID de la mascota que quiere modificar: ","\nERROR - Ese ID no existe.",100,200))
            {
                indiceParaEditar=buscarxID(mascotas,tam,idParaEditar);
                printf("\nEsta es la mascota que desea modificar?: \n");
                mostrarMascota(mascotas[indiceParaEditar],tipos,tiposTam,colores,coloresTam,clientes,clientesTam);

                if(getDosChar("\nIngrese S para confirmar, o N para negar: ","\nERROR - Re-ingrese su eleccion.",'s','n')==0)
                {
                    printf("\nElija que campo desea modificar:\n");
                }
                else
                {
                    printf("\nModifiacion cancelada.");
                    break;
                }

                while(salidaMiniMenu!='s')
                {
                    switch(mostrarMenuParaModificar())
                    {
                    case 1:
                        if(!getNombre(auxiliares[indiceParaEditar].nombreMascota,"\nIngrese el nombre: ","\nERROR - Re-ingrese el nombre.",21))
                        {
                            printf("\nLa modificacion fue realizada con exito: \n");
                            strcpy(mascotas[indiceParaEditar].nombreMascota,auxiliares[indiceParaEditar].nombreMascota);
                            mostrarMascota(mascotas[indiceParaEditar],tipos,tiposTam,colores,coloresTam,clientes,clientesTam);
                        }
                        break;
                    case 2:
                        if(!getNumero(&auxiliar.idTipo,"\nIngrese el ID del TIPO(1000-1004): ","\nERROR - Re-ingrese el ID del TIPO.",1000,1004))
                        {
                            printf("\nLa modificacion fue realizada con exito: \n");
                            mascotas[indiceParaEditar].idTipo=auxiliar.idTipo;
                            mostrarMascota(mascotas[indiceParaEditar],tipos,tiposTam,colores,coloresTam,clientes,clientesTam);
                        }
                        break;
                    case 3:
                        if(!getNumero(&auxiliar.idColor,"\nIngrese el ID del COLOR(5000-5004): ","\nERROR - Re-ingrese el ID del COLOR.",5000,5004))
                        {
                            printf("\nLa modificacion fue realizada con exito: \n");
                            mascotas[indiceParaEditar].idColor=auxiliar.idColor;
                            mostrarMascota(mascotas[indiceParaEditar],tipos,tiposTam,colores,coloresTam,clientes,clientesTam);
                        }
                        break;
                    case 4:
                        if(!getNumero(&auxiliar.edad,"\nIngrese la EDAD: ","\nERROR - Re-ingrese la EDAD",1,99))
                        {
                            printf("\nLa modificacion fue realizada con exito: \n");
                            mascotas[indiceParaEditar].edad=auxiliar.edad;
                            mostrarMascota(mascotas[indiceParaEditar],tipos,tiposTam,colores,coloresTam,clientes,clientesTam);
                        }
                        break;
                    case 5:
                        if(getDosChar("\nDesea volver al menu anterior?(S para confirmar, N para negar): ","\nERROR - Re-ingrese su eleccion.",'n','s')==0)
                        {
                            salidaMiniMenu='n';
                        }
                        else
                        {
                            salidaMiniMenu='s';
                        }
                        break;
                    }
                }
            }
            else
            {
                printf("\nERROR - No hay mascotas para modificar.\n");
                break;
            }
            if(getDosChar("\nDesea modificar otra mascota?(S para confirmar, N para negar): ","\nERROR - Re-ingrese su eleccion.",'n','s')==0)
            {
                salida='s';
            }
            else
            {
                salida='n';
            }
        }
    }
    return error;
}
int bajaMascota(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam)
{
    int error=1;
    int idParaBorrar=-1;
    int indiceParaBorrar=-1;
    char salida;

    if(mascotas!=NULL && tipos!=NULL && colores!=NULL)
    {
        while(salida!='s')
        {
            if(!mostrarMascotas(mascotas,tam,tipos,tiposTam,colores,coloresTam,clientes,clientesTam)
                &&!getNumero(&idParaBorrar,"\nIngrese el ID de la mascota a borrar: ","\nERROR - Ese ID no existe.",100,200))
            {
                indiceParaBorrar=buscarxID(mascotas,tam,idParaBorrar);
                printf("\nEsta es la mascota que desea dar de baja?: \n");
                mostrarMascota(mascotas[indiceParaBorrar],tipos,tiposTam,colores,coloresTam,clientes,clientesTam);

                if(getDosChar("\nIngrese S para confirmar, o N para negar: ","\nERROR - Re-ingrese su eleccion.",'s','n')==0)
                {
                    printf("\nBaja realizada con exito.");
                    mascotas[indiceParaBorrar].isEmpty=VACIO;
                }
                else
                {
                    printf("\nBaja cancelada.");
                }
            }
            else
            {
                printf("\nERROR - No hay mascotas cargadas para dar de baja.\n");
                break;
            }
            if(getDosChar("\nDesea eliminar otro?(S para confirmar, N para negar): ","\nERROR - Re-ingrese su eleccion.",'n','s')==0)
            {
                salida='s';
            }
            else
            {
                salida='n';
            }
        }
    }

    return error;
}
int cargarDescripcionTipo(int id,eTipoMascota tipos[],int tam, char descripcion[])
{
    int error=1;

    if(id>=1000 && id<=1004 && tipos!=NULL && tam>0 && descripcion!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(tipos[i].id==id)
            {
                strcpy(descripcion,tipos[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}
int cargarNombreColor(int id,eColorMascota colores[],int tam, char nombreColor[])
{
    int error=1;

    if(id>=5000 && id<=5004 && colores!=NULL && tam>0 && nombreColor!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(colores[i].id==id)
            {
                strcpy(nombreColor,colores[i].nombreColor);
                error=0;
                break;
            }
        }
    }
    return error;
}
int cargarNombreCliente(int id,eCliente clientes[],int tam, char nombreCliente[])
{
    int error=1;

    if(id>=300 && id<=304 && clientes!=NULL && tam>0 && nombreCliente!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(clientes[i].id==id)
            {
                strcpy(nombreCliente,clientes[i].nombreCliente);
                error=0;
                break;
            }
        }
    }
    return error;
}
int buscarxID(eMascota mascotas[],int tam,int idBuscado)
{
    int indiceBuscado=-1;

    if(mascotas!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(mascotas[i].id==idBuscado)
            {
                indiceBuscado=i;
                break;
            }
        }
    }

    return indiceBuscado;
}
int mostrarMenuParaModificar()
{
    int menuOpcion;

    if(!getNumero(&menuOpcion,
        "\n1) Modificar el Nombre."
        "\n2) Modificar el Tipo."
        "\n3) Modificar el Color."
        "\n4) Modificar la Edad."
        "\n5) Volver al menu anterior.\n"
        "\nIngrese una opcion: "
        ,"\nERROR - Opcion invalida.",1,5))
    {
        printf("\nMenu de modificaciones cargado con exito.");
    }
    else
    {
        printf("\nERROR al cargar el menu de modificaciones cargado con exito.");
    }

    return menuOpcion;
}
int mostrarMascotaDeMenorEdad(eMascota mascotas[],int tam)
{
    int error=1;
    int flag=1;
    int menorEdad=0;
    int mascotaDeMenorEdadIndice;

    if(mascotas!=NULL && tam>0 && mascotas[0].isEmpty==OCUPADO)
    {
        for(int i=0;i<tam;i++)
        {
            if(flag==1 && mascotas[i].isEmpty==OCUPADO)
            {
                menorEdad=mascotas[i].edad;
                mascotaDeMenorEdadIndice=i;
                flag=0;
            }
            else if(mascotas[i].edad<menorEdad && mascotas[i].isEmpty==OCUPADO)
            {
                mascotaDeMenorEdadIndice=i;
                menorEdad=mascotas[i].edad;
            }
        }
        printf("\nLa mascota de menor edad es %s con %d anios",mascotas[mascotaDeMenorEdadIndice].nombreMascota,menorEdad);
        error=0;
    }

    return error;
}

