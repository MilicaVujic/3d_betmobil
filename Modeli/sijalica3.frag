#version 330 core

uniform float plava;
out vec4 outCol;

uniform float zuta;

void main()
{
	

	outCol = vec4(0.0,0.0+zuta,0.0, 1.0); 
}