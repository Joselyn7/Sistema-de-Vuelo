#pragma once
#include <iostream>
#include "aeropuerto.h"
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

class Vuelos{
	
	public:
		vector<Aeropuerto> ady[1000]; 
		map<int, string> aero;
		int tiempo[1000];     
		bool visitado[1000];     
		int previo[1000];         
		int V;
		priority_queue<Aeropuerto, vector<Aeropuerto>, cmp> Q; 
		
		Vuelos(int);
		void init(int, int, int);
		void relajacion(int, int, int);
		void print(int);
		void sistemaVuelo(int);
		
};

Vuelos::Vuelos(int V){
	
	for(int i = 0 ; i <= V ; ++i){
        tiempo[i] = INT_MAX;  
        visitado[i] = false; 
        previo[i] = -1;    
    }
    
    this->V = V;
    
    //--------------//
    
    aero[1] = "A.I.Rodriguez Ballon-Arequipa";
	aero[2] = "A.I.Jorge Chavez-Lima";
	aero[3] = "A.I.Alejandro Velasco Astete-Cuzco";
	aero[4] = "A.I.Capitan FAP Jose A. Quiniones-Lambayeque";
	aero[5] = "A.I.Carlos Martinez de Pinillos-La Libertad";
	aero[6] = "A.I.Capitan Renan Elias Olivera-Ica";
	
}

void Vuelos::init(int origen, int destino, int tiempo){
	
    ady[origen].push_back(Aeropuerto(destino, tiempo));
    
}

void Vuelos::relajacion(int actual, int adyacente, int peso){
    
    if(tiempo[actual] + peso < tiempo[adyacente]){
        tiempo[adyacente] = tiempo[actual] + peso; 
        previo[adyacente] = actual;                        
        Q.push(Aeropuerto(adyacente, tiempo[adyacente]));
    }
    
}

void Vuelos::print(int destino){
    if(previo[destino] != -1) 
        print(previo[destino]);  
    cout<<aero[destino]<<endl;        
}

void Vuelos::sistemaVuelo(int inicial){
    
    Q.push(Aeropuerto(inicial, 0)); 
    tiempo[inicial] = 0;  
    int actual, adyacente, peso;
    
    
    while(!Q.empty()){                   
        actual = Q.top().destino;           
        
		Q.pop();                          
        if(visitado[actual]) continue;
        visitado[actual] = true;         

        for(int i = 0; i < ady[actual].size(); ++i){ 
            adyacente = ady[actual][i].destino;  
            peso = ady[actual][i].tiempo;       
            if(!visitado[adyacente])    
                relajacion(actual, adyacente, peso); 
        }
    }

    
	int destino;
    cout<<"Punto de destino: ";
    
    cin>>destino;
    
    cout<<"\nRecorrido final\n\n";
    print(destino);
   
}

