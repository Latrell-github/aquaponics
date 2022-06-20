int milli_water_level = 10;
unsigned long time_water_level = 0;

void water_level() {
  if(millis() >= time_water_level + milli_water_level){
    time_water_level += milli_water_level;
    
    //Water level
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  duration = pulseIn(3, HIGH);
  inches = microsecondsToInches(duration);
  percentage = (set_val-inches)*110/set_val;

  if(percentage<0)percentage=0;

  Serial.print(percentage);
  
  if(percentage<60)pump=1;
  if(percentage>80)pump=0;
  digitalWrite(13, !pump);


  }
}
