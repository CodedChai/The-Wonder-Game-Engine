#version 450 core

layout(location = 0) out vec4 out_color;

uniform sampler2D texture1;

in vec2 texcoord;
 
void main(void)
{
	vec4 color = texture(texture1, texcoord);
	//color += vec4(0.1, 0.1, 0.1, 0.0);
	out_color = color;
}