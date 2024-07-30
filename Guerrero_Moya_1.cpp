#include <iostream>

using namespace std;

enum opciones{
    Opc_Salir,
    Opc_Agregar,
    Opc_Consultar,
    Opc_Buscar
};

union UnidadMedida{
    float litros;
    float kilos;
    int gramos;
    int piezas;
};

struct Producto{
    string nombre;
    int existencia;
    UnidadMedida UnidadDeMedida;
    int TipoUnidadDeMedida;
    float precio;
};

enum unidad{
    U_Litro,
    U_Kilos,
    U_Gramos,
    U_Piezas
};
const int Lim_Productos = 25;
Producto productos[Lim_Productos];
int contadorProductos;

void Agregar(Producto &p){
    cout<<"Dame el nombre del producto: ";
    getline(cin,p.nombre);
    cout<<"Cuantos hay en existencia en esta tienda?: ";
    cin>>p.existencia;
    cout<<"Dame el precio del producto(en mxn): ";
    cin>>p.precio;
    do{
            cout<<"En que tipo de unidad de medida registrara?"<<endl
                 <<U_Litro<<".- Litro"<<endl
                  <<U_Kilos<<".- Kilos"<<endl
                   <<U_Gramos<<".- Gramos"<<endl
                    <<U_Piezas<<".- Piezas"<<endl;
            cin>>p.TipoUnidadDeMedida;
    }while(p.TipoUnidadDeMedida<U_Litro || p.TipoUnidadDeMedida>U_Piezas);
    if(p.TipoUnidadDeMedida==U_Litro){
        cout<<"Unidad en litros: ";
        cin>>p.UnidadDeMedida.litros;
    }if(p.TipoUnidadDeMedida==U_Kilos){
        cout<<"Unidad en kilos: ";
        cin>>p.UnidadDeMedida.kilos;
    }if(p.TipoUnidadDeMedida==U_Gramos){
        cout<<"Unidad en gramos: ";
        cin>>p.UnidadDeMedida.gramos;
    }if(p.TipoUnidadDeMedida==U_Piezas){
        cout<<"Unidad en piezas: ";
        cin>>p.UnidadDeMedida.piezas;
    }
}

void Consultar(Producto p){
    cout<<"\nNombre del producto: "<<p.nombre<<endl
         <<"En Existencia: "<<p.existencia<<endl
          <<"Precio(mxn): "<<p.precio<<endl;
    if(p.TipoUnidadDeMedida==U_Litro){
        cout<<"Unidad de Medida: "<<p.UnidadDeMedida.litros<<" Litros"<<endl;
    }if(p.TipoUnidadDeMedida==U_Kilos){
        cout<<"Unidad de Medida: "<<p.UnidadDeMedida.kilos<<" Kilos"<<endl;
    }if(p.TipoUnidadDeMedida==U_Gramos){
        cout<<"Unidad de Medida: "<<p.UnidadDeMedida.gramos<<" Gramos"<<endl;
    }if(p.TipoUnidadDeMedida==U_Piezas){
        cout<<"Unidad de Medida: "<<p.UnidadDeMedida.piezas<<" Piezas"<<endl;
    }
}

void Buscar(){
    string busqueda;
    int productoEncontrado=0;
    cout<<"Inserte el Nombre para buscarlo: "<<endl;
    getline(cin, busqueda);
        for(int i=0;i<contadorProductos;++i){
            if(productos[i].nombre.find(busqueda, 0) < productos[i].nombre.size()){
                Consultar(productos[i]);
                ++productoEncontrado;
            }
        }if(productoEncontrado==0){
            cout<<"No hay productos con ese nombre"<<endl;
        }
}
int main(){
    int opcion;
    do{
        cout<<"\n            Tienda de Abarrotes"<<endl
             <<Opc_Agregar<<".- Agregar Producto"<<endl
              <<Opc_Consultar<<".- Consultar Producto"<<endl
               <<Opc_Buscar<<".- Buscar Producto"<<endl
                <<Opc_Salir<<".- Salir del Interfaz"<<endl
                 <<"Elige una opcion: ";
        cin>>opcion;
        cin.ignore();
        switch(opcion){
            case Opc_Agregar: cout<<"\nAgrega el Producto:\n"<<endl;
                if(contadorProductos<Lim_Productos){
                    Agregar(productos[contadorProductos]);
                    contadorProductos++;
                }else{
                    cout<<"Ya no se pueden permitir mas productos"<<endl;
                }break;
            case Opc_Consultar: cout<<"\nConsultar productos: ("<<contadorProductos<<")"<<endl;
                if(contadorProductos>0){
                    for(int i=0;i<contadorProductos;++i){
                        Consultar(productos[i]);
                    }
                }else{
                    cout<<"\nNo hay productos registrados"<<endl;
                }break;
            case Opc_Buscar: cout<<"\nBuscar producto:"<<endl;
                if(contadorProductos>0){
                    Buscar();
                }else{
                    cout<<"\nNo hay productos registrados"<<endl;
                }break;
            case Opc_Salir: cout<<"\nSaliendo..."<<endl;
                break;
            default: cout<<"\nOpcion no valida"<<endl;
        }
    }while(opcion!=Opc_Salir);
}
