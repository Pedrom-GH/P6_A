#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

// Pines que acabas de conectar
#define RST_PIN  22   // Pin 22 para el RST
#define SS_PIN   5    // Pin 5 para el SDA (SS)

MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {
  Serial.begin(9600); 
  delay(1000); // Pausa de seguridad para que abras el monitor serie

  Serial.println("\n=== INICIANDO PRUEBA AISLADA RFID ===");

  SPI.begin();        
  mfrc522.PCD_Init(); 
  
  // Verificamos si los cables están bien conectados
  mfrc522.PCD_DumpVersionToSerial(); 
  
  // Ponemos la antena al máximo
  mfrc522.PCD_SetAntennaGain(mfrc522.RxGain_max);
  
  Serial.println("----------------------------------");
  Serial.println("LISTO. Acerca la tarjeta o el llavero...");
}

void loop() {
  // 1. Preguntamos si hay una tarjeta en el lector
  if (mfrc522.PICC_IsNewCardPresent()) {  
    
    // 2. Si hay tarjeta, intentamos leerla
    if (mfrc522.PICC_ReadCardSerial()) {
      
      Serial.print("✅ TARJETA DETECTADA! UID:");
      
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);   
      } 
      Serial.println();
      
      // 3. Pausamos la lectura de esta tarjeta
      mfrc522.PICC_HaltA();         
    }      
  }	
} 