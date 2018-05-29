#pragma once
#include "display.h"

class Image {
  int imgData[800][600];
};

class MakeImage {
  Display& displayToSendImage;
};
