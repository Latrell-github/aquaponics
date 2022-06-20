int milli_lcd_display = 10;
unsigned long time_lcd_display = 0;

void lcd_display() {
  if(millis() >= time_lcd_display + milli_lcd_display){
    time_lcd_display += milli_lcd_display;

     //soil sensor
  lcd.setCursor(0,0);
  lcd.print("Moist:");
  lcd.setCursor(6,0);
  lcd.print(output_value);
  lcd.print("%   ");

  //ph sensor
       lcd.setCursor(10, 0);
       lcd.print("pH:");
       lcd.setCursor(13, 0);
       lcd.print(ph_act);
    
    //water level display
  lcd.setCursor(0,1);
  lcd.print("Water Level: ");
  lcd.print(percentage);
  lcd.print("%   ");
  Serial.print(percentage);

 
  

//  //temp&humid
//  lcd.setCursor(0,0);
//  lcd.print("Temperature: ");lcd.print(i[2]);lcd.print("C");
//  lcd.setCursor(0,1);
//  lcd.print("Humidity: ");lcd.print(i[0]);lcd.print("%");



  }
}
