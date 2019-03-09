#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h> 
#include <fstream>
#include <windows.h>

using namespace std;

//alumnos
struct alu{
	char carnet [10];
	char nombre [12];
	char dir[11];
	char tel[9];	
	alu*ala;
};
alu * al=NULL;

struct cursos {
	char codigo[10];
		char nombrec[10];
	cursos*curso;
};
cursos*raizcur=NULL;	

struct asignacion {
	char codigooo[10];
	char carnettt[10];
	char fecha[10];
	asignacion*asigna;
};
asignacion*raizasig=NULL;	
	
	struct errores{
		char error[80];
		errores*siguienteerr;
	};
errores*raizerror=NULL;
	

void operacion(){
		system ("cls");
	errores*a;
	a=raizerror;
	while(a!=0){
		cout<<"LISTADO DE DATOS DE ERRORES"<<endl;
		cout<<"operaciones no permitidas : "<<a->error<<endl;	 
	a=a->siguienteerr;
	}
	 system("pause");	
}

	
	
void alumno (){
	system ("cls");
		alu*nodo;
			errores*actuall;
	char car[10];
	char nom[10];
	char d[10];
	char tele[8];
	char corr[10];
	bool enco=false;
	cout<<"DATOS QUE DESEA INGRESAR"<<endl;
	cout<<"ingrese el carnet"<<endl;
	cin>> car;
	alu*actual;
	actual=al;
	while(actual!=0){
	if(strcmp(actual->carnet,car)==0){
		enco=true;
	cout << "El carnet ya existe ingrese otro" << endl;
	}
	actual=actual->ala;
			}
	if(enco!=true){
		cout<<"el carnet no se repite siga ingresando sus datos"<<endl;
			alu*nodo= new alu;
			nodo->ala=NULL;
			strcpy(nodo->carnet,car);	
			cout<<"ingrese el nombre"<<endl;
			cin>>nodo->nombre,nom;
			cout<<"ingrese la direccion"<<endl;
			cin>>nodo->dir,d;
			cout<<"ingrese el telefono"<<endl;
			cin>>nodo->tel,tele;
			nodo ->ala=al;
			al=nodo;
			}
			else{
		errores*actuall=new errores;
		actuall->siguienteerr=NULL;
	strcpy(actuall->error,"error,ya existe el carnet");
		actuall->siguienteerr=raizerror;
		raizerror=actuall;
		}	
				system("pause");		
	}
	
void lista (){
		system ("cls");
	alu*a;
	a=al;
	while(a!=0){
		cout<<"LISTADO DE DATOS"<<endl;
		cout<<"el carnet es: "<<a->carnet<<endl;
		cout<<"el nombre es: "<<a->nombre<<endl;
		cout<<"la direccion es: "<<a->dir<<endl;
		cout<<"el telefono es: "<<a->tel<<endl;
		a=a->ala;		 	
	}	
	 system("pause");	
}

void buscar (){
		system ("cls");
	alu*a=al;
	bool enco=false;
	char bus [10];
	cout<<"ingrese el dato que busca"<<endl;
	cin>>bus;
	if(al !=NULL){
			while(a!=NULL && enco !=true){
		if(strcmp(a->carnet,bus)==0){
			cout<<"dato encontrado"<< bus<<endl;
		cout<<"el carnet es: "<<a->carnet<<endl;
		cout<<"el nombre es: "<<a->nombre<<endl;
		cout<<"la direccion es: "<<a->dir<<endl;
		cout<<"el telefono es: "<<a->tel<<endl;
			enco=true;
		}
		else{
		errores*actuall=new errores;
		actuall->siguienteerr=NULL;
	strcpy(actuall->error,"busqueda de alumno no aparecida");
		actuall->siguienteerr=raizerror;
		raizerror=actuall;
		}	
		
		a=a->ala;	 	
	}
	if(!enco){
		cout<<"no esta el nodo"<<endl;
	}	
		
	}
		
	 system("pause");
}

