/*
 * map.cpp
 *
 *  Created on: May 27, 2016
 *      Author: user
 */
#include "map.h"


Map::Map (string& file_path) {
	vector<unsigned char> map;

	// Load the map from the given file.
	lodepng::load_file(map,file_path);
	unsigned error = lodepng::decode(image, width, height, map);

	// If there is error, display it
	if(error) cout << "decoder error " << error << ": " <<
									lodepng_error_text(error) << endl;
}
