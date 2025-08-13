#ifndef SENSORS_HPP
#define SENSORS_HPP

#include "api.h"
#include "Hardware.hpp" // Necesita Hardware para acceder a las declaraciones de sensores
#include <cmath>

// Configuración de odometría
enum tipoOdometria { ENCODERS, MOTORES };

struct Position {

};

class Sensors {
private:
    
public:

};

#endif

// Propósito: Gestión completa de sensores

// - Inicialización de sensores
// - Lecturas y calibración
// - Filtrado de datos
// - Funciones de utilidad para sensores específicos