void eliminar (){
		system ("cls");
	char bo[10];
	bool enco=false;
	cout<<"ingrese el numero de carnet que va eliminar"<<endl;
	cin>>bo;
	asignacion*actu;
	actu=raizasig;
	while(actu!=0){
		if(strcmp(actu->carnettt,bo)==0){
			enco=true;
	cout<<"el carnet ya esta asignado no se puede eliminar"<<endl;
		}		
	actu=actu->asigna;
	}
	if(enco!=true){
			alu*actual;
	actual=al;
	if(al !=NULL){
		alu*borrar;
		alu*ante=NULL;
		borrar=al;
		while((borrar!=NULL) && (strcmp(borrar->carnet,bo)!=0)){
			ante=borrar;
			borrar=borrar->ala;
		}
		
			if(borrar==NULL){
			cout<<"no se encontro el carnet"<<endl;
				errores*actuall=new errores;
		actuall->siguienteerr=NULL;
	strcpy(actuall->error,"eliminacion de alumnos no aparecida");
		actuall->siguienteerr=raizerror;
		raizerror=actuall;
			 system("pause"); 
			}
			
			
			
				else if(ante==NULL){
						al=al->ala;
						delete borrar;
						cout<<"se ha eliminado"<<endl;
							}
								else{
								ante->ala =borrar->ala;
									delete borrar;
									cout<<"se ha eliminado"<<endl;
									}									
	}
	}
 system("pause"); 	
}

//cursos

void agregarcurso (){
		system ("cls");
	cursos*nodoo;
	char codi[10];
	char nombrecur[10];
	bool enco=false;
cout<<"datos que se ingresa del curso"<<endl;
cout<<"ingrese un codigo del curso"<<endl;
cin>>codi;
cursos*actual;
actual=raizcur;
while(actual!=0){
	if(strcmp(actual->codigo,codi)==0){
		enco=true;
		cout<<"el codigo del curso ya esta registrado ingrese otro"<<endl;
	}
	actual=actual->curso;
	}
	if(enco!=true){
		cout<<"el codigo del curso no se repite"<<endl;
			cursos*nodoo= new cursos;
			nodoo->curso=NULL;
			strcpy(nodoo->codigo,codi);	
			cout<<"ingrese el nombre del curso"<<endl;
			cin>>nodoo->nombrec,nombrecur;
			nodoo ->curso=raizcur;
			raizcur=nodoo;
	}
		else{
		errores*actu=new errores;
		actu->siguienteerr=NULL;
	strcpy(actu->error,"error,ya existe el codigo del curso");
		actu->siguienteerr=raizerror;
		raizerror=actu;
		}	
	system("pause");
}

void listacurso(){
		system ("cls");
	cursos*nodo;
	nodo=raizcur;
	while(nodo!=0){
	cout<<"LISTADO DE DATOS DE CURSO"<<endl;
	cout<<"el codigo del curso es: "<<nodo->codigo<<endl;
	cout<<"el nombre del curso es: "<<nodo->nombrec<<endl;
	nodo=nodo->curso;	
	}
system("pause");
}

void busquedacurso(){
		system ("cls");
	cursos*a=raizcur;
	bool enco=false;
	char bus [10];
	cout<<"ingrese el dato que busca"<<endl;
	cin>>bus;
	if(raizcur!=NULL){
			while(a!=NULL && enco !=true){
		if(strcmp(a->codigo,bus)==0){
			cout<<"dato encontrado"<< bus<<endl;
		cout<<"el codigo del curso es: "<<a->codigo<<endl;
		cout<<"el nombre del curso es: "<<a->nombrec<<endl;
			enco=true;
		}
		else{
		errores*actuall=new errores;
		actuall->siguienteerr=NULL;
	strcpy(actuall->error,"busqueda de curso no aparecida");
		actuall->siguienteerr=raizerror;
		raizerror=actuall;
		}	
		
		a=a->curso;	 	
	}
	if(!enco){
		cout<<"no esta el nodo"<<endl;
	}	
		
	}
		
	 system("pause");
}
	
