#pragma once

#ifndef ODOM_HPP
#define ODOM_HPP

#include "api.h"
#include "Hardware.hpp"  // Para acceso a encoders/IMU
#include "Sensors.hpp"   // Para funciones de lectura de sensores
#include "Utils.hpp"     // Para funciones matemáticas

class Odom {
public:

private:

};

#endif

// Propósito: Sistema completo de odometría

// - Cálculo de posición (x, y, θ)
// - Tracking wheels/encoders
// - Algoritmos de odometría
// - Reseteo y calibración de posición
// - Funciones de utilidad para coordenadas