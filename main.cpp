#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" // Image library I found online
#include "image_conversion.hpp"

#include <stdexcept>
#include <iostream>
#include <limits>

int main(const int argc, char* argv[]) 
{
	// first arg should be the file path of the image, second arg should be the target number
	if (argc != 3)
	{
		std::cerr << "Usage: <program> <image path> <target number>\n";
		return 1;
	}

	const char* imagePath = argv[1];
	std::string targetStr = argv[2];
	int target;

	// Target integer parsing
	try
	{
    		target = std::stoi(targetStr);
		std::cout << target << '\n';
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Out of range: " << e.what() << '\n';
		return 1;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Invalid input: " << e.what() << '\n';
		return 1;
	}

	int width, height, channels;
	unsigned char* data = stbi_load(imagePath, &width, &height, &channels, 0);

	if (!data)
	{
		std::cerr << "Image load failed: " << stbi_failure_reason() << '\n';
		return 1;
	}
	
	std::string out = ImageConversion::GenerateExpression(data, target);
	std::cout << out << '\n';
	stbi_image_free(data);
	return 0;
}
