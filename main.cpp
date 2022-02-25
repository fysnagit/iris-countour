#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main()
{
  //Declaring area
  VideoCapture cap("ball.mp4");
  Mat frame,frame_hsv,frame_thresshold;
  Mat final = frame.clone();

  while (1)
  {
      cap >> frame;
      cvtColor(frame,frame_hsv,COLOR_BGR2HSV);
      inRange(frame_hsv,Scalar(0,100,0),Scalar(13,255,255),frame_thresshold);

      //DETECTING COUNTOUR
      vector<vector<Point>> contours;
      vector<Vec4i> hierarchy;
      findContours(frame_thresshold,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
      drawContours(frame,contours,-1,Scalar(0,255,0),4);
      char key =(char)waitKey(25);
      if (key == 'q')
      {
          break;
      }

      //showing area
      imshow("window",frame);
          
  }
  cap.release();
  destroyAllWindows();
  return 0;
}
