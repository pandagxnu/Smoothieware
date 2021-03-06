/*
      This file is part of Smoothie (http://smoothieware.org/). The motion control part is heavily based on Grbl (https://github.com/simen/grbl).
      Smoothie is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
      Smoothie is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
      You should have received a copy of the GNU General Public License along with Smoothie. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef UniversalAdapter_H
#define UniversalAdapter_H

#include "LcdBase.h"
#include "mbed.h"

class Pin;

class UniversalAdapter : public LcdBase {
    public:
        UniversalAdapter();
        virtual ~UniversalAdapter();
        void home();
        void clear();
        void display();
        void setCursor(uint8_t col, uint8_t row);
        void init();
        void write(const char* line, int len);
        bool encoderReturnsDelta() { return true; }

        void setLed(int led, bool onoff);

        uint8_t readButtons();
        int readEncoderDelta();

        // this is the number of clicks per detent
        int getEncoderResolution() { return 2; }

        void buzz(long,uint16_t);

    private:
        uint8_t writeSPI(uint8_t b);
        void wait_until_ready();
        uint8_t sendReadCmd(uint8_t cmd);
        uint16_t ledBits;
        mbed::SPI* spi;
        Pin *cs_pin;
        Pin *busy_pin;
        int col;
        int row;
};


#endif