void eliminarcur(){
		system ("cls");
char busqueda[10];
bool enco=false;
	cout<<"ingrese el codigo del curso que va eliminar"<<endl;
	cin>>busqueda;
	asignacion*actu;
	actu=raizasig;
	while(actu!=0){
		if(strcmp(actu->codigooo,busqueda)==0){
			enco=true;
	cout<<"el codigo delcurso ya esta asignado no se puede eliminar"<<endl;
		}
	actu=actu->asigna;
	}
	if(enco!=true){
	if(raizcur !=NULL){
		cursos*borrar;
		cursos*ante=NULL;
		borrar=raizcur;	
		while((borrar!=NULL) && (strcmp(borrar->codigo,busqueda)!=0)){
			ante=borrar;
			borrar=borrar->curso;
		}
			if(borrar==NULL){
			cout<<"no se encontro el codigo del curso"<<endl;
			errores*actuall=new errores;
		actuall->siguienteerr=NULL;
	strcpy(actuall->error,"eliminacion de cursos no aparecida");
		actuall->siguienteerr=raizerror;
		raizerror=actuall;
	 system("pause"); 
			}
				else if(ante==NULL){
						raizcur=raizcur->curso;
						delete borrar;
						cout<<"se ha eliminado"<<endl;
							}
								else{
								ante->curso =borrar->curso;
									delete borrar;
									cout<<"se ha eliminado"<<endl;
									}	
										
		}			
	}		
}	

// ASIGNACION

void asigna (){
		system ("cls");
	asignacion*nodo; 
	nodo=raizasig;
	char carnett[10];
	char codii[10];
	char fechaa[10];
	bool carn=false;
	bool codi=false;
	bool asig=false;
cout<<"ingrese carnet del alumno que va asignar"<<endl;
cin>>carnett;
alu*actual;
	actual=al;
	while(actual!=0){
	if(strcmp(actual->carnet,carnett)==0){
	carn=true;
	cout << "El carnet si existe" << endl;
	}
		else{
		errores*actuall=new errores;
		actuall->siguienteerr=NULL;
	strcpy(actuall->error,"error,el carnet para asignar no esta");
		actuall->siguienteerr=raizerror;
		raizerror=actuall;
		}
	actual=actual->ala;
			}
			
				system("pause");		
if(carn==true){
cout<<"ingrese codigo del curso que va asignar"<<endl;
cin>>codii;
cursos*actualll;
	actualll=raizcur;
	while(actualll!=0){
	if(strcmp(actualll->codigo,codii)==0){
	codi=true;
	
	cout << "El codigo si existe puede seguir" << endl;
	}
	else{
		errores*actuall=new errores;
		actuall->siguienteerr=NULL;
	strcpy(actuall->error,"error,el codigo del curso para asignar no esta");
		actuall->siguienteerr=raizerror;
		raizerror=actuall;
		}
	actualll=actualll->curso;
			}
			
}			
if(codi==true){
 while(nodo!=0){
	if((strcmp(nodo->carnettt,carnett)==0) && (strcmp(nodo->codigooo,codii)==0)){  
	asig=true; // otra variable bool
}

nodo=nodo->asigna; 
}

if(asig==false){ 
cout<<"asignacion completa"<<endl;
asignacion *nodoa =new asignacion; 
nodoa->asigna=NULL;
cout<<"ingrese la fecha para la asignacion"<<endl;
cin>>nodoa->fecha,fechaa;
strcpy(nodoa->codigooo,codii);
strcpy(nodoa->carnettt,carnett);
nodoa->asigna=raizasig; 
raizasig=nodoa;	 
}else{ 
cout<<"ERROR esta asignado "<<endl;

}
}
system("pause");
}
	



void listaasig(){
		system ("cls");
asignacion*nodo;
	nodo=raizasig;
	while(nodo!=0){
	cout<<"LISTADO DE DATOS DE asignacion"<<endl;
	cout<<"el codigo del curso es: "<<nodo->codigooo<<endl;
	cout<<"el carnet es : "<<nodo->carnettt<<endl;
	cout<<"la fecha de la signacion es"<<nodo->fecha<<endl;
	nodo=nodo->asigna;	
	}
system("pause");
}

