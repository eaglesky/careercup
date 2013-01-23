#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;
typedef unsigned int uint;

class RanImage {
 public:
  RanImage(int image_width = 10);
  ~RanImage();
  void ShowMatrix();
  void Rotate();

 private:
  void Swap(int x1, int y1, int x2, int y2);
  int width;
  uint **matrix;  
};

RanImage::RanImage(int image_width)
{
  width = image_width;
  matrix = new uint*[width];
  srand(time(0));
  for (int i = 0; i < width; i++)
  {
    matrix[i] = new uint[width];
    for (int j = 0; j < width; j++)
      matrix[i][j] = rand() % 10;
  }
}

RanImage::~RanImage()
{
  for (int i = 0; i < width; i++)
    delete []matrix[i];
  delete []matrix;
}

void RanImage::ShowMatrix()
{
  for(int i = 0; i < width; i++)
  {
    for(int j = 0; j < width; j++)
      cout << setw(12) << matrix[i][j];
    cout << endl;
  }
}

void RanImage::Rotate()
{
  for (int i = 0; i < width; i++)
    for (int j = 0; j < width -1  - i; j++)
      Swap(i, j, width -1 -j, width -1 - i);
  
  for (int i = 0; i < width/2; i++)
    for (int j = 0; j < width; j++)
      Swap(j, i, j, width - 1 - i);
}

void RanImage::Swap(int x1, int y1, int x2, int y2)
{
  int temp = matrix[x1][y1];
  matrix[x1][y1] = matrix[x2][y2];
  matrix[x2][y2] = temp;  
}

int main(int argc, char *argv[])
{
  int img_width = 5;  //Width is 5 by default;
  if (argc > 1)
    img_width = atoi(argv[1]);

  RanImage img(img_width);
  cout << "Before rotation: " << endl;
  img.ShowMatrix();
  cout << endl;
  cout << "After rotation: " << endl;
  img.Rotate();
  img.ShowMatrix();
  return 0;
}
