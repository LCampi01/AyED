#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define VACIO 0
#define TAM 10000

using namespace std;


struct Tarjeta
{
  int TarjetaID[3] = {0,0,0};
  int FechaCreacion;
  bool  activa = false;
  float Saldo=0;
  int Nrocliente;
};

struct Movimientos
{
int MovimientoID;
int Fecha;
float Monto;
int TarjetaID;
};

void menu()
{
  cout << "a-A Cargar nueva cuenta" << endl;
  cout << "b-B Activar/Desactivar cuenta " << endl;
  cout << "c-C Buscar cuenta - ID o Nro de cliente " << endl;
  cout << "d-D Ordenar cuentas por saldo descendente" << endl;
  cout << "e-E Transferir lote de movimientos" << endl;
  cout << "f-F Finalizar y guardar" << endl;
}

void inicializar(Tarjeta clientes[])
{
  for(int i = 0; i < TAM; i++)
  {
    clientes[i].Nrocliente = VACIO;
  }
}

int sigpos(Tarjeta clientes[])
{
  int posvacia;
  for (int i = 0; i < TAM; i++)
  {
    if(clientes[i].Nrocliente == VACIO)
    {
      posvacia = i;
      return posvacia;
    }
    i++;
  }
  posvacia = -1;
  return posvacia;
}

void ordenarSaldo( Tarjeta clientes[] )
{
   Tarjeta aux;
for (int i=0; i < TAM -1 ; i++ )
  {
    for (int j = 0; j < TAM - i - 1;j++)
    {
      if (clientes[j].Saldo < clientes[j+1].Saldo)
      {
        aux = clientes[j];
        clientes[j]= clientes[j+1];
        clientes[j+1]= aux;
      }
    }
  }
}

void ordenarCuenta (Tarjeta clientes[])
{
  Tarjeta aux;
for (int i=0; i < TAM -1 ; i++ )
  {
    for (int j = 0; j < TAM - i - 1;j++)
    {
      if (clientes[j+1].Nrocliente< clientes[j].Nrocliente)
      {
        aux = clientes[j];
        clientes[j]= clientes[j+1];
        clientes[j+1]= aux;
      }
    }
  }
}

void ordenarTarjeta(Tarjeta clientes[], int k)
{
      Tarjeta aux;
for (int i=0; i < TAM -1 ; i++ )
  {
    for (int j = 0; j < TAM - i - 1;j++)
    {
      if (clientes[j+1].TarjetaID[k]< clientes[j].TarjetaID[k])
      {
        aux = clientes[j];
        clientes[j]= clientes[j+1];
        clientes[j+1]= aux;
      }
    }
  }
}

int postar(Tarjeta clientes[], int i, int numcl)
{
    ordenarTarjeta(clientes,i);
    int primero = 0, ultimo = TAM-1, medio;

medio = (primero+ultimo)/2;
while(primero <= ultimo)
{
  if(clientes[medio].TarjetaID[i] < numcl)
  {
    primero = medio+1;
  }
  else if(clientes[medio].TarjetaID[i] == numcl)
  {
   return medio;
  }

  else
  {
    ultimo = medio-1;
  }
  medio = (primero+ultimo)/2;
}
if(primero > ultimo)
{
    if(i!=2){
            i++;
   postar(clientes, i, numcl);
    }
  else
    cout << "No se ha encontrado el cliente" << endl;
    return -1;
}
      }

