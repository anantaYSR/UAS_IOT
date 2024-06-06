#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <PubSubClient.h>

// Replace with your network credentials
const char* ssid = "ARPM";
const char* password = "qqwwee123";

const char* mqtt_server = "public.cloud.shiftr.io";
const char* mqtt_username = "ananta-2109106024";
const char* mqtt_password = "dhu9iayH2ZvPSlNi";

#define MQ_PIN A0
#define DHTPIN D4
#define DHTTYPE DHT11
#define RELAY_PIN D6       // Pin yang terhubung ke relay

bool relayState = true; // Status awal relay mati

WiFiClient espClient;
PubSubClient pubClient(espClient);
LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long lastTimeBotRan;
DHT dht(DHTPIN, DHTTYPE);

float baseline_ppm = 0;
void readSensor() {
  unsigned int sensorValue = analogRead(MQ_PIN);  // Read the analog value from sensor
  float voltage = sensorValue * (3.3 / 1023.0);
  float ppm = (voltage - 0.22) / 0.1;
  float t = dht.readTemperature();

  String payload = String(t) + " - " + String(ppm);
  pubClient.publish("modis/info", payload.c_str());
  baseline_ppm = ppm;
  Serial.println(relayState);

  if(relayState) {
    if(ppm > 13.2 || t >= 32) {
      digitalWrite(RELAY_PIN, LOW);
    } else {
      digitalWrite(RELAY_PIN, HIGH);
    }
  }

  lcd.clear();
  lcd.setCursor(2, 0); // Set the cursor on the third column and first row.
  lcd.print("PPM GAS: " + String(ppm)); // Print the string "Hello World!"
  lcd.setCursor(2, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("SUHU: " + String(t) + "°C");
}

void messageReceived(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  // Convert byte array to string
  String payloadStr = "";
  for (int i = 0; i < length; i++) {
    payloadStr += (char)payload[i];
  }

  Serial.println(topic);
  if (strcmp(topic, "modis/speaker-status") == 0) {
    if (payloadStr == "on") {
      relayState = true;
    } else if (payloadStr == "off") {
      relayState = false;
      digitalWrite(RELAY_PIN, HIGH);
    }
  }

  Serial.println(topic);
  if(strcmp(topic, "modis/speaker-test") == 0) {
    relayState = false;
    digitalWrite(RELAY_PIN, LOW); // Turn off the relay
    delay(2000);
    digitalWrite(RELAY_PIN, HIGH);
    relayState = true;
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Pastikan relay mati saat boot

  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  dht.begin();
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
    lcd.print("Connecting to WiFi.."); 
  }

  // MQTT CLIENT
  pubClient.setServer(mqtt_server, 1883);
  pubClient.setCallback(messageReceived);

  lcd.clear();
  lcd.print("Connecting to MQTT...");
  Serial.print("Connecting to MQTT...");
  while (!pubClient.connect("ESP8266Client", mqtt_username, mqtt_password)) {
    Serial.print(".");
    delay(1000);
  }
  lcd.print("Connected to MQTT...");
  Serial.println("\nConnected to MQTT");
  pubClient.subscribe("modis/speaker-test");
  pubClient.subscribe("modis/speaker-status");



  // ALL CONNECTED
  Serial.println(WiFi.localIP());
  lcd.clear();
  lcd.print(WiFi.localIP()); 
}

void loop() {
  pubClient.loop();
  readSensor();
  delay(1000);
}