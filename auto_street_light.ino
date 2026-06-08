#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

// Pin LDR
#define LDR_PIN 34

// Pin 4 Relay
#define RELAY1 26
#define RELAY2 27
#define RELAY3 14
#define RELAY4 12

// Batas gelap LDR
int batasGelap = 2000;

// Relay module biasanya aktif LOW
#define RELAY_ON  LOW
#define RELAY_OFF HIGH

void setup() {
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  matikanSemuaRelay();

  Wire.begin();

  if (!rtc.begin()) {
    Serial.println("RTC tidak terdeteksi!");
    while (1);
  }

  // Aktifkan sekali saja untuk setting waktu RTC
  // Setelah waktu benar, komentari kembali
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("Sistem 4 Relay Lampu Otomatis Siap");
}

void loop() {
  DateTime now = rtc.now();

  int nilaiLDR = analogRead(LDR_PIN);
  int jam = now.hour();
  int menit = now.minute();

  bool kondisiGelap = nilaiLDR > batasGelap;

  bool waktuMalam =
    (jam > 18 || (jam == 18 && menit >= 0)) ||
    (jam < 5 || (jam == 5 && menit <= 30));

  if (kondisiGelap || waktuMalam) {
    nyalakanSemuaRelay();
  } else {
    matikanSemuaRelay();
  }

  Serial.print("Jam: ");
  print2digit(jam);
  Serial.print(":");
  print2digit(menit);

  Serial.print(" | LDR: ");
  Serial.print(nilaiLDR);

  Serial.print(" | Gelap: ");
  Serial.print(kondisiGelap ? "YA" : "TIDAK");

  Serial.print(" | Timer: ");
  Serial.print(waktuMalam ? "AKTIF" : "NONAKTIF");

  Serial.print(" | Lampu: ");
  Serial.println((kondisiGelap || waktuMalam) ? "NYALA" : "MATI");

  delay(1000);
}

void nyalakanSemuaRelay() {
  digitalWrite(RELAY1, RELAY_ON);
  digitalWrite(RELAY2, RELAY_ON);
  digitalWrite(RELAY3, RELAY_ON);
  digitalWrite(RELAY4, RELAY_ON);
}

void matikanSemuaRelay() {
  digitalWrite(RELAY1, RELAY_OFF);
  digitalWrite(RELAY2, RELAY_OFF);
  digitalWrite(RELAY3, RELAY_OFF);
  digitalWrite(RELAY4, RELAY_OFF);
}

void print2digit(int angka) {
  if (angka < 10) Serial.print("0");
  Serial.print(angka);
}