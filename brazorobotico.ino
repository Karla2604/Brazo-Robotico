#include <Servo.h> //incluir biblioteca para controlar servomotores

//definir nuestros servos 1 y 2
Servo servo1;
Servo servo2;

//definir los pines de entrada del joystick (pines analógicos)
int joy1 = 0; //correspondiente al eje x del joystick
int joy2 = 1; //correspondientes al eje y del joystick

//declarar variables para leer los valores para los pins analógicos
int joyVal1;
int joyVal2;

void setup()
//adjuntamos los servomotores con sus pines PWM correspondientes
{
  servo1.attach(3); //servomotor 1 con el pin PWM 3
  servo2.attach(5); //servomotor 2 con el pin PWM 5
  Serial.begin(9600); //inicializar la comunicación serial entre el arduino y la computadora
}

void loop()
{
  posicionDeseada(); //función que presneta los valores de entrada
  movimientoServo(); //función que asigna los valores de salida hacia servos
  delay(15);
}

void posicionDeseada(){
  //Se asigna el valor de la entrada analógica a la nueva variable para el servo 1
  joyVal1 = analogRead(joy1);
  Serial.print(joyVal1); //nos ayuda a imprimir los datos de la comunicación serial en el monitor serie
  Serial.print("-->");
  joyVal1 = map(joyVal1, 0, 1023, 0, 71); //convertir valores digitales del joystick al rango PWM 0 a 71 correspondiente al ángulo de 50°
   Serial.println(joyVal1);
   
  joyVal2 = analogRead(joy2);  //Se asigna el valor de la entrada analógica a la nueva variable para el servomotor 2
  joyVal2 = map(joyVal2, 0, 1023, 0, 255);//convertir valores digitales del joystick al rango PWM 0 a 255 correspondiente al ángulo de 180°
}

void movimientoServo(){
  servo1.write(joyVal1); //poner la posición del servo 1 acorde a la del eje x del joystick
  servo2.write(joyVal2); //poner la posición del servo 2 acorde a la del eje y del joystick
}
