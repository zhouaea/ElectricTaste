const int MAX_VOLTAGE = 150;

int digitalPin = 9;
const int currentPin = A5;

int voltage = 0;
int current = 0;
char rx_byte;
String rx_str = "";

void setVoltage(int new_voltage) {
  if (new_voltage > MAX_VOLTAGE) {
    voltage = MAX_VOLTAGE;
  } else if (new_voltage < 0) {
    voltage = 0;
  } else {
    voltage = new_voltage;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  pinMode(digitalPin, OUTPUT);
  Serial.println("hi");
  Serial.println("Voltage:" + String(voltage));
}

void loop() {
  // Read serial port.
  if (Serial.available() > 0) {    
    rx_byte = Serial.read();     
    
    if (rx_byte != '\n') {
      rx_str += rx_byte;
    }
    else {
      setVoltage(rx_str.toInt());
      rx_str = "";
      Serial.println("Voltage:" + String(voltage));
    }
  }
  
  // Powering circuit.
  analogWrite(digitalPin, voltage);

  // Read current
  int adc = analogRead(currentPin);
  float voltage = adc*5/1023.0;
  float current = (voltage-2.5)/0.66;
  Serial.println("Current:" + String(current));
}
