#pragma once

#ifndef Buffer_h
#define Buffer_h

#include "Arduino.h"
#include "FS.h"
#include "settings.h"
#include "esp_wifi_types.h"

#define BUF_SIZE 3 * 1024 // Reduced buffer size to save RAM
#define SNAP_LEN 2324 // Max length of each received packet

extern Settings settings_obj;

class Buffer {
  public:
    Buffer();
    void pcapOpen(String file_name, fs::FS* fs, bool serial, uint32_t link_type);
    void add(const uint8_t* buf, uint32_t len, bool is_pcap);
    void appendPcapEntry(const String &mac, uint8_t *payload, size_t length);
    void logOpen(String file_name, fs::FS* fs, bool serial);
    void append(wifi_promiscuous_pkt_t *packet, int len);
    void append(String log);
    void save();
  private:
    void createFile(String name, bool is_pcap);
    void open(bool is_pcap, uint32_t link_type);
    void openFile(String file_name, fs::FS* fs, bool serial, bool is_pcap, uint32_t link_type);
    void write(int32_t n);
    void write(uint32_t n);
    void write(uint16_t n);
    void write(const uint8_t* buf, uint32_t len);
    void saveFs();
    void saveSerial();
    
    uint8_t* bufA;
    uint8_t* bufB;

    uint32_t bufSizeA = 0;
    uint32_t bufSizeB = 0;

    bool writing = false; // Accepting writes to buffer
    bool useA = true; // Writing to bufA or bufB
    bool saving = false; // Currently saving to SD card

    String fileName = "/0.pcap";
    File file;
    fs::FS* fs;
    bool serial;
};

#endif
