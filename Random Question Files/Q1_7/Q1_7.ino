float second_filt(float x0){
  static float y1=0;  // y[n-1]
  static float y2=0;  // y[n-2]
  static float x1=0;  // x[n-1]
  static float x2=0;  // x[n-2]
  
  float y0 = 0; // TODO: Fill in this line
  
  // Shift values
  y2 = y1;  // Shift y[n-1] to y[n-2]
  y1 = y0;  // Shift y[n] to y[n-1]
  x2 = x1;  // Shift x[n-1] to x[n-2]
  x1 = x0;  // Shift x[n] to x[n-1]
  
  return y0;
}
