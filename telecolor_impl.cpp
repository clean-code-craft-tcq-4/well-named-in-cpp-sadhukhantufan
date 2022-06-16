#include <string>
#include <iostream>
#include "telecolor_impl.h"

namespace TelCoColorCoder
{
    const char *MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
    int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const char *MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    MajorColor ColorPair::getMajor() { return majorColor; }

    MinorColor ColorPair::getMinor() { return minorColor; }

    std::string ColorPair::ToString()
    {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }

    ColorPair ColorPair::GetColorFromPairNumber(int pairNumber)
    {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int ColorPair::GetPairNumberFromColor(MajorColor major, MinorColor minor)
    {
        return major * numberOfMinorColors + minor + 1;
    }

    void ColorPair::printColorCodeReferenceManual(void)
    {
        int majorColorIterator, minorColorIterator;
        int pairNumber = 1;

        std::cout << "25 PAIR COLOR CODE REFERNCE MANUAL" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "| PAIR NO. | MAJOR COLOR | MINOR COLOR |" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        for (majorColorIterator = 0; majorColorIterator < numberOfMajorColors; majorColorIterator++)
        {
            for (minorColorIterator = 0; minorColorIterator < numberOfMinorColors; minorColorIterator++)
            {
                std::cout << "|   " << pairNumber++ << " \t  -->  " << MajorColorNames[majorColorIterator] << "\t -->  " << MinorColorNames[minorColorIterator] << "\t |" << std::endl;
            }
            std::cout << "----------------------------------------" << std::endl;
        }
    }
}
