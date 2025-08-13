#pragma once

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "api.h"
#include "Hardware.hpp"
#include "Sensors.hpp"
#include "Utils.hpp"
#include "Odometry.hpp"
#include "Movement.hpp"
#include "Control.hpp"
// Robot conoce TODOS los módulos - es la capa de integración

class Robot {
private:

public:

};

#endif

// Propósito: Clase principal que representa el robot

// - Posición actual (x, y, θ) desde odometría
// - Estados del robot (Autonomous, Driver Control, Skills, Disabled)
// - Métodos de alto nivel (`Robot::moveTo()`, `Robot::getX()`)
// - Integración entre todos los módulos
// - Interface unificada para el robot completo