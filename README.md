# UAS_IOT
## Pembuatan Perangkat IoT MODIS (Mobile Odor Detection And Identification System) Sebagai Sistem Pencegahan Pertama Kebocoran Gas

## Kelompok : 
1. Ananta Yusra Putra Akmal - 2109106024
2. Bayu Setiawan - 2109106026

## Latar Belakang 
Latar Belakang : 
Projek ini dipilih berdasarkan kebutuhan akan sistem deteksi kebakaran dini yang efektif dan mudah diakses. Kebakaran merupakan salah satu bencana yang dapat menyebabkan kerugian besar baik secara material maupun korban jiwa. Penerapan teknologi modern untuk mendeteksi kebakaran sejak dini menjadi sangat penting untuk meminimalisir risiko dan kerugian yang disebabkan oleh kebakaran. Dengan berkembangnya teknologi IoT (Internet of Things), alat pendeteksi kebakaran yang terhubung ke internet dapat memberikan notifikasi langsung kepada pemilik bangunan atau pihak berwenang sehingga tindakan pencegahan dapat segera dilakukan.

## Spesifikasi dan alat 
Sistem yang akan dibangun terdiri dari beberapa komponen utama:
Sensor Gas (MQ-2): Untuk mendeteksi adanya gas berbahaya yang dapat memicu kebakaran.
Sensor Suhu (DHT11): Untuk memantau suhu lingkungan.
LCD Display (I2C 16x2): Untuk menampilkan data suhu dan gas secara langsung.
Relay: Untuk mengendalikan perangkat eksternal seperti alarm atau sistem pemadam kebakaran otomatis.
WiFi Module (ESP8266/ESP32): Untuk menghubungkan sistem ke jaringan internet.
MQTT Client: Untuk mengirim data ke server dan menerima perintah dari aplikasi monitoring.
Relay : menjadi alarm dalam prototype 
Batrai 18650 7.5v : sebagai sumber daya mandiri
Batrai holder : untuk menaruh batrai 

Spesifikasi Teknis
ESP8266/ESP32:
Memori Flash: 4 MB
Frekuensi CPU: 80 MHz
Protokol WiFi: IEEE 802.11 b/g/n

Sensor Gas MQ-2:
Tegangan Operasi: 5V
Konsumsi Daya: 150 mA
Rentang Deteksi: 300 - 10000 ppm (Gas LPG, Smoke)


Sensor Suhu DHT11:
Rentang Suhu: 0-50°C
Akurasi: ±2°C
Tegangan Operasi: 3-5V


LCD I2C 16x2:
Tegangan Operasi: 5V
Interface: I2C

Relay:
Tegangan Operasi: 5V
Arus Operasi: 20 mA
Kapasitas Kontak: 10A 250VAC/30VDC

## Dokumentasi 
![100](https://github.com/anantaYSR/UAS_IOT/assets/93465182/9617c03a-cd02-4f22-90da-5e33ba46e7a5)

![102](https://github.com/anantaYSR/UAS_IOT/assets/93465182/b5f4b2ed-6c31-4be6-82db-966e73032dfc)

![101](https://github.com/anantaYSR/UAS_IOT/assets/93465182/00c18f86-6ffb-4f29-bff3-a7b98921d75e)

## Link Youtube 
https://www.youtube.com/watch?v=UkumVLgrqe0 
