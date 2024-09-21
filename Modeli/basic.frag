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
uniform PointLight pointLight2;
uniform PointLight pointLight3;
uniform PointLight pointLight4;
uniform sampler2D uDiffMap1;

void main()
{    


    vec3 resA = uLight.kA * texture(uDiffMap1, chUV).rgb;

	vec3 normal = normalize(chNormal);
	vec3 lightDirection = normalize(-uLight.dir);
	float nD = max(dot(normal, lightDirection), 0.0);
	vec3 resD = uLight.kD * ( nD * texture(uDiffMap1, chUV).rgb);

	vec3 viewDirection = normalize(uViewPos - chFragPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float s = pow(max(dot(viewDirection, reflectionDirection), 0.0), 32);
	vec3 resS = uLight.kS * (s * texture(uDiffMap1, chUV).rgb);
    
	vec3 lightDir1 = normalize(pointLight1.position - chFragPos);
    float diff1 = max(dot(normal, lightDir1), 0.0);
    vec3 reflectDir1 = reflect(-lightDir1, normal);
    float spec1 = pow(max(dot(viewDirection, reflectDir1), 0.0), 32);
    float distance1 = length(pointLight1.position - chFragPos);
    float attenuation1 = 1.0 / (pointLight1.constant + pointLight1.linear * distance1 + pointLight1.quadratic * (distance1 * distance1));    
    vec3 ambient1 = pointLight1.ambient * texture(uDiffMap1, chUV).rgb;
    vec3 diffuse1 = pointLight1.diffuse * diff1 * texture(uDiffMap1, chUV).rgb;
    vec3 specular1 = pointLight1.specular * spec1 * texture(uDiffMap1, chUV).rgb;
    ambient1 *= attenuation1;
    diffuse1 *= attenuation1;
    specular1 *= attenuation1;

    vec3 lightDir2 = normalize(pointLight2.position - chFragPos);
    float diff2 = max(dot(normal, lightDir2), 0.0);
    vec3 reflectDir2 = reflect(-lightDir2, normal);
    float spec2 = pow(max(dot(viewDirection, reflectDir2), 0.0), 32);
    float distance2 = length(pointLight2.position - chFragPos);
    float attenuation2 = 1.0 / (pointLight2.constant + pointLight2.linear * distance2 + pointLight2.quadratic * (distance2 * distance2));    
    vec3 ambient2 = pointLight2.ambient * texture(uDiffMap1, chUV).rgb;
    vec3 diffuse2 = pointLight2.diffuse * diff2 * texture(uDiffMap1, chUV).rgb;
    vec3 specular2 = pointLight2.specular * spec2 * texture(uDiffMap1, chUV).rgb;
    ambient2 *= attenuation2;
    diffuse2 *= attenuation2;
    specular2 *= attenuation2;

    vec3 lightDir3 = normalize(pointLight3.position - chFragPos);
    float diff3 = max(dot(normal, lightDir3), 0.0);
    vec3 reflectDir3 = reflect(-lightDir3, normal);
    float spec3 = pow(max(dot(viewDirection, reflectDir3), 0.0), 32);
    float distance3 = length(pointLight3.position - chFragPos);
    float attenuation3 = 1.0 / (pointLight3.constant + pointLight3.linear * distance3 + pointLight3.quadratic * (distance3 * distance3));    
    vec3 ambient3 = pointLight3.ambient * texture(uDiffMap1, chUV).rgb;
    vec3 diffuse3 = pointLight3.diffuse * diff3 * texture(uDiffMap1, chUV).rgb;
    vec3 specular3 = pointLight3.specular * spec3 * texture(uDiffMap1, chUV).rgb;
    ambient3 *= attenuation3;
    diffuse3 *= attenuation3;
    specular3 *= attenuation3;

    vec3 lightDir4 = normalize(pointLight4.position - chFragPos);
    float diff4 = max(dot(normal, lightDir4), 0.0);
    vec3 reflectDir4 = reflect(-lightDir4, normal);
    float spec4 = pow(max(dot(viewDirection, reflectDir4), 0.0), 32);
    float distance4 = length(pointLight4.position - chFragPos);
    float attenuation4 = 1.0 / (pointLight4.constant + pointLight4.linear * distance4 + pointLight4.quadratic * (distance4 * distance4));    
    vec3 ambient4 = pointLight4.ambient * texture(uDiffMap1, chUV).rgb;
    vec3 diffuse4 = pointLight4.diffuse * diff4 * texture(uDiffMap1, chUV).rgb;
    vec3 specular4 = pointLight4.specular * spec4 * texture(uDiffMap1, chUV).rgb;
    ambient4 *= attenuation4;
    diffuse4 *= attenuation4;
    specular4 *= attenuation4;

   FragColor=vec4(resA+resD+resS+ambient1+diffuse1+specular1+ambient2+diffuse2+specular2+ambient3+diffuse3+specular3+
   ambient4+diffuse4+specular4, 1.0);

}

