#version 330 core

struct Light{ //Svjetlosni izvor
	vec3 dir; //Pozicija
	vec3 kA; //Ambijentalna komponenta (Indirektno svjetlo)
	vec3 kD; //Difuzna komponenta (Direktno svjetlo)
	vec3 kS; //Spekularna komponenta (Odsjaj)
};
struct Material{ //Materijal objekta
	vec3 kA;
	vec3 kD;
	vec3 kS;
	float shine; //Uglancanost
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

in vec3 chNor;
in vec3 chFragPos;

out vec4 outCol;


uniform PointLight pointLight1;
uniform Light uLight;
uniform Material uMaterial;
uniform vec3 uViewPos;	//Pozicija kamere (za racun spekularne komponente)
uniform float providnost;

void main()
{
	vec3 resA = uLight.kA * uMaterial.kA;
	
	vec3 normal = normalize(chNor);
	vec3 lightDirection = normalize(-uLight.dir);
	float nD = max(dot(normal, lightDirection), 0.0);
	vec3 resD = uLight.kD * ( nD * uMaterial.kD);

	vec3 viewDirection = normalize(uViewPos - chFragPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float s = pow(max(dot(viewDirection, reflectionDirection), 0.0), 32);
	vec3 resS = uLight.kS * (s * uMaterial.kS);

	vec3 lightDir1 = normalize(pointLight1.position - chFragPos);
    float diff1 = max(dot(normal, lightDir1), 0.0);
    vec3 reflectDir1 = reflect(-lightDir1, normal);
    float spec1 = pow(max(dot(viewDirection, reflectDir1), 0.0), 32);
    float distance1 = length(pointLight1.position - chFragPos);
    float attenuation1 = 1.0 / (pointLight1.constant + pointLight1.linear * distance1 + pointLight1.quadratic * (distance1 * distance1));    
    vec3 ambient1 = pointLight1.ambient * uMaterial.kA;
    vec3 diffuse1 = pointLight1.diffuse * uMaterial.kD;
    vec3 specular1 = pointLight1.specular * spec1 * uMaterial.kS;
    ambient1 *= attenuation1;
    diffuse1 *= attenuation1;
    specular1 *= attenuation1;



	outCol = vec4(resA+resD+resS+ambient1+diffuse1+specular1, providnost); 
}