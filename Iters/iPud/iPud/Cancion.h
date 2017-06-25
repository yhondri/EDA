
#include <string>

class Cancion {
public:
	Cancion() : nombre(""), artista(""), duracion(0) {}
	Cancion(std::string n, std::string a, int d) : nombre(n), artista(a), duracion(d) {}
	
	std::string getNombre() const {
		return nombre;
	}

	 int getDuracion() const {
		 return duracion;
	 }

private:

	std::string nombre;
	std::string artista;
	int duracion;
};
