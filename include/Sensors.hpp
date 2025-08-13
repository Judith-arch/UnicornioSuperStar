#ifndef SENSORS_HPP
#define SENSORS_HPP

#include "api.h"
#include "Hardware.hpp"
#include <cmath>

// Configuración de odometría
enum tipoOdometria { ENCODERS, MOTORES };

struct Position {
    double x;
    double y;
    double heading;
    
    Position() : x(0), y(0), heading(0) {}
    Position(double x, double y, double heading) : x(x), y(y), heading(heading) {}
};

class Sensors {
private:
    pros::IMU imu;
    pros::ADIEncoder RightEnc;
    pros::ADIEncoder LeftEnc;
    
    // Variables de odometría (tus variables exactas)
    double posx;
    double posy;
    double prepos;
    double actualPos;
    double headingTotal;
    double prevPosCM;
    double prevHeadingRad;
    double sum;
    
    // Configuración (tus constantes exactas)
    const bool usingEncoders;
    const bool unaPasiva;
    const bool hayImu;
    tipoOdometria tipo;
    
    // Constantes del robot (tus valores exactos)
    const double diametroRuedaEncoder;  // 8.3
    const double diametroRuedaMotor;    // 10.3
    const double distanciaEntreEncoders; // 21.8
    
public:
    Sensors();
    
    // Configuración
    void calibrateIMU();
    void resetEncoders();
    void resetOdometry();
    
    // Lectura básica de sensores
    double getHeading();         // Tu función original
    double getRotation();        // Tu función original
    double getLeftEncoder();
    double getRightEncoder();
    
    // Tus funciones específicas de ángulo
    double heading2Pasivas();    // Tu función original
    double headingMotores();     // Tu función original
    
    // Tus funciones de posición
    double pos2Pasivas();        // Tu función original
    double pos1Pasiva();         // Tu función original
    double getModulePos();       // Tu función original
    double getModule(double x, double y); // Tu función original
    
    // Tus funciones de utilidad
    double getVectorAngle(double x, double y); // Tu función original
    double get_absolute_error_giro(double target, double heading = -1); // Tu función original
    
    // Funciones de odometría originales
    void reset_odom();           // Tu función original
    double rad(double eul);      // Tu función original
    double eul(double rad);      // Tu función original
    double sumMotores();         // Tu función original
    double conversorEncoders(double tick); // Tu función original
    double conversorMotores(double tick);  // Tu función original
    double anguloEncoders();     // Tu función original
    double getPosition();        // Tu función original (retorna double)
    double variacionPosicion();  // Tu función original
    std::pair<double, double> posicion(); // Tu función original
    void iniciarOdometria(double x, double y); // Tu función original
    static void odom_task(void* param); // Tu función original
    
    // Nuevas funciones para compatibilidad
    void updateOdometry();
    Position getCurrentPosition(); // Renombrada para evitar conflicto
    void setPosition(double x, double y, double heading = 0);
    
    // Getters para variables internas
    double getPosX() const { return posx; }
    double getPosY() const { return posy; }
    tipoOdometria getTipoOdometria() const { return tipo; }
    
    // Setters para configuración
    void setTipoOdometria(tipoOdometria newTipo) { tipo = newTipo; }
};

#endif