void buscatar(Tarjeta clientes[], int i, int numcl)
{
    ordenarTarjeta(clientes,i);
    int primero = 0, ultimo = TAM-1, medio;

medio = (primero+ultimo)/2;
while(primero <= ultimo)
{
  if(clientes[medio].TarjetaID[i] < numcl)
  {
    primero = medio+1;
  }
  else if(clientes[medio].TarjetaID[i] == numcl)
  {
    cout << "Se ha hallado el cliente numero: " << clientes[medio].Nrocliente << endl;
    cout << "Estado de cuenta :";
    if(clientes[medio].activa == true)
    {
      cout << " ACTIVA" << endl;
    } else
    {
      cout << " DESACTIVADA" << endl;
    }
    cout << " Saldo: $" << clientes[medio].Saldo << endl;
    cout << " Fecha de creacion: " << clientes[medio].FechaCreacion << endl;
    for(int i=0; i < 3; i++)
    {
      if ( clientes[medio].TarjetaID[i] != 0)
      cout << " Numero de tarjeta " << i+1 << ": " << clientes[medio].TarjetaID[i] << endl;
    }
	break;
  }

  else
  {
    ultimo = medio-1;
  }
  medio = (primero+ultimo)/2;
}
if(primero > ultimo)
{
    if(i!=2){
            i++;
   buscatar(clientes, i, numcl);
    }
  else
    cout << "No se ha encontrado el cliente" << endl;
    return;
}
      }

void buscarid(Tarjeta clientes[])
{
  ordenarCuenta(clientes);

  char opcionid;
  cout << "Desea buscar por Nro. de cliente o por ID de tarjeta?" << endl;
  cout << "1 - Numero de cuenta" << endl;
  cout << "2 - ID de tarjeta" << endl;

   opcionid = getch();
   system("cls");
  while(opcionid != '1' && opcionid != '2')
  {
  cout<<" Opcion incorrecta, digite otro valor: "<<endl;
  opcionid = getch();
  }

  switch(opcionid)
  {
  case '1':
      {
          int numcl, primero = 0, ultimo = TAM-1, medio;

cout << "Ingrese numero de cliente." << endl;
cin >> numcl;
cout << endl << endl;
medio = (primero+ultimo)/2;
while(primero <= ultimo)
{
  if(clientes[medio].Nrocliente < numcl)
  {
    primero = medio+1;
  }
  else if(clientes[medio].Nrocliente == numcl)
  {
    cout << "Se ha hallado el cliente numero: " << clientes[medio].Nrocliente << endl;
    cout << "Estado de cuenta :";
    if(clientes[medio].activa == true)
    {
      cout << " ACTIVA" << endl;
    } else
    {
      cout << " DESACTIVADA" << endl;
    }
    cout << " Saldo: $" << clientes[medio].Saldo << endl;
    cout << " Fecha de creacion: " << clientes[medio].FechaCreacion << endl;
    for(int i=0; i < 3; i++)
    {
      if ( clientes[medio].TarjetaID[i] != 0)
      cout << " Numero de tarjeta " << i+1 << ": " << clientes[medio].TarjetaID[i] << endl;
    }

   return;
  }

  else
  {
    ultimo = medio-1;
  }
  medio = (primero+ultimo)/2;
}
if(primero > ultimo)
{
  cout << "El cliente no ha sido encontrado." << endl;
}
      }
    break;

  case '2':
 {

 int numcl;
cout << "Ingrese el ID de tarjeta." << endl;
cin >> numcl;
cout << endl << endl;
     buscatar(clientes, 0, numcl);
 }
    break;
 }
}

void desactivacion(Tarjeta clientes[])
{
  ordenarCuenta(clientes);
  int numcl, primero = 0, ultimo = TAM-1, medio;
cout << "Ingrese numero de cliente." << endl;
cin >> numcl;
medio = (primero+ultimo)/2;
while(primero <= ultimo)
{
  if(clientes[medio].Nrocliente < numcl)
  {
    primero = medio+1;
  }
  else if(clientes[medio].Nrocliente == numcl)
  {
      if(clientes[medio].activa == false)
      {
          clientes[medio].activa = true;
          cout << "Se ha reactivado la cuenta exitosamente" << endl;
      }
      else
      {
          clientes[medio].activa = false;
    cout << "Se ha desactivado la cuenta exitosamente." << endl;
      }

    return;
  }
  else
  {
    ultimo = medio-1;
  }
  medio = (primero+ultimo)/2;
}
if(primero>ultimo)
{
  cout << "El cliente no ha sido encontrado." << endl;
}
}

