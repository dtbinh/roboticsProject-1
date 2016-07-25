/*
 * map.cpp
 *
 *  Created on: May 27, 2016
 *      Author: user
 */
#include "map.h"


Map::Map (const char* file_path, double mapResolution) {
	this->resolution = mapResolution;

	vector<unsigned char> map;

	// Load the map from the given file.
	lodepng::load_file(map,file_path);
	unsigned error = lodepng::decode(image, width, height, map);

	// If there is error, display it
	if(error) cout << "decoder error " << error << ": " <<
									lodepng_error_text(error) << endl;
}

void Map::MapBlowing(double robotHeight, double robotWidth) {
	//this->imageAfterBlow.resize(this->image.size());
	//	for (int i=0;i<this->image.size(); i++){
	//			this->imageAfterBlow[i] = this->image[i];
	//	}

	// Copy image to imageAfterBlow
	this->imageAfterBlow = new vector<unsigned char>(this->image);

	for (int nRow=0; nRow < this->height; nRow++){
		for (int nCol=0; nCol < this->width; nCol++){

		}
	}

}

