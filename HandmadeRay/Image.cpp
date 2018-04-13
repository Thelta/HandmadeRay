#include <vector>

#include "Image.h"
#include "Vector3.h"

using namespace std;


Image::Image(int const weight, int const height)
{
	m_width = weight;
	m_height = height;
	m_currentPixel = 0;
	m_filledPixels = 0;

	m_pixels = vector<Vector3<uint8_t>>(weight * height);
	m_colors = unordered_set<Vector3<uint8_t>, VECTOR3_UINT8_HASH>(0, Vector3<uint8_t>::Hash);
}

void Image::AddPixel(Vector3<uint8_t> pixel)
{
	m_pixels[m_currentPixel++] = pixel;
	if (!m_colors.count(pixel))
	{
		m_colors.insert(pixel);
	}

	m_filledPixels++;
}

void Image::AddPixel(Vector3<uint8_t> pixel, int x, int y)
{
	m_pixels[m_width * y + x] = pixel;
	if (!m_colors.count(pixel))
	{
		m_colors.insert(pixel);
	}

	m_filledPixels++;
}

int Image::GetWidth()
{
	return m_width;
}

int Image::GetHeight()
{
	return m_height;
}

Vector3<uint8_t> Image::GetPixel(int x, int y)
{
	return m_pixels[m_width * y + x];
}

vector<Vector3<uint8_t>> &Image::GetPixels()
{
	return m_pixels;
}

unordered_set<Vector3<uint8_t>, VECTOR3_UINT8_HASH>& Image::GetColors()
{
	return m_colors;
}
