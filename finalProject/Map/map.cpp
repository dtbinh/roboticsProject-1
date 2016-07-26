/*
 * map.cpp
 *
 *  Created on: May 27, 2016
 *      Author: user
 */
#include "map.h"


Map::Map (const char* file_path, double mapResolution, double gridResolution) {
	this->mapResolution = mapResolution;
	this->gridResolution = gridResolution;

	vector<unsigned char> map;

	// Load the map from the given file.
	lodepng::load_file(map,file_path);
	unsigned error = lodepng::decode(this->image, this->width,
			this->height, map);

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
	this->imageAfterBlow = vector<unsigned char>(this->image);

	for (int nRow=0; nRow < this->height; nRow++){
		for (int nCol=0; nCol < this->width; nCol++){
			// If the cell is black we need to weight it.
			if ((this->image[nRow * width * 4 + nCol * 4] == 0) &
					(this->image[nRow * width * 4 + nCol * 4 + 1] == 0) &
					(this->image[nRow *  width * 4 + nCol * 4 + 2] == 0))
			{
				this->WeightCell(nRow, nCol, this->mapResolution);
			}
		}
	}

}

void Map::WeightCell(int nRow, int nCol, double resolution) {
	for (int nRowWeighter = nRow - resolution; nRowWeighter < nRow + resolution; nRowWeighter++ ){
		for (int nColWeighter = nCol - resolution;
			 nColWeighter < nCol + resolution;
			 nColWeighter++){

			// Check to see that we are not exceeding the size of the image.
			if (nRowWeighter >= 0 &
					nColWeighter >= 0 &
					nRowWeighter <= height * 4 &
					nColWeighter <= width * 4){
				this->imageAfterBlow[nRowWeighter * width * 4 + nColWeighter * 4] = 0;
				this->imageAfterBlow[nRowWeighter * width * 4 + nColWeighter * 4 + 1] = 0;
				this->imageAfterBlow[nRowWeighter * width * 4 + nColWeighter * 4 + 2] = 0;
				this->imageAfterBlow[nRowWeighter * width * 4 + nColWeighter * 4 + 3] = 255;
			}
		}
	}
}

void Map::CreateMatrix() {
	// Number of cells in the first array of the grid.
	int nPixelInGrid = this->GetGridMapResolution();

	// Grid size
	int nGridHeight = this->height / nPixelInGrid;
	int nGridWidth = this->width / nPixelInGrid;

	this->vMapMatrix.resize(nGridHeight);

	// Resize each cell in the vector
	for (int i=0; i< this->vMapMatrix.size(); i++) {
		this->vMapMatrix[i].resize(nGridWidth);
	}

	// According to the image set all the cells in the matrix to their types
	for (int i =0; i<this->vMapMatrix.size();i++){
		for (int j =0; j<this->vMapMatrix[0].size();i++){
			// Check cell type insert it to matrix.
			this->vMapMatrix[i][j] = (CELL)CheckCellInPng(i,j);

		}
	}
}

CELL Map::CheckCellInPng(int nRow, int nCol){
	nRow *= this->GetGridMapResolution();
	nCol *= this->GetGridMapResolution();

	// If this counter is less than 16 so the
	int nIsFreeCounter = 0;
}

double Map::GetGridMapResolution(){
	return (this->gridResolution/ this->mapResolution);
}

