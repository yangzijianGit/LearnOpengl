#version 330 core

out vec4 fragColor;
out vec4 FragColor; // 只拿第一个输出颜色变量 
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    fragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2f);
    FragColor = mix(fragColor, vec4(0.0 ,0.8 ,0.8, 1.0), 0.2f);
    // FragColor = vec4(0.0 ,0.8 ,0.8, 1.0);
}