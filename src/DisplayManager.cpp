#include "DisplayManager.h"
#include <functional>

#ifdef WIRELESS_STICK_V3
static SSD1306Wire display_static(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_64_32, RST_OLED);
#else
static SSD1306Wire display_static(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED);
#endif

DisplayUi displayUi(&display_static);
std::vector<std::pair<String, String>> messages;
FrameCallback dynamicFrames[MAX_DYNAMIC_FRAMES]; // Масив динамічних фреймів
int dynamicFrameCount = 0;
int currentFrameIndex = 0;
std::vector<std::pair<String, String>> previousMessages;

void initDisplay() {
    displayUi.setTargetFPS(60);
    displayUi.setIndicatorPosition(BOTTOM);
    displayUi.setIndicatorDirection(LEFT_RIGHT);
    displayUi.setFrameAnimation(SLIDE_LEFT);
    displayUi.disableAutoTransition();
    displayUi.init();
    // clearDynamicFrames();
    currentFrameIndex = 0;
}

// Функція перемикання фреймів через кнопку
void nextFrame_over() {
    currentFrameIndex++;
    if (currentFrameIndex >= dynamicFrameCount) {
        currentFrameIndex = 0;  // Якщо останній фрейм — повертаємося до першого
    }

    displayUi.switchToFrame(currentFrameIndex);  // Переключаємо фрейм
    // displayUi.update();
}

// Функція додавання повідомлень
void drawDynamicFrame(ScreenDisplay *d, DisplayUiState* state, int16_t x, int16_t y) {
    int i = currentFrameIndex;  // Використовуємо глобальний `currentFrameIndex`

    if (i < messages.size()) {
        d->setFont(ArialMT_Plain_10);
        d->setTextAlignment(TEXT_ALIGN_LEFT);
        d->drawStringMaxWidth(x, y, 64, messages[i].first);
        d->drawStringMaxWidth(x, y + 10, 64, messages[i].second);
    }
}

// Функція генерації фреймів
void generateDynamicFrames() {
    clearDynamicFrames();
    dynamicFrameCount = messages.size();

    if (dynamicFrameCount > MAX_DYNAMIC_FRAMES) {
        dynamicFrameCount = MAX_DYNAMIC_FRAMES;
    }

    for (int i = 0; i < dynamicFrameCount; i++) {
        dynamicFrames[i] = drawDynamicFrame;
    }

    displayUi.setFrames(dynamicFrames, dynamicFrameCount);
}

// Додавання нового повідомлення
void addMessageFrame(String title, String message) { 
    messages.push_back({title, message}); 
    generateDynamicFrames();  // Оновлюємо фрейми
}
void clearDynamicFrames() {
    for (int i = 0; i < MAX_DYNAMIC_FRAMES; i++) {
        dynamicFrames[i] = nullptr;  // Скидаємо всі фрейми
    }
    dynamicFrameCount = 0;
    displayUi.setFrames(nullptr, 0);  // Очищаємо дисплей
}

// Функція запису старих фреймів
void savePreviousFrame(String title, String message) {
    previousMessages.push_back({title, message}); // Збереження історичних фреймів
}

// Функція для отримання старих фреймів
void printPreviousFrames() {
    Serial.println("Історія фреймів:");
    for (const auto& frame : previousMessages) {
        Serial.println("Заголовок: " + frame.first + ", Повідомлення: " + frame.second);
    }
}

void VextON(void)
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, LOW);
}

void VextOFF(void) //Vext default OFF
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, HIGH);
}

