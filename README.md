# Display Manager Library for OLED Wireless Stick V3 by Heltec (Arduino C++ Library)

This library provides a simple API to manage an OLED display based on the SSD1306 chipset using an Arduino-compatible board. It supports dynamic frame management, message display, and external voltage control for the display module. The library utilizes the HT_SSD1306Wire and HT_DisplayUi frameworks to handle frame animations and text rendering.

# Бібліотека Display Manager для OLED Wireless Stick V3 від компанії Heltec (Arduino C++ Бібліотека)

Ця бібліотека забезпечує простий API для керування OLED-дисплеєм на базі чіпа SSD1306 з використанням плати, сумісної з Arduino. Вона підтримує динамічне керування фреймами, відображення повідомлень та керування зовнішньою напругою для дисплея. Бібліотека використовує фреймворки HT_SSD1306Wire та HT_DisplayUi для організації анімації фреймів і відображення тексту.

---

## Features / Особливості

- **Dynamic Frames Management / Динамічне управління фреймами:**  
  EN: Easily add, regenerate, and cycle through dynamic message frames on the OLED display.  
  UA: Легке додавання, оновлення та перемикання між динамічними фреймами з повідомленнями.

- **Integrated Display UI / Інтегрований керуючий інтерфейс дисплею:**  
  EN: Uses the HT_DisplayUi framework to provide animated transitions between frames.  
  UA: Використовує HT_DisplayUi для забезпечення анімації та плавного переходу між фреймами.

- **Message Stack / Історія повідомлень:**  
  EN: Capable of storing previous messages for reference and further analysis.  
  UA: Забезпечує збереження історії повідомлень для подальшого аналізу.

- **Voltage Control / Керування напругою:**  
  EN: Includes functions to control external voltage (Vext) for powering the OLED module.  
  UA: Містить функції для управління зовнішньою напругою (Vext) дисплея для оптимізації енергоспоживання або захисту пристрою.

---

## Requirements / Вимоги

- **Arduino IDE** або сумісне середовище розробки для Arduino.
- **OLED Display:** SSD1306-дисплей; використовується дві геометрії: GEOMETRY_64_32 або GEOMETRY_128_64 (залежно від налаштувань).
- **Dependencies / Залежності:**
  - `HT_SSD1306Wire.h`
  - `HT_DisplayUi.h`
  - Стандартна бібліотека C++ `<vector>`

---

## Installation / Встановлення

1. **Clone or Download:**  
   Клонувати репозиторій або завантажити бібліотеку через .ZIP  і скопіювати її у каталог `libraries` вашої інсталяції Arduino IDE.
   
   ```bash
   git clone githttps://github.com/Dimitri-Y/OLED-Heltec-Wireless-Stick-V3.git

### Usage / Використання

  EN: In your sketch, initialize the display and add message frames as follows:
  
  UA: У вашому скетчі ініціалізуйте дисплей та додайте фрейми повідомлень наступним чином:
  
  ```bash
  #include "DisplayManager.h"
  void setup() {
    Serial.begin(115200);
    initDisplay();
    addMessageFrame("Title 1", "Message 1");
    addMessageFrame("Title 2", "Message 2");
  }

  void loop() {
    displayUi.update();
    // Example: call nextFrame_over() on a button press to cycle frames.
  }
  ```


## API Overview / Опис API
### void initDisplay()
  EN: Initializes the OLED display with default configuration (FPS, indicator position, clears frames).
  
  UA: Ініціалізує OLED-дисплей із типовими параметрами (кадрова частота, позиція індикатора, очищення фреймів).

### void addMessageFrame(String title, String message)
  EN: Adds a new frame with title and message, and regenerates dynamic frames.
  
  UA: Додає новий фрейм із заголовком і повідомленням та оновлює масив фреймів.

### void drawDynamicFrame(ScreenDisplay *d, DisplayUiState *state, int16_t x, int16_t y)
  EN: Callback function that renders the frame content with text alignment.
  
  UA: Callback-функція для малювання фрейму з вирівнюванням заголовка та тексту.

### void generateDynamicFrames()
  EN: Regenerates all frames from the stored messages and applies them to the display UI.
  
  UA: Генерує фрейми зі збережених повідомлень і застосовує їх до дисплею.

### void clearDynamicFrames()
  EN: Clears all message frames and resets frame tracking.
  
  UA: Очищає всі фрейми та скидає лічильник кадрів.

### void nextFrame_over()
  EN: Cycles to the next frame. If it’s the last one, wraps to the first.
  
  UA: Перемикає на наступний фрейм. Якщо останній — повертається до першого.

### void VextON() / void VextOFF()
  EN: Enables or disables external power supply to OLED by toggling Vext pin.
  
  UA: Вмикає або вимикає зовнішнє живлення OLED через керування піном Vext.
