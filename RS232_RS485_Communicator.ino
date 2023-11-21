#include <ArduinoRS485.h>

class DataCommunicator {
public:
  DataCommunicator(int baudRate, int delayInterval) : baudRate(baudRate), delayInterval(delayInterval) {}

  void begin() {
    Serial.begin(baudRate);
    RS485.begin(baudRate);
    RS485.receive();
  }

  String receiveData(Stream& stream, const String& source) {
    String receivedString;

    while (stream.available()) {
      char receivedChar = stream.read();
      if (receivedChar == '\n') {
        Serial.println("Received data from " + source + ": " + receivedString);
        return receivedString;
      }
      receivedString += receivedChar;
    }

    return "";
  }

  void sendData(Stream& stream, const String& data, const String& destination) {
    stream.println(data);
    Serial.println("Sent data to " + destination + ": " + data);
  }

  void run() {
    if (Serial.available()) {
      String receivedSerialData = receiveData(Serial, "Serial");
      sendData(RS485, receivedSerialData, "RS-485");
    } else {
      
      delay(delayInterval);
    }
  }

private:
  int baudRate;
  int delayInterval;
};

DataCommunicator dataCommunicator(9600, 1000);

void setup() {
  dataCommunicator.begin();
}

void loop() {
  dataCommunicator.run();
}
