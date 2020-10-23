#include <MX1508.h>
#include <RF24.h>
#include <pb_decode.h>
#include "DataPacket.pb.h"

#define IDENTIFIER "GLD2"

const int IN1 = 3; 
const int IN2 = 4;
const uint8_t radioAddress[9] = "Gateway1";

bool isConfigured = false;

MX1508 motorA(IN1, IN2, FAST_DECAY, 2);
RF24 radio(8, 10);

void(* resetFunc) (void) = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("=-=-=-=-= ReGlade v0.1a =-=-=-=-=");
  Serial.println("(c) 2019 Ovidiu D. Nitan");
  Serial.println();
  Serial.println("Booting...");

  Serial.print("Configuring pins: ");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.println("OK");
  
  Serial.print("Starting radio: ");
  if (!radio.begin()) {
    Serial.println("FAIL");
    isConfigured = false;
    return;
  }
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, radioAddress);
  radio.startListening();
  Serial.println("OK");

  Serial.println("ReGlade is ready.");
  isConfigured = true;
}

void loop() {
  if (!isConfigured) return;
  
  if (radio.available()) {
    uint8_t buf[DataPacket_size];
    uint8_t len = sizeof(buf);
    radio.read(&buf, len);
    DataPacket packet = DataPacket_init_zero;
    pb_istream_t istream = pb_istream_from_buffer(buf, len);
    if (pb_decode(&istream, DataPacket_fields, &packet)) {
      Serial.print("Received "); Serial.print(DataPacket_size); Serial.println(" bytes of data");
      if (packet.packet_type == DataPacket_PacketType_MEASUREMENT) {
        if (strcmp (packet.identifier, IDENTIFIER) == 0) {
          Serial.println("Refreshing air...");
          motorA.motorGo(255);
          delay(500);
          motorA.stopMotor();

          // Motor depletes us of power and destabilizes the program, reset the CPU
          // resetFunc();
        }
      }
    }
  }
}