void busquedaa(){
		system ("cls");
	asignacion*noodo=raizasig;
	bool enco=false;
	char busqueda [10];
	cout<<"ingrese el carnet que va buscar de asignacion"<<endl;
	cin>>busqueda;
	if(raizasig !=NULL){
			while(noodo!=NULL && enco !=true){
		if(strcmp(noodo->carnettt,busqueda)==0){
			cout<<"dato encontrado"<< busqueda<<endl;
		cout<<"el codigo del curso es: "<<noodo->codigooo<<endl;
	cout<<"el carnet es : "<<noodo->carnettt<<endl;
	cout<<"la fecha de la signacion es"<<noodo->fecha<<endl;
		enco=true;
		}
			else{
		errores*actuall=new errores;
		actuall->siguienteerr=NULL;
	strcpy(actuall->error,"busqueda de asignacion no aparecida");
		actuall->siguienteerr=raizerror;
		raizerror=actuall;
		}	
		noodo=noodo->asigna;	
	}
	if(!enco){
		cout<<"no esta el nodo"<<endl;
	}
	}

	 system("pause"); 	
}

void eliminarasig(){
		system ("cls");
char busqueda[10];
char busque[10];
char fech[10];
	cout<<"ingrese el carnet del alumno que va eliminar la asignacion"<<endl;
	cin>>busqueda;
	cout<<"ingrese el codigo del curso de la asignacion que va eliminar"<<endl;
	cin>>busque;
	if(raizasig !=NULL){
		asignacion*borrar;
		asignacion*ante=NULL;
		borrar=raizasig;	
		while((borrar!=NULL) && (strcmp(borrar->codigooo,busque)!=0) && (strcmp(borrar->carnettt,busqueda)!=0)){
			ante=borrar;
			borrar=borrar->asigna;	}
			if(borrar==NULL){
			cout<<"no se encontro el codigo del curso y el carnet del alumno"<<endl;
			errores*actu=new errores;
		actu->siguienteerr=NULL;
	strcpy(actu->error,"error,no esta el nodo para eliminar en asignacion");
		actu->siguienteerr=raizerror;
		raizerror=actu;
		system("pause");
			}
				else if(ante==NULL){
						raizasig=raizasig->asigna;
						delete borrar;
						cout<<"se ha eliminado"<<endl;
							}
								else{
								ante->asigna =borrar->asigna;
									delete borrar;
									cout<<"se ha eliminado"<<endl;
									}	
	}	
		}		


void cargar (){
char lineas[50];
ifstream carga;
carga.open("alumnos.txt");
if(carga.fail()){
cout<<"no se pudo abrir el archivo"<<endl;
}else{  

while(!carga.eof()){
	carga.getline(lineas,50);
	
	if(lineas[0]!=0){
	alu*nodoo;
		nodoo=new alu;
		strcpy(nodoo->carnet,lineas);
	carga.getline(lineas,50);
		strcpy(nodoo->nombre,lineas);
		carga.getline(lineas,50);
		strcpy(nodoo->dir,lineas);
		carga.getline(lineas,50);
		strcpy(nodoo->tel,lineas);
	nodoo->ala=al;
	al=nodoo;			
	}
}
}
carga.close(); 

}

void cargarr(){
	char line[50];
ifstream cargaa;
cargaa.open("curso.txt");
if(cargaa.fail()){
cout<<"no se pudo abrir el archivo"<<endl;

}else{ 

while(!cargaa.eof()){
	cargaa.getline(line,50);
	if(line[0]!=0){
	cursos*nod;
		nod=new cursos;
		strcpy(nod->codigo,line);
	cargaa.getline(line,50);
		strcpy(nod->nombrec,line);
	nod->curso=raizcur;
	raizcur=nod;			
	}
}
}
	cargaa.close(); 
}

