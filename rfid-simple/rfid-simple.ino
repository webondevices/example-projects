#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

// Create MFRC522 RFID reader instance
MFRC522 reader(SS_PIN, RST_PIN);

void setup() {
    
    // Start serial communication
    Serial.begin(9600);
    
    // Start SPI bus
    SPI.begin();
    
    // Initialise reader 
    reader.PCD_Init();

    Serial.println("Waiting for card");
}

String getUID(MFRC522 reader) {
    String content = "";
    byte letter;
    
    // Read card UID byte by byte and concatenate to string
    for (byte i = 0; i < reader.uid.size; i++) {
        content.concat(String(reader.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(reader.uid.uidByte[i], HEX));
    }

    content.toUpperCase();

    return content;
}

void loop() {
    
    // Check if card is present, exit loop if not
    if (!reader.PICC_IsNewCardPresent()) {
        return;
    }

    // Read available cards, exit loop if failed
    if (!reader.PICC_ReadCardSerial()) {
        return;
    }

    // Get UID
    String content = getUID(reader);

    // Show UID on serial monitor
    Serial.println("UID tag:" + content);
    
    // Authenticate    
    // Change UID here to the card you want to give access to
    if (content.substring(1) == "BD 31 15 2B") {
        Serial.println("Access granted!");
        delay(2000);
    
    } else {
        Serial.println("Access denied!");
        delay(2000);
    }
} 