int milli_dht11 = 10;
unsigned long time_dht11 = 0;

void dht11() {
  if(millis() >= time_dht11 + milli_dht11){
    time_dht11 += milli_dht11;
    
      //temp & humidity
   while(1)
 {
  //delay(1000);
  pinMode(gate,OUTPUT);
  digitalWrite(gate,LOW);
  delay(20);
  digitalWrite(gate,HIGH);
  pinMode(gate,INPUT_PULLUP);//by default it will become high due to internal pull up
 // delayMicroseconds(40);

  
  tempduration=pulseIn(gate, LOW);
  if(tempduration <= 84 && tempduration >= 72)
  {
      while(1)
      {
        tempduration=pulseIn(gate, HIGH);
        
        if(tempduration <= 26 && tempduration >= 20){
        value=0;}
        
        else if(tempduration <= 74 && tempduration >= 65){
        value=1;}
        
        else if(z==40){
        break;}
        
        i[z/8]|=value<<(7- (z%8));
        j[z]=value;
        z++;
      }
    }
answer=i[0]+i[1]+i[2]+i[3];

if(answer==i[4] && answer!=0){
Serial.print("Temperature");
Serial.print(i[2]);
}

z=0;
i[0]=i[1]=i[2]=i[3]=i[4]=0;
break;


  }
}
}
