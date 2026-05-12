# Lector RFID - Arduino

Programa Arduino para detectar y leer tarjetas RFID usando el módulo MFRC522. El sistema identifica tarjetas/llaveros RFID y muestra su UID único en el monitor serie.

---

## Descripcion

Este proyecto implementa un sistema de lectura RFID que:

- Detecta automaticamente la presencia de tarjetas/llaveros RFID
- Lee el UID (identificador unico) de cada tarjeta
- Muestra la informacion en el monitor serie del Arduino
- Verifica la conexion y calibracion del modulo RFID

Ideal para proyectos de control de acceso, identificacion de objetos o sistemas de autenticacion.

---

## Componentes Necesarios

| Componente | Cantidad | Notas |
|:---|:---|:---|
| Arduino (Mega/Uno/Similar) | 1 | Con soporte SPI |
| Modulo RFID MFRC522 | 1 | Lector con antena integrada |
| Tarjeta/Llavero RFID | 1+ | Compatible con 13.56 MHz |
| Cables DuPont | 6+ | Para conexiones |
| Breadboard (opcional) | 1 | Para facilitar las conexiones |

---

## Conexiones

Conecta el modulo MFRC522 al Arduino de la siguiente manera:

| MFRC522 | Arduino Mega | Arduino Uno |
|:---|:---|:---|
| VCC | 5V | 5V |
| GND | GND | GND |
| MISO | Pin 50 | Pin 12 |
| MOSI | Pin 51 | Pin 11 |
| SCK | Pin 52 | Pin 13 |
| SDA (SS) | Pin 5 | Pin 5 |
| RST | Pin 22 | Pin 22 |
| IRQ | NO CONECTADO | NO CONECTADO |

**Nota:** Los pines SDA y RST pueden modificarse en el codigo si es necesario.

---

## Instalacion

### 1. Requisitos Previos

- Arduino IDE instalado
- Biblioteca MFRC522 instalada

### 2. Instalar la Biblioteca MFRC522

Sigue estos pasos en Arduino IDE:

1. Ve a Sketch → Include Library → Manage Libraries
2. Busca MFRC522
3. Instala la version mas reciente (recomendado: GithubCommunity MFRC522)

### 3. Cargar el Codigo

1. Copia el contenido de main.cpp
2. Pégalo en Arduino IDE
3. Selecciona tu placa: Tools → Board
4. Selecciona el puerto: Tools → Port
5. Haz clic en Upload

---

## Como Usar

1. **Abre el Monitor Serie:**
   - Arduino IDE → Tools → Serial Monitor
   - Velocidad: 9600 baud

2. **Esperaras ver:**

```
=== INICIANDO PRUEBA AISLADA RFID ===
(Informacion de version del modulo)
----------------------------------
LISTO. Acerca la tarjeta o el llavero...
```

3. **Acerca una tarjeta RFID:**
   - Veras el mensaje: TARJETA DETECTADA! UID: XX XX XX XX
   - Cada byte del UID se muestra en hexadecimal

---

## Ejemplo de Salida

```
=== INICIANDO PRUEBA AISLADA RFID ===
Firmware Version: 0x92 = v1.0
LISTO. Acerca la tarjeta o el llavero...
TARJETA DETECTADA! UID: 3A 1B 2C D5
TARJETA DETECTADA! UID: 5F E2 8A 12
```

---

## Explicacion del Codigo

### setup()

- Inicializa comunicacion Serial a 9600 baud
- Inicia protocolo SPI para comunicacion con el modulo
- Inicializa el modulo MFRC522
- Verifica la version del firmware
- Configura la ganancia de la antena al maximo

### loop()

- Paso 1: Detecta si hay una nueva tarjeta presente
- Paso 2: Si se detecta, intenta leerla
- Paso 3: Imprime el UID en formato hexadecimal
- Paso 4: Pausa la lectura de esa tarjeta (evita lecturas duplicadas)

---

## Configuracion de Pines

Si necesitas usar otros pines, modifica estas lineas:

```cpp
#define RST_PIN  22   // Cambia 22 por tu pin
#define SS_PIN   5    // Cambia 5 por tu pin
```

**Importante:** Los pines SPI (MISO, MOSI, SCK) son fijos segun tu placa Arduino y no se pueden cambiar.

---

## Solucion de Problemas

| Problema | Solucion |
|:---|:---|
| No aparece salida en Serial | Verifica baudrate (9600), conexion USB y placa seleccionada |
| Error de compilacion sobre MFRC522 | Instala la biblioteca MFRC522 desde Library Manager |
| Modulo no responde | Revisa las conexiones SPI (MISO, MOSI, SCK) |
| Tarjetas no se detectan | Verifica que sea compatible con 13.56 MHz y cercalas mas |
| Lectura inconsistente | Aumenta el delay entre intentos o mejora la antena |

---

## Recursos Utiles

- Documentacion MFRC522: https://github.com/miguelbalboa/rfid
- Arduino SPI: https://www.arduino.cc/en/reference/SPI
- Estandar ISO14443A: https://en.wikipedia.org/wiki/ISO/IEC_14443

---

## Licencia

Este proyecto es de codigo abierto y libre de usar para fines educativos y personales.

---

## Autor

Creado como practica de sistemas embebidos con Arduino.
