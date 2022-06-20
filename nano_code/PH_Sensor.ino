 int milli_ph_balancer = 10;
unsigned long time_ph_balancer = 0;

void ph_balancer() {
  if(millis() >= time_ph_balancer + milli_ph_balancer){
    time_ph_balancer += milli_ph_balancer;

     //phsensor
           
      for(int l=0;l<10;l++) 
       { 
       buffer_arr[l]=analogRead(A1);
       delay(30);
       }
       for(int l=0;l<9;l++)
       {
       for(int j=l+1;j<10;j++)
       {
       if(buffer_arr[l]>buffer_arr[j])
       {
       temp=buffer_arr[l];
       buffer_arr[l]=buffer_arr[j];
       buffer_arr[j]=temp;
       }
       }
       }
       avgval=0;
       for(int l=2;l<8;l++)
       avgval+=buffer_arr[l];
       float volt=(float)avgval*5.0/1024/6;
       ph_act = -5.70 * volt + calibration_value;


      
      
        if(ph_act = 6.5) {
          pinMode(ppumpin, OUTPUT);
          digitalWrite(ppumpin, LOW);
          }
          else{
            digitalWrite(ppumpin, HIGH);
            delay(500);
          }
      
        }
}
