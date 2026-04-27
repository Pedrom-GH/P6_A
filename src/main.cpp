#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

File myFile;

// El ESP32 usa el pin 5 por defecto para el CS del bus VSPI.
// Si tu cableado usa el pin 4 (como dice el ejemplo original), cambia este número a 4.
const int CS_PIN = 5; 

void setup() {
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  
  // Inicializamos la SD con nuestro pin CS
  if (!SD.begin(CS_PIN)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
 
  // En ESP32, es recomendable poner la barra "/" antes del nombre del archivo
  myFile = SD.open("/archivo.txt"); 
  
  if (myFile) {
    Serial.println("archivo.txt:");
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
    myFile.close(); //cerramos el archivo
  } else {
    Serial.println("Error al abrir el archivo");
  }
}

void loop() {
  // Bucle vacío, la lectura solo se hace una vez al encender la placa
}