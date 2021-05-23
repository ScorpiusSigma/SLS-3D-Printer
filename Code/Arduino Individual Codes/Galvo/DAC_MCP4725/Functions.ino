//Galvo X-Axis
void xposON(int xpos)
{
  digitalWrite(2, HIGH);
  dac.setVoltage(xpos,false);

}
void xposOFF()
{
  digitalWrite(2, LOW);
}

void xnegON(int xneg)
{
  digitalWrite(3, HIGH);
  dac.setVoltage(xneg,false);
}
void xnegOFF()
{
  digitalWrite(3, LOW);
}

//Gavlo Y-Axis
void yposON(int ypos)
{
  digitalWrite(4, HIGH);
  dac.setVoltage(ypos,false);
}
void yposOFF()
{
  digitalWrite(4, LOW);
}
void ynegON(int yneg)
{
  digitalWrite(5, HIGH);
  dac.setVoltage(yneg,false);
}
void ynegOFF()
{
  digitalWrite(5, LOW);
}

//Straight Line
void straightLine(float x, float y)
{
  //y=mx+c
  float m = y/x;
  float c = y - (m * x);

  for(int xbit=0; xbit<((x/5)*4095); xbit++)
  {
    int ybit=(m*xbit)+c;
    yposON(ybit);
    yposOFF();
    xposON(xbit);
    xposOFF();
  }
  
}

void circle(float x, float y, float r)
{
 //sq(y)+sq(x)=sq(r)
 for(int xbit=0; xbit<((x/5)*4095);xbit++)
 {
  int ybit=sqrt(sq(r)-sq(xbit)); 
  xposON(xbit);
  xposOFF();
  yposON(ybit);
  yposOFF();
 }
}
