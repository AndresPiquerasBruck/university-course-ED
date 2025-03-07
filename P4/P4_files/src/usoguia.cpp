#include "guiatlf.h"
#include <fstream>
int main(int argc , char * argv[]){
  if (argc!=2){
      cout<<"Dime el nombre del fichero con la guia"<<endl;
      return 0;
  }
  ifstream f(argv[1]);
  if (!f){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }
  
 Guia_Tlf g, g2;

 g2.insert("Amadeo de Saboya","2345345432");
 g2.insert("Simon Bolivar Carrion", "444444444");
 
 f>>g;
 cout<<"La guia insertada "<<g<<endl;
 cin.clear();
 cout<<"Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 string n;
 while (getline(cin,n)){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   string tlf = g.gettelefono(n);
	   if (tlf==""){
		     cout<<"No existe ese nombre en la guia"<<endl;
	   }
	   else 
	    cout<<"El telefono es: "<<tlf<<endl;
	   cout<<"[Pulse CTRL+D para finalizar] Dime un nombre sobre el que quieres obtener el telefono"<<endl;
 }


    cout<<"\n////////////////////////////////////////";	
    cout<<"\nPrueba de busqueda por inicial";
    cout<<"\n////////////////////////////////////////\n";	

    string inicial = "F";

    Guia_Tlf tlf = g.gettelefonoinicial(inicial);
    cout<<"\nEmpiezan por "<<inicial<<" los siguientes telefonos:\n";

    cout << tlf;
    cout << "\n";

    cout<<"\n////////////////////////////////////////";	
    cout<<"\nPrueba de lista entre A y H";
    cout<<"\n////////////////////////////////////////\n";	

    char minimo = 'A';
    char maximo = 'H';
    Guia_Tlf entre = g.listaentre(minimo,maximo);

    cout << entre;

    cout<<"\n////////////////////////////////////////";	
    cout<<"\nPrueba de asignacion";
    cout<<"\n////////////////////////////////////////\n";	

    g.modifica_num("Laureano Cruz Sol", "456345654756756");

 cout<<"\nListando la guia con iteradores:"<<endl;
 Guia_Tlf::iterator it;
 for (it=g.begin(); it!=g.end(); ++it)
     cout<<*it<<endl;

}
