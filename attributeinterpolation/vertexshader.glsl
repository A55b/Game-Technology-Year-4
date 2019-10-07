


#version 330
                                       
layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 tex;
layout (location = 2) in vec4 Colour;

out vec4 Colour0;
out vec2 tex0;
                                                                   
void main()
{  
    gl_Position = vec4(Position.x, Position.y, Position.z, 1.0);
	Colour0 = Colour;
}