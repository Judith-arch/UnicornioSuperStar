#ifndef UTILS_HPP
#define UTILS_HPP

#include "api.h"
#include <cmath>

// Constantes matemáticas
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Clase PID - TU IMPLEMENTACIÓN EXACTA
class PID {
private:
    double kP;
    double kI = 0.0;              // ← Integral
    double kD = 0.0;              // ← Derivativo
    double objetivo;
    double error;
    double integral = 0.0;  // ← Integral acumulada
    double max_integral = 100.0; // ← Limite de la integral
    double last_error = 0.0;     // ← Para derivativo
    
public:
    PID(double kP, double kI, double kD);
    double Calculo_vel(double error, int max_speed);
    void reset();
};

// PIDManager para manejar los PIDs estáticos - TUS CONSTANTES EXACTAS
class PIDManager {
public:
    static PID PID_RelativeAvance;  // (0.1, 0, 0)
    static PID PID_Giro;           // (0.3, 0.03, 0.04)
    static PID PID_CorrectionGiro; // (0.1, 0, 0)
};

// Namespace de utilidades matemáticas
namespace MathUtils {
    double normalizeAngle(double angle);
    double degreesToRadians(double degrees);
    double radiansToDegrees(double radians);
    double distance(double x1, double y1, double x2, double y2);
    int sign(double value);
    double clamp(double value, double min, double max);
    double deadband(double value, double threshold);
    double inchesToMM(double inches);
    double mmToInches(double mm);
    double rpmToInchesPerSec(double rpm, double wheelDiameter);
}

// Clase Timer para timeouts
class Timer {
private:
    uint32_t startTime;
    
public:
    Timer();
    void reset();
    uint32_t time();
    bool timeout(uint32_t ms);
};

#endif // UTILS_HPP