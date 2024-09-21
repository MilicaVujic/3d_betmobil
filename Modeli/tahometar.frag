#version 330 core
out vec4 FragColor;

in vec3 chNormal;  
in vec3 chFragPos;  
in vec2 chUV;
  
struct Light{ //Svjetlosni izvor
	vec3 dir; //Pozicija
	vec3 kA; //Ambijentalna komponenta (Indirektno svjetlo)
	vec3 kD; //Difuzna komponenta (Direktno svjetlo)
	vec3 kS; //Spekularna komponenta (Odsjaj)
};

struct PointLight {
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;
	
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 uViewPos; 
uniform Light uLight;
uniform PointLight pointLight1;

uniform sampler2D uTex;

void main()
{    

    vec3 resA = uLight.kA * texture(uTex, chUV).rgb;

	vec3 normal = normalize(chNormal);
	vec3 lightDirection = normalize(-uLight.dir);
	float nD = max(dot(normal, lightDirection), 0.0);
	vec3 resD = uLight.kD * ( nD * texture(uTex, chUV).rgb);

	vec3 viewDirection = normalize(uViewPos - chFragPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float s = pow(max(dot(viewDirection, reflectionDirection), 0.0), 32);
	vec3 resS = uLight.kS * (s * texture(uTex, chUV).rgb);

	vec3 lightDir1 = normalize(pointLight1.position - chFragPos);
    float diff1 = max(dot(normal, lightDir1), 0.0);
    vec3 reflectDir1 = reflect(-lightDir1, normal);
    float spec1 = pow(max(dot(viewDirection, reflectDir1), 0.0),32);
    float distance1 = length(pointLight1.position - chFragPos);
    float attenuation1 = 1.0 / (pointLight1.constant + pointLight1.linear * distance1 + pointLight1.quadratic * (distance1 * distance1));    
    vec3 ambient1 = pointLight1.ambient * texture(uTex, chUV).rgb;
    vec3 diffuse1 = pointLight1.diffuse * diff1 * texture(uTex, chUV).rgb;
    vec3 specular1 = pointLight1.specular * spec1 * texture(uTex, chUV).rgb;
    ambient1 *= attenuation1;
    diffuse1 *= attenuation1;
    specular1 *= attenuation1;

	FragColor=vec4(resA+resD+resS+ambient1+diffuse1+specular1,1.0);
}

