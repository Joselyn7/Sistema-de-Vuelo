#pragma once

class Aeropuerto{
	
	public:

		int destino;
		int tiempo;
		
		Aeropuerto(){};
		Aeropuerto(int, int);
};

Aeropuerto::Aeropuerto(int destino, int tiempo){
	
	this->destino = destino;
	this->tiempo = tiempo;

}

struct cmp {
    bool operator() (const Aeropuerto &a, const Aeropuerto &b) {
        return a.tiempo > b.tiempo;
    }
};
