#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombreCliente[51];
    char sexo;
}eCliente;

int initClientes(eCliente clientes[],int tam);
int mostrarCliente(eCliente cliente);
int mostrarClientes(eCliente clientes[],int tam);

#endif // CLIENTE_H_INCLUDED
