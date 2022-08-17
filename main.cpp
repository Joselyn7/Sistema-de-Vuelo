#pragma once
#include <iostream>
#include "vuelos.h"
using namespace std;

int main(){
	
    int V, E , origen, destino, tiempo, inicio;
    
    cin>>V>>E;
    
    Vuelos obj(V);	
    
    while(E--){
    	
    	cin>>origen>>destino>>tiempo;
    	
    	obj.init(origen, destino, tiempo);
    	
	}

	cout<<"Punto de inicio: ";
    cin>>inicio;
    
    obj.sistemaVuelo(inicio);
    
    return 0;
}

/*
input 

5 10

1 2 113
1 4 258
2 3 102
2 4 94
2 5 102
3 5 212
4 2 102
4 3 214
4 5 30
5 3 212

*/
