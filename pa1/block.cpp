#include "block.h"

int  Block::Dimension() const{
    PNG image;
    return image.height();
}
void Block::Build(PNG & im, int upper, int left, int dimension){
    for (int x = left; x < left+dimension; x++) {
        vector<HSLAPixel> verticalStrip;
        for (int y = upper; y < upper+dimension; y++) {
          HSLAPixel* pix =  im.getPixel(x, y);
          verticalStrip.push_back(*pix);
        }
        this->data.push_back(verticalStrip);
    }
}
void Block::Render(PNG & im, int x, int y ) const{
    for (int x = 0; x < Dimension(); x++) {
        for (int y = 0; y < Dimension(); y++) {
            *(im.getPixel(x,y)) = this->data.at(x).at(y);
            }
        }
}

void Block::Negative(){
    for (int x = 0; x < Dimension(); x++) {
        for (int y = 0; y < Dimension(); y++) {
            this->data.at(x).at(y).h = 1.0 - this->data.at(x).at(y).h;
            this->data.at(x).at(y).l = 1.0 - this->data.at(x).at(y).l;
            }
        }

}