#include <BMI160.h>
#include <CurieIMU.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Initializndo IMU..");
  CurieIMU.begin();

  CurieIMU.setGyroRange(250);
}
void loop() {
  int gxRaw, gyRaw, gzRaw;

  CurieIMU.readGyro(gxRaw, gyRaw, gzRaw);

  flaot gx = convertRawGyro(gxRaw):
  flaot gy = convertRawGyro(gyRaw):
  flaot gz = convertRawGyro(gzRaw):

  Serial.print(gx);
  Serial.print("\t");
  Serial.print(gy);
  Serial.print("\t");
  Serial.print(gz);
  Serial.println();
}
