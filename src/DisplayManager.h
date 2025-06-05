#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include "HT_SSD1306Wire.h"
#include "HT_DisplayUi.h"
#include <vector>

#define MAX_DYNAMIC_FRAMES 10

// Оголошення змінних
extern DisplayUi displayUi;
extern std::vector<std::pair<String, String>> messages;
extern FrameCallback dynamicFrames[MAX_DYNAMIC_FRAMES];
extern int dynamicFrameCount;

// Оголошення функцій
void initDisplay();
void addMessageFrame(String title, String message);
void drawDynamicFrame(ScreenDisplay *displayUi, DisplayUiState* state, int16_t x, int16_t y);
void generateDynamicFrames();
void clearDynamicFrames();
void nextFrame_over();
void VextOFF();
void VextON();
#endif