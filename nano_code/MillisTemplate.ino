//the delay to execute this program forever in milliseconds
int milli_sensor = 10;
unsigned long time_sensor = 0;

void loop_sensor() {
  if(millis() >= time_sensor + milli_sensor){
    time_sensor += milli_sensor;
    



  }
}
