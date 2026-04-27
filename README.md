# Práctica 6A - Lectura y Escritura de Memoria SD (SPI)

## Objetivo
Comprender el funcionamiento del bus SPI leyendo un archivo de texto almacenado en una tarjeta MicroSD mediante un microcontrolador ESP32.

## Descripción de la salida por el puerto serie
Al iniciar la placa, el puerto serie (a 9600 baudios) mostrará `"Iniciando SD ..."`. 
* Si la conexión es correcta y el pin CS está bien configurado, imprimirá `"inicializacion exitosa"`.
* A continuación, intentará abrir `archivo.txt`. Si lo encuentra, imprimirá todo su contenido por pantalla carácter a carácter.
* Si hay un fallo de conexión mostrará `"No se pudo inicializar"`, y si el archivo no existe mostrará `"Error al abrir el archivo"`.

## Explicación del funcionamiento
Se inicializa el bus SPI y la tarjeta SD indicando el pin correspondiente al Chip Select (CS), que en el ESP32 suele ser el GPIO 5. Se utiliza la clase `File` para crear un puntero al archivo. Mediante `SD.open()`, se abre el documento en modo lectura. Un bucle `while` comprueba si hay bytes disponibles (`available()`) y los va enviando al Monitor Serie con `Serial.write()`. Al finalizar la lectura, es imperativo utilizar `myFile.close()` para liberar los recursos del bus y la memoria.