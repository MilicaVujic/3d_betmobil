#version 330 core

uniform float crvena;
uniform bool nv;

out vec4 outCol;



void main()
{
	
	if(nv==true)
	{
		if(crvena==1.0)
		{
			outCol=vec4(0.3,0.7,0.2,1.0);
		}
		else
		{
			outCol=vec4(0.0,0.0,0.0,1.0);

		}

	}
	else if(nv==false)
	{

		if(crvena==1.0)
		{
			outCol=vec4(1.0,0.0,0.0,1.0);
		}
		else
		{
			outCol=vec4(0.0,0.0,0.0,1.0);

		}
	}
	

}