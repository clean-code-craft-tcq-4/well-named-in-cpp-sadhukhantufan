#include <iostream>
#include <assert.h>
#include "telecolor_getter.h"

void testNumberToPair(int pairNumber,
                      TelCoColorCoder::MajorColor expectedMajor,
                      TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair *l_color{};
    auto colorPair = l_color->GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    TelCoColorCoder::ColorPair *l_color{};
    int pairNumber = l_color->GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void testPrintColorCodeReferenceManual()
{
    TelCoColorCoder::ColorPair *l_color{};
    l_color->printColorCodeReferenceManual();
}

int main()
{
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    testPrintColorCodeReferenceManual();

    return 0;
}
