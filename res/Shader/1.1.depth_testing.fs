// /*
//  * @Author       : yangzijian
//  * @Description  : 
//  * @Date         : 2021-03-03 15:12:28
//  */
// #version 330 core
// out vec4 fragColor;

// in vec2 TexCoord;

// // texture samplers
// uniform sampler2D texture1;

// void main()
// {
// 	// fragColor = texture(texture1, TexCoord);
// 	fragColor = vec4(vec3(gl_FragCoord.z), 1.0);
// }

#version 330 core
out vec4 FragColor;

float near = 0.1; 
float far  = 100.0; 

float LinearizeDepth(float depth) 
{
    float z = depth * 2.0 - 1.0; // back to NDC 
    return (2.0 * near * far) / (far + near - z * (far - near));    
}

void main()
{             
    float depth = LinearizeDepth(gl_FragCoord.z) / far; // 为了演示除以 far
    FragColor = vec4(vec3(depth), 1.0);
}