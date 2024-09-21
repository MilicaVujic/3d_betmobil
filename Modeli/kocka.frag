#version 330 core

struct Light{ //Svjetlosni izvor
	vec3 dir; //Pozicija
	vec3 kA; //Ambijentalna komponenta (Indirektno svjetlo)
	vec3 kD; //Difuzna komponenta (Direktno svjetlo)
	vec3 kS; //Spekularna komponenta (Odsjaj)
};
struct Material{ //Materijal objekta
	sampler2D diffuse;
	sampler2D specular;
	float shine; //Uglancanost
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};


in vec3 chNor;
in vec3 chFragPos;
in vec2 chUV;

out vec4 outCol;
uniform SpotLight spotLight;
uniform SpotLight spotLight2;
uniform SpotLight spotLight3;
uniform SpotLight spotLight4;
uniform Light uLight;
uniform Material uMaterial;
uniform vec3 uViewPos;	//Pozicija kamere (za racun spekularne komponente)

void main()
{
	vec3 resA = uLight.kA * texture(uMaterial.diffuse, chUV).rgb;

	vec3 normal = normalize(chNor);
	vec3 lightDirection = normalize(-uLight.dir);
	float nD = max(dot(normal, lightDirection), 0.0);
	vec3 resD = uLight.kD * ( nD * texture(uMaterial.diffuse, chUV).rgb);

	vec3 viewDirection = normalize(uViewPos - chFragPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float s = pow(max(dot(viewDirection, reflectionDirection), 0.0), 1);
	vec3 resS = uLight.kS * (s * texture(uMaterial.specular, chUV).rgb);

	vec3 lightDirSpot = normalize(spotLight.position - chFragPos);
    float diff = max(dot(normal, lightDirSpot), 0.0);

	vec3 reflectDir = reflect(-lightDirSpot, normal);
    float spec = pow(max(dot(viewDirection, reflectDir), 0.0), 1);

	vec3 ambientSpot = spotLight.ambient * texture(uMaterial.diffuse, chUV).rgb;
    vec3 diffuseSpot = spotLight.diffuse * diff * texture(uMaterial.diffuse, chUV).rgb;
    vec3 specularSpot = spotLight.specular * spec * texture(uMaterial.specular, chUV).rgb;

	float distance = length(spotLight.position - chFragPos);
    float attenuation = 1.0 / (spotLight.constant + spotLight.linear * distance + spotLight.quadratic * (distance * distance));    
    float theta = dot(lightDirSpot, normalize(-spotLight.direction)); 
    float epsilon = spotLight.cutOff - spotLight.outerCutOff;
    float intensity = clamp((theta - spotLight.outerCutOff) / epsilon, 0.0, 1.0);

	ambientSpot *= attenuation * intensity;
    diffuseSpot *= attenuation * intensity;
    specularSpot *= attenuation * intensity;


	vec3 lightDirSpot2 = normalize(spotLight2.position - chFragPos);
    float diff2 = max(dot(normal, lightDirSpot2), 0.0);

	vec3 reflectDir2 = reflect(-lightDirSpot2, normal);
    float spec2 = pow(max(dot(viewDirection, reflectDir2), 0.0), 1);

	vec3 ambientSpot2 = spotLight2.ambient * texture(uMaterial.diffuse, chUV).rgb;
    vec3 diffuseSpot2 = spotLight2.diffuse * diff2 * texture(uMaterial.diffuse, chUV).rgb;
    vec3 specularSpot2 = spotLight2.specular * spec2 * texture(uMaterial.specular, chUV).rgb;

	float distance2 = length(spotLight2.position - chFragPos);
    float attenuation2 = 1.0 / (spotLight2.constant + spotLight2.linear * distance2 + spotLight2.quadratic * (distance2 * distance2));    
    float theta2 = dot(lightDirSpot2, normalize(-spotLight2.direction)); 
    float epsilon2 = spotLight2.cutOff - spotLight2.outerCutOff;
    float intensity2 = clamp((theta2 - spotLight2.outerCutOff) / epsilon, 0.0, 1.0);

	ambientSpot2 *= attenuation2 * intensity2;
    diffuseSpot2 *= attenuation2 * intensity2;
    specularSpot2 *= attenuation2 * intensity2;




	
   outCol = vec4(resS+resA+resD+ambientSpot+diffuseSpot+specularSpot+ambientSpot2+diffuseSpot2+specularSpot2, 1.0); //Fongov model sjencenja
  
}
