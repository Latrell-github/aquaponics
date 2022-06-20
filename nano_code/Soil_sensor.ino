int milli_soil_sensor = 10;
unsigned long time_soil_sensor = 0;

void soil_sensor() {
  if(millis() >= time_soil_sensor + milli_soil_sensor){
    time_soil_sensor += milli_soil_sensor;
    
//Soil Sensor
  output_value = analogRead(sensor_pin);
  output_value = map(output_value,550,10,0,100);


  if(output_value<25){
    digitalWrite(relayPin, LOW);
    }
    else{
      digitalWrite(relayPin, HIGH);
      }


  }
}
