case R61581:
	// locate fontdata address
	temp=((c-cfont.offset)*((cfont.x_size/8)*cfont.y_size))+4;

	// read each row of fontdata, from left to right, from top to bottom
	for(j=0;j<((cfont.x_size/8)*cfont.y_size);j+=(cfont.x_size/8))
	{
		// set region to print
		setXY(x,y+(j/(cfont.x_size/8)),x+cfont.x_size-1,y+(j/(cfont.x_size/8)));
		for (int zz=0; zz<=(cfont.x_size/8)-1; zz++)
		{
			ch=pgm_read_byte(&cfont.font[temp+zz]);
			for(i=0;i<8;i++)
			{   
				if((ch&(1<<(7-i)))!=0)   
				{
					setPixel((fch<<8)|fcl);
				} 
				else
				{
					setPixel((bch<<8)|bcl);
				}   
			}
		}
		temp+=(cfont.x_size/8);
	}
	break;