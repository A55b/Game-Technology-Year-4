#version 330
                                       
layout (location = 0) in vec3 Position;
layout (location = 1) in vec4 Colour;

out vec4 Colour0;

uniform float gScale;

//uniform float gOffsetX;
//uniform float gOffsetY;

uniform vec2 gOffsetVec;
                                                                   
void main()
{  
    //gl_Position = vec4(Position.x * gScale, Position.y * gScale, Position.z * gScale, 1.0);
	//gl_Position = vec4(Position.x * gOffsetX, Position.y * gOffsetY, Position.z , 1.0);
	gl_Position = vec4(Position.x , Position.y , Position.z , 1.0);
	Colour0 = Colour;
}