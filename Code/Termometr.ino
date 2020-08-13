#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MLX90614.h>


Adafruit_SSD1306 display(-1);
Adafruit_MLX90614 mlx = Adafruit_MLX90614(0x5A); 
void setup()   
{                
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   

  mlx.begin();
  
}

void loop() {
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("");
  display.setTextSize(3);
  display.print(mlx.readObjectTempC());
  display.setTextSize(1);
  display.print(" O");
  display.setTextSize(2);
  display.print("C");
  
  display.display();
  delay(1000);
  display.clearDisplay();
  }
