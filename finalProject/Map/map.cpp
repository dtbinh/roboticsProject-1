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
	// Copy image to imageAfterBlow
	this->imageAfterBlow = vector<unsigned char>(this->image);

	for (int nRow=0; nRow < this->height; nRow++){
		for (int nCol=0; nCol < this->width; nCol++){
			// If the cell is black we need to weight it.
			if ((this->image[nRow * width * 4 + nCol * 4] == 0) &
					(this->image[nRow * width * 4 + nCol * 4 + 1] == 0) &
					(this->image[nRow *  width * 4 + nCol * 4 + 2] == 0))
			{
				this->WeightCell(nRow, nCol, robotHeight/2);
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
	for (unsigned int i=0; i< this->vMapMatrix.size(); i++) {
		this->vMapMatrix[i].resize(nGridWidth);
	}

	// According to the image set all the cells in the matrix to their types
	for (unsigned int i =0; i<nGridHeight;i++){
		for (unsigned int j =0; j<nGridWidth;j++){
			// Check cell type insert it to matrix.
			CELL cell = (CELL)CheckCellInPng(i,j);
			this->vMapMatrix[i][j] = cell;
		}
	}
}

int Map::ArrPosToMatrixPos(int nRow, int nCol) {
	return (this->imageAfterBlow[nRow*width*4 +nCol*4]);
}

int Map::CheckCellInPng(int nRow, int nCol){
	nRow *= this->GetGridMapResolution();
	nCol *= this->GetGridMapResolution();

	// If this counter is less than 16 so the cell is occupied.
	int nIsFreeCounter = 0;

	for (int nRowOffSet=0; nRowOffSet < this->GetGridMapResolution(); nRowOffSet++) {
		for (int nColOffSet=0; nColOffSet < this->GetGridMapResolution(); nColOffSet++) {
			if (ArrPosToMatrixPos(nRow + nRowOffSet,nCol +nColOffSet)==255){
				nIsFreeCounter++;
			}
		}
	}
	// In case there is less than 16 free pixels the cell if occupied.
	if (nIsFreeCounter<16) {
		return OCCUPIED;
	} else {
		return FREE;
	}
}

double Map::GetGridMapResolution(){
	return (this->gridResolution/ this->mapResolution);
}

point Map::calcPointInMap(point p){
	point result = {(int)(p.X/this->GetGridMapResolution()),
				    (int)(p.Y/this->GetGridMapResolution())};
	return result;
}

bool Map::IsCellFree(point p){
	if (this->vMapMatrix[p.Y][p.X] == OCCUPIED) {
		return false;
	}
	return true;
}
