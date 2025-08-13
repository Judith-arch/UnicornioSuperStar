#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "api.h"
#include "Hardware.hpp" // Para control directo de motores
#include "Sensors.hpp" // Para movimientos con sensores
#include "Utils.hpp" // Para controladores PID
#include "Odom.hpp" // Para movimientos con odometría
#include <cmath>

enum class DriveMode {
    ARCADE,
    TANK,
    TAYLOR
};

class Movement {
private:

public:

};

#endif

// Propósito: Funciones básicas de movimiento

// - Movimiento del chasis (forward, turn, etc.)
// - Control directo de motores
// - Movimientos simples sin odometría
// - Movimientos avanzados con odometría