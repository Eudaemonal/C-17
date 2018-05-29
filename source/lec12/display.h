#pragma once
#include "makeimage.h"

class Display {
  void receiveImage(const Image& img);
  Image lastReceivedImage;
};
