#version 330 core

uniform float plava;
uniform bool nv;
out vec4 outCol;



void main()
{
	

	if(nv==true)
	{
		if(plava==1.0)
		{
			outCol=vec4(0.15,0.7,0.3,1.0);
		}
		else
		{
			outCol=vec4(0.0,0.0,0.0,1.0);

		}

	}
	else if(nv==false)
	{

		if(plava==1.0)
		{
			outCol=vec4(0.0,0.0,1.0,1.0);
		}
		else
		{
			outCol=vec4(0.0,0.0,0.0,1.0);

		}
	}
}