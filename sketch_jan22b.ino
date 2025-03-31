const int sensorMin=0;
const int sensorMax=1024;


void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop() {
  int sensorReading =analogRead(A0);
  int range=map(sensorReading, sensorMin,sensorMax,0,3);
  switch(range)
  {
    case 0:
    Serial.println("Close Fire");
    break;
    case 1:
    Serial.println('Distant Fire');
    break;
    case 2:
    Serial.println("no fire");
    break;
    int (0.3)
    printf ( "teh fre hehmn")

  }
  delay(1);
  // put your main code here, to run repeatedly:

}
