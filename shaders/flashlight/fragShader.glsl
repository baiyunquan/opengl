#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float     shininess;
}; 

struct Light {
    vec3  position;
    vec3  direction;
    float cutOff;
    float outerCutOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);

    // ambient
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;
  	
    // diffuse 
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;

    float theta = dot(lightDir, normalize(-light.direction));
    // theta and cutOff are cosin value

         // 执行光照计算
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//    vec3 specular = light.specular * spec * (vec3(1.0f) - vec3(texture(material.specular, TexCoords)));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
        //attenuation
        float distance    = length(light.position - FragPos);
        float attenuation = 1.0 / (light.constant + light.linear * distance + 
                light.quadratic * (distance * distance));
        ambient  *= attenuation; 
        diffuse  *= attenuation;
        specular *= attenuation;
        vec3 result = ambient + diffuse + specular;

    if(theta > light.cutOff)  {      

        FragColor = vec4(result, 1.0);
    }
     else  {
        float epsilon   = light.cutOff - light.outerCutOff;
        float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);    

        // 将不对环境光做出影响，让它总是能有一点光
        diffuse  *= intensity;
        specular *= intensity;
        FragColor = vec4(result, 1.0);
    }
    
} 