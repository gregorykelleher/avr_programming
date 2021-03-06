
int address_pins[] = {22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,47,49,51,53};
int data_pins[] = {38,40,42,44,46,48,50,52};

#define RESET 13

int data_pin_num = 8;
int address_pin_num = 20;

unsigned long int bus_read(int *pins, int pin_num);
void reset();

void setup()
{

    for (int i = 0; i < address_pin_num; i++) {
        pinMode(address_pins[i], INPUT); 
    }
    for (int i = 0; i < data_pin_num; i++) {
        pinMode(data_pins[i], INPUT); 
    }

    Serial.begin(115200);

    pinMode(RESET, OUTPUT);
    reset();

    delay(1000);

}

void loop()
{

    // int data = bus_read(data_pins, data_pin_num);
    unsigned long int address = bus_read(address_pins, address_pin_num);

    Serial.print("address BIN: ");
    Serial.println(address, BIN);
    Serial.print("address HEX: ");
    Serial.println(address, HEX);
    Serial.println();

    // Serial.print("data BIN: ");
    // Serial.println(data, BIN);
    // Serial.print("data HEX: ");
    // Serial.println(data, HEX);
    // Serial.println();

}

unsigned long int bus_read(int *pins, int pin_num) {

    char bin[pin_num+1];
    bin[pin_num+1] = '\0';

    for (int i = 0; i < pin_num; i++) {
        if (digitalRead(pins[i]) == HIGH) {
            bin[i] = '1';
        }
        if (digitalRead(pins[i]) == LOW) {
            bin[i] = '0';
        }
    }

    // bin str to int
    unsigned long int val = strtol(bin, NULL, 2);
    return val;

}

void reset() {

    digitalWrite(RESET, HIGH);

    unsigned long previousMillis = 0;
    unsigned long interval = 50;

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        digitalWrite(RESET, LOW);
    }

}
