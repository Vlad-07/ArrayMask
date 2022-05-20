#include "Image.h"

class ArrayMask
{
private:
	Image m_Image;
	uint8_t m_DefaultLevel;

public:
	enum ChannelTarget
	{
		None = 0, Red, Green, Blue, Alpha
	};

	ArrayMask(const std::string maskPath, uint8_t defLevel = 1);
	~ArrayMask();

	Image& GetImage();

	bool CheckCoords(int x, int y, ChannelTarget target, uint8_t level = 0);
};