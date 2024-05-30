// Definición de pines del puente H
const int enable1 = 9;  // Pin para Enable1
const int enable2 = 10; // Pin para Enable2
const int input1 = 2;   // Pin para Input1
const int input2 = 3;   // Pin para Input2
const int input3 = 4;   // Pin para Input3
const int input4 = 5;   // Pin para Input4

// Variable para almacenar el carácter recibido
char command;

// Velocidad fija para los motores (0-255)
const int speed = 200; // Ajusta este valor para cambiar la velocidad

void setup() {
  // Configurar los pines del puente H como salida
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);

  // Inicializar el puerto serial
  Serial.begin(9600);

  // Configurar los pines de enable a un valor inicial
  analogWrite(enable1, 0);
  analogWrite(enable2, 0);
}

void loop() {
  // Verificar si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    // Leer el carácter recibido
    command = Serial.read();
    
    // Ejecutar la acción correspondiente al carácter recibido
    switch (command) {
      case 'c': // Mover hacia adelante
        analogWrite(enable1, speed);
        analogWrite(enable2, speed);
        digitalWrite(input1, HIGH);
        digitalWrite(input2, LOW);
        digitalWrite(input3, HIGH);
        digitalWrite(input4, LOW);
        break;
      case 'd': // Mover hacia atrás
        analogWrite(enable1, speed);
        analogWrite(enable2, speed);
        digitalWrite(input1, LOW);
        digitalWrite(input2, HIGH);
        digitalWrite(input3, LOW);
        digitalWrite(input4, HIGH);
        break;
      case 'b': // Girar a la izquierda
        analogWrite(enable1, speed);
        analogWrite(enable2, speed);
        digitalWrite(input1, LOW);
        digitalWrite(input2, HIGH);
        digitalWrite(input3, HIGH);
        digitalWrite(input4, LOW);
        break;
      case 'a': // Girar a la derecha
        analogWrite(enable1, speed);
        analogWrite(enable2, speed);
        digitalWrite(input1, HIGH);
        digitalWrite(input2, LOW);
        digitalWrite(input3, LOW);
        digitalWrite(input4, HIGH);
        break;
      case 'e': // Detener el robot
        analogWrite(enable1, 0);
        analogWrite(enable2, 0);
        break;
    }
  }
}
