#pragma once
#include <vector>
#include <unordered_set>
#include "Vector3.h"

using namespace std;
class Image
{
	vector<Vector3<uint8_t>> m_pixels;
	unordered_set<Vector3<uint8_t>, VECTOR3_UINT8_HASH> m_colors;
	int m_width;
	int m_height;
	int m_currentPixel;
	int m_filledPixels;

	public:

	Image(int weight, int height);
	int GetWidth();
	int GetHeight();
	void AddPixel(Vector3<uint8_t> pixel);
	void AddPixel(Vector3<uint8_t> pixel, int x, int y);
	Vector3<uint8_t> GetPixel(int x, int y);
	vector<Vector3<uint8_t>> &GetPixels();
	unordered_set<Vector3<uint8_t>, VECTOR3_UINT8_HASH> &GetColors();
};
