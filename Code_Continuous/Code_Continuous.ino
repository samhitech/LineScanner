int led = LED_BUILTIN;
int CLKpin = 4;    // <-- Arduino pin delivering the clock pulses to CLK of the TSL1401 
int SIpin = 5;     // <-- Arduino pin delivering the SI (serial-input) pulse to the TSL1401 
int AOpin1 = 1;    // <-- Arduino pin connected analog output of TSL1401
short dataD1[130]; // <-- Array where readout of the photodiodes is stored, as short for Detector 
int count = 0;
char serialCommand = '0';


void setup() {
  pinMode(led, OUTPUT);
  pinMode(CLKpin, OUTPUT); 
  pinMode(SIpin, OUTPUT);
  
  Serial.begin(115200);

  dataD1[1] = 0;
  dataD1[129] = 0;

  Initialize();
}

void loop() {
      On();
      ReadAnalog();
      Off();
      SendReading();
}

// Function to turn off led for debugging
void Off() {
  digitalWrite(led, LOW);
}

// Function to turn on led for debugging
void On() {
  digitalWrite(led, HIGH);
}

// Function to generate an outgoing clock pulse
void ClockPulse() {
  delayMicroseconds(1);
  digitalWrite(CLKpin, HIGH);
  digitalWrite(CLKpin, LOW);
  //count++;
}

//Clear the register
void Initialize() {
  // Clock out any existing SI pulse through the ccd register:
  for (int i = 0; i < 128; i++) {
    ClockPulse();
  }
  // send an SI pulse and clock out the sensor register:
  digitalWrite(SIpin, HIGH);
  ClockPulse();
  digitalWrite(SIpin, LOW);
  for (int i = 1; i < 128; i++)
  {
    ClockPulse();
  }

}

void ReadAnalog() {
  
  // Start next cycle of integration by sending SI pulse
  digitalWrite(SIpin, HIGH);
  ClockPulse();
  digitalWrite(SIpin, LOW);

  delayMicroseconds(20);
  dataD1[0] = analogRead(AOpin1);
  
  for(int i=1; i < 128; i++) {
    delayMicroseconds(10);
    dataD1[i] = analogRead(AOpin1);
    ClockPulse();
  }
}

void SendReading() {
  if(Serial) {
    Serial.write((uint8_t*) dataD1, 260);
  }
}
