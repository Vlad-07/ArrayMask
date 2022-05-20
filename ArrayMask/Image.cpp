#include "Image.h"

Image::Image(const std::string path)
{
	int width = 0, height = 0, channels = 0;
	stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, channels);
	if (!data)
	{
		std::cout << "Invalid image path: " + path + "\n\n";
		m_Data = 0;
		m_Width = 0;
		m_Height = 0;
		m_Channels = 0;
		return;
	}

	m_Data = data;
	m_Width = width;
	m_Height = height;
	m_Channels = channels;
}

Image::~Image()
{
	stbi_image_free(m_Data);
}

Vec3 Image::GetPixel(int x, int y)
{
	Vec3 pixel;

	pixel.x = m_Data[x * m_Channels + y * m_Width * m_Channels];
	pixel.y = m_Data[x * m_Channels + y * m_Width * m_Channels + 1];
	pixel.z = m_Data[x * m_Channels + y * m_Width * m_Channels + 2];

	return pixel;
}

uint8_t Image::operator[](int i)
{
	return m_Data[i];
}