void crearcuenta(Tarjeta clientes[])
{
  ordenarCuenta(clientes);
  int numcl, primero = 0, ultimo = TAM-1, medio, pb;
cout << "Ingrese numero de cliente." << endl;
cin >> numcl;
medio = (primero+ultimo)/2;
while(primero <= ultimo)
{
  if(clientes[medio].Nrocliente < numcl)
  {
    primero = medio+1;
  }
  else if(clientes[medio].Nrocliente == numcl)
  {
    srand (time(0));
      if(clientes[medio].TarjetaID[1] == 0)
      {
         clientes[medio].TarjetaID[1] = rand() % 100000;
         cout << "Numero de TarjetaID: " << clientes[medio].TarjetaID[1] << endl;
           cout <<" Su nueva cuenta a sido creada con exito: "<< endl;
           return;

      }else if(clientes[medio].TarjetaID[2] == 0)
      {
           clientes[medio].TarjetaID[2] = rand() % 100000;
           cout << "Numero de TarjetaID: " << clientes[medio].TarjetaID[2] << endl;
             cout <<" Su nueva cuenta a sido creada con exito.: "<< endl;
             return;
      }else
      {
     cout <<" La capacidad de cuentas esta completa. "<< endl;
     return;
      }

  }
  else
  {
    ultimo = medio-1;
  }
  medio = (primero+ultimo)/2;
}
if(primero>ultimo)
{
  cout << "El cliente no ha sido encontrado." << endl;
}
}

void crearcliente(Tarjeta &cuenta)//datos
{
   srand (time(0));
  cout << "***************************************" << endl;
   cout << "Ingrese fecha de creacion - AAAAMMDD: " << endl;
   cin >> cuenta.FechaCreacion;

   cuenta.activa = true;
   cout << "Ingrese el saldo del cliente: " << endl;
   cin >> cuenta.Saldo;
   cout << "El cliente ha sido creado con exito! " << endl;
   cuenta.Nrocliente = rand() % 10000;
   cuenta.TarjetaID[0] = rand() % 100000;
    cout << endl;
   cout << "Estado de cuenta del cliente ACTIVA" << endl;
   cout << endl;
   cout << "Numero de TarjetaID: " << cuenta.TarjetaID[0] << endl;
   cout << "Numero de cliente: " << cuenta.Nrocliente << endl;
   cout << "Saldo actual: " << cuenta.Saldo << endl;
   cout << "***************************************" << endl;
}