void cargaarr(){
	char tex[50];
ifstream cargaaa;
cargaaa.open("asignacion.txt");
if(cargaaa.fail()){
cout<<"no se pudo abrir el archivo"<<endl;
} else{

while(!cargaaa.eof()){
	cargaaa.getline(tex,50);
	if(tex[0]!=0){
	asignacion*nodd;
		nodd=new asignacion;
		strcpy(nodd->codigooo,tex);
	cargaaa.getline(tex,50);
		strcpy(nodd->carnettt,tex);
			cargaaa.getline(tex,50);
		strcpy(nodd->fecha,tex);
	nodd->asigna=raizasig;
	raizasig=nodd;			
	}
	
}
}
cargaaa.close(); 
}

//salida al momento de guardar en txt 
void salida(){
	fstream alumnos("alumnos.txt", fstream::out);
	alu *a=al;
  if (al!=0){ 
    while (a!=0){
    	alumnos<<a->carnet<<endl;
		alumnos<<a->nombre<<endl;
	alumnos	<<a->dir<<endl;
		alumnos<<a->tel<<endl;
		al=a->ala;
		delete a;
		a=al;
    }
  }
  alumnos.close();
  
  	fstream cursoo("curso.txt", fstream::out);
	cursos*nodo=raizcur;
  if (raizcur!=0){ 
    while (nodo!=0){
    	cursoo<<nodo->codigo<<endl;
	     cursoo<<nodo->nombrec<<endl;
		raizcur=nodo->curso;
		delete nodo;
		nodo=raizcur;
    }
  }
  cursoo.close();
  
  fstream asignacioness ("asignacion.txt", fstream::out);
  asignacion*nodoo=raizasig;
  if(raizasig!=0){
  	while(nodoo!=0){
  	asignacioness<<nodoo->codigooo<<endl;
	asignacioness<<nodoo->carnettt<<endl;
	asignacioness<<nodoo->fecha<<endl;
	raizasig=nodoo->asigna;
	delete nodoo;
	nodoo=raizasig;
	  }
  }
  asignacioness.close();
}

void menu(){
	system("color 0a");
	fflush(stdin);
	int opcion;
	cargar ();
	cargaarr();
	cargarr();	

	while (opcion!=15){
		system ("cls");
		cout<<"-----------ALUMNO----------------"<<endl;
		cout<<"1. ingresar datos del alumno"<<endl;
		cout<<"2. lista de alumnos"<<endl;
		cout<<"3.buscar alumno"<<endl;
		cout<<"4.eliminar el alumno"<<endl;
		cout<<"----------CURSOS-----------------"<<endl;
		cout<<"5. ingrese el curso"<<endl;
		cout<<"6. listado del curso"<<endl;
		cout<<"7. busqueda del curso"<<endl;
		cout<<"8. eliminar curso"<<endl;
		cout<<"----------asignaciones-------"<<endl;
		cout<<"9. agregar asignacion"<<endl;
		cout<<"10. lista de asignacion"<<endl;
		cout<<"11.busqueda de asignacion"<<endl;
		cout<<"12. eliminar asignacion"<<endl;
		cout<<"------LISTA DE ERRORES-------"<<endl;
		cout<<"13. operaciones no permitidas"<<endl;
		cout<<"15. salida"<<endl;
		cout <<"eliga una opcion"<<endl;
		cin >>opcion;
		if(opcion==1){alumno();}
		if(opcion==2){lista();}
		if(opcion==3){buscar();}
		if(opcion==4){eliminar();}
		if(opcion==5){agregarcurso();}
		if(opcion==6){listacurso();}
		if(opcion==7){busquedacurso();}
		if(opcion==8){eliminarcur();}
		if(opcion==9){asigna();}
		if(opcion==10){listaasig();}
		if(opcion==11){busquedaa();}
		if(opcion==12){eliminarasig();}
		if(opcion==13){operacion();}
        if(opcion==15){salida();}
	}
}

int main(){
	menu();
	return 0;
	Sleep(30);
}

