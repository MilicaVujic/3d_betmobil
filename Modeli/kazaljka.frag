#version 330 core 

out vec4 outCol;
uniform float u;
uniform bool nv;

void main() 
{
	if(nv)
	{
		outCol = vec4(0.0,abs(0.9-u),0.05,1.0);
	}
	else
	{
		outCol = vec4(abs(0.7-u),abs(0.3-u),abs(0.5-u),1.0);

	}

}