#include "filesystem.h"

#include <string>
#include <fstream>
#include <iostream>

std::string filesystem::LoadAsset(std::string file)
{
	// Create a text string, which is used to output the text file
	std::string out;
	std::string endfile;

	// Read from the text file
	std::ifstream asset(std::filesystem::current_path().u8string() + g_contentPath + file);
	g_output->Log("ENGINE: Loading asset " + std::filesystem::current_path().u8string() + g_contentPath + file, false);

	// Use a while loop together with the getline() function to read the file line by line
	while (std::getline(asset, out)) {
		// Output the text from the file
		endfile += std::string(out + "\n");
	}

	// Close the file
	asset.close();

	// g_output->Log("ENGINE: Asset data " + endfile, false);

	return endfile;
}
