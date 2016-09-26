
#include <CurieIMU.h>
/*
Code points which part of the Arduino board is point in upwards.
*/

int lastOrientation = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Initializndo papa..");
  CurieIMU.begin();

  CurieIMU.setAccelerometerRange(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int orientation = -1;
  String orientationString;

  int x = CurieIMU.readAccelerometer(X_AXIS);
  int y = CurieIMU.readAccelerometer(Y_AXIS);
  int z = CurieIMU.readAccelerometer(Z_AXIS);

  int absX = abs(x);
  int absY = abs(y);
  int absZ = abs(z);

  if ( (absZ > absX ) && (absZ > absY)) {
      if (z > 0){
          orientationString = "arriba";
          orientation = 0;
        } else {
            orientationString = "abajo";
            orientation = 1;
          }
    } else if ( (absY > absX ) && (absY > absZ)) {
      if (y > 0){
          orientationString = "digital pins up";
          orientation = 2;
        } else {
            orientationString = "analog pins up";
            orientation = 3;
          }
    } else {
      if (x < 0){
          orientationString = "connector up";
          orientation = 4;
       } else {
            orientationString = "connector down";
            orientation = 5;
        }
     }

     if ( orientation != lastOrientation) {
      
        Serial.println(orientationString);
        lastOrientation = orientation;
        
      }
}
