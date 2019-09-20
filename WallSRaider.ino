#include <NewPing.h>
#define trigPin 13
#define echoPin 12
#define MotorI 7
#define MotorD 8

     void setup()
        {   Serial.begin (9600);
            pinMode(trigPin, OUTPUT);
            pinMode(echoPin, INPUT); 
            pinMode(MotorI, OUTPUT);
            pinMode(MotorD, OUTPUT);
        }

     void loop()
        {   long duracion, distancia ;
            digitalWrite(trigPin, LOW);        // Nos aseguramos de que el trigger está desactivado
            delayMicroseconds(2);              // Para asegurarnos de que el trigger esta LOW
            digitalWrite(trigPin, HIGH);       // Activamos el pulso de salida
            delayMicroseconds(10);             // Esperamos 10µs. El pulso sigue active este tiempo
            digitalWrite(trigPin, LOW);        // Cortamos el pulso y a esperar el echo
            duracion = pulseIn(echoPin, HIGH) ;
            distancia = duracion / 2 / 29.1  ;
            Serial.println(String(distancia) + " cm.") ;
            int Limite = 6 ;
            int Limite2 = 7 ;
            
            if ( distancia < Limite)
                 digitalWrite ( MotorI , LOW) ;
            else
                 digitalWrite( MotorI , HIGH) ;
            delay (500) ;                  // Para limitar el número de mediciones
            
            
            if ( distancia > Limite2)
                 digitalWrite ( MotorD , LOW) ;
            else
                 digitalWrite( MotorD , HIGH) ;
            delay (500) ;                  // Para limitar el número de mediciones
        }
