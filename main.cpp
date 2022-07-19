#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>

using namespace cv;
using namespace std;

//densitie string
string DENSITIES = "@QB#NgWM8RDHdOKq9$6khEPXwmeZaoS2yjufF]}{tx1zv7lciL/\\|?*>r^;:_\"~,'.-` ";
const size_t len = DENSITIES.length();

int main(int argc, char* argv[]) {
    //open image in greyscale
    string inputName = argc > 1 ? argv[1] : "input.png";
    Mat image = imread(inputName, IMREAD_GRAYSCALE);
    
    //calculate scale and resize image
    double scale = double(argc > 2 ? stoi(argv[2]) : image.cols)/image.cols;
    resize(image, image, Size(0, 0), scale, scale / 2, INTER_LINEAR);

    //open output
    string outputName = argc > 3 ? argv[3] : "output.txt";
    ofstream output(outputName);

    //loop over image
    for(size_t i = 0; i < image.rows; i++) {
        for(size_t j = 0; j < image.cols; j++) {
            //calculate index and enforce max calue
            size_t index = (DENSITIES.length() / 255.0) * image.at<uchar>(i, j);
            index = index < len ? index : len - 1; 
            //output char
            output << DENSITIES[index];
        }
        output << "\n";
    }
    output.close();
}