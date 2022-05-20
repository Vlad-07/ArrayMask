#include <iostream>
#include "Utils.h"
#include "vendor/stb_image/stb_image.h"

class Image
{
public:
	stbi_uc* m_Data;
	int8_t m_Width, m_Height, m_Channels;

	Image(const std::string path);
	~Image();

	Vec3 GetPixel(int x, int y);

	uint8_t operator[](int i);
};