int main()
{
  Tarjeta clientes[TAM], cargadatos;
  Movimientos procesados;
  char opcion;
  int pf=0;

  inicializar(clientes);

// Levantar cuentas del archivo Cuentas.BIC .
FILE *ct;
ct = fopen("Cuentas.BIC","rb");
if(ct == NULL)
{
  cout << " No se pudo abrir el archivo" << endl;
  return 1;
}
else
{
fread(clientes,sizeof(Tarjeta),TAM,ct);
}
fclose(ct);
// Struct clientes, cargado con las cuentas.




while(int(opcion) != 102 && int(opcion) != 70)
{
menu();
opcion = getch();

switch(opcion)
{
case 'A': case 'a':
{
    system("cls");
  // Se va a crear en la variable auxiliar cargadatos el nuevo cliente
  cout << " 1 - Crear nueva cuenta para cliente existente." << endl;
  cout << " 2 - Crear cliente nuevo. " << endl;
  char opcion2;
  opcion2 = getch();
  while(opcion2 != '1' && opcion2 != '2')
  {
  cout<<" Opcion incorrecta, digite otro valor: "<<endl;
  opcion2 = getch();
  }


  switch(opcion2)
  {
    case '1':
system("cls");
    crearcuenta(clientes);//cliente ya existente

    break;

    case '2':
        system("cls");
    int posvacia = sigpos(clientes);
      if( posvacia == -1)
      {
        cout<< "Capacidad del sistema completa." <<endl;
      }
      else
      {
                crearcliente(cargadatos);
              ct = fopen("Cuentas.BIC","ab");

              if(ct == NULL)
              {
                cout << " No se pudo abrir el archivo" << endl;
                return 1;
              }
              // El nuevo cliente, que se encuentra en cargadatos, es escrito en el archivo
              fseek(ct,posvacia*sizeof(Tarjeta),SEEK_SET);
              fwrite(&cargadatos,sizeof(Tarjeta),1,ct);
              fclose(ct);

              // Guardamos el nuevo cliente en la prosición vacía del vector clientes.
              clientes[posvacia] = cargadatos;
            }
    break;
      }

        getch();
      system("cls");
  break;
}

case 'b': case 'B':
{
system("cls");
desactivacion(clientes);
getch();
system("cls");
}
break;

case 'c': case 'C':
    {
system("cls");
buscarid(clientes);
getch();
system("cls");
}
break;

case 'd': case 'D':
{
system("cls");

         ordenarSaldo(clientes);

         for ( int i = 0; i < TAM; i++)
         {
             if(clientes[i].Nrocliente != 0)
             {
                 cout << "***************-" << i+1 <<"-***************" << endl;
         cout << "Numero de cliente: " << clientes[i].Nrocliente << endl;
        cout << "Estado de cuenta: ";
         if(clientes[i].activa == true)
      {
        cout << " ACTIVA" << endl;
      } else
      {
        cout << " DESACTIVADA" << endl;
      }
         cout << "Saldo total: $" << clientes[i].Saldo << endl;
          for(int j=0; j < 3; j++)
    {
      if ( clientes[i].TarjetaID[j] != 0)
      cout << "Numero de tarjeta " << j+1 << ": " << clientes[i].TarjetaID[j] << endl;
    }
         cout << "******************************" << endl;
         cout << endl;

         if ( i>1 && i%20 == 0 )
         {
            char des;
             cout << "Desea continuar?" << endl;
             cout << "Esc - Volver al menu." << endl;
             cout << "Enter - Continuar procesando." << endl;
             des = getch();
             if ( int(des) == 27)
                break;
             else
                system("cls");

         }
             }

        }
         getch();
         system("cls");
}
    break;

case 'e': case 'E':
    {


    system("cls");
    char nombrear[15];
    int pos;
    FILE* save;
    cout << "Ingrese nombre del lote a procesar (Ej: lote1.BIC)" << endl;
    gets(nombrear);

    ct = fopen(nombrear,"rb");
    save = fopen("procesados.BIC", "ab");
    if(ct == NULL)
    {
    cout << " El lote no existe." << endl;

      getch();
         system("cls");
    break;
    }
        fread(&procesados,sizeof(Movimientos),1,ct);

    while(!feof(ct))
    {
    fread(&procesados,sizeof(Movimientos),1,ct);
    pos = postar(clientes,0,procesados.TarjetaID);
    if (clientes[pos].activa){

    cout << "******************************" << endl;
    cout << "Fecha de operacion: " << procesados.Fecha << endl;
    cout << "Numero de operacion: " << procesados.MovimientoID << endl;
    cout << "Cuenta destino: " << procesados.TarjetaID << endl;
    cout << "Saldo inicial: $" << clientes[pos].Saldo << endl;
          clientes[pos].Saldo += procesados.Monto;
    cout << "Saldo final: $" << clientes[pos].Saldo << endl;
    cout << "Valor de la operacion: $" << procesados.Monto << endl;
    cout << "******************************" << endl;
    cout << endl;
    fwrite(&procesados,sizeof(Movimientos),1,save);
    }
    else
        cout << " o el cliente " << clientes[pos].Nrocliente << " ha desactivado la cuenta" << endl;
        cout << endl;

    }
    cout << endl;
    cout << "********************************" << endl;
    cout << "Lote procesado exitosamente." << endl;
    cout << "********************************" << endl;
    fclose(save);
    fclose(ct);


      getch();
         system("cls");
    }
   break;

case 'f': case 'F':
    {

    system("cls");

     ct = fopen("Cuentas.BIC","wb");
     for(int i = 0; i < TAM; i++)
     {
        if(clientes[i].activa == true )
        {
            cargadatos = clientes[i];
            fwrite(&cargadatos,sizeof(Tarjeta),1,ct);
        }

     }

     fclose(ct);
            cout << "El programa ha guardado y finalizado correctamente. " << endl;

    getch();
     system("cls");
    }
 break;
}

system("cls");
}
  return 0;
}
