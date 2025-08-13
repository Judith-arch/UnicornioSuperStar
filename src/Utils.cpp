#include "Utils.hpp" // SOLO su propio header - funciones matemáticas independientes

// Implementación PID
PID::PID(double kP, double kI, double kD) : kP(kP), objetivo(0), error(0), integral(0), last_error(0) {}

double PID::Calculo_vel(double error, int max_speed) {
    
    integral += error;
    
    // Limitar la integral dentro de un rango
    if (integral > max_integral) integral = max_integral;
    if (integral < -max_integral) integral = -max_integral;

    // Calcular la derivada
    double derivative = error - last_error;
    last_error = error;

    double salida = (kP * error) + (kI * integral) + (kD * derivative);

    // Limitar la salida a un rango
    if (salida > max_speed) salida = max_speed;
    if (salida < -max_speed) salida = -max_speed;


    return salida;
}

void PID::reset() {
    integral = 0;
    last_error = 0;
}

// JUDITH: Lo dejo comentado por que seria para usar en pasos para las autonomas, esta en prueba

// Implementación Timer
// Timer::Timer() {
//     reset();
// }

// void Timer::reset() {
//     startTime = pros::millis();
// }

// uint32_t Timer::time() {
//     return pros::millis() - startTime;
// }

// bool Timer::timeout(uint32_t ms) {
//     return time() >= ms;
// }