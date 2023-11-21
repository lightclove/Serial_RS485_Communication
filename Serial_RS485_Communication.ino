#include <ArduinoRS485.h>

const int RS485_BAUD_RATE = 9600;
const int SERIAL_BAUD_RATE = 9600;
const int DELAY_INTERVAL = 1000;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  RS485.begin(RS485_BAUD_RATE);
  RS485.receive();
}

String receiveDataFromSerial() {

  String receivedString = "";  

  while (Serial.available() > 0) {
    char receivedChar = Serial.read();

    if (receivedChar == '\n') {
      // Если принят символ новой строки, отправляем строку через Serial
      Serial.print("Received data from Serial: ");
      Serial.println(receivedString);

      // Очищаем строку для следующего приема
      return receivedString;
    } else {
      // Накапливаем символы в строке
      receivedString += receivedChar;
    }
  }
} 

void sendDataToRS485(const String& data) {
  RS485.beginTransmission();
  RS485.println(data);
  RS485.endTransmission();
}

void writeDataToRS485(const String& data) {
  Serial.write(data.c_str(), data.length());
}

void sendDataToSerial(const String& data) {
  Serial.println(data);
}

void writeDataToSerial(const String& data) {
  Serial.write(data.c_str(), data.length());
}


String receiveDataFromRS485() {
  String receivedString = "";  

  while (RS485.available()) {
    char receivedChar = RS485.read();

    if (receivedChar == '\n') {
      // Если принят символ новой строки, отправляем строку через Serial
      Serial.print("Received data from RS-485: ");
      Serial.println(receivedString);

      // Очищаем строку для следующего приема
      return receivedString;
    } else {
      // Накапливаем символы в строке
      receivedString += receivedChar;
    }
  }
}  
String receiveData(Stream& stream, const String& source) {
  String receivedString = "";

  while (stream.available()) {
    char receivedChar = stream.read();

    if (receivedChar == '\n') {
      Serial.print("Received data from " + source + ": ");
      Serial.println(receivedString);
      return receivedString;
    } else {
      receivedString += receivedChar;
    }
  }

  return "";
}

void sendData(Stream& stream, const String& data, const String& destination) {
  stream.println(data);
  Serial.println("Sent data to " + destination + ": " + data);
}


void loop() {

  if (Serial.available() > 0) {
  // Принимаем и отправляем данные через Serial
  String receivedSerialData = receiveData(Serial, "Serial");
  sendData(RS485, receivedSerialData, "RS-485");
  // Принимаем и отправляем данные через RS-485
  String receivedRS485Data = receiveData(RS485, "RS-485");
  sendData(Serial, receivedRS485Data, "RS-485");
  }
  delay(DELAY_INTERVAL);

}
