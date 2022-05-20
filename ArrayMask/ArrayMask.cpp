#include "ArrayMask.h"

ArrayMask::ArrayMask(const std::string maskPath, uint8_t defLevel)
	: m_Image(maskPath), m_DefaultLevel(defLevel)
{
}

ArrayMask::~ArrayMask()
{
}

Image& ArrayMask::GetImage()
{
	return m_Image;
}

bool ArrayMask::CheckCoords(int x, int y, ChannelTarget target, uint8_t level)
{
	if (!level)
		level = m_DefaultLevel;

	Vec3 pixel = m_Image.GetPixel(x, y);
	int maskVal = 0;

	switch (target)
	{
	case ArrayMask::Red:
		maskVal = pixel.x;
		break;
	case ArrayMask::Green:
		maskVal = pixel.y;
		break;
	case ArrayMask::Blue:
		maskVal = pixel.z;
		break;
	default:
		std::cout << "Invalid/unimplemented channel: " + target;
		break;
	}

	if (maskVal >= level)
		return true;
	else
		return false;
}
