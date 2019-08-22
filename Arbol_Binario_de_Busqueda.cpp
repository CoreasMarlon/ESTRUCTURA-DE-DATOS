//PROGRAMADO POR MARLON SALOMON COREAS VILLANUEVA, CARNET: CV18035
//ESTRUCTURA DE DATOS
//ARBOL BINARIO DE BUSQUEDA

#include <iostream>
#include <cstdlib>

using namespace std;

void menu();
int nn = 0;//contador de nodos en el arbol
int acum;

typedef class ArboldeBusqueda *ABB;
class ArboldeBusqueda
{
private:
    int nro;
    ArboldeBusqueda *izq, *der;

public:
    ABB crearNodo(int x)
    {
         ABB nuevoNodo = new(class ArboldeBusqueda);
         nuevoNodo->nro = x;
         nuevoNodo->izq = NULL;
         nuevoNodo->der = NULL;
         nn++;

         return nuevoNodo;
    }

    void insertar(ABB &arbol, int x)
    {
         if(arbol==NULL)
         {
               arbol = crearNodo(x);
         }
         else if(x < arbol->nro)
              insertar(arbol->izq, x);
         else if(x > arbol->nro)
              insertar(arbol->der, x);
    }

    void preOrden(ABB arbol)
    {
         if(arbol!=NULL)
         {
              cout << arbol->nro <<" ";
              preOrden(arbol->izq);
              preOrden(arbol->der);
         }
    }

    void inOrden(ABB arbol)
    {
         if(arbol!=NULL)
         {
              inOrden(arbol->izq);
              cout << arbol->nro << " ";
              inOrden(arbol->der);
         }
    }

    void postOrden(ABB arbol)
    {
         if(arbol!=NULL)
         {
              postOrden(arbol->izq);
              postOrden(arbol->der);
              cout << arbol->nro << " ";
         }
    }

int altura(ABB arbol)
    {
        int AltIzq, AltDer;

        if(arbol==NULL)
            return -1;
        else
        {
            AltIzq = altura(arbol->izq);
            AltDer = altura(arbol->der);

            if(AltIzq>AltDer)
                return AltIzq+1;
            else
                return AltDer+1;
        }
    }

    void verArbol(ABB arbol, int n)
    {
         if(arbol==NULL)
              return;
         verArbol(arbol->der, n+1);

         for(int i=0; i<n; i++)
             cout<<"   ";

         cout<< arbol->nro <<endl;

         verArbol(arbol->izq, n+1);
    }

    void suma(ABB arbol)
    {
         if(arbol!=NULL)
         {
              suma(arbol->izq);
              suma(arbol->der);
              acum = acum + arbol->nro;
         }
    }
};

int main()
{
    ArboldeBusqueda *arb = new ArboldeBusqueda;
    ABB arbol = NULL;

    int opc;//Opcion del menu
    int n;//numero de nodos a incertar
    int x;//valor de los nodos

    do
    {
        n = 0;
        menu();
        cin>>opc;
        switch(opc)
        {
        case 1:
            {
                system("cls");
                cout << " NUMERO DE NODOS A INGRESAR:  ";
                cin >> n;
                cout << endl;

                for(int i=0; i<n; i++)
                {
                    cout << "VALOR DEL NODO: " << nn + 1 << ": ";
                    cin >> x;
                    arb->insertar(arbol, x);
                }

                cout<<"Enter para volver al menu";
                system("pause>arch2");
            }
            break;
        case 2:
            {
                system("cls");
                cout << "\n MOSTRANDO ABB \n\n";
                arb->verArbol(arbol, x);

                acum = 0;
                int h;
                h = arb->altura(arbol);
                arb->suma(arbol);
                cout<<"ALTURA: "<<h<<endl;
                cout<<"SUMA DE TODAS LAS CLAVES DEL ARBOL: "<<acum<<endl;
                cout << "\n RECORRIDOS DEL ARBOL";

                cout << "\n\n INORDEN   :  ";   arb->inOrden(arbol);
                cout << "\n\n PREORDEN  :  ";   arb->preOrden(arbol);
                cout << "\n\n POSTORDEN :  ";   arb->postOrden(arbol);

                cout << endl << endl;
                cout<<"Enter para volver al menu";
                system("pause>arch2");
            }
            break;
        case 3:
            {
                exit(0);
            }
        }
    }while(true);
    return 0;
}

void menu()
{
    system("cls");
    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
    cout<<"\n\tNODOS ACTUALES DEL ARBOL "<<nn<<endl;
    cout<<"\n\t  1.  INGRESAR NODOS"<<endl;
    cout<<"\n\t  2.  VER ARBOL Y DETALLES"<<endl;
    cout<<"\n\t  3.  SALIR"<<endl;
}
