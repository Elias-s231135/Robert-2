#pragma once

namespace MathClasses
{
    struct Colour
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
        uint32_t colour;

        //unsigned char is a 1 byte number that stores a value from 0 to 255, perfect for colours!
        unsigned char GetRed() const {
            return colour >> 24;
        }
        unsigned char GetGreen() const {
            return colour >> 16;
        }
        unsigned char GetBlue() const {
            return colour >> 8;
        }
        unsigned char GetAlpha() const {
            return colour;
        }
        
        void SetRed(unsigned char red) {
            //Slide the red bits into the correct position;
            unsigned int v = (unsigned int)red << 24;
            //Clear the current red values
            colour = colour & 0x00ffffff;
            //Put the new red values into place.
            colour = colour | v;
        }
        void SetGreen(unsigned char green) {
            //Slide the green bits into the correct position;
            unsigned int v = (unsigned int)green << 16;
            //Clear the current green values
            colour = colour & 0xff00ffff;
            //Put the new green values into place.
            colour = colour | v;
        }
        void SetBlue(unsigned char blue) {
            //Slide the blue bits into the correct position;
            unsigned int v = (unsigned int)blue << 8;
            //Clear the current blue values
            colour = colour & 0xffff00ff;
            //Put the new blue values into place.
            colour = colour | v;
        }
        void SetAlpha(unsigned char alpha) {
            //Slide the alpha bits into the correct position;
            unsigned int v = (unsigned int)alpha;
            //Clear the current alpha values
            colour = colour & 0xffffff00;
            //Put the new alpha values into place.
            colour = colour | v;
        }
        Colour() {
            colour = 0x000000ff;
            // initialize all colour components to 0 except Alpha which is 255
        }

        Colour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
            // initialize all colour components as per the parameters
            colour = (unsigned int)red << 24 | (unsigned int)green << 16 |  (unsigned int)blue << 8 |  (unsigned int)alpha;
             
        }

        bool operator==(Colour& rhs)
        {
          return rhs.colour == colour;
        }

    };

}