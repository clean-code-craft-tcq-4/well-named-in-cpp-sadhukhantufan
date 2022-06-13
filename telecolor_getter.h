#include <string>

namespace TelCoColorCoder
{
    enum MajorColor
    {
        WHITE,
        RED,
        BLACK,
        YELLOW,
        VIOLET
    };
    enum MinorColor
    {
        BLUE,
        ORANGE,
        GREEN,
        BROWN,
        SLATE
    };
    class ColorPair
    {
    private:
        MajorColor majorColor;
        MinorColor minorColor;

    public:
        ColorPair(MajorColor major, MinorColor minor) : majorColor(major), minorColor(minor) {}
        MajorColor getMajor();
        MinorColor getMinor();
        std::string ToString();
        ColorPair GetColorFromPairNumber(int pairNumber);
        int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    };
}
