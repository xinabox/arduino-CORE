#include <XiX_Core.h>

String I2Cfound1 = "";
String I2Cfound2 = "";

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nI2C Scanner");
  Serial.println("===========");
}

void loop() {
  I2C_scan();
  delay(2000);
}

void I2C_scan()
{
  byte error, address;
  int nDevices = 0;

  Serial.println("xCHIP scan...");
  I2Cfound1 = "";
  I2Cfound2 = "";
  for (address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      String v = String(address, HEX);
      if (v.length() == 1) v = "0" + v;
      v.toUpperCase();
      Serial.print("0x");
      Serial.print(v);
      Serial.print(" ");
      nDevices = 1;
    }
  }
  if (nDevices == 0) {
    Serial.print("No xCHIPs connected to the xBUS\n");
  }
  Serial.println